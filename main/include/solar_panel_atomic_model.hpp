#ifndef SOLAR_PANEL_ATOMIC_MODEL_HPP
#define SOLAR_PANEL_ATOMIC_MODEL_HPP

#include <random>
#include <iostream>
#include "cadmium/modeling/devs/atomic.hpp"
#include "solar_panel_model.hpp"

using namespace cadmium;


struct solar_panel_atomic_modelState {
    double sigma;
    double sp_irridiance;
    double sp_temperature;
    double smppt_power_1;
    double smppt_power_2;
    double smppt_power_3;
    double smppt_power_4;

    explicit solar_panel_atomic_modelState() : sigma(0),sp_irridiance(800), sp_temperature(293.15), smppt_power_1((37.3/60)*10), smppt_power_2((37.3/60)*10), smppt_power_3((37.3/60)*10), smppt_power_4((37.3/60)*10){

    }
};


class solar_panel_atomic_model : public Atomic<solar_panel_atomic_modelState> {
    public:
    
    //Static variables
    static double ap_irridiance;
    static double ap_temperature;
    static double ap_voltage;
    static double ap_current;
    static double string_voltage_1;
    static double string_voltage_2;
    static double string_voltage_3;
    static double string_voltage_4;
    static double string_voltage_5;
    static double string_voltage_6;
    static double inc_voltage_1;
    static double inc_voltage_2;
    static double inc_voltage_3;
    static double inc_voltage_4;
    static double inc_voltage_5;
    static double inc_voltage_6;

    //Declare your ports
    Port<double> in_temperature;
    Port<double> in_irridiance;
    Port<double> out_mppt_power_1;
    Port<double> out_mppt_power_2;
    Port<double> out_mppt_power_3;
    Port<double> out_mppt_power_4;
    
    solar_panel_atomic_model(const std::string id) : Atomic<solar_panel_atomic_modelState>(id, solar_panel_atomic_modelState()){
        ap_irridiance=800;
        ap_temperature=293.15;
        ap_voltage = 37.3/60;
        ap_current = 7.67;
        string_voltage_1=(37.3/60)*10;
        string_voltage_2=(37.3/60)*10;
        string_voltage_3=(37.3/60)*10;
        string_voltage_4=(37.3/60)*10;
        string_voltage_5=(37.3/60)*10;
        string_voltage_6=(37.3/60)*10;

        inc_voltage_1 = 0;
        inc_voltage_2 = 0;
        inc_voltage_3 = 0;
        inc_voltage_4 = 0;
        inc_voltage_5 = 0;
        inc_voltage_6 = 0;

        in_temperature = addInPort<double>("in_temperature");
        in_irridiance = addInPort<double>("in_irridiance");
        out_mppt_power_1 = addOutPort<double>("out_mppt_power_1");
        out_mppt_power_2 = addOutPort<double>("out_mppt_power_2");
        out_mppt_power_3 = addOutPort<double>("out_mppt_power_3");
        out_mppt_power_4 = addOutPort<double>("out_mppt_power_4");
    }

    
    // inernal transition
    void internalTransition(solar_panel_atomic_modelState& state) const override {
        //your internal transition function goes here
        if(solar_panel_atomic_model::inc_voltage_1==10){
            state.smppt_power_1 = solar_panel_atomic_model::string_voltage_1 *solar_panel_atomic_model::ap_current;
        }
        if (((solar_panel_atomic_model::string_voltage_2<solar_panel_atomic_model::string_voltage_3)&&(solar_panel_atomic_model::inc_voltage_3==10)&&(solar_panel_atomic_model::inc_voltage_2==10)) || (solar_panel_atomic_model::inc_voltage_2==10)){
            state.smppt_power_2 = solar_panel_atomic_model::string_voltage_2*solar_panel_atomic_model::ap_current;
        
        }else if (((solar_panel_atomic_model::string_voltage_2>solar_panel_atomic_model::string_voltage_3)&&(solar_panel_atomic_model::inc_voltage_3==10)&&(solar_panel_atomic_model::inc_voltage_2==10)) || (solar_panel_atomic_model::inc_voltage_3==10)){
            state.smppt_power_2 = solar_panel_atomic_model::string_voltage_3*solar_panel_atomic_model::ap_current;
        
        }
        if (((solar_panel_atomic_model::string_voltage_4<solar_panel_atomic_model::string_voltage_5)&&(solar_panel_atomic_model::inc_voltage_4==10)&&((solar_panel_atomic_model::inc_voltage_5==10))) || (solar_panel_atomic_model::inc_voltage_4==10)){
            state.smppt_power_3 = solar_panel_atomic_model::string_voltage_4*solar_panel_atomic_model::ap_current;
        
        }else if (((solar_panel_atomic_model::string_voltage_4>solar_panel_atomic_model::string_voltage_5)&&(solar_panel_atomic_model::inc_voltage_4==10)&&((solar_panel_atomic_model::inc_voltage_5==10))) || (solar_panel_atomic_model::inc_voltage_5==10)){
        
            state.smppt_power_3 = solar_panel_atomic_model::string_voltage_5*solar_panel_atomic_model::ap_current;
        
        }
        if(solar_panel_atomic_model::inc_voltage_6==10){
            state.smppt_power_4 = solar_panel_atomic_model::string_voltage_6*solar_panel_atomic_model::ap_current;
        }
        state.sigma += 1;
    }

    // external transition
    void externalTransition(solar_panel_atomic_modelState& state, double e) const override {
        //your external transition function goes here
        if((!in_temperature->empty()) && (!in_irridiance->empty())){
            for(const int &update_temp: in_temperature -> getBag()){
                state.sp_temperature = update_temp;
            }
            for(const double &update_irridiance: in_irridiance -> getBag()){
                state.sp_irridiance = update_irridiance;
            }

            double* data_IV = calculateIV(state.sp_temperature,state.sp_irridiance);
            solar_panel_atomic_model::ap_voltage = data_IV[1];
            solar_panel_atomic_model::ap_current = data_IV[0];
        }
    }
    
    
    // output function
    void output(const solar_panel_atomic_modelState& state) const override {
        //your output function goes here
        out_mppt_power_1 -> addMessage(state.smppt_power_1);
        out_mppt_power_2 -> addMessage(state.smppt_power_2);
        out_mppt_power_3 -> addMessage(state.smppt_power_3);
        out_mppt_power_4 -> addMessage(state.smppt_power_4);  
    }

    // time_advance function
    [[nodiscard]] double timeAdvance(const solar_panel_atomic_modelState& state) const override {     
            return 1;
    }



    static double* calculateIV(double temperature, double irridiance){

        double* rt = (double*)malloc(sizeof(double));
        
        
        double i_l = Isc * (irridiance / Dirridiance);

        double temp_kelvin = temperature + 273.15;
        
        double i_s = Isc * exp(-1*(Qcharge * Voc) / (Mfactor * KBconstant * temp_kelvin)); 

        double V_mpp = 0.0;
        double I_mpp = 0.0;
        double P_mpp = 0.0;

        double V_step = 0.001;
        for (double V = 0.0; V < Voc; V += V_step) {
            double I = current_Eq(V, i_l, i_s, temp_kelvin);
            double P = I * V;
            if (P > P_mpp) {
                P_mpp = P;
                V_mpp = V;
                I_mpp = I;
            }
        }

        rt[0] = I_mpp;
        rt[1] = V_mpp;
        return rt;
    }

    static double current_Eq(double new_volt, double i_l, double i_s, double temperature){
        return i_l - i_s * (exp((Qcharge * (new_volt + (Isc * R_s))) / (Mfactor * KBconstant * temperature)) - 1);
    }
};

#ifndef NO_LOGGING
std::ostream& operator<<(std::ostream &out, const solar_panel_atomic_modelState& state) {
    out  << "{Cell Voltage - " << solar_panel_atomic_model::ap_voltage << ", Cell Current - " <<solar_panel_atomic_model::ap_current<< "}";
    return out;
}
#endif

double solar_panel_atomic_model::ap_irridiance;
double solar_panel_atomic_model::ap_temperature;
double solar_panel_atomic_model::ap_voltage;
double solar_panel_atomic_model::ap_current;
double solar_panel_atomic_model::string_voltage_1;
double solar_panel_atomic_model::string_voltage_2;
double solar_panel_atomic_model::string_voltage_3;
double solar_panel_atomic_model::string_voltage_4;
double solar_panel_atomic_model::string_voltage_5;
double solar_panel_atomic_model::string_voltage_6;
double solar_panel_atomic_model::inc_voltage_1;
double solar_panel_atomic_model::inc_voltage_2;
double solar_panel_atomic_model::inc_voltage_3;
double solar_panel_atomic_model::inc_voltage_4;
double solar_panel_atomic_model::inc_voltage_5;
double solar_panel_atomic_model::inc_voltage_6;

#endif
#ifndef MPPT_MODEL_HPP
#define MPPT_MODEL_HPP


#include <iostream>
#include <nlohmann/json.hpp> 
#include <cadmium/modeling/celldevs/grid/cell.hpp> 
#include <cadmium/modeling/celldevs/grid/config.hpp> 
#include "cadmium/modeling/devs/atomic.hpp"
#include <cadmium/cadmium/modeling/ports.hpp>
#include <cadmium/cadmium/modeling/message_bag.hpp>
#include <tuple>

using namespace cadmium;
using namespace cadmium::celldevs;

//struct in_mppt_port : public cadmium::in_port<double> {};
struct mppt_modelState {
    double sigma;
    double mppt_1;
    double mppt_2;
    double mppt_3;
    double mppt_4;

    double daily_power_generation;
    double panel_total_power;

    //you can have as many state variables as you want/ need

    explicit mppt_modelState(): sigma(0),mppt_1(0),mppt_2(0),mppt_3(0),mppt_4(0), daily_power_generation(0.0), panel_total_power(0.0) {
    }
};

#ifndef NO_LOGGING
std::ostream& operator<<(std::ostream &out, const mppt_modelState& state) {
    out  << "{MPPT 1 - " << state.mppt_1<< ", MPPT 2 - " <<state.mppt_2<< ", MPPT 3 - " <<state.mppt_3<< ", MPPT 4 - " <<state.mppt_4<<"}";
    return out;
}
#endif

class mppt_model : public Atomic<mppt_modelState> {
    public:
    Port<double> in_mppt_power_1;
    Port<double> in_mppt_power_2;
    Port<double> in_mppt_power_3;
    Port<double> in_mppt_power_4;

    //cadmium::Port<double> in_voltage = addInPort<double>("in_voltage");

    mppt_model(const std::string id) : Atomic<mppt_modelState>(id, mppt_modelState()) {
        //Input Ports
        in_mppt_power_1 = addInPort<double>("in_mppt_power_1");
        in_mppt_power_2 = addInPort<double>("in_mppt_power_2");
        in_mppt_power_3 = addInPort<double>("in_mppt_power_3");
        in_mppt_power_4 = addInPort<double>("in_mppt_power_4");
    }

    // inernal transition
    void internalTransition(mppt_modelState& state) const override {
        
        int day_24 = (int)state.sigma%24;
        if (day_24==0){
            std::cout<<"Day "<<state.sigma/24<<" : "<<state.daily_power_generation<<std::endl;
            state.daily_power_generation = 0;
        }
        state.sigma += 1;
        if (state.sigma==2951){
            state.panel_total_power = state.mppt_1 + (2*state.mppt_2) + (2*state.mppt_3) + state.mppt_4;
            std::cout<<"Total power generated over 123 days : "<<state.panel_total_power<<std::endl;
        }
    }

    // external transition
    void externalTransition(mppt_modelState& state, double e) const override {
        if(!in_mppt_power_1->empty()){ 
            for(const double &update_power_1: in_mppt_power_1-> getBag()){
                state.mppt_1 += update_power_1 ;
                state.daily_power_generation += update_power_1;
            }
        }
        if(!in_mppt_power_2->empty()){ 
            for(const double &update_power_2: in_mppt_power_2-> getBag()){
                state.mppt_2 += update_power_2 ;
                state.daily_power_generation += update_power_2;
            }
        }
        if(!in_mppt_power_3->empty()){ 
            for(const double &update_power_3: in_mppt_power_1-> getBag()){
                state.mppt_3 += update_power_3 ;
                state.daily_power_generation += update_power_3;
            }
        }
        if(!in_mppt_power_4->empty()){ 
            for(const double &update_power_4: in_mppt_power_4-> getBag()){
                state.mppt_4 += update_power_4;
                state.daily_power_generation += update_power_4;
            }
        }
    }
    
    
    // output function
    void output(const mppt_modelState& state) const override {
        //your output function goes here
    }

    // time_advance function
    [[nodiscard]] double timeAdvance(const mppt_modelState& state) const override {     
        return 1;
    }
};

#endif
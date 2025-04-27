#ifndef SOLAR_PANEL_MODEL_HPP
#define SOLAR_PANEL_MODEL_HPP

#include <random>
#include <iostream>
#include <nlohmann/json.hpp> 
#include <cadmium/modeling/celldevs/grid/cell.hpp> 
#include <cadmium/modeling/celldevs/grid/config.hpp> 
#include "cadmium/modeling/devs/atomic.hpp"
#include <cadmium/cadmium/modeling/ports.hpp>
#include <tuple>
#include "solar_cell_state.hpp" 
#include "solar_panel_atomic_model.hpp"
#include <string>
#include <cmath>
#include <array>
#include <random>
#include <chrono>
#include <cadmium/cadmium/modeling/message_bag.hpp>
#include <cadmium/cadmium/modeling/message_box.hpp>

using namespace cadmium;
using namespace cadmium::celldevs;


struct solar_panel_modelState{
    double p_irridiance;
    double p_temperature;
    double p_voltage;
    double p_current;
    double mppt_voltage_1;
    double mppt_voltage_2;
    double mppt_voltage_3;
    double mppt_voltage_4;

    //std::vector<solarCellState> neighborhood;
    explicit solar_panel_modelState() : p_irridiance(Dirridiance), p_temperature(Dtemp), p_voltage(Dvmpp), p_current(Dimpp), mppt_voltage_1(Dvmpp*10), mppt_voltage_2(Dvmpp*10), mppt_voltage_3(Dvmpp*10), mppt_voltage_4(Dvmpp*10){}
};

class solar_panel_model : public GridCell<solarCellState, double>  {
    public:
    double p_irridiance = Dirridiance;
    double p_temperature = Dtemp;
    double p_voltage = Dvmpp;
    double p_current = Dimpp;
    double mppt_voltage_1 = Dvmpp * 10;
    double mppt_voltage_2 = Dvmpp * 10;
    double mppt_voltage_3 = Dvmpp * 10;
    double mppt_voltage_4 = Dvmpp * 10;
    

    solar_panel_model(const std::vector<int>& id,const std::shared_ptr<const GridCellConfig<solarCellState, double>>& config): 
                GridCell<solarCellState, double>(id, config){
                srand(time(NULL));
               
    }
    
       
    [[nodiscard]] solarCellState localComputation(solarCellState state,  const std::unordered_map<std::vector<int>,  
      NeighborData<solarCellState, double>>& neighborhood) const override { 
        if ((solar_panel_atomic_model::ap_voltage<0) || (solar_panel_atomic_model::ap_current<0)){
            state.solar_mode = false;
            state.voltage = 0;
        }else{
            float rnd = (float)rand()/(float)RAND_MAX;
            if (rnd<=0.995){
                state.solar_mode = true;
                state.voltage =solar_panel_atomic_model::ap_voltage;
                state.total_power += (solar_panel_atomic_model::ap_voltage*solar_panel_atomic_model::ap_current);
            }else{
                state.solar_mode = false;
                state.voltage = Vdiode;
                state.total_power += (Vdiode*solar_panel_atomic_model::ap_current);
            }
        }
        
        state.sum_voltage = state.voltage;
        
        
       
        bool bool_center = true;
        int row_panel = -1;
        int col_panel = -1;
        for (const auto& [neighborId, neighborData]: neighborhood) { 
            for (const auto& [neighborId2, neighborData2]: neighborhood) { 
                int neighboor_1 = neighborId[0]*10 + neighborId[1];
                int neighboor_2 = neighborId2[0]*10 + neighborId2[1];
                if((std::abs(neighboor_1-neighboor_2)!=1)&&(std::abs(neighboor_1-neighboor_2)!=10)&&(std::abs(neighboor_1-neighboor_2)!=0)){
                    bool_center = false;
                    break;
                }
            }
            if(bool_center){
                row_panel = neighborId[0];
                col_panel = neighborId[1];
            }
            bool_center = true;
        }

        switch(row_panel){
            case 0:
                if(solar_panel_atomic_model::inc_voltage_1 == 10){
                    solar_panel_atomic_model::string_voltage_1 =0;
                    solar_panel_atomic_model::inc_voltage_1 =0;
                }
                solar_panel_atomic_model::string_voltage_1 += state.voltage; 
                solar_panel_atomic_model::inc_voltage_1 += 1;
                break;
            case 1:
                
                if(solar_panel_atomic_model::inc_voltage_2 == 10){
                    solar_panel_atomic_model::string_voltage_2 =0;
                    solar_panel_atomic_model::inc_voltage_2 =0;
                }
                solar_panel_atomic_model::string_voltage_2 += state.voltage; 
                solar_panel_atomic_model::inc_voltage_2 += 1;
                break;
            case 2:
                if(solar_panel_atomic_model::inc_voltage_3 == 10){
                    solar_panel_atomic_model::string_voltage_3 =0;
                    solar_panel_atomic_model::inc_voltage_3 =0;
                }
                solar_panel_atomic_model::string_voltage_3 += state.voltage; 
                solar_panel_atomic_model::inc_voltage_3 += 1;
                break;
            case 3:
                if(solar_panel_atomic_model::inc_voltage_4 == 10){
                    solar_panel_atomic_model::string_voltage_4 =0;
                    solar_panel_atomic_model::inc_voltage_4 =0;
                }
                solar_panel_atomic_model::string_voltage_4 += state.voltage; 
                solar_panel_atomic_model::inc_voltage_4 += 1;
                break;
            case 4:
                if(solar_panel_atomic_model::inc_voltage_5 == 10){
                    solar_panel_atomic_model::string_voltage_5 =0;
                    solar_panel_atomic_model::inc_voltage_5 =0;
                }
                solar_panel_atomic_model::string_voltage_5 += state.voltage; 
                solar_panel_atomic_model::inc_voltage_5 += 1;
                break;
            case 5:
                if(solar_panel_atomic_model::inc_voltage_6 == 10){
                    solar_panel_atomic_model::string_voltage_6 =0;
                    solar_panel_atomic_model::inc_voltage_6 =0;
                }
                solar_panel_atomic_model::string_voltage_6 += state.voltage; 
                solar_panel_atomic_model::inc_voltage_6 += 1;
                break;
        }
       
        state.sigma += 1;
        return state; 
    }

    [[nodiscard]] double outputDelay(const solarCellState& state) const override { 
        return  1; //Output every one hour
    } 



};

#endif
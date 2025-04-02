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
    std::vector<solarCellState> neighborhood;
    explicit solar_panel_modelState():p_irridiance(800){}
};

class solar_panel_model : public GridCell<solarCellState, double>  {
    public:

    solar_panel_model(const std::vector<int>& id,const std::shared_ptr<const GridCellConfig<solarCellState, double>>& config): 
                GridCell<solarCellState, double>(id, config) {
                    srand(time(NULL));
                    
    }
    
       
    [[nodiscard]] solarCellState localComputation(solarCellState state,  const std::unordered_map<std::vector<int>,  
      NeighborData<solarCellState, double>>& neighborhood) const override { 
                state.sigma += 1;
                float rnd = (float)rand()/(float)RAND_MAX;
                if (rnd<=0.9){
                    state.solar_mode = true;
                    state.voltage = Vmpp;
                    state.total_power += (Vmpp*Impp);
                }else{
                    state.solar_mode = false;
                    state.voltage = Vdiode;
                    state.total_power += (Vdiode*Impp);
                }       
        return state; 
    }

    
    [[nodiscard]] double outputDelay(const solarCellState& state) const override { 
        return  1; //Output every one hour
    } 


};

#endif
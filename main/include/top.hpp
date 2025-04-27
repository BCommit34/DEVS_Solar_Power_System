#ifndef SAMPLE_TOP_HPP
#define SAMPLE_TOP_HPP

#include "cadmium/modeling/devs/coupled.hpp"
#include "sun_model.hpp"
#include "mppt_model.hpp"
#include "solar_panel_model.hpp"
#include "solar_panel_atomic_model.hpp"
#include <nlohmann/json.hpp> 
#include <cadmium/modeling/celldevs/grid/coupled.hpp> 
#include <fstream> 
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace cadmium;

static int* return_index(std::string str){
    int* rt_index = (int*)malloc(sizeof(int));
    int i = 0;

    std::string str_digits = str.substr(1,str.length()-2);

    std::stringstream ss(str_digits);
    std::string token;
    while(std::getline(ss,token,',')){
        rt_index[i] = std::stoi(token);
        i++;
    }

    return rt_index;
}

std::shared_ptr<GridCell<solarCellState, double>> addGridCell( const coordinates & cellId,const std::shared_ptr<const GridCellConfig<solarCellState, double>>& cellConfig){ 
    auto cellModel = cellConfig->cellModel;
    if(cellModel == "solarCellState") { 
        return std::make_shared<solar_panel_model>(cellId, cellConfig);   
    }else{ 
        throw std::runtime_error("Unknown cell model: " + cellModel);
    } 
}

struct top_coupled : public Coupled {
    top_coupled(const std::string& id) : Coupled(id) {
        
        auto sun_model_1 = addComponent<sun_model>("Model - Sun");
        auto mppt_model_1 = addComponent<mppt_model>("Model - MPPT");
        auto solar_panel_atomic_model_1 = addComponent<solar_panel_atomic_model>("Model - Solar Panel");
		auto solar_panel_model_1 = addComponent<GridCellDEVSCoupled<solarCellState, double>>("CellDEVS Model - Solar Panel", addGridCell,"./main/include/solar_cell_config.json");
        
        solar_panel_model_1->buildModel();
        
      
        addCoupling(sun_model_1->out_temperature,solar_panel_atomic_model_1->in_temperature);
        addCoupling(sun_model_1->out_irridiance,solar_panel_atomic_model_1->in_irridiance);
        addCoupling(solar_panel_atomic_model_1->out_mppt_power_1,mppt_model_1->in_mppt_power_1);
        addCoupling(solar_panel_atomic_model_1->out_mppt_power_2,mppt_model_1->in_mppt_power_2);
        addCoupling(solar_panel_atomic_model_1->out_mppt_power_3,mppt_model_1->in_mppt_power_3);
        addCoupling(solar_panel_atomic_model_1->out_mppt_power_4,mppt_model_1->in_mppt_power_4);
        
    }
};

#endif
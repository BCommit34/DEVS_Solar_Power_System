#ifndef SOLAR_CELL_STATE_HPP
#define SOLAR_CELL_STATE_HPP

#include <iostream> 
#include <nlohmann/json.hpp> 
#include <math.h>
#include <stdio.h>

//Specification of the Solar Cell in LG380Q1C-V5 panel
#define Vdiode      -0.5
#define Isc        8.73
#define Voc        (40.3/60)
#define Pmax       (286/60)
#define Vmpp       (37.3/60)
#define Impp       7.67
#define Qcharge    1.602e-19
#define Mfactor    1.5
#define KBconstant 1.38e-23 
#define CEuler     2.71828182845904523536


struct solarCellState { 
    bool solar_mode;
    mutable double voltage;
    mutable double current;
    mutable double total_power;
    double t_cell;
    double i_S;
    double i_L;
    double sigma;

    //Default constructor function. 
    solarCellState() : sigma(0),solar_mode(true),  voltage(0.0),current(Impp), t_cell(293.15){} 

}; 

std::ostream& operator<<(std::ostream& os, const solarCellState& x) { 
    //os <<"State : Time-"<<x.sigma<<", Voltage-"<<((x.solar_mode)? (Vmpp): (Vdiode))<< ", Total power-" <<x.total_power;
    os <<((x.solar_mode)? (Vmpp): (Vdiode))<< "/" <<x.total_power;
    return os; 
} 
 
bool operator!=(const solarCellState& x, const solarCellState& y) { 
    return (x.sigma != y.sigma); 
} 
 
[[maybe_unused]] void from_json(const nlohmann::json& j, solarCellState& s) { 
        j.at("solar_mode").get_to(s.solar_mode); 
        j.at("voltage").get_to(s.voltage); 
        j.at("total_power").get_to(s.total_power); 
        j.at("sigma").get_to(s.sigma);
}

#endif
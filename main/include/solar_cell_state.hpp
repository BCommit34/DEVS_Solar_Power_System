#ifndef SOLAR_CELL_STATE_HPP
#define SOLAR_CELL_STATE_HPP

#include <iostream> 
#include <nlohmann/json.hpp> 
#include <math.h>
#include <stdio.h>

//Specification of the Solar Cell in LG380Q1C-V5 panel

#define Qcharge    1.602e-19
#define KBconstant 1.38e-23 
#define Mfactor    1.5
#define Isc        10.84
#define Voc        (42.9/60)
#define Dirridiance 1000
#define Dpmax      (380/60)
#define Dvmpp      (37.4/60)
#define Dtemp      298.15
#define Dimpp      10.17
#define CEuler     2.71828182845904523536
#define Vdiode     -0.5

#define R_s       6.782e-4
//#define R_s         (((37.3/60)*((8.73/7.67)-1))+(((40.3-37.3)/60)/(log(1-(7.67/8.73)))))/(8.73-7.67+(7.67/(log(1-(7.67/8.73)))))
        




struct solarCellState { 
    bool solar_mode;
    mutable double voltage;
    mutable double sum_voltage;
    mutable double current;
    mutable double total_power;
    double t_cell;
    double irrid_cell;
    double i_S;
    double i_L;
    double sigma;
    

    //Default constructor function. 
    solarCellState() : sigma(0),solar_mode(true),  voltage(Dvmpp), sum_voltage(0.0), current(Dimpp), t_cell(Dtemp),irrid_cell(Dirridiance){} 

}; 

std::ostream& operator<<(std::ostream& os, const solarCellState& x) { 
    //os <<"State : Time-"<<x.sigma<<", Voltage-"<<((x.solar_mode)? (Dvmpp): (Vdiode))<< ", Total power-" <<x.total_power;
    os <<((x.solar_mode)? (x.voltage): (Vdiode))<< "/" <<x.total_power;
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
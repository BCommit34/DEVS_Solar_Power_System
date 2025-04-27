#ifndef SUN_MODEL_HPP
#define SUN_MODEL_HPP


#include <iostream>
#include <nlohmann/json.hpp> 
#include <cadmium/modeling/celldevs/grid/cell.hpp> 
#include <cadmium/modeling/celldevs/grid/config.hpp> 
#include "cadmium/modeling/devs/atomic.hpp"
#include <cadmium/cadmium/modeling/ports.hpp>
#include <cadmium/cadmium/modeling/message_bag.hpp>
#include "climate_data.hpp"
#include <tuple>


using namespace cadmium;
using namespace cadmium::celldevs;

struct sun_modelState {
    double sigma;
    std::vector<double> hourly_weather;
    std::vector<std::vector<double>> climate;
    explicit sun_modelState(): sigma(0), hourly_weather({0.0,0.0,0.0,0.0,800,20}){
    }
};

#ifndef NO_LOGGING
std::ostream& operator<<(std::ostream &out, const sun_modelState& state) {
    out  << "{Date (Year/Month/Day - Time) : " << state.hourly_weather[0]<<"/"<< state.hourly_weather[1]<<"/"<< state.hourly_weather[2]<<" - " << state.hourly_weather[3]<<":00 " << ", Temperature : "<<state.hourly_weather[5]<<", Irridiance : "<<state.hourly_weather[4]<<"}";
    return out;
}
#endif

class sun_model : public Atomic<sun_modelState> {
    //Declare Out Ports
    public:
    Port<double> out_temperature;
    Port<double> out_irridiance;

    sun_model(const std::string id) : Atomic<sun_modelState>(id, sun_modelState()) {
       //Out Ports
        out_temperature = addOutPort<double>("out_temperature");
        out_irridiance = addOutPort<double>("out_irridiance");

        //Increment time advance
        state.climate = climate_data::set_climate_database();
    }

    // inernal transition
    void internalTransition(sun_modelState& state) const override {
        //Update the weather conditions
        state.hourly_weather = state.climate[state.sigma];

        //Increment time advance
        state.sigma += 1;
    }

    // external transition
    void externalTransition(sun_modelState& state, double e) const override {
        //your external transition function goes here
    }
    
    // output function
   void output(const sun_modelState& state) const override {

        out_temperature -> addMessage(state.hourly_weather[5]);
        out_irridiance -> addMessage(state.hourly_weather[4]);
    }

    // time_advance function
    [[nodiscard]] double timeAdvance(const sun_modelState& state) const override {     
        return 1;
    }
};




#endif
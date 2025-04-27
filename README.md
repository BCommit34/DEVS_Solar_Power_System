
# Cell-DEVS : Photovoltaic Panel Power System
The project is a prototype of a Photovoltaic Panel Power System used to compute the voltage across the cells hourly and calculate the total energy generated (watts-hours). The project utilize CADMIUM Cell-DEVS model to simulate the system. The Cell-DEVS model represent a configuration of a grid that is 6x10. 

## Reference

The author would like to acknowledge [@Sasisekhar](https://github.com/Sasisekhar/blank_project_rt) for providing a template to develop a DEVS model.
Link : https://github.com/Sasisekhar/blank_project_rt

The author would like to acknowledge the climate data provided by the contributor Manvi Mishra from Delhi Technological University Department of Electrical Engineering for providing a dataset detailing Irradiance and Temperature in Dehli, India from May 1st, 2021 to September 4th, 2021. The data was used to create the data file climate_dataset.csv 
Link : https://data.mendeley.com/datasets/9jcxhpznyj/1 

## Script Writer
Name : Brigitte H.

Github: [https://github.com/BCommit34/CellDEVS_Solar_Panel](https://github.com/BCommit34/DEVS_Solar_Power_System)


## Documentations for CellDEVS_Solar_Panel
Cell_DEVS model
 - [solar_cell_state.hpp](https://github.com/BCommit34/DEVS_Solar_Power_System/blob/main/main/include/solar_cell_state.hpp) : The script contains the state variables of each individual solar cells in the panel
 - [solar_panel_model.hpp](https://github.com/BCommit34/DEVS_Solar_Power_System/blob/main/main/include/solar_panel_model.hpp) : The class generate the structure containing the cells of the grid. It implements the localComputation function and the outputDelay function. The localComputation Function changes the status of the cell (current voltage and total power generated). The outputDelay function increment the time.
 - [solar_cell_config.json](https://github.com/BCommit34/DEVS_Solar_Power_System/blob/main/main/include/solar_cell_config.json) : Json file containing the configuration details of the solar panel used to create the panel_model object.
- [main.hpp](https://github.com/BCommit34/DEVS_Solar_Power_System/blob/main/main/main.cpp) : The main script running the simmulation and generating the DEVS Simulation files

Atomic DEVS model
 - [solar_panel_atomic_model.hpp](https://github.com/BCommit34/DEVS_Solar_Power_System/blob/main/main/include/solar_panel_atomic_model.hpp) : The atomic model used to communicate with the Sun atomic model and the MPPT atomic model.
 - [sun_model.hpp](https://github.com/BCommit34/DEVS_Solar_Power_System/blob/main/main/include/sun_model.hpp) : The atomic model manage the weather conditions data collected from the file climate_dataset.csv. The model communicate the weather condition to the solaratomic model via the ports.
 - [mppt_model.hpp](https://github.com/BCommit34/DEVS_Solar_Power_System/blob/main/main/include/mppt_model.hpp) : Collect the output data from the solar atomic model. 



DEVS Simulation : Additional file for ARSLabs (DEVS Web Viewer)
- [simulation_power.log](https://github.com/BCommit34/DEVS_Solar_Power_System/blob/main/simulation_power.log): Log file containing the data points collected during the simulation for the power generation
- [simulation_voltage.log](https://github.com/BCommit34/DEVS_Solar_Power_System/blob/main/simulation_voltage.log): Log file containing the data points collected during the simulation for the voltage change across the cells
- [simulation_atomic_models.log](https://github.com/BCommit34/DEVS_Solar_Power_System/blob/main/simulation_atomic_models.log): Log file containing the output from the atomic models.
- [climate_dataset.csv](https://github.com/BCommit34/DEVS_Solar_Power_System/blob/main/main/include/climate_dataset.csv): The CSV file was derived from a data set containing weather conditions in Dehli, India from May 1st 2021 to Septembe 4th 2021. 


## Acknowledgements

 - [@Sasisekhar](https://github.com/Sasisekhar/blank_project_rt)




# Cell-DEVS : Photovoltaic Panel Power System
The project is a prototype of a Photovoltaic Panel Power System used to compute the voltage across the cells hourly and calculate the total energy generated (watts-hours). The project utilize CADMIUM Cell-DEVS model to simulate the system. The Cell-DEVS model represent a configuration of a grid that is 6x10. 

## Reference

The author would like to acknowledge [@Sasisekhar](https://github.com/Sasisekhar/blank_project_rt) for providing a template to develop a DEVS model.

Link : https://github.com/Sasisekhar/blank_project_rt


## Script Writer
Name : Brigitte H.

Github: https://github.com/BCommit34/CellDEVS_Solar_Panel


## Documentations for CellDEVS_Solar_Panel
Cell_DEVS model
 - [solar_cell_state.hpp](https://linktodocumentation) : The script contains the state variables of each individual solar cells in the panel
 - [solar_panel_model.hpp](https://linktodocumentation) : The class generate the structure containing the cells of the grid. It implements the localComputation function and the outputDelay function. The localComputation Function changes the status of the cell (current voltage and total power generated). The outputDelay function increment the time.
 - [solar_cell_config.json](https://linktodocumentation) : Json file containing the configuration details of the solar panel used to create the panel_model object.
- [main.hpp](https://linktodocumentation) : The main script running the simmulation and generating the DEVS Simulation files


DEVS Simulation : Additional file for ARSLabs (DEVS Web Viewer)
- [simulation_power.log](https://linktodocumentation): Log file containing the data points collected during the simulation for the power generation
- [simulation_voltage.log](https://linktodocumentation): Log file containing the data points collected during the simulation for the voltage change across the cells


## Acknowledgements

 - [@Sasisekhar](https://github.com/Sasisekhar/blank_project_rt)



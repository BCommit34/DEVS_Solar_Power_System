#include <limits>

#ifdef SIM_TIME
	#include "cadmium/simulation/root_coordinator.hpp"
#else
	#include "cadmium/simulation/rt_root_coordinator.hpp"
	#ifdef ESP_PLATFORM
		#include <cadmium/simulation/rt_clock/ESPclock.hpp>
	#else
		#include <cadmium/simulation/rt_clock/chrono.hpp>
	#endif
#endif

#ifndef NO_LOGGING
	#include "cadmium/simulation/logger/stdout.hpp"
	#include "cadmium/simulation/logger/csv.hpp"
#endif

#include <nlohmann/json.hpp> 
#include <cadmium/modeling/celldevs/grid/coupled.hpp> 
#include <cadmium/simulation/logger/csv.hpp> 
#include <cadmium/simulation/root_coordinator.hpp> 
#include <fstream> 
#include <string>
#include <ios>
#include <iostream>
#include <sstream> 
#include "include/solar_panel_model.hpp" 
#include "include/top.hpp" 

#include "cadmium/modeling/devs/coupled.hpp"
#include <vector>
#include <numeric>

 
using namespace cadmium::celldevs; 
using namespace cadmium; 

extern "C" {

	int main(int argc, char ** argv) { 
		auto model = std::make_shared<top_coupled> ("top");
		auto rootCoordinator = RootCoordinator(model); 
		rootCoordinator.setLogger<CSVLogger>("grid_log.txt", "/"); 
		
		rootCoordinator.start(); 
		rootCoordinator.simulate(2952.0);
		rootCoordinator.stop(); 
		
		//*********************************CREATE LOG FILE AND ATOMIC MODEL FILE******************************/
		std::string token_term;
		std::ifstream io_csv_file("grid_log.txt");
		std::ofstream io_log_file;
		std::ofstream io_log_file2;
		std::ofstream io_log_file3;

		io_log_file.open("simulation_voltage.log",std::ios::trunc);
		io_log_file2.open("simulation_power.log",std::ios::trunc);
		io_log_file3.open("simulation_atomic_models.log",std::ios::trunc);

		io_log_file << "Mensaje I / 00:00:00:000 / Root(00) para top(01)"<<std::endl;
		io_log_file << "Mensaje I / 00:00:00:000 / top(01) para panel(02)"<<std::endl;

		io_log_file2 << "Mensaje I / 00:00:00:000 / Root(00) para top(01)"<<std::endl;
		io_log_file2 << "Mensaje I / 00:00:00:000 / top(01) para panel(02)"<<std::endl;

		for (int d = 0; d<2 ; d++){
			for(int i=0 ; i<10 ; i++){
				for(int j=0 ; j<6 ; j++){
					switch(d){
						case 0:
							io_log_file << "Mensaje I / 00:00:00:000 / panel(02) para panel("<<i<<","<<j<<")("<< std::setw(2) << std::setfill('0')<<((i*10)+j+3)<<")"<<std::endl;
							io_log_file2 << "Mensaje I / 00:00:00:000 / panel(02) para panel("<<i<<","<<j<<")("<< std::setw(2) << std::setfill('0')<<((i*10)+j+3)<<")"<<std::endl;
							break;
						case 1:
							io_log_file << "Mensaje D / 00:00:00:000 / panel("<<i<<","<<j<<")("<< std::setw(2) << std::setfill('0')<<((i*10)+j+3)<<") / 00:00:00:001 para panel(02)"<<std::endl;
							io_log_file2 << "Mensaje D / 00:00:00:000 / panel("<<i<<","<<j<<")("<< std::setw(2) << std::setfill('0')<<((i*10)+j+3)<<") / 00:00:00:001 para panel(02)"<<std::endl;
							break;
					}
				}
			}
		}
		
		io_log_file << "Mensaje D / 00:00:00:000 / panel(02) / 00:00:00:001 para top(01)"<<std::endl;
		io_log_file << "Mensaje D / 00:00:00:000 / top(01) / 00:00:00:001 para Root(00)"<<std::endl;
		
		io_log_file2 << "Mensaje D / 00:00:00:000 / panel(02) / 00:00:00:001 para top(01)"<<std::endl;
		io_log_file2 << "Mensaje D / 00:00:00:000 / top(01) / 00:00:00:001 para Root(00)"<<std::endl;
		
		if (!io_csv_file.is_open()){
			std::cerr << "Error opening file: grid_log.txt" << std::endl;
		}else{
			std::stringstream prefix;
			std::stringstream time;
			std::stringstream operation;
			std::stringstream port;
			std::stringstream status;
			std::stringstream power;

			std::stringstream file;
			file << io_csv_file.rdbuf();
			char* buffer = new char[file.str().length()+1];
			std::strcpy(buffer, file.str().c_str());
			
			char *token_csv;
			token_csv = std::strtok(buffer, "\n");
			token_csv = std::strtok(NULL, "\n");
			token_csv = std::strtok(NULL, "\n");
			while (token_csv != nullptr) {
				int i_term = 0;
				std::string tmp_token_csv(token_csv);
                std::stringstream lineStream(tmp_token_csv);
				if (tmp_token_csv.find("Model") != std::string::npos){
					io_log_file3<<tmp_token_csv<<std::endl;
				}else{
					while (std::getline(lineStream, token_term, '/')) {
						switch(i_term){
							case 0:{
								time={};
								time<<"00:00:"<< std::setw(2) << std::setfill('0')<< std::stoi(token_term)+1<<":000";
								break;
							}
							case 2:{

								operation={};
								int* cell_index = return_index(token_term);
								operation<<"panel(" << cell_index[1] <<","<< cell_index[0] <<")("<< std::setw(2) << std::setfill('0')<<((cell_index[0]*10)+cell_index[1]+3)<<")" ;
								break;
							}
							case 3:{
								prefix={};
								port={};
								if (token_term == ""){
									prefix<<"Mensaje D";
									port<<"...";
								}else{
									prefix<<"Mensaje Y";
									port<<"out /";
								}
								break;
							}
							case 4:{
								status={};
								if (token_term.compare("Mensaje D") == 0){
									status<< "para panel(02)";
								}else{
									status<<" "<< token_term << " para panel(02)";
								}
								break;
							}
							case 5:{
								power={};
								if (token_term.compare("Mensaje D") == 0){
									power<< "para panel(02)";
								}else{
									power<<" "<< token_term << " para panel(02)";
								}
								break;
							}
						}
						i_term++;
					}
					io_log_file<<prefix.str()<<" / "<<time.str()<< " / "<<operation.str()<<" / "<<port.str()<<" "<<status.str()<<std::endl;
					io_log_file2<<prefix.str()<<" / "<<time.str()<< " / "<<operation.str()<<" / "<<port.str()<<" "<<power.str()<<std::endl;
				}
				token_csv = std::strtok(NULL, "\n");
			}
		}
		io_csv_file.close();
		io_log_file.close();
		io_log_file2.close();
		io_log_file3.close();
	} 
}
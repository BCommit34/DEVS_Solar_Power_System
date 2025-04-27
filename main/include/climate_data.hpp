#ifndef CLIMATE_DATA_HPP
#define CLIMATE_DATA_HPP

class climate_data{
    public:
        static std::vector<std::vector<double>> set_climate_database(){
            return set_climate_database("./main/include/climate_dataset.csv");
        }



        static std::vector<std::vector<double>> set_climate_database(std::string database_csv_file){

            std::ifstream io_csv_file(database_csv_file);
            std::vector<std::vector<double>> collection_climate_data = {};
            //std::string tmp_street_name = "";
            //int index_street=0;


            if (!io_csv_file.is_open()){
                std::cerr << "Error opening file: " << database_csv_file << std::endl;
            }else{
                //Create vector collection of street
                std::stringstream file_buffer;
                file_buffer << io_csv_file.rdbuf();
                char* str_file_buffer = new char[file_buffer.str().length()+1];
                std::strcpy(str_file_buffer, file_buffer.str().c_str());

                char *tokenh_climate;
                std::string tokenh_split;
                std::vector<double> vector_climateh;
                tokenh_climate = std::strtok(str_file_buffer, "\n");
                while (tokenh_climate != nullptr) {
                    vector_climateh = {};
                    std::string tmp_tokenh_climate(tokenh_climate);
                    std::stringstream lineStream(tmp_tokenh_climate);
                    
                    while (std::getline(lineStream, tokenh_split, ',')) {
                        vector_climateh.push_back(std::stoi(tokenh_split));
                    }
                    tokenh_climate = std::strtok(NULL, "\n");
                    collection_climate_data.push_back(vector_climateh);
                }
            }
            
            io_csv_file.close();
            //climate_data::print_map(collection_climate_data);
            return collection_climate_data;
        }
    
        static void print_map(std::vector<std::vector<double>> map){
            for(int i = 0 ; i < map.size() ; i++){
                std::cout << map[i][0]<<" : " <<map[i][1]<< " : " << map[i][2]<< " : " << map[i][3]<< " : " << map[i][4]<< " : " << map[i][5]<< std::endl;
                std::cout <<"_________________________________________________________________________________"<<std::endl;

            }
        }

};

#endif
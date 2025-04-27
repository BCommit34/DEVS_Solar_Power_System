solar_panel_atomic_model.hpp:56:21: error: ‘solar_panel_model’ was not declared in this scope; did you mean ‘solar_panel_atomic_model’?
   56 |     std::shared_ptr<solar_panel_model> atom_model;
      |                     ^~~~~~~~~~~~~~~~~
      |                     solar_panel_atomic_model
/.../CellDEVS_Solar_Panel/main/include/solar_panel_atomic_model.hpp:56:38: error: template argument 1 is invalid
   56 |     std::shared_ptr<solar_panel_model> atom_model;
      |                                      ^
/.../CellDEVS_Solar_Panel/main/include/solar_panel_atomic_model.hpp:56:10: error: ‘<expression error>’ in namespace ‘std’ does not name a type
   56 |     std::shared_ptr<solar_panel_model> atom_model;
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/.../CellDEVS_Solar_Panel/main/include/solar_panel_atomic_model.hpp:59:68: error: ‘solar_panel_model’ was not declared in this scope; did you mean ‘solar_panel_atomic_model’?
   59 |     solar_panel_atomic_model(const std::string id, std::shared_ptr<solar_panel_model> cd_model) : Atomic<solar_panel_atomic_modelState>(id, solar_panel_atomic_modelState()){
      |                                                                    ^~~~~~~~~~~~~~~~~
      |                                                                    solar_panel_atomic_model
/.../CellDEVS_Solar_Panel/main/include/solar_panel_atomic_model.hpp:59:85: error: template argument 1 is invalid
   59 |     solar_panel_atomic_model(const std::string id, std::shared_ptr<solar_panel_model> cd_model) : Atomic<solar_panel_atomic_modelState>(id, solar_panel_atomic_modelState()){
      |                                                                                     ^
/.../CellDEVS_Solar_Panel/main/include/solar_panel_atomic_model.hpp:59:52: error: ‘std::cd_model’ has not been declared
   59 |     solar_panel_atomic_model(const std::string id, std::shared_ptr<solar_panel_model> cd_model) : Atomic<solar_panel_atomic_modelState>(id, solar_panel_atomic_modelState()){
      |                                                    ^~~
/.../CellDEVS_Solar_Panel/main/include/solar_panel_atomic_model.hpp: In constructor ‘solar_panel_atomic_model(std::string, int)’:
/.../CellDEVS_Solar_Panel/main/include/solar_panel_atomic_model.hpp:63:9: error: ‘atom_model’ was not declared in this scope
   63 |         atom_model = cd_model;
      |         ^~~~~~~~~~
/.../CellDEVS_Solar_Panel/main/include/solar_panel_atomic_model.hpp:63:22: error: ‘cd_model’ was not declared in this scope
   63 |         atom_model = cd_model;
      |                      ^~~~~~~~


       /*p_irridiance = Dirridiance;
        p_temperature = Dtemp;
        p_voltage = Dvmpp;
        p_current = Dimpp;
        mppt_voltage_1 = Dvmpp*10;
        mppt_voltage_2 = Dvmpp*10;
        mppt_voltage_3 = Dvmpp*10;
        mppt_voltage_4 = Dvmpp*10;*/
        //std::cout <<"Construct Panel"<<std::endl; 
        /*in_temperature = addInBigPort<std::shared_ptr<double>>("in_temperature");
        in_irridiance = addInBigPort<std::shared_ptr<double>>("in_irridiance");
        out_mppt_voltage_1 = addOutBigPort<std::shared_ptr<double>>("out_mppt_voltage_1");
        out_mppt_voltage_2 = addOuBigtPort<std::shared_ptr<double>>("out_mppt_voltage_2");
        out_mppt_voltage_3 = addOutBigPort<std::shared_ptr<double>>("out_mppt_voltage_3");
        out_mppt_voltage_4 = addOutBigPort<std::shared_ptr<double>>("out_mppt_voltage_4");  */ 


        /*Port<std::shared_ptr<double>> in_temperature;
         Port<std::shared_ptr<double>> in_irridiance;
         Port<std::shared_ptr<double>> out_mppt_voltage_1;
         Port<std::shared_ptr<double>> out_mppt_voltage_2;
         Port<std::shared_ptr<double>> out_mppt_voltage_3;
         Port<std::shared_ptr<double>> out_mppt_voltage_4;*/
         //std::shared_ptr<solar_panel_atomic_model> 
         

         /*void set_atomic_model(std::shared_ptr<solar_panel_atomic_model> model){
            atom_model = model;
         }*/

         /*for (const auto& [neighborId, neighborData]: neighborhood) { 
            auto nState = neighborData.state; 
            nState->voltage = atomic_model->ap_voltage;
            nState->current = atomic_model->ap_current;
        }*/

        /*auto it = neighborhood.find({2, 1});
        if (it != neighborhood.end()) {
            state.sum_voltage += it->first.state.sum_voltage;
        }
        //state.sum_voltage += neighborhood[2][1].state.sum_voltage;
        //for (const auto& [neighborId, neighborData]: neighborhood) {
        auto it = neighborhood.find({2, 0});
        if (it != neighborhood.end()) {
            switch(it->first){
                case "(0,8)":
                    atomic_model->amppt_voltage_1 = state.sum_voltage;
                    break;
                case "(1,8)":
                    auto it = neighborhood.find({1, 1});
                    if (it != neighborhood.end()) {
                        if((it->second.state.sum_voltage) > (state.sum_voltage)){
                            atomic_model->amppt_voltage_2 = state.sum_voltage;
                        }
                    }
                    break;  
                case "(2,8)":
                    auto it = neighborhood.find({0, 1});
                    if (it != neighborhood.end()) {
                        if((it->second.state.sum_voltage) > (state.sum_voltage)){
                            atomic_model->amppt_voltage_2 = state.sum_voltage;
                        }
                    }
                    break;
                case "(3,8)":
                    auto it = neighborhood.find({1, 1});
                    if (it != neighborhood.end()) {
                        if((it->second.state.sum_voltage) > (state.sum_voltage)){
                            atomic_model->amppt_voltage_3 = state.sum_voltage;
                        }
                    }
                    break;
                case "(4,8)":
                    auto it = neighborhood.find({0, 1});
                    if (it != neighborhood.end()) {
                        if((it->second.state.sum_voltage) > (state.sum_voltage)){
                            atomic_model->amppt_voltage_3 = state.sum_voltage;
                        }
                    }
                    break;
                case "(5,8)":
                    atomic_model->amppt_voltage_4 = state.sum_voltage;
                    break;
    
            }
        } */
        //}




        std::shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double>> cd_model


        [ 50%] Building CXX object main/CMakeFiles/CellDEVS_Solar_Panel.dir/main.cpp.o
In file included from /usr/include/c++/13/bits/stl_tempbuf.h:61,
                 from /usr/include/c++/13/memory:66,
                 from /.../cadmium_v2/include/cadmium/simulation/root_coordinator.hpp:25,
                 from /.../CellDEVS_Solar_Panel/main/main.cpp:4:
/usr/include/c++/13/bits/stl_construct.h: In instantiation of ‘constexpr void std::_Construct(_Tp*, _Args&& ...) [with _Tp = solar_panel_atomic_model; _Args = {const char (&)[20], shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}]’:
/usr/include/c++/13/bits/alloc_traits.h:661:19:   required from ‘static constexpr void std::allocator_traits<std::allocator<void> >::construct(allocator_type&, _Up*, _Args&& ...) [with _Up = solar_panel_atomic_model; _Args = {const char (&)[20], std::shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}; allocator_type = std::allocator<void>]’
/usr/include/c++/13/bits/shared_ptr_base.h:604:39:   required from ‘std::_Sp_counted_ptr_inplace<_Tp, _Alloc, _Lp>::_Sp_counted_ptr_inplace(_Alloc, _Args&& ...) [with _Args = {const char (&)[20], std::shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}; _Tp = solar_panel_atomic_model; _Alloc = std::allocator<void>; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/13/bits/shared_ptr_base.h:971:16:   required from ‘std::__shared_count<_Lp>::__shared_count(_Tp*&, std::_Sp_alloc_shared_tag<_Alloc>, _Args&& ...) [with _Tp = solar_panel_atomic_model; _Alloc = std::allocator<void>; _Args = {const char (&)[20], std::shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/13/bits/shared_ptr_base.h:1712:14:   required from ‘std::__shared_ptr<_Tp, _Lp>::__shared_ptr(std::_Sp_alloc_shared_tag<_Tp>, _Args&& ...) [with _Alloc = std::allocator<void>; _Args = {const char (&)[20], std::shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}; _Tp = solar_panel_atomic_model; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/13/bits/shared_ptr.h:464:59:   required from ‘std::shared_ptr<_Tp>::shared_ptr(std::_Sp_alloc_shared_tag<_Tp>, _Args&& ...) [with _Alloc = std::allocator<void>; _Args = {const char (&)[20], std::shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}; _Tp = solar_panel_atomic_model]’
/usr/include/c++/13/bits/shared_ptr.h:1009:14:   required from ‘std::shared_ptr<std::_NonArray<_Tp> > std::make_shared(_Args&& ...) [with _Tp = solar_panel_atomic_model; _Args = {const char (&)[20], shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}; _NonArray<_Tp> = solar_panel_atomic_model]’
/.../cadmium_v2/include/cadmium/simulation/core/../../modeling/devs/coupled.hpp:153:49:   required from ‘std::shared_ptr<_Tp> cadmium::Coupled::addComponent(Args&& ...) [with T = solar_panel_atomic_model; Args = {const char (&)[20], std::shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}]’
/.../CellDEVS_Solar_Panel/main/include/top.hpp:63:81:   required from here
/usr/include/c++/13/bits/stl_construct.h:115:28: error: no matching function for call to ‘construct_at(solar_panel_atomic_model*&, const char [20], std::shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&)’
  115 |           std::construct_at(__p, std::forward<_Args>(__args)...);
      |           ~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/usr/include/c++/13/bits/stl_construct.h:94:5: note: candidate: ‘template<class _Tp, class ... _Args> constexpr decltype (::new(void*(0)) _Tp) std::construct_at(_Tp*, _Args&& ...)’
   94 |     construct_at(_Tp* __location, _Args&&... __args)
      |     ^~~~~~~~~~~~
/usr/include/c++/13/bits/stl_construct.h:94:5: note:   template argument deduction/substitution failed:
/usr/include/c++/13/bits/stl_construct.h: In substitution of ‘template<class _Tp, class ... _Args> constexpr decltype (::new(void*(0)) _Tp) std::construct_at(_Tp*, _Args&& ...) [with _Tp = solar_panel_atomic_model; _Args = {const char (&)[20], std::shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}]’:
/usr/include/c++/13/bits/stl_construct.h:115:21:   required from ‘constexpr void std::_Construct(_Tp*, _Args&& ...) [with _Tp = solar_panel_atomic_model; _Args = {const char (&)[20], shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}]’
/usr/include/c++/13/bits/alloc_traits.h:661:19:   required from ‘static constexpr void std::allocator_traits<std::allocator<void> >::construct(allocator_type&, _Up*, _Args&& ...) [with _Up = solar_panel_atomic_model; _Args = {const char (&)[20], std::shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}; allocator_type = std::allocator<void>]’
/usr/include/c++/13/bits/shared_ptr_base.h:604:39:   required from ‘std::_Sp_counted_ptr_inplace<_Tp, _Alloc, _Lp>::_Sp_counted_ptr_inplace(_Alloc, _Args&& ...) [with _Args = {const char (&)[20], std::shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}; _Tp = solar_panel_atomic_model; _Alloc = std::allocator<void>; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/13/bits/shared_ptr_base.h:971:16:   required from ‘std::__shared_count<_Lp>::__shared_count(_Tp*&, std::_Sp_alloc_shared_tag<_Alloc>, _Args&& ...) [with _Tp = solar_panel_atomic_model; _Alloc = std::allocator<void>; _Args = {const char (&)[20], std::shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/13/bits/shared_ptr_base.h:1712:14:   required from ‘std::__shared_ptr<_Tp, _Lp>::__shared_ptr(std::_Sp_alloc_shared_tag<_Tp>, _Args&& ...) [with _Alloc = std::allocator<void>; _Args = {const char (&)[20], std::shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}; _Tp = solar_panel_atomic_model; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/13/bits/shared_ptr.h:464:59:   required from ‘std::shared_ptr<_Tp>::shared_ptr(std::_Sp_alloc_shared_tag<_Tp>, _Args&& ...) [with _Alloc = std::allocator<void>; _Args = {const char (&)[20], std::shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}; _Tp = solar_panel_atomic_model]’
/usr/include/c++/13/bits/shared_ptr.h:1009:14:   required from ‘std::shared_ptr<std::_NonArray<_Tp> > std::make_shared(_Args&& ...) [with _Tp = solar_panel_atomic_model; _Args = {const char (&)[20], shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}; _NonArray<_Tp> = solar_panel_atomic_model]’
/.../cadmium_v2/include/cadmium/simulation/core/../../modeling/devs/coupled.hpp:153:49:   required from ‘std::shared_ptr<_Tp> cadmium::Coupled::addComponent(Args&& ...) [with T = solar_panel_atomic_model; Args = {const char (&)[20], std::shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}]’
/.../CellDEVS_Solar_Panel/main/include/top.hpp:63:81:   required from here
/usr/include/c++/13/bits/stl_construct.h:96:17: error: no matching function for call to ‘solar_panel_atomic_model(const char [20], std::shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&)’
   96 |     -> decltype(::new((void*)0) _Tp(std::declval<_Args>()...))
      |                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from /.../CellDEVS_Solar_Panel/main/include/solar_panel_model.hpp:13,
                 from /.../CellDEVS_Solar_Panel/main/main.cpp:28:
/.../CellDEVS_Solar_Panel/main/include/solar_panel_atomic_model.hpp:60:5: note: candidate: ‘solar_panel_atomic_model(std::string)’
   60 |     solar_panel_atomic_model(const std::string id) : Atomic<solar_panel_atomic_modelState>(id, solar_panel_atomic_modelState()){
      |     ^~~~~~~~~~~~~~~~~~~~~~~~
/.../CellDEVS_Solar_Panel/main/include/solar_panel_atomic_model.hpp:60:5: note:   candidate expects 1 argument, 2 provided
/.../CellDEVS_Solar_Panel/main/include/solar_panel_atomic_model.hpp:37:7: note: candidate: ‘solar_panel_atomic_model(const solar_panel_atomic_model&)’
   37 | class solar_panel_atomic_model : public Atomic<solar_panel_atomic_modelState> {
      |       ^~~~~~~~~~~~~~~~~~~~~~~~
/.../CellDEVS_Solar_Panel/main/include/solar_panel_atomic_model.hpp:37:7: note:   candidate expects 1 argument, 2 provided
/.../CellDEVS_Solar_Panel/main/include/solar_panel_atomic_model.hpp:37:7: note: candidate: ‘solar_panel_atomic_model(solar_panel_atomic_model&&)’
/.../CellDEVS_Solar_Panel/main/include/solar_panel_atomic_model.hpp:37:7: note:   candidate expects 1 argument, 2 provided
/usr/include/c++/13/bits/stl_construct.h: In instantiation of ‘constexpr void std::_Construct(_Tp*, _Args&& ...) [with _Tp = solar_panel_atomic_model; _Args = {const char (&)[20], shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}]’:
/usr/include/c++/13/bits/alloc_traits.h:661:19:   required from ‘static constexpr void std::allocator_traits<std::allocator<void> >::construct(allocator_type&, _Up*, _Args&& ...) [with _Up = solar_panel_atomic_model; _Args = {const char (&)[20], std::shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}; allocator_type = std::allocator<void>]’
/usr/include/c++/13/bits/shared_ptr_base.h:604:39:   required from ‘std::_Sp_counted_ptr_inplace<_Tp, _Alloc, _Lp>::_Sp_counted_ptr_inplace(_Alloc, _Args&& ...) [with _Args = {const char (&)[20], std::shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}; _Tp = solar_panel_atomic_model; _Alloc = std::allocator<void>; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/13/bits/shared_ptr_base.h:971:16:   required from ‘std::__shared_count<_Lp>::__shared_count(_Tp*&, std::_Sp_alloc_shared_tag<_Alloc>, _Args&& ...) [with _Tp = solar_panel_atomic_model; _Alloc = std::allocator<void>; _Args = {const char (&)[20], std::shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/13/bits/shared_ptr_base.h:1712:14:   required from ‘std::__shared_ptr<_Tp, _Lp>::__shared_ptr(std::_Sp_alloc_shared_tag<_Tp>, _Args&& ...) [with _Alloc = std::allocator<void>; _Args = {const char (&)[20], std::shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}; _Tp = solar_panel_atomic_model; __gnu_cxx::_Lock_policy _Lp = __gnu_cxx::_S_atomic]’
/usr/include/c++/13/bits/shared_ptr.h:464:59:   required from ‘std::shared_ptr<_Tp>::shared_ptr(std::_Sp_alloc_shared_tag<_Tp>, _Args&& ...) [with _Alloc = std::allocator<void>; _Args = {const char (&)[20], std::shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}; _Tp = solar_panel_atomic_model]’
/usr/include/c++/13/bits/shared_ptr.h:1009:14:   required from ‘std::shared_ptr<std::_NonArray<_Tp> > std::make_shared(_Args&& ...) [with _Tp = solar_panel_atomic_model; _Args = {const char (&)[20], shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}; _NonArray<_Tp> = solar_panel_atomic_model]’
/.../cadmium_v2/include/cadmium/simulation/core/../../modeling/devs/coupled.hpp:153:49:   required from ‘std::shared_ptr<_Tp> cadmium::Coupled::addComponent(Args&& ...) [with T = solar_panel_atomic_model; Args = {const char (&)[20], std::shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&}]’
/.../CellDEVS_Solar_Panel/main/include/top.hpp:63:81:   required from here
/usr/include/c++/13/bits/stl_construct.h:119:7: error: no matching function for call to ‘solar_panel_atomic_model(const char [20], std::shared_ptr<cadmium::celldevs::GridCellDEVSCoupled<solarCellState, double> >&)’
  119 |       ::new((void*)__p) _Tp(std::forward<_Args>(__args)...);
      |       ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/.../CellDEVS_Solar_Panel/main/include/solar_panel_atomic_model.hpp:60:5: note: candidate: ‘solar_panel_atomic_model(std::string)’
   60 |     solar_panel_atomic_model(const std::string id) : Atomic<solar_panel_atomic_modelState>(id, solar_panel_atomic_modelState()){
      |     ^~~~~~~~~~~~~~~~~~~~~~~~
/.../CellDEVS_Solar_Panel/main/include/solar_panel_atomic_model.hpp:60:5: note:   candidate expects 1 argument, 2 provided
/.../CellDEVS_Solar_Panel/main/include/solar_panel_atomic_model.hpp:37:7: note: candidate: ‘solar_panel_atomic_model(const solar_panel_atomic_model&)’
   37 | class solar_panel_atomic_model : public Atomic<solar_panel_atomic_modelState> {
      |       ^~~~~~~~~~~~~~~~~~~~~~~~
/.../CellDEVS_Solar_Panel/main/include/solar_panel_atomic_model.hpp:37:7: note:   candidate expects 1 argument, 2 provided
/.../CellDEVS_Solar_Panel/main/include/solar_panel_atomic_model.hpp:37:7: note: candidate: ‘solar_panel_atomic_model(solar_panel_atomic_model&&)’
/.../CellDEVS_Solar_Panel/main/include/solar_panel_atomic_model.hpp:37:7: note:   candidate expects 1 argument, 2 provided
make[2]: *** [main/CMakeFiles/CellDEVS_Solar_Panel.dir/build.make:76: main/CMakeFiles/CellDEVS_Solar_Panel.dir/main.cpp.o] Error 1
make[1]: *** [CMakeFiles/Makefile2:98: main/CMakeFiles/CellDEVS_Solar_Panel.dir/all] Error 2
make: *** [Makefile:91: all] Error 2
Compilation done. Executable in the bin folder


-- Build files have been written to: /.../CellDEVS_Solar_Panel/build
[ 50%] Building CXX object main/CMakeFiles/CellDEVS_Solar_Panel.dir/main.cpp.o
[100%] Linking CXX executable /.../CellDEVS_Solar_Panel/bin/CellDEVS_Solar_Panel
/usr/bin/ld: CMakeFiles/CellDEVS_Solar_Panel.dir/main.cpp.o: warning: relocation against `_ZN24solar_panel_atomic_model10ap_currentE' in read-only section `.text._ZNK17solar_panel_model16localComputationE14solarCellStateRKSt13unordered_mapISt6vectorIiSaIiEEN7cadmium8celldevs12NeighborDataIS0_dEESt4hashIS4_ESt8equal_toIS4_ESaISt4pairIKS4_S8_EEE[_ZNK17solar_panel_model16localComputationE14solarCellStateRKSt13unordered_mapISt6vectorIiSaIiEEN7cadmium8celldevs12NeighborDataIS0_dEESt4hashIS4_ESt8equal_toIS4_ESaISt4pairIKS4_S8_EEE]'
/usr/bin/ld: CMakeFiles/CellDEVS_Solar_Panel.dir/main.cpp.o: in function `solar_panel_atomic_model(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)':
main.cpp:(.text._ZN24solar_panel_atomic_modelC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE[_ZN24solar_panel_atomic_modelC5ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE]+0x14e): undefined reference to `ap_irridiance'
/usr/bin/ld: main.cpp:(.text._ZN24solar_panel_atomic_modelC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE[_ZN24solar_panel_atomic_modelC5ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE]+0x15e): undefined reference to `ap_temperature'
/usr/bin/ld: main.cpp:(.text._ZN24solar_panel_atomic_modelC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE[_ZN24solar_panel_atomic_modelC5ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE]+0x16e): undefined reference to `ap_voltage'
/usr/bin/ld: main.cpp:(.text._ZN24solar_panel_atomic_modelC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE[_ZN24solar_panel_atomic_modelC5ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE]+0x17e): undefined reference to `ap_current'
/usr/bin/ld: main.cpp:(.text._ZN24solar_panel_atomic_modelC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE[_ZN24solar_panel_atomic_modelC5ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE]+0x18e): undefined reference to `amppt_voltage_1'
/usr/bin/ld: main.cpp:(.text._ZN24solar_panel_atomic_modelC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE[_ZN24solar_panel_atomic_modelC5ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE]+0x19e): undefined reference to `amppt_voltage_2'
/usr/bin/ld: main.cpp:(.text._ZN24solar_panel_atomic_modelC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE[_ZN24solar_panel_atomic_modelC5ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE]+0x1ae): undefined reference to `amppt_voltage_3'
/usr/bin/ld: main.cpp:(.text._ZN24solar_panel_atomic_modelC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE[_ZN24solar_panel_atomic_modelC5ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE]+0x1be): undefined reference to `amppt_voltage_4'
/usr/bin/ld: CMakeFiles/CellDEVS_Solar_Panel.dir/main.cpp.o: in function `output(solar_panel_atomic_modelState const&) const':
main.cpp:(.text._ZNK24solar_panel_atomic_model6outputERK29solar_panel_atomic_modelState[_ZNK24solar_panel_atomic_model6outputERK29solar_panel_atomic_modelState]+0x2c): undefined reference to `amppt_voltage_1'
/usr/bin/ld: main.cpp:(.text._ZNK24solar_panel_atomic_model6outputERK29solar_panel_atomic_modelState[_ZNK24solar_panel_atomic_model6outputERK29solar_panel_atomic_modelState]+0x55): undefined reference to `amppt_voltage_2'
/usr/bin/ld: main.cpp:(.text._ZNK24solar_panel_atomic_model6outputERK29solar_panel_atomic_modelState[_ZNK24solar_panel_atomic_model6outputERK29solar_panel_atomic_modelState]+0x7e): undefined reference to `amppt_voltage_3'
/usr/bin/ld: main.cpp:(.text._ZNK24solar_panel_atomic_model6outputERK29solar_panel_atomic_modelState[_ZNK24solar_panel_atomic_model6outputERK29solar_panel_atomic_modelState]+0xa7): undefined reference to `amppt_voltage_4'
/usr/bin/ld: CMakeFiles/CellDEVS_Solar_Panel.dir/main.cpp.o: in function `solar_panel_model::localComputation(solarCellState, std::unordered_map<std::vector<int, std::allocator<int> >, cadmium::celldevs::NeighborData<solarCellState, double>, std::hash<std::vector<int, std::allocator<int> > >, std::equal_to<std::vector<int, std::allocator<int> > >, std::allocator<std::pair<std::vector<int, std::allocator<int> > const, cadmium::celldevs::NeighborData<solarCellState, double> > > > const&) const':
main.cpp:(.text._ZNK17solar_panel_model16localComputationE14solarCellStateRKSt13unordered_mapISt6vectorIiSaIiEEN7cadmium8celldevs12NeighborDataIS0_dEESt4hashIS4_ESt8equal_toIS4_ESaISt4pairIKS4_S8_EEE[_ZNK17solar_panel_model16localComputationE14solarCellStateRKSt13unordered_mapISt6vectorIiSaIiEEN7cadmium8celldevs12NeighborDataIS0_dEESt4hashIS4_ESt8equal_toIS4_ESaISt4pairIKS4_S8_EEE]+0x1d): undefined reference to `ap_voltage'
/usr/bin/ld: main.cpp:(.text._ZNK17solar_panel_model16localComputationE14solarCellStateRKSt13unordered_mapISt6vectorIiSaIiEEN7cadmium8celldevs12NeighborDataIS0_dEESt4hashIS4_ESt8equal_toIS4_ESaISt4pairIKS4_S8_EEE[_ZNK17solar_panel_model16localComputationE14solarCellStateRKSt13unordered_mapISt6vectorIiSaIiEEN7cadmium8celldevs12NeighborDataIS0_dEESt4hashIS4_ESt8equal_toIS4_ESaISt4pairIKS4_S8_EEE]+0x2a): undefined reference to `ap_current'
/usr/bin/ld: warning: creating DT_TEXTREL in a PIE
collect2: error: ld returned 1 exit status
make[2]: *** [main/CMakeFiles/CellDEVS_Solar_Panel.dir/build.make:97: /.../CellDEVS_Solar_Panel/bin/CellDEVS_Solar_Panel] Error 1
make[1]: *** [CMakeFiles/Makefile2:98: main/CMakeFiles/CellDEVS_Solar_Panel.dir/all] Error 2
make: *** [Makefile:91: all] Error 2
Compilation done. Executable in the bin folder
















/usr/bin/ld: CMakeFiles/CellDEVS_Solar_Panel.dir/main.cpp.o: warning: relocation against `_ZN24solar_panel_atomic_model10ap_currentE' in read-only section `.text._ZNK17solar_panel_model16localComputationE14solarCellStateRKSt13unordered_mapISt6vectorIiSaIiEEN7cadmium8celldevs12NeighborDataIS0_dEESt4hashIS4_ESt8equal_toIS4_ESaISt4pairIKS4_S8_EEE[_ZNK17solar_panel_model16localComputationE14solarCellStateRKSt13unordered_mapISt6vectorIiSaIiEEN7cadmium8celldevs12NeighborDataIS0_dEESt4hashIS4_ESt8equal_toIS4_ESaISt4pairIKS4_S8_EEE]'
/usr/bin/ld: CMakeFiles/CellDEVS_Solar_Panel.dir/main.cpp.o: in function `solar_panel_atomic_model(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)':
main.cpp:(.text._ZN24solar_panel_atomic_modelC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE[_ZN24solar_panel_atomic_modelC5ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE]+0x14e): undefined reference to `ap_irridiance'
/usr/bin/ld: main.cpp:(.text._ZN24solar_panel_atomic_modelC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE[_ZN24solar_panel_atomic_modelC5ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE]+0x15e): undefined reference to `ap_temperature'
/usr/bin/ld: main.cpp:(.text._ZN24solar_panel_atomic_modelC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE[_ZN24solar_panel_atomic_modelC5ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE]+0x16e): undefined reference to `ap_voltage'
/usr/bin/ld: main.cpp:(.text._ZN24solar_panel_atomic_modelC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE[_ZN24solar_panel_atomic_modelC5ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE]+0x17e): undefined reference to `ap_current'
/usr/bin/ld: main.cpp:(.text._ZN24solar_panel_atomic_modelC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE[_ZN24solar_panel_atomic_modelC5ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE]+0x18e): undefined reference to `amppt_voltage_1'
/usr/bin/ld: main.cpp:(.text._ZN24solar_panel_atomic_modelC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE[_ZN24solar_panel_atomic_modelC5ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE]+0x19e): undefined reference to `amppt_voltage_2'
/usr/bin/ld: main.cpp:(.text._ZN24solar_panel_atomic_modelC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE[_ZN24solar_panel_atomic_modelC5ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE]+0x1ae): undefined reference to `amppt_voltage_3'
/usr/bin/ld: main.cpp:(.text._ZN24solar_panel_atomic_modelC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE[_ZN24solar_panel_atomic_modelC5ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE]+0x1be): undefined reference to `amppt_voltage_4'
/usr/bin/ld: CMakeFiles/CellDEVS_Solar_Panel.dir/main.cpp.o: in function `solar_panel_model::localComputation(solarCellState, std::unordered_map<std::vector<int, std::allocator<int> >, cadmium::celldevs::NeighborData<solarCellState, double>, std::hash<std::vector<int, std::allocator<int> > >, std::equal_to<std::vector<int, std::allocator<int> > >, std::allocator<std::pair<std::vector<int, std::allocator<int> > const, cadmium::celldevs::NeighborData<solarCellState, double> > > > const&) const':
main.cpp:(.text._ZNK17solar_panel_model16localComputationE14solarCellStateRKSt13unordered_mapISt6vectorIiSaIiEEN7cadmium8celldevs12NeighborDataIS0_dEESt4hashIS4_ESt8equal_toIS4_ESaISt4pairIKS4_S8_EEE[_ZNK17solar_panel_model16localComputationE14solarCellStateRKSt13unordered_mapISt6vectorIiSaIiEEN7cadmium8celldevs12NeighborDataIS0_dEESt4hashIS4_ESt8equal_toIS4_ESaISt4pairIKS4_S8_EEE]+0x1d): undefined reference to `ap_voltage'
/usr/bin/ld: main.cpp:(.text._ZNK17solar_panel_model16localComputationE14solarCellStateRKSt13unordered_mapISt6vectorIiSaIiEEN7cadmium8celldevs12NeighborDataIS0_dEESt4hashIS4_ESt8equal_toIS4_ESaISt4pairIKS4_S8_EEE[_ZNK17solar_panel_model16localComputationE14solarCellStateRKSt13unordered_mapISt6vectorIiSaIiEEN7cadmium8celldevs12NeighborDataIS0_dEESt4hashIS4_ESt8equal_toIS4_ESaISt4pairIKS4_S8_EEE]+0x2a): undefined reference to `ap_current'
/usr/bin/ld: warning: creating DT_TEXTREL in a PIE
collect2: error: ld returned 1 exit status
make[2]: *** [main/CMakeFiles/CellDEVS_Solar_Panel.dir/build.make:97: /.../CellDEVS_Solar_Panel/bin/CellDEVS_Solar_Panel] Error 1
make[1]: *** [CMakeFiles/Makefile2:98: main/CMakeFiles/CellDEVS_Solar_Panel.dir/all] Error 2
make: *** [Makefile:91: all] Error 2
Compilation done. Executable in the bin folder


        ap_irridiance=800;
        ap_temperature=293.15;
        ap_voltage = 37.3/60;
        ap_current = 7.67;
        amppt_voltage_1=(37.3/60)*10;
        amppt_voltage_2=(37.3/60)*10;
        amppt_voltage_3=(37.3/60)*10;
        amppt_voltage_4=(37.3/60)*10;
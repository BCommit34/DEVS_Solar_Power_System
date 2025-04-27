[top]
components: panel

[panel]
type : cell
dim:(10,6)
delay: transport
defaultDelayTime : 24
border: nowrapped
neighbors: panel(-1,0) panel(1,0)
initialvalue : 0
localtransition : panel

[initialize]
rule :{
    ~solar_mode := true;
    ~voltage := 0.0;
    ~total_power := 0.0;
    ~sigma := 0.0
}1 { t }

[cell_map]
(0,0)..(0,9) : panel
(1,0)..(1,9) : panel
(2,0)..(2,9) : panel
(3,0)..(3,9) : panel
(4,0)..(4,9) : panel
(5,0)..(5,9) : panel
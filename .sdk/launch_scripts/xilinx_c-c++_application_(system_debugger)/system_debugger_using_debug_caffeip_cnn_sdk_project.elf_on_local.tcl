connect -url tcp:127.0.0.1:3121
configparams mdm-detect-bscan-mask 2
targets -set -nocase -filter {name =~ "microblaze*#0" && bscan=="USER2"  && jtag_cable_name =~ "Digilent JTAG-SMT2NC 210308A3B7FE"} -index 0
rst -processor
targets -set -nocase -filter {name =~ "microblaze*#0" && bscan=="USER2"  && jtag_cable_name =~ "Digilent JTAG-SMT2NC 210308A3B7FE"} -index 0
dow C:/Users/niles/Documents/VivadoProjects/CaffeIP_CNN/CaffeIP_CNN.sdk/CaffeIP_CNN_SDK_Project/Debug/CaffeIP_CNN_SDK_Project.elf
targets -set -nocase -filter {name =~ "microblaze*#0" && bscan=="USER2"  && jtag_cable_name =~ "Digilent JTAG-SMT2NC 210308A3B7FE"} -index 0
con

# invoke SourceDir generated makefile for app_ble.pem3
app_ble.pem3: .libraries,app_ble.pem3
.libraries,app_ble.pem3: package/cfg/app_ble_pem3.xdl
	$(MAKE) -f D:\WorkSpace\Project\CCS\workspace_v8\CC2640R2F_Project\CC2640R2F_Ble5_Central_Peripheral\ble5_simple_central_cc2640r2lp_app\TOOLS/src/makefile.libs

clean::
	$(MAKE) -f D:\WorkSpace\Project\CCS\workspace_v8\CC2640R2F_Project\CC2640R2F_Ble5_Central_Peripheral\ble5_simple_central_cc2640r2lp_app\TOOLS/src/makefile.libs clean


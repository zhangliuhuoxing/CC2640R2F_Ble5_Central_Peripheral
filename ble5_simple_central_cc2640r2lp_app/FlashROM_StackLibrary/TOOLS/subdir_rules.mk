################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-1432121841:
	@$(MAKE) --no-print-directory -Onone -f TOOLS/subdir_rules.mk build-1432121841-inproc

build-1432121841-inproc: ../TOOLS/app_ble.cfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: XDCtools'
	"C:/ti/xdctools_3_50_03_33_core/xs" --xdcpath="D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source;D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/kernel/tirtos/packages;D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack;" xdc.tools.configuro -o configPkg -t ti.targets.arm.elf.M3 -p ti.platforms.simplelink:CC2640R2F -r release -c "C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS" --compileOptions "-mv7M3 --code_state=16 -me -O4 --opt_for_speed=0 --include_path=\"D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/ble5_simple_central_cc2640r2lp_app\" --include_path=\"D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/ble5_simple_central_cc2640r2lp_app/Application\" --include_path=\"D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/ble5_simple_central_cc2640r2lp_app/Startup\" --include_path=\"D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/ble5_simple_central_cc2640r2lp_app/PROFILES\" --include_path=\"D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/ble5_simple_central_cc2640r2lp_app/Include\" --include_path=\"D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/controller/cc26xx_r2/inc\" --include_path=\"D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/inc\" --include_path=\"D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/rom\" --include_path=\"D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/common/cc26xx\" --include_path=\"D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/icall/inc\" --include_path=\"D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/profiles/simple_profile\" --include_path=\"D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/target\" --include_path=\"D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/hal/src/target/_common\" --include_path=\"D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/hal/src/target/_common/cc26xx\" --include_path=\"D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/hal/src/inc\" --include_path=\"D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/heapmgr\" --include_path=\"D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/icall/src/inc\" --include_path=\"D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/osal/src/inc\" --include_path=\"D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/services/src/saddr\" --include_path=\"D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack/services/src/sdata\" --include_path=\"D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/devices/cc26x0r2\" --include_path=\"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include\" --define=DeviceFamily_CC26X0R2 --define=BOARD_DISPLAY_USE_LCD=0 --define=BOARD_DISPLAY_USE_UART=1 --define=BOARD_DISPLAY_USE_UART_ANSI=1 --define=CC2640R2DK_4XS --define=CC26XX --define=CC26XX_R2 --define=ICALL_EVENTS --define=ICALL_JT --define=ICALL_LITE --define=ICALL_MAX_NUM_ENTITIES=6 --define=ICALL_MAX_NUM_TASKS=3 --define=ICALL_STACK0_ADDR --define=POWER_SAVING --define=RF_SINGLEMODE --define=STACK_LIBRARY --define=USE_ICALL --define=xdc_runtime_Assert_DISABLE_ALL --define=xdc_runtime_Log_DISABLE_ALL -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi " "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

configPkg/linker.cmd: build-1432121841 ../TOOLS/app_ble.cfg
configPkg/compiler.opt: build-1432121841
configPkg/: build-1432121841



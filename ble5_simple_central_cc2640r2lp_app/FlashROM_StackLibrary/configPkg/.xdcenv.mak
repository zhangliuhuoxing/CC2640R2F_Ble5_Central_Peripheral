#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source;D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/kernel/tirtos/packages;D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack
override XDCROOT = C:/ti/xdctools_3_50_03_33_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source;D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/kernel/tirtos/packages;D:/WorkSpace/Project/CCS/workspace_v8/CC2640R2F_Project/CC2640R2F_Ble5_Central_Peripheral/simplelink_cc2640r2_sdk_1_40_00_45/source/ti/ble5stack;C:/ti/xdctools_3_50_03_33_core/packages;..
HOSTOS = Windows
endif

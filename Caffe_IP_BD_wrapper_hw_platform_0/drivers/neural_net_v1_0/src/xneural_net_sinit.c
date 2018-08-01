// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.2
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xneural_net.h"

extern XNeural_net_Config XNeural_net_ConfigTable[];

XNeural_net_Config *XNeural_net_LookupConfig(u16 DeviceId) {
	XNeural_net_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XNEURAL_NET_NUM_INSTANCES; Index++) {
		if (XNeural_net_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XNeural_net_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XNeural_net_Initialize(XNeural_net *InstancePtr, u16 DeviceId) {
	XNeural_net_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XNeural_net_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XNeural_net_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

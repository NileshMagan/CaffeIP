// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.2
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

/***************************** Include Files *********************************/
#include "xneural_net.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XNeural_net_CfgInitialize(XNeural_net *InstancePtr, XNeural_net_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Hls_macc_periph_bus_BaseAddress = ConfigPtr->Hls_macc_periph_bus_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XNeural_net_Start(XNeural_net *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNeural_net_ReadReg(InstancePtr->Hls_macc_periph_bus_BaseAddress, XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_AP_CTRL) & 0x80;
    XNeural_net_WriteReg(InstancePtr->Hls_macc_periph_bus_BaseAddress, XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_AP_CTRL, Data | 0x01);
}

u32 XNeural_net_IsDone(XNeural_net *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNeural_net_ReadReg(InstancePtr->Hls_macc_periph_bus_BaseAddress, XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XNeural_net_IsIdle(XNeural_net *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNeural_net_ReadReg(InstancePtr->Hls_macc_periph_bus_BaseAddress, XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XNeural_net_IsReady(XNeural_net *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNeural_net_ReadReg(InstancePtr->Hls_macc_periph_bus_BaseAddress, XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XNeural_net_EnableAutoRestart(XNeural_net *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNeural_net_WriteReg(InstancePtr->Hls_macc_periph_bus_BaseAddress, XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_AP_CTRL, 0x80);
}

void XNeural_net_DisableAutoRestart(XNeural_net *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNeural_net_WriteReg(InstancePtr->Hls_macc_periph_bus_BaseAddress, XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_AP_CTRL, 0);
}

u32 XNeural_net_Get_result(XNeural_net *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNeural_net_ReadReg(InstancePtr->Hls_macc_periph_bus_BaseAddress, XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_RESULT_DATA);
    return Data;
}

u32 XNeural_net_Get_result_vld(XNeural_net *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNeural_net_ReadReg(InstancePtr->Hls_macc_periph_bus_BaseAddress, XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_RESULT_CTRL);
    return Data & 0x1;
}

u32 XNeural_net_Get_mean_image_BaseAddress(XNeural_net *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Hls_macc_periph_bus_BaseAddress + XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_MEAN_IMAGE_BASE);
}

u32 XNeural_net_Get_mean_image_HighAddress(XNeural_net *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Hls_macc_periph_bus_BaseAddress + XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_MEAN_IMAGE_HIGH);
}

u32 XNeural_net_Get_mean_image_TotalBytes(XNeural_net *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_MEAN_IMAGE_HIGH - XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_MEAN_IMAGE_BASE + 1);
}

u32 XNeural_net_Get_mean_image_BitWidth(XNeural_net *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XNEURAL_NET_HLS_MACC_PERIPH_BUS_WIDTH_MEAN_IMAGE;
}

u32 XNeural_net_Get_mean_image_Depth(XNeural_net *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XNEURAL_NET_HLS_MACC_PERIPH_BUS_DEPTH_MEAN_IMAGE;
}

u32 XNeural_net_Write_mean_image_Words(XNeural_net *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_MEAN_IMAGE_HIGH - XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_MEAN_IMAGE_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Hls_macc_periph_bus_BaseAddress + XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_MEAN_IMAGE_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XNeural_net_Read_mean_image_Words(XNeural_net *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_MEAN_IMAGE_HIGH - XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_MEAN_IMAGE_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Hls_macc_periph_bus_BaseAddress + XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_MEAN_IMAGE_BASE + (offset + i)*4);
    }
    return length;
}

u32 XNeural_net_Write_mean_image_Bytes(XNeural_net *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_MEAN_IMAGE_HIGH - XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_MEAN_IMAGE_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Hls_macc_periph_bus_BaseAddress + XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_MEAN_IMAGE_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XNeural_net_Read_mean_image_Bytes(XNeural_net *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_MEAN_IMAGE_HIGH - XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_MEAN_IMAGE_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Hls_macc_periph_bus_BaseAddress + XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_MEAN_IMAGE_BASE + offset + i);
    }
    return length;
}

u32 XNeural_net_Get_input_image_BaseAddress(XNeural_net *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Hls_macc_periph_bus_BaseAddress + XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_INPUT_IMAGE_BASE);
}

u32 XNeural_net_Get_input_image_HighAddress(XNeural_net *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Hls_macc_periph_bus_BaseAddress + XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_INPUT_IMAGE_HIGH);
}

u32 XNeural_net_Get_input_image_TotalBytes(XNeural_net *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_INPUT_IMAGE_HIGH - XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_INPUT_IMAGE_BASE + 1);
}

u32 XNeural_net_Get_input_image_BitWidth(XNeural_net *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XNEURAL_NET_HLS_MACC_PERIPH_BUS_WIDTH_INPUT_IMAGE;
}

u32 XNeural_net_Get_input_image_Depth(XNeural_net *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XNEURAL_NET_HLS_MACC_PERIPH_BUS_DEPTH_INPUT_IMAGE;
}

u32 XNeural_net_Write_input_image_Words(XNeural_net *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_INPUT_IMAGE_HIGH - XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_INPUT_IMAGE_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Hls_macc_periph_bus_BaseAddress + XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_INPUT_IMAGE_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XNeural_net_Read_input_image_Words(XNeural_net *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_INPUT_IMAGE_HIGH - XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_INPUT_IMAGE_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Hls_macc_periph_bus_BaseAddress + XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_INPUT_IMAGE_BASE + (offset + i)*4);
    }
    return length;
}

u32 XNeural_net_Write_input_image_Bytes(XNeural_net *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_INPUT_IMAGE_HIGH - XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_INPUT_IMAGE_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Hls_macc_periph_bus_BaseAddress + XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_INPUT_IMAGE_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XNeural_net_Read_input_image_Bytes(XNeural_net *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_INPUT_IMAGE_HIGH - XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_INPUT_IMAGE_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Hls_macc_periph_bus_BaseAddress + XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_INPUT_IMAGE_BASE + offset + i);
    }
    return length;
}

void XNeural_net_InterruptGlobalEnable(XNeural_net *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNeural_net_WriteReg(InstancePtr->Hls_macc_periph_bus_BaseAddress, XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_GIE, 1);
}

void XNeural_net_InterruptGlobalDisable(XNeural_net *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNeural_net_WriteReg(InstancePtr->Hls_macc_periph_bus_BaseAddress, XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_GIE, 0);
}

void XNeural_net_InterruptEnable(XNeural_net *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XNeural_net_ReadReg(InstancePtr->Hls_macc_periph_bus_BaseAddress, XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_IER);
    XNeural_net_WriteReg(InstancePtr->Hls_macc_periph_bus_BaseAddress, XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_IER, Register | Mask);
}

void XNeural_net_InterruptDisable(XNeural_net *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XNeural_net_ReadReg(InstancePtr->Hls_macc_periph_bus_BaseAddress, XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_IER);
    XNeural_net_WriteReg(InstancePtr->Hls_macc_periph_bus_BaseAddress, XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_IER, Register & (~Mask));
}

void XNeural_net_InterruptClear(XNeural_net *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNeural_net_WriteReg(InstancePtr->Hls_macc_periph_bus_BaseAddress, XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_ISR, Mask);
}

u32 XNeural_net_InterruptGetEnabled(XNeural_net *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XNeural_net_ReadReg(InstancePtr->Hls_macc_periph_bus_BaseAddress, XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_IER);
}

u32 XNeural_net_InterruptGetStatus(XNeural_net *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XNeural_net_ReadReg(InstancePtr->Hls_macc_periph_bus_BaseAddress, XNEURAL_NET_HLS_MACC_PERIPH_BUS_ADDR_ISR);
}


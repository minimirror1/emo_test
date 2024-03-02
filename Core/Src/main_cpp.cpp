/*
 * main_cpp.cpp
 *
 *  Created on: Feb 27, 2024
 *      Author: minim
 */



#include "main.h"
#include "main_cpp.h"

#include "emo_Status.h"

Emo_Status emo[8];

void emo_Init();

void main_cpp(void){

	emo_Init();

	while(1){


	}
}


void emo_Init(){
    EMO_GPIO_TypeDef PinSetting;

    // ALM (Alarm Inputs)
    const EMO_GPIO_TypeDef ALM_Settings[] = {
        {ALM1_GPIO_Port, ALM1_Pin, GPIO_PIN_RESET}, // ALM1
        {ALM2_GPIO_Port, ALM2_Pin, GPIO_PIN_RESET}, // ALM2
        {ALM3_GPIO_Port, ALM3_Pin, GPIO_PIN_RESET}, // ALM3
        {ALM4_GPIO_Port, ALM4_Pin, GPIO_PIN_RESET}, // ALM4
        {ALM5_GPIO_Port, ALM5_Pin, GPIO_PIN_RESET}, // ALM5
        {ALM6_GPIO_Port, ALM6_Pin, GPIO_PIN_RESET}  // ALM6
    };

    // SV (Servo Input/Interrupts)
    const EMO_GPIO_TypeDef SV_Settings[] = {
        {SV1_EXTI0_GPIO_Port, SV1_EXTI0_Pin, GPIO_PIN_RESET}, // SV1
        {SV2_EXTI3_GPIO_Port, SV2_EXTI3_Pin, GPIO_PIN_RESET}, // SV2
        {SV3_EXTI6_GPIO_Port, SV3_EXTI6_Pin, GPIO_PIN_RESET}, // SV3
        {SV4_EXTI5_GPIO_Port, SV4_EXTI5_Pin, GPIO_PIN_RESET}, // SV4
        {SV5_EXTI2_GPIO_Port, SV5_EXTI2_Pin, GPIO_PIN_RESET}, // SV5
        {SV6_EXTI9_GPIO_Port, SV6_EXTI9_Pin, GPIO_PIN_RESET}  // SV6
    };

    // BR (Brake Signals)
    const EMO_GPIO_TypeDef BR_Settings[] = {
        {BR1_SIG_GPIO_Port, BR1_SIG_Pin, GPIO_PIN_SET}, // BR1
        {BR2_SIG_GPIO_Port, BR2_SIG_Pin, GPIO_PIN_SET}, // BR2
        {BR3_SIG_GPIO_Port, BR3_SIG_Pin, GPIO_PIN_SET}, // BR3
        {BR4_SIG_GPIO_Port, BR4_SIG_Pin, GPIO_PIN_SET}, // BR4
        {BR5_SIG_GPIO_Port, BR5_SIG_Pin, GPIO_PIN_SET}, // BR5
        {BR6_SIG_GPIO_Port, BR6_SIG_Pin, GPIO_PIN_SET}  // BR6
    };

    // SV (Servo Signals)
    const EMO_GPIO_TypeDef SV_SIG_Settings[] = {
        {SV1_SIG_GPIO_Port, SV1_SIG_Pin, GPIO_PIN_SET}, // SV1
        {SV2_SIG_GPIO_Port, SV2_SIG_Pin, GPIO_PIN_SET}, // SV2
        {SV3_SIG_GPIO_Port, SV3_SIG_Pin, GPIO_PIN_SET}, // SV3
        {SV4_SIG_GPIO_Port, SV4_SIG_Pin, GPIO_PIN_SET}, // SV4
        {SV5_SIG_GPIO_Port, SV5_SIG_Pin, GPIO_PIN_SET}, // SV5
        {SV6_SIG_GPIO_Port, SV6_SIG_Pin, GPIO_PIN_SET}  // SV6
    };

    for(int i = 0; i < 6; i++) {
        emo[i+1].assign_in_AC_Err((EMO_GPIO_TypeDef*)&ALM_Settings[i]);
        emo[i+1].assign_in_BTN((EMO_GPIO_TypeDef*)&SV_Settings[i]);
        emo[i+1].assign_out_Brake((EMO_GPIO_TypeDef*)&BR_Settings[i]);
        emo[i+1].assign_out_ServoOn((EMO_GPIO_TypeDef*)&SV_SIG_Settings[i]);
    }

    LD_GPIO_TypeDef LedSetting;

     // 기존 ALM, SV, BR, SV_SIG 설정 코드...

     // LED 설정
     LD_GPIO_TypeDef ServoOn_LED_Settings[] = {
         // ServoOn LED for each Servo
         {SV1_LD_G_GPIO_Port, SV1_LD_G_Pin, GPIO_PIN_RESET}, // SV1 Green
         {SV1_LD_R_GPIO_Port, SV1_LD_R_Pin, GPIO_PIN_RESET},   // SV1 Red
         {SV2_LD_G_GPIO_Port, SV2_LD_G_Pin, GPIO_PIN_RESET}, // SV2 Green
         {SV2_LD_R_GPIO_Port, SV2_LD_R_Pin, GPIO_PIN_RESET},   // SV2 Red
         {SV3_LD_G_GPIO_Port, SV3_LD_G_Pin, GPIO_PIN_RESET}, // SV3 Green
         {SV3_LD_R_GPIO_Port, SV3_LD_R_Pin, GPIO_PIN_RESET},   // SV3 Red
         {SV4_LD_G_GPIO_Port, SV4_LD_G_Pin, GPIO_PIN_RESET}, // SV4 Green
         {SV4_LD_R_GPIO_Port, SV4_LD_R_Pin, GPIO_PIN_RESET},   // SV4 Red
         {SV5_LD_G_GPIO_Port, SV5_LD_G_Pin, GPIO_PIN_RESET}, // SV5 Green
         {SV5_LD_R_GPIO_Port, SV5_LD_R_Pin, GPIO_PIN_RESET},   // SV5 Red
         {SV6_LD_G_GPIO_Port, SV6_LD_G_Pin, GPIO_PIN_RESET}, // SV6 Green
         {SV6_LD_R_GPIO_Port, SV6_LD_R_Pin, GPIO_PIN_RESET},   // SV6 Red
     };

     LD_GPIO_TypeDef Status_LED_Settings[] = {
         // Status LED for each Status
         {STATE1_LD_G_GPIO_Port, STATE1_LD_G_Pin, GPIO_PIN_RESET}, // STATE1 Green
         {STATE1_LD_R_GPIO_Port, STATE1_LD_R_Pin, GPIO_PIN_RESET},   // STATE1 Red
         {STATE2_LD_G_GPIO_Port, STATE2_LD_G_Pin, GPIO_PIN_RESET}, // STATE2 Green
         {STATE2_LD_R_GPIO_Port, STATE2_LD_R_Pin, GPIO_PIN_RESET},   // STATE2 Red
         {STATE3_LD_G_GPIO_Port, STATE3_LD_G_Pin, GPIO_PIN_RESET}, // STATE3 Green
         {STATE3_LD_R_GPIO_Port, STATE3_LD_R_Pin, GPIO_PIN_RESET},   // STATE3 Red
         {STATE4_LD_G_GPIO_Port, STATE4_LD_G_Pin, GPIO_PIN_RESET}, // STATE4 Green
         {STATE4_LD_R_GPIO_Port, STATE4_LD_R_Pin, GPIO_PIN_RESET},   // STATE4 Red
         {STATE5_LD_G_GPIO_Port, STATE5_LD_G_Pin, GPIO_PIN_RESET}, // STATE5 Green
         {STATE5_LD_R_GPIO_Port, STATE5_LD_R_Pin, GPIO_PIN_RESET},   // STATE5 Red
         {STATE6_LD_G_GPIO_Port, STATE6_LD_G_Pin, GPIO_PIN_RESET}, // STATE6 Green
         {STATE6_LD_R_GPIO_Port, STATE6_LD_R_Pin, GPIO_PIN_RESET},   // STATE6 Red
     };

     LD_GPIO_TypeDef Brake_LED_Settings[] = {
         // Brake LED for each Brake
         {BR1_LD_GPIO_Port, BR1_LD_Pin, GPIO_PIN_RESET}, // BR1
         {BR2_LD_GPIO_Port, BR2_LD_Pin, GPIO_PIN_RESET}, // BR2
         {BR3_LD_GPIO_Port, BR3_LD_Pin, GPIO_PIN_RESET}, // BR3
         {BR4_LD_GPIO_Port, BR4_LD_Pin, GPIO_PIN_RESET}, // BR4
         {BR5_LD_GPIO_Port, BR5_LD_Pin, GPIO_PIN_RESET}, // BR5
         {BR6_LD_GPIO_Port, BR6_LD_Pin, GPIO_PIN_RESET}, // BR6
     };

     // ServoOn LED 할당
     for (int i = 0; i < sizeof(ServoOn_LED_Settings)/sizeof(ServoOn_LED_Settings[0]); i += 2) {
    	 emo[i+1].assign_out_led_ServoOn(&ServoOn_LED_Settings[i], &ServoOn_LED_Settings[i + 1]);
     }

     // Status LED 할당
     for (int i = 0; i < sizeof(Status_LED_Settings)/sizeof(Status_LED_Settings[0]); i += 2) {
    	 emo[i+1].assign_out_led_Status(&Status_LED_Settings[i], &Status_LED_Settings[i + 1]);
     }

     // Brake LED 할당
     for (int i = 0; i < sizeof(Brake_LED_Settings)/sizeof(Brake_LED_Settings[0]); i++) {
    	 emo[i+1].assign_out_led_Brake(&Brake_LED_Settings[i]);
     }
}

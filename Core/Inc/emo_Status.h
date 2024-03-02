/*
 * emo_Status.h
 *
 *  Created on: Feb 27, 2024
 *      Author: minim
 */

#ifndef INC_EMO_STATUS_H_
#define INC_EMO_STATUS_H_


#include "main.h"

typedef struct{
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
	GPIO_PinState TrueState; 	//감지, on
	uint8_t Status;				//입력일때: 1감지,  출력일때: 1출력
	GPIO_PinState read1;
	GPIO_PinState read2;
}EMO_GPIO_TypeDef;

typedef struct{
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
	GPIO_PinState OnState; 	//감지, on
}LD_GPIO_TypeDef;

class Emo_Status{
private:
	EMO_GPIO_TypeDef in_AC_Err;
	EMO_GPIO_TypeDef in_BTN;

	EMO_GPIO_TypeDef out_Brake;
	EMO_GPIO_TypeDef out_ServoOn;

	LD_GPIO_TypeDef LD_R_ServoOn;
	LD_GPIO_TypeDef LD_G_ServoOn;
	LD_GPIO_TypeDef LD_R_Status;
	LD_GPIO_TypeDef LD_G_Status;
	LD_GPIO_TypeDef LD_Brake;

public:
	Emo_Status(){
	}
	~Emo_Status(){
	}

	/**Init**/
	/*in put*/
	void assign_in_AC_Err(EMO_GPIO_TypeDef *GPIO_info){
		in_AC_Err.GPIOx = GPIO_info->GPIOx;
		in_AC_Err.GPIO_Pin = GPIO_info->GPIO_Pin;
		in_AC_Err.TrueState = GPIO_info->TrueState;
		in_AC_Err.Status = RESET;
		in_AC_Err.read1 = GPIO_PIN_RESET;
		in_AC_Err.read2 = GPIO_PIN_RESET;
	}
	void assign_in_BTN(EMO_GPIO_TypeDef *GPIO_info) {
	    in_BTN.GPIOx = GPIO_info->GPIOx;
	    in_BTN.GPIO_Pin = GPIO_info->GPIO_Pin;
	    in_BTN.TrueState = GPIO_info->TrueState;
	    in_BTN.Status = RESET;
	    in_BTN.read1 = GPIO_PIN_RESET;
	    in_BTN.read2 = GPIO_PIN_RESET;
	}
	/*out put*/
	void assign_out_Brake(EMO_GPIO_TypeDef *GPIO_info) {
	    out_Brake.GPIOx = GPIO_info->GPIOx;
	    out_Brake.GPIO_Pin = GPIO_info->GPIO_Pin;
	    out_Brake.TrueState = GPIO_info->TrueState;
	    out_Brake.Status = RESET;
	}
	void assign_out_ServoOn(EMO_GPIO_TypeDef *GPIO_info) {
	    out_ServoOn.GPIOx = GPIO_info->GPIOx;
	    out_ServoOn.GPIO_Pin = GPIO_info->GPIO_Pin;
	    out_ServoOn.TrueState = GPIO_info->TrueState;
	    out_ServoOn.Status = RESET;
	}

	/*led*/
	void assign_out_led_ServoOn(LD_GPIO_TypeDef *GPIO_info_R, LD_GPIO_TypeDef *GPIO_info_G){
		LD_R_ServoOn.GPIOx = GPIO_info_R->GPIOx;
		LD_R_ServoOn.GPIO_Pin = GPIO_info_R->GPIO_Pin;
		LD_R_ServoOn.OnState = GPIO_info_R->OnState;

		LD_G_ServoOn.GPIOx = GPIO_info_G->GPIOx;
		LD_G_ServoOn.GPIO_Pin = GPIO_info_G->GPIO_Pin;
		LD_G_ServoOn.OnState = GPIO_info_G->OnState;
	}
	void assign_out_led_Status(LD_GPIO_TypeDef *GPIO_info_R, LD_GPIO_TypeDef *GPIO_info_G){
		LD_R_Status.GPIOx = GPIO_info_R->GPIOx;
		LD_R_Status.GPIO_Pin = GPIO_info_R->GPIO_Pin;
		LD_R_Status.OnState = GPIO_info_R->OnState;

		LD_G_Status.GPIOx = GPIO_info_G->GPIOx;
		LD_G_Status.GPIO_Pin = GPIO_info_G->GPIO_Pin;
		LD_G_Status.OnState = GPIO_info_G->OnState;
	}
	void assign_out_led_Brake(LD_GPIO_TypeDef *GPIO_info){
		LD_Brake.GPIOx = GPIO_info->GPIOx;
		LD_Brake.GPIO_Pin = GPIO_info->GPIO_Pin;
		LD_Brake.OnState = GPIO_info->OnState;
	}


	/* Read */
	void update_in_AC_Err1(){
		 in_AC_Err.read1= HAL_GPIO_ReadPin(in_AC_Err.GPIOx, in_AC_Err.GPIO_Pin);
	}
	void update_in_AC_Err2(){
		in_AC_Err.read2= HAL_GPIO_ReadPin(in_AC_Err.GPIOx, in_AC_Err.GPIO_Pin);
	}
	void update_in_BTN_read1(){
	    in_BTN.read1 = HAL_GPIO_ReadPin(in_BTN.GPIOx, in_BTN.GPIO_Pin);
	}
	void update_in_BTN_read2(){
	    in_BTN.read2 = HAL_GPIO_ReadPin(in_BTN.GPIOx, in_BTN.GPIO_Pin);
	}

	void read1_process(){
		update_in_AC_Err1();
		update_in_BTN_read1();
	}
	void read2_process(){
		update_in_AC_Err2();
		update_in_BTN_read2();
	}


	/* LED Contorl */
	void LED_Ctr_ServoOn(uint8_t ctr){
		if(ctr == 1) // ServoON
		{
			 HAL_GPIO_WritePin(LD_G_ServoOn.GPIOx, LD_G_ServoOn.GPIO_Pin, LD_G_ServoOn.OnState);
			 HAL_GPIO_WritePin(LD_R_ServoOn.GPIOx, LD_R_ServoOn.GPIO_Pin, (LD_R_ServoOn.OnState == GPIO_PIN_SET) ? GPIO_PIN_RESET : GPIO_PIN_SET);
		}
		else{
			HAL_GPIO_WritePin(LD_G_ServoOn.GPIOx, LD_G_ServoOn.GPIO_Pin, (LD_G_ServoOn.OnState == GPIO_PIN_SET) ? GPIO_PIN_RESET : GPIO_PIN_SET);
			HAL_GPIO_WritePin(LD_R_ServoOn.GPIOx, LD_R_ServoOn.GPIO_Pin, LD_R_ServoOn.OnState);
		}
	}
	void LED_Ctr_Status(uint8_t ctr){
		if(ctr == 1) // Normal
		{
			 HAL_GPIO_WritePin(LD_G_Status.GPIOx, LD_G_Status.GPIO_Pin, LD_G_Status.OnState);
			 HAL_GPIO_WritePin(LD_R_Status.GPIOx, LD_R_Status.GPIO_Pin, (LD_R_Status.OnState == GPIO_PIN_SET) ? GPIO_PIN_RESET : GPIO_PIN_SET);
		}
		else{			// Error
			HAL_GPIO_WritePin(LD_G_Status.GPIOx, LD_G_Status.GPIO_Pin, (LD_G_Status.OnState == GPIO_PIN_SET) ? GPIO_PIN_RESET : GPIO_PIN_SET);
			HAL_GPIO_WritePin(LD_R_Status.GPIOx, LD_R_Status.GPIO_Pin, LD_R_Status.OnState);
		}
	}
	void LED_Ctr_Brake(uint8_t ctr){
		if(ctr == 1) 	// Brake on
		{
			 HAL_GPIO_WritePin(LD_Brake.GPIOx, LD_Brake.GPIO_Pin, LD_Brake.OnState);
		}
		else{			// Brake off
			HAL_GPIO_WritePin(LD_Brake.GPIOx, LD_Brake.GPIO_Pin, (LD_Brake.OnState == GPIO_PIN_SET) ? GPIO_PIN_RESET : GPIO_PIN_SET);
		}
	}
};


#endif /* INC_EMO_STATUS_H_ */


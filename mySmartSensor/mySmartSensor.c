/*
 * mySmartSensor.c
 *
 *  Created on: Dec 11, 2019
 *      Author: Andi
 */

#include "mySmartSensor.h"

unsigned char Kirim='B';
unsigned char Terima='0';

/* Value Sensor Variable	*/
uint8_t SH0=0, SL0=0;
uint8_t SH1=0, SL1=0;
uint8_t SH2=0, SL2=0;
uint16_t SF0=0, SF1=0, SF2=0;

/* Variable Calibrate 1	*/
uint8_t TH0=0, TL0=0, TF0=0;
uint8_t TH1=0, TL1=0, TF1=0;
uint8_t TH2=0, TL2=0, TF2=0;

/* variable Calibrate 2 */
uint16_t dark0=0, dark1=0, dark2=0;
uint16_t light0=1023, light1=1023, light2=1023;
uint16_t Threshold0, Threshold1, Threshold2;

void SmartSensor(void){
	/*	---	*/
	Terima = SPI_SlaveReceive(Kirim);
	switch(Terima){
	case 0x00:{
		Kirim = 0x00;
	}break;

	/* Send low byte sensor 0	*/
	case 0x01:{
		myADC_read(0, 0, &SL0, 0);		// only save value to variable SL0
		Kirim = SL0;
	}break;

	/* Send high byte sensor 0	*/
	case 0x02:{
		myADC_read(0, &SH0, 0, 0);		// only save value to variable SL0
		Kirim = SH0;
	}break;

	/*	Send low byte sensor 1	*/
	case 0x03:{
		myADC_read(1, 0, &SL1, 0);		// only save value to variable SL0
		Kirim = SL1;
	}break;

	/*	Send high byte sensor 1	*/
	case 0x04:{
		myADC_read(1, &SH1, 0, 0);		// only save value to variable SL0
		Kirim = SH1;
	}break;

	/* Send low byte sensor 2	*/
	case 0x05:{
		myADC_read(2, 0, &SL2, 0);		// only save value to variable SL0
		Kirim = SL2;
	}break;

	/* Send low high byte sensor 2	*/
	case 0x06:{
		myADC_read(2, &SH2, 0, 0);		// only save value to variable SL0
		Kirim = SH2;
	}break;

	/*	Send low byte threshold CH0	*/
	case 0x07:{
		calibrate_S0(0, &TL0, 0);
		Kirim = TL0;
	}break;

	/*	Send high byte threshold CH0	*/
	case 0x08:{
		calibrate_S0(&TH0, 0, 0);
		Kirim = TH0;
	}break;

	/*	Send low byte threshold CH1	*/
	case 0x09:{
		calibrate_S1(0, &TL1, 0);
		Kirim = TL1;
	}break;

	/*	Send high byte threshold CH1	*/
	case 0x0A:{
		calibrate_S1(&TH1, 0, 0);
		Kirim = TH1;
	}break;

	/*	Send low byte threshold CH2	*/
	case 0x0B:{
		calibrate_S2(0, &TL2, 0);
		Kirim = TL2;
	}break;

	/*	Send high byte threshold CH2	*/
	case 0x0C:{
		calibrate_S2(&TH2, 0, 0);
		Kirim = TH2;
	}break;

	/* Calibrate all sensor	*/
	case 0x0D:{
		calibrate_S2(&TH2, 0, 0);
		Kirim = TH2;
	}break;

	/* Auto calibrate	*/
	case 0x0E:{
		calibrate_S2(&TH2, 0, 0);
		Kirim = TH2;
	}break;

	/* digitalRaw	*/
	case 0x0E:{

	}break;

	/* Decision	*/
	case 0x0E:{

	}break;
	}
}

void calibrate_S0(uint8_t *ThrsHigh, uint8_t *ThrsLow, uint16_t *ThrsFull){
	/* read the adc	*/
	myADC_read(0, 0, 0, &SF0);

	/* get min value	*/
	if(SF0 < light0)
		light0=SF0;

	/* get max value	*/
	if(SF0 > dark0)
		dark0=SF0;

	/*	calculate threshold	*/
	Threshold0 = (light0+dark0)/2;
	*ThrsFull = Threshold0;
	/*	parsing the Threshold to ThrsHigh and ThrsLow	*/
	*ThrsHigh = Threshold0 >> 8;
	*ThrsLow = Threshold0 & 0xFF;
}
void calibrate_S1(uint8_t *ThrsHigh, uint8_t *ThrsLow, uint16_t *ThrsFull){
	/* read the adc	*/
	myADC_read(1, 0, 0, &SF1);

	/* get min value	*/
	if(SF1 < light1)
		light1=SF1;

	/* get max value	*/
	if(SF1 > dark1)
		dark1=SF1;

	/*	calculate threshold	*/
	Threshold1 = (light1+dark1)/2;
	*ThrsFull = Threshold1;
	/*	parsing the Threshold to ThrsHigh and ThrsLow	*/
	*ThrsHigh = Threshold1 >> 8;
	*ThrsLow = Threshold1 & 0xFF;
}

void calibrate_S2(uint8_t *ThrsHigh, uint8_t *ThrsLow, uint16_t *ThrsFull){
	/* read the adc	*/
	myADC_read(2, 0, 0, &SF2);

	/* get min value	*/
	if(SF2 < light2)
		light2=SF2;

	/* get max value	*/
	if(SF2 > dark2)
		dark2=SF2;

	/*	calculate threshold	*/
	Threshold2 = (light2+dark2)/2;
	*ThrsFull = Threshold2;
	/*	parsing the Threshold to ThrsHigh and ThrsLow	*/
	*ThrsHigh = Threshold2 >> 8;
	*ThrsLow = Threshold2 & 0xFF;
}

uint8_t digitalRaw(uint16_t Thrs2, uint16_t Thrs1, uint16_t Thrs0){
	uint8_t result;
	/* read all sensor	*/
	myADC_read(0, 0, 0, &SF0);
	myADC_read(0, 0, 0, &SF1);
	myADC_read(0, 0, 0, &SF2);
	if(SF0 > th)
	return result;
}
uint8_t dicision(uint8_t in_digitalRaw){

}

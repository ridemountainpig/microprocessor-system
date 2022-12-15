//
// TMR_Capture_SR04 : usi[ng Timer Capture to read Ultrasound Ranger SR-04
//
// EVB : Nu-LB-NUC140 (need to manually switch RSTCAPSEL)
// MCU : NUC140VE3CN
// Sensor: SR-04

// SR-04 connection
// Trig connected to PB8
// Echo connected to TC2/PB2 (TC0_PB15, TC1_PE5, TC2_PB2, TC3_PB3)

#include <stdio.h>
#include "NUC100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "LCD.h"
#include "Seven_Segment.h"

unsigned char dinosaur[] = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xF8,0x1C,0x18,0x00,0x00,0x00,0x00,0x00,
	  0x00,0x00,0x00,0x00,0x00,0x02,0x1F,0x0F,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

unsigned char ob1[] = {
	0x00,0xC0,0x00,0xFC,0x00,0x00,0x00,0xC0,0xFC,0xE0,0x80,0x00,0xFC,0x00,0x00,0x00,
	0x00,0x03,0x04,0x7F,0x4E,0x04,0x00,0x03,0x7F,0x07,0x07,0x04,0x7F,0x06,0x00,0x00
};

unsigned char ob2[] = {
	0x00,0x00,0xC0,0x00,0x00,0xF8,0x00,0x00,0x00,0x00,0xC0,0xF8,0xF8,0xC0,0x00,0x00,
	0x00,0x00,0x07,0x04,0x4C,0x7F,0x04,0x04,0x04,0x00,0x07,0x7F,0x7F,0x07,0x04,0x04
};

void display(int pc, int number, int delay) {
  if (pc == 4) {
    PC4 = 1;
  } else if (pc == 5) {
    PC5 = 1;
  } else if (pc == 6) {
    PC6 = 1;
  } else if (pc == 7) {
    PC7 = 1;
  }
			PE0 = 1;
			PE1 = 1;
      PE2 = 1;
      PE3 = 1;
      PE4 = 1;
			PE5 = 1;
      PE6 = 1;
			PE7 = 1;
	
  switch (number) {
    case 0:
      PE0 = 0;
      PE5 = 0;
      PE6 = 0;
      PE2 = 0;
      PE3 = 0;
      PE4 = 0;
      CLK_SysTickDelay(delay);
      PE0 = 1;
      PE5 = 1;
      PE6 = 1;
      PE2 = 1;
      PE3 = 1;
      PE4 = 1;
      break;
    case 1:
      PE0 = 0;
      PE4 = 0;
      CLK_SysTickDelay(delay);
      PE0 = 1;
      PE4 = 1;
      break;
    case 2:
      PE3 = 0;
      PE4 = 0;
      PE7 = 0;
      PE6 = 0;
      PE5 = 0;
      CLK_SysTickDelay(delay);
      PE3 = 1;
      PE4 = 1;
      PE7 = 1;
      PE6 = 1;
      PE5 = 1;
      break;
    case 3:
      PE3 = 0;
      PE4 = 0;
      PE7 = 0;
      PE0 = 0;
      PE5 = 0;
      CLK_SysTickDelay(delay);
      PE3 = 1;
      PE4 = 1;
      PE7 = 1;
      PE0 = 1;
      PE5 = 1;
      break;
    case 4:
      PE4 = 0;
      PE7 = 0;
      PE0 = 0;
      PE2 = 0;
      CLK_SysTickDelay(delay);
      PE4 = 1;
      PE7 = 1;
      PE0 = 1;
      PE2 = 1;
      break;
    case 5:
      PE3 = 0;
      PE2 = 0;
      PE7 = 0;
      PE0 = 0;
      PE5 = 0;
      CLK_SysTickDelay(delay);
      PE3 = 1;
      PE2 = 1;
      PE7 = 1;
      PE0 = 1;
      PE5 = 1;
      break;
    case 6:
      PE3 = 0;
      PE2 = 0;
      PE6 = 0;
      PE5 = 0;
      PE0 = 0;
      PE7 = 0;
      CLK_SysTickDelay(delay);
      PE3 = 1;
      PE2 = 1;
      PE6 = 1;
      PE5 = 1;
      PE0 = 1;
      PE7 = 1;
      break;
    case 7:
      PE2 = 0;
      PE3 = 0;
      PE4 = 0;
      PE0 = 0;
      CLK_SysTickDelay(delay);
      PE2 = 1;
      PE3 = 1;
      PE4 = 1;
      PE0 = 1;
      break;
    case 8:
      PE0 = 0;
      PE2 = 0;
      PE3 = 0;
      PE4 = 0;
      PE5 = 0;
      PE6 = 0;
      PE7 = 0;
      CLK_SysTickDelay(delay);
      PE0 = 1;
      PE2 = 1;
      PE3 = 1;
      PE4 = 1;
      PE5 = 1;
      PE6 = 1;
      PE7 = 1;
      break;
    case 9:
      PE2 = 0;
      PE3 = 0;
      PE4 = 0;
      PE7 = 0;
      PE0 = 0;
      PE5 = 0;
      CLK_SysTickDelay(delay);
      PE2 = 1;
      PE3 = 1;
      PE4 = 1;
      PE7 = 1;
      PE0 = 1;
      PE5 = 1;
      break;
  }
  if (pc == 4) {
    PC4 = 0;
  } else if (pc == 5) {
    PC5 = 0;
  } else if (pc == 6) {
    PC6 = 0;
  } else if (pc == 7) {
    PC7 = 0;
  }
}

void Show(int x, uint32_t delay) {
  int n1, n2, n3, n4;
  if (x < 10) {
    display(4, x, delay);
  } else if (x < 100) {
    display(4, x % 10, delay);
    display(5, x / 10, delay);
  } else if (x < 1000) {
    display(4, x % 10, delay);
    display(5, x / 10 % 10, delay);
    display(6, x / 100, delay);
  } else {
    display(4, x % 10, delay);
    display(5, x / 10 % 10, delay);
    display(6, x / 100 % 10, delay);
    display(7, x / 1000, delay);
  }
}

char Text[16];

void Init_ADC(void)
{
    ADC_Open(ADC, ADC_INPUT_MODE, ADC_OPERATION_MODE, ADC_CHANNEL_MASK);
    ADC_POWER_ON(ADC);
}

int32_t main (void)
{
    uint32_t x, y, z;
		int heart = 4, obTime = 0, jumpCount = 0, check = 0;
		int i, j;
		float yy = 48;
		float obx = 114;
    SYS_Init();
    Init_ADC();
	  init_LCD();
	  clear_LCD();
		OpenSevenSegment();
	
		PD14 = 0;
		
		PC4 = 0;
		PC5 = 0;
		PC6 = 0;
		PC7 = 0;
	
		ADC_START_CONV(ADC);
		CLK_SysTickDelay(100000);
    while(1)
		{
			PC4 = 0;
			PC5 = 0;
			PC6 = 0;
			PC7 = 0;
			
			y = ADC_GET_CONVERSION_DATA(ADC, 1);
			clear_LCD();
			
			if (obx < 0) {
				obTime++;
				obx = 112;
			};
			
			if (obTime % 2 == 0) draw_Bmp16x16(obx, 48, FG_COLOR, BG_COLOR, ob1);
			else draw_Bmp16x16(obx, 48, FG_COLOR, BG_COLOR, ob2);
			
			obx -= 0.8;
			
			draw_Bmp16x16(0, yy, FG_COLOR, BG_COLOR, dinosaur);
			
			check = 0;
			if (y < 3000) {
				if (obx < 20 && obx > 0) jumpCount++;
				for (i = 0; i < 20; i++) {
					clear_LCD();
					Show(jumpCount, 5000);
					draw_Bmp16x16(0, yy, FG_COLOR, BG_COLOR, dinosaur);
					if (obTime % 2 == 0) draw_Bmp16x16(obx, 48, FG_COLOR, BG_COLOR, ob1);
					else draw_Bmp16x16(obx, 48, FG_COLOR, BG_COLOR, ob2);
					//if (obx < 16 && yy > 34) check = 1;
					yy -= 0.8;
					obx -= 0.8;
				}
				for (i = 0; i < 20; i++) {
					clear_LCD();
					Show(jumpCount, 5000);
					draw_Bmp16x16(0, yy, FG_COLOR, BG_COLOR, dinosaur);
					if (obTime % 2 == 0) draw_Bmp16x16(obx, 48, FG_COLOR, BG_COLOR, ob1);
					else draw_Bmp16x16(obx, 48, FG_COLOR, BG_COLOR, ob2);
					if (obx < 16 && yy > 34 && obx > 2) check = 1;
					yy += 0.8;
					obx -= 0.8;
				}
				if (check == 1) heart--;
			}
			
			if (obx < 12 && obx > 11.2 && y > 3000) heart--;
			
			Show(jumpCount, 5000);
			
			if (heart == 4) {
				PC12 = 0;
				PC13 = 0;
				PC14 = 0;
				PC15 = 0;
			} else if (heart == 3) {
				PC12 = 1;
				PC13 = 0;
				PC14 = 0;
				PC15 = 0;
			} else if (heart == 2) {
				PC12 = 1;
				PC13 = 1;
				PC14 = 0;
				PC15 = 0;
			} else if (heart == 1) {
				PC12 = 1;
				PC13 = 1;
				PC14 = 1;
				PC15 = 0;
			} else {
				break;
			}
			
			/*
			sprintf(Text,"T = %5d", x);
	    print_Line(1, Text);
      y = ADC_GET_CONVERSION_DATA(ADC, 1);
			sprintf(Text,"T = %5d", y);
	    print_Line(2, Text);
			z = PB0;
	    sprintf(Text,"T = %5d", z);
	    print_Line(3, Text);
			*/
    }
}

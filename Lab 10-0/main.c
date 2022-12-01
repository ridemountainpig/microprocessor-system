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
#include <stdlib.h>

#include "LCD.h"
#include "MCU_init.h"
#include "NUC100Series.h"
#include "SYS_init.h"
#include "Seven_Segment.h"

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
  if (delay < 10)
    delay = 10;
  else if (delay > 5000)
    delay = 5000;
  delay /= 20;
  delay += 10;
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

void Init_ADC(void) {
  ADC_Open(ADC, ADC_INPUT_MODE, ADC_OPERATION_MODE, ADC_CHANNEL_MASK);
  ADC_POWER_ON(ADC);
}

int32_t main(void) {
  int i, d;
  int count = 0;
  uint32_t u32ADCvalue;
  SYS_Init();
  Init_ADC();
  init_LCD();
  clear_LCD();

  PD14 = 0;

  print_Line(0, "VR");

  PC4 = 0;
  PC5 = 0;
  PC6 = 0;
  PC7 = 0;

  while (1) {
    ADC_START_CONV(ADC);
    u32ADCvalue = ADC_GET_CONVERSION_DATA(ADC, 7);
    sprintf(Text, "T = %5d", u32ADCvalue);
    print_Line(1, Text);
    for (i = 0; i < 80; i++) Show(count, u32ADCvalue);
    count++;
  }
}

//
// TMR_LED : change LED on/off by Timer1 interrupt
//
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "LCD.h"
#include "MCU_init.h"
#include "NUC100Series.h"
#include "SYS_init.h"
#include "Seven_Segment.h"

uint8_t ledState = 0;
uint32_t keyin = 0;
uint32_t i = 5;
uint32_t j = 0;

void TMR1_IRQHandler(void) {
  // PC14 = ~PC14;
  PD14 = PB0 == 0 ? ~PD14 : PD14;
  TIMER_ClearIntFlag(TIMER1);  // Clear Timer1 time-out interrupt flag
}

void Init_Timer1(void) {
  TIMER_Open(TIMER1, TMR1_OPERATING_MODE, 1);
  TIMER_EnableInt(TIMER1);
  NVIC_EnableIRQ(TMR1_IRQn);
  TIMER_Start(TIMER1);
}

void Init_ADC(void) {
  ADC_Open(ADC, ADC_INPUT_MODE, ADC_OPERATION_MODE, ADC_CHANNEL_MASK);
  ADC_POWER_ON(ADC);
}

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

void Show(int x) {
  if (x < 10) {
    display(4, x, 1000);
  } else if (x < 100) {
    display(4, x % 10, 1000);
    display(5, x / 10, 1000);
  } else if (x < 1000) {
    display(4, x % 10, 1000);
    display(5, x / 10 % 10, 1000);
    display(6, x / 100, 1000);
  } else {
    display(4, x % 10, 1000);
    display(5, x / 10 % 10, 1000);
    display(6, x / 100 % 10, 1000);
    display(7, x / 1000, 1000);
  }
}

int main(void) {
  uint32_t x, y, z;
  int delay = 100000;
  int count = 0;
  char Text[16];

  SYS_Init();
  Init_ADC();
  init_LCD();
  clear_LCD();
  OpenSevenSegment();

  PD14 = 0;
  print_Line(0, "timer");
  Init_Timer1();

  ADC_START_CONV(ADC);
  x = ADC_GET_CONVERSION_DATA(ADC, 0);
  CLK_SysTickDelay(1000);

  while (1) {
    x = ADC_GET_CONVERSION_DATA(ADC, 0);

    delay = (x + 1) * 20;

    PC12 = 0;
    CLK_SysTickDelay(delay);
    for (i = 0; i < 60; i++) Show(x / 1000);
    PC12 = 1;
    CLK_SysTickDelay(delay);
    for (i = 0; i < 60; i++) Show(x / 1000);
    PC13 = 0;
    CLK_SysTickDelay(delay);
    for (i = 0; i < 60; i++) Show(x / 1000);
    PC13 = 1;
    CLK_SysTickDelay(delay);
    for (i = 0; i < 60; i++) Show(x / 1000);
    PC14 = 0;
    CLK_SysTickDelay(delay);
    for (i = 0; i < 60; i++) Show(x / 1000);
    PC14 = 1;
    CLK_SysTickDelay(delay);
    for (i = 0; i < 80; i++) Show(x / 1000);
    PC15 = 0;
    CLK_SysTickDelay(delay);
    for (i = 0; i < 60; i++) Show(x / 1000);
    PC15 = 1;
    CLK_SysTickDelay(delay);
    for (i = 0; i < 60; i++) Show(x / 1000);

    sprintf(Text, "T = %5d", x);
    print_Line(1, Text);
    y = ADC_GET_CONVERSION_DATA(ADC, 1);
    sprintf(Text, "T = %5d", y);
    print_Line(2, Text);
    z = PB0;
    sprintf(Text, "T = %5d", z);
    print_Line(3, Text);
  }
}

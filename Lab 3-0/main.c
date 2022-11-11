#include <stdio.h>

#include "MCU_init.h"
#include "NUC100Series.h"
#include "SYS_init.h"
#include "Scankey.h"
#include "Seven_Segment.h"

int time = 1000;
int number1, number2;

uint8_t ScanKey(void) {
  PA0 = 1;
  PA1 = 1;
  PA2 = 0;
  PA3 = 1;
  PA4 = 1;
  PA5 = 1;
  if (PA3 == 0) return 1;
  if (PA4 == 0) return 4;
  if (PA5 == 0) return 7;
  PA0 = 1;
  PA1 = 0;
  PA2 = 1;
  PA3 = 1;
  PA4 = 1;
  PA5 = 1;
  if (PA3 == 0) return 2;
  if (PA4 == 0) return 5;
  if (PA5 == 0) return 8;
  PA0 = 0;
  PA1 = 1;
  PA2 = 1;
  PA3 = 1;
  PA4 = 1;
  PA5 = 1;
  if (PA3 == 0) return 3;
  if (PA4 == 0) return 6;
  if (PA5 == 0) return 9;
  return 0;
}

void Show(uint16_t value) {
  int v0 = value % 10;
  int v1 = value / 10;

  PC5 = 0;
  PC4 = 0;
  PC5 = 1;
  switch (v1) {
    case 0:
      PE0 = 0;
      PE5 = 0;
      PE6 = 0;
      PE2 = 0;
      PE3 = 0;
      PE4 = 0;
      CLK_SysTickDelay(time);
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
      CLK_SysTickDelay(time);
      PE0 = 1;
      PE4 = 1;
      break;
    case 2:
      PE3 = 0;
      PE4 = 0;
      PE7 = 0;
      PE6 = 0;
      PE5 = 0;
      CLK_SysTickDelay(time);
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
      CLK_SysTickDelay(time);
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
      CLK_SysTickDelay(time);
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
      CLK_SysTickDelay(time);
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
      CLK_SysTickDelay(time);
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
      CLK_SysTickDelay(time);
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
      CLK_SysTickDelay(time);
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
      CLK_SysTickDelay(time);
      PE2 = 1;
      PE3 = 1;
      PE4 = 1;
      PE7 = 1;
      PE0 = 1;
      PE5 = 1;
      break;
  }

  PC5 = 0;
  PC4 = 0;
  PC4 = 1;
  switch (v0) {
    case 0:
      PE0 = 0;
      PE5 = 0;
      PE6 = 0;
      PE2 = 0;
      PE3 = 0;
      PE4 = 0;
      CLK_SysTickDelay(time);
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
      CLK_SysTickDelay(time);
      PE0 = 1;
      PE4 = 1;
      break;
    case 2:
      PE3 = 0;
      PE4 = 0;
      PE7 = 0;
      PE6 = 0;
      PE5 = 0;
      CLK_SysTickDelay(time);
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
      CLK_SysTickDelay(time);
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
      CLK_SysTickDelay(time);
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
      CLK_SysTickDelay(time);
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
      CLK_SysTickDelay(time);
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
      CLK_SysTickDelay(time);
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
      CLK_SysTickDelay(time);
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
      CLK_SysTickDelay(time);
      PE2 = 1;
      PE3 = 1;
      PE4 = 1;
      PE7 = 1;
      PE0 = 1;
      PE5 = 1;
      break;
  }
  PC4 = 0;
  PC5 = 0;
}

void Buzz(void) {
  PB11 = 0;
  CLK_SysTickDelay(50000);
  PB11 = 1;
}

int i;
int j;
int input;
int main(void) {
  SYS_Init();

  OpenSevenSegment();
  OpenKeyPad();

  number1 = 0;
  number2 = 0;

  while (number1 == 0) {
    number1 = ScanKey();
  }
  CLK_SysTickDelay(1000000);
  while (number2 == 0) {
    number2 = ScanKey();
  }

  input = number1 * 10 + number2;
  for (i = input; i >= 0; i--) {
    for (j = 0; j < 150; j++) {
      Show(i);
    }
    if (i <= 10 && i >= 1) {
      Buzz();
    }
  }
  number1 = 0;
  while (1) {
    number1 = ScanKey();
    if (number1 != 0) {
      break;
    }
    Show(0);
    PB11 = 0;
  }
}
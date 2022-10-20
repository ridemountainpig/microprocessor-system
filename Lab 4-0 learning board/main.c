//
// GPIO_7seg_keypad : 3x3 keypad inpt and display on 7-segment LEDs
//
#include "LCD.h"
#include "MCU_init.h"
#include "NUC100Series.h"
#include "SYS_init.h"
#include "Scankey.h"
#include "Seven_Segment.h"

// display an integer on four 7-segment LEDs
int n1 = 0, n2 = 0, n3 = 0, n4 = 0;

void Show(uint16_t x) {
  int time;
  time = 1000;
  switch (x) {
    case 1:
      x = 1000;
      break;
    case 2:
      x = 100;
      break;
    case 3:
      x = 10;
      break;
    case 4:
      x = 1;
      break;
  }
  PC4 = 0;
  PC5 = 0;
  PC6 = 0;
  PC7 = 0;
  CLK_SysTickDelay(1);
  n1 = x / 1000;
  n2 = x / 100 % 10;
  n3 = x / 10 % 10;
  n4 = x % 10;
  PC4 = 1;
  switch (n4) {
    case 1:
      PE0 = 0;
      PE4 = 0;
      break;
    case 2:
      PE3 = 0;
      PE4 = 0;
      PE7 = 0;
      PE6 = 0;
      PE5 = 0;
      break;
    case 3:
      PE3 = 0;
      PE4 = 0;
      PE7 = 0;
      PE0 = 0;
      PE5 = 0;
      break;
    case 4:
      PE0 = 0;
      PE7 = 0;
      PE2 = 0;
      PE4 = 0;
      break;
    case 5:
      PE3 = 0;
      PE2 = 0;
      PE7 = 0;
      PE0 = 0;
      PE5 = 0;
      break;
    case 6:
      PE3 = 0;
      PE2 = 0;
      PE7 = 0;
      PE0 = 0;
      PE5 = 0;
      PE6 = 0;
      break;
    case 7:
      PE2 = 0;
      PE3 = 0;
      PE0 = 0;
      PE4 = 0;
      break;
    case 8:
      PE0 = 0;
      PE4 = 0;
      PE7 = 0;
      PE2 = 0;
      PE3 = 0;
      PE5 = 0;
      PE6 = 0;
      PE7 = 0;
      break;
    case 9:
      PE3 = 0;
      PE2 = 0;
      PE0 = 0;
      PE4 = 0;
      PE7 = 0;
      break;
    case 0:
      PE0 = 0;
      PE4 = 0;
      PE2 = 0;
      PE3 = 0;
      PE5 = 0;
      PE6 = 0;
  }
  CLK_SysTickDelay(time);
  CloseSevenSegment();
  OpenSevenSegment();
  PC4 = 0;
  PC5 = 0;
  PC6 = 0;
  PC7 = 0;
  CLK_SysTickDelay(1);
  PC4 = 0;
  PC5 = 1;
  switch (n3) {
    case 1:
      PE0 = 0;
      PE4 = 0;
      break;
    case 2:
      PE3 = 0;
      PE4 = 0;
      PE7 = 0;
      PE6 = 0;
      PE5 = 0;
      break;
    case 3:
      PE3 = 0;
      PE4 = 0;
      PE7 = 0;
      PE0 = 0;
      PE5 = 0;
      break;
    case 4:
      PE0 = 0;
      PE7 = 0;
      PE2 = 0;
      PE4 = 0;
      break;
    case 5:
      PE3 = 0;
      PE2 = 0;
      PE7 = 0;
      PE0 = 0;
      PE5 = 0;
      break;
    case 6:
      PE3 = 0;
      PE2 = 0;
      PE7 = 0;
      PE0 = 0;
      PE5 = 0;
      PE6 = 0;
      break;
    case 7:
      PE2 = 0;
      PE3 = 0;
      PE0 = 0;
      PE4 = 0;
      break;
    case 8:
      PE0 = 0;
      PE4 = 0;
      PE7 = 0;
      PE2 = 0;
      PE3 = 0;
      PE5 = 0;
      PE6 = 0;
      PE7 = 0;
      break;
    case 9:
      PE3 = 0;
      PE2 = 0;
      PE0 = 0;
      PE4 = 0;
      PE7 = 0;
      break;
    case 0:
      PE0 = 0;
      PE4 = 0;
      PE2 = 0;
      PE3 = 0;
      PE5 = 0;
      PE6 = 0;
  }
  CLK_SysTickDelay(time);
  CloseSevenSegment();
  OpenSevenSegment();
  PC4 = 0;
  PC5 = 0;
  PC6 = 0;
  PC7 = 0;
  CLK_SysTickDelay(1);
  PC5 = 0;
  PC6 = 1;
  switch (n2) {
    case 1:
      PE0 = 0;
      PE4 = 0;
      break;
    case 2:
      PE3 = 0;
      PE4 = 0;
      PE7 = 0;
      PE6 = 0;
      PE5 = 0;
      break;
    case 3:
      PE3 = 0;
      PE4 = 0;
      PE7 = 0;
      PE0 = 0;
      PE5 = 0;
      break;
    case 4:
      PE0 = 0;
      PE7 = 0;
      PE2 = 0;
      PE4 = 0;
      break;
    case 5:
      PE3 = 0;
      PE2 = 0;
      PE7 = 0;
      PE0 = 0;
      PE5 = 0;
      break;
    case 6:
      PE3 = 0;
      PE2 = 0;
      PE7 = 0;
      PE0 = 0;
      PE5 = 0;
      PE6 = 0;
      break;
    case 7:
      PE2 = 0;
      PE3 = 0;
      PE0 = 0;
      PE4 = 0;
      break;
    case 8:
      PE0 = 0;
      PE4 = 0;
      PE7 = 0;
      PE2 = 0;
      PE3 = 0;
      PE5 = 0;
      PE6 = 0;
      PE7 = 0;
      break;
    case 9:
      PE3 = 0;
      PE2 = 0;
      PE0 = 0;
      PE4 = 0;
      PE7 = 0;
      break;
    case 0:
      PE0 = 0;
      PE4 = 0;
      PE2 = 0;
      PE3 = 0;
      PE5 = 0;
      PE6 = 0;
  }
  CLK_SysTickDelay(time);
  CloseSevenSegment();
  OpenSevenSegment();
  PC4 = 0;
  PC5 = 0;
  PC6 = 0;
  PC7 = 0;
  CLK_SysTickDelay(1);
  PC6 = 0;
  PC7 = 1;
  switch (n1) {
    case 1:
      PE0 = 0;
      PE4 = 0;
      break;
    case 2:
      PE3 = 0;
      PE4 = 0;
      PE7 = 0;
      PE6 = 0;
      PE5 = 0;
      break;
    case 3:
      PE3 = 0;
      PE4 = 0;
      PE7 = 0;
      PE0 = 0;
      PE5 = 0;
      break;
    case 4:
      PE0 = 0;
      PE7 = 0;
      PE2 = 0;
      PE4 = 0;
      break;
    case 5:
      PE3 = 0;
      PE2 = 0;
      PE7 = 0;
      PE0 = 0;
      PE5 = 0;
      break;
    case 6:
      PE3 = 0;
      PE2 = 0;
      PE7 = 0;
      PE0 = 0;
      PE5 = 0;
      PE6 = 0;
      break;
    case 7:
      PE2 = 0;
      PE3 = 0;
      PE0 = 0;
      PE4 = 0;
      break;
    case 8:
      PE0 = 0;
      PE4 = 0;
      PE7 = 0;
      PE2 = 0;
      PE3 = 0;
      PE5 = 0;
      PE6 = 0;
      PE7 = 0;
      break;
    case 9:
      PE3 = 0;
      PE2 = 0;
      PE0 = 0;
      PE4 = 0;
      PE7 = 0;
      break;
    case 0:
      PE0 = 0;
      PE4 = 0;
      PE2 = 0;
      PE3 = 0;
      PE5 = 0;
      PE6 = 0;
  }
  CLK_SysTickDelay(time);
  CloseSevenSegment();
  OpenSevenSegment();
  PC4 = 0;
  PC5 = 0;
  PC6 = 0;
  PC7 = 0;
  CLK_SysTickDelay(1);
}
int main(void) {
  uint16_t i;
  int now = 3;
  SYS_Init();
  init_LCD();
  clear_LCD();
  GPIO_SetMode(PC, BIT12, GPIO_PMD_OUTPUT);
  GPIO_SetMode(PC, BIT13, GPIO_PMD_OUTPUT);
  GPIO_SetMode(PC, BIT14, GPIO_PMD_OUTPUT);
  GPIO_SetMode(PC, BIT15, GPIO_PMD_OUTPUT);
  OpenSevenSegment();
  OpenKeyPad();

  PD14 = 0;

  while (1) {
    if (ScanKey() != 0) {
      i = ScanKey();
      Show(now);
      CLK_SysTickDelay(1000000);
      Show(now);
    } else {
      i = 0;
      Show(now);
    }
    if (i == 4) {
      now--;
      if (now == 0) now = 4;
    } else if (i == 6) {
      now++;
      if (now == 5) now = 1;
    } else if (i == 5) {
      now = 3;
    }
    Show(now);

    switch (now) {
      case 1:
        PC12 = 0;
        PC13 = 1;
        PC14 = 1;
        PC15 = 1;
        print_Line(1, "1 0 0 0");
        Show(now);
        break;
      case 2:
        PC12 = 1;
        PC13 = 0;
        PC14 = 1;
        PC15 = 1;
        print_Line(1, "0 1 0 0");
        Show(now);
        break;
      case 3:
        PC12 = 1;
        PC13 = 1;
        PC14 = 0;
        PC15 = 1;
        print_Line(1, "0 0 1 0");
        Show(now);
        break;
      case 4:
        PC12 = 1;
        PC13 = 1;
        PC14 = 1;
        PC15 = 0;
        print_Line(1, "0 0 0 1");
        Show(now);
        break;
    }
  }
}
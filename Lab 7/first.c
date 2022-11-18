// GPIO_7seg_keypad : 3x3 keypad inpt and display on 7-segment LEDs
//
#include "LCD.h"
#include "MCU_init.h"
#include <stdio.h>
#include "NUC100Series.h"
#include "SYS_init.h"
#include "Scankey.h"
#include "Seven_Segment.h"

// display an integer on four 7-segment LEDs

int main(void) {
  uint32_t keyin = 0;

  GPIO_SetMode(PB, BIT0, GPIO_MODE_QUASI);
  GPIO_SetMode(PB, BIT1, GPIO_MODE_QUASI);
  GPIO_SetMode(PB, BIT2, GPIO_MODE_QUASI);
  GPIO_SetMode(PB, BIT3, GPIO_MODE_QUASI);
  GPIO_SetMode(PB, BIT4, GPIO_MODE_QUASI);
  GPIO_SetMode(PB, BIT5, GPIO_MODE_QUASI);
  GPIO_SetMode(PB, BIT6, GPIO_MODE_QUASI);
  GPIO_SetMode(PB, BIT7, GPIO_MODE_QUASI);
  GPIO_SetMode(PB, BIT8, GPIO_MODE_QUASI);

  SYS_Init();
  init_LCD();
  clear_LCD();
  OpenKeyPad();
  clear_LCD();
  PD14 = 0;

  while (1) {
    PB0 = 1;
    PB1 = 1;
    PB2 = 1;
    PB2 = 1;
    PB3 = 1;
    PB4 = 1;
    PB5 = 1;
    PB6 = 1;
    PB7 = 1;
    PB8 = 1;
    PC12 = 1;
    PC13 = 1;
    PC14 = 1;
    PC15 = 1;
    keyin = ScanKey();
    if (keyin == 1 || PB1 == 0) {
      PC15 = 0;
      PB0 = 0;
      CLK_SysTickDelay(1000);
    } else if (keyin == 2 || PB0 == 0) {
      PC14 = 0;
      PB1 = 0;
      CLK_SysTickDelay(1000);
    } else if (keyin == 3 || PB3 == 0) {
      PC14 = 0;
      PC15 = 0;
      PB2 = 0;
      CLK_SysTickDelay(1000);
    } else if (keyin == 4 || PB2 == 0) {
      PC13 = 0;
      PB3 = 0;
      CLK_SysTickDelay(1000);
    } else if (keyin == 5 || PB5 == 0) {
      PC13 = 0;
      PC15 = 0;
      PB4 = 0;
      CLK_SysTickDelay(1000);
    } else if (keyin == 6 || PB4 == 0) {
      PC13 = 0;
      PC14 = 0;
      PB5 = 0;
      CLK_SysTickDelay(1000);
    } else if (keyin == 7 || PB7 == 0) {
      PC13 = 0;
      PC14 = 0;
      PC15 = 0;
      PB6 = 0;
      CLK_SysTickDelay(1000);
    } else if (keyin == 8 || PB6 == 0) {
      PC12 = 0;
      PB7 = 0;
      CLK_SysTickDelay(1000);
    } else if (keyin == 9 || PB8 == 0) {
      PC12 = 0;
      PC15 = 0;
      PB8 = 0;
      CLK_SysTickDelay(1000);
    }
  }
}
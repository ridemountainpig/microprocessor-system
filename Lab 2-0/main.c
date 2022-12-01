//
// GPIO_7seg : counting from 0 to 9999 and display on 7-segment LEDs
//
#include <stdio.h>

#include "MCU_init.h"
#include "NUC100Series.h"
#include "SYS_init.h"
#include "Seven_Segment.h"

// for while loop use
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
  int n1, n2, n3, n4;
  if (x < 10) {
    while (1) {
      display(4, x, 1000);
    }
  } else if (x < 100) {
    while (1) {
      display(4, x % 10, 1000);
      display(5, x / 10, 1000);
    }
  } else if (x < 1000) {
    while (1) {
      display(4, x % 10, 1000);
      display(5, x / 10 % 10, 1000);
      display(6, x / 100, 1000);
    }
  } else {
    while (1) {
      display(4, x % 10, 1000);
      display(5, x / 10 % 10, 1000);
      display(6, x / 100 % 10, 1000);
      display(7, x / 1000, 1000);
    }
  }
}

int main(void) {
  int i = 0;

  SYS_Init();
  OpenSevenSegment();

  PC4 = 0;
  PC5 = 0;
  PC6 = 0;
  PC7 = 0;
  CLK_SysTickDelay(1000000);

  // Show(1234);

  while (1) {
    // 0
    PC4 = 1;
    PE0 = 0;
    PE1 = 0;
    PE2 = 0;
    PE3 = 0;
    PE4 = 0;
    PE5 = 0;
    PE6 = 0;
    PE7 = 1;
    CLK_SysTickDelay(1000000);
    PC4 = 0;
    PE0 = 1;
    PE1 = 1;
    PE2 = 1;
    PE3 = 1;
    PE4 = 1;
    PE5 = 1;
    PE6 = 1;
    PE7 = 1;

    // 1
    PC4 = 1;
    PE0 = 0;
    PE1 = 1;
    PE2 = 1;
    PE3 = 1;
    PE4 = 0;
    PE5 = 1;
    PE6 = 1;
    PE7 = 1;
    CLK_SysTickDelay(1000000);
    PC4 = 0;
    PE0 = 1;
    PE1 = 1;
    PE2 = 1;
    PE3 = 1;
    PE4 = 1;
    PE5 = 1;
    PE6 = 1;
    PE7 = 1;

    // 2
    PC4 = 1;
    PE0 = 1;
    PE1 = 0;
    PE2 = 1;
    PE3 = 0;
    PE4 = 0;
    PE5 = 0;
    PE6 = 0;
    PE7 = 0;
    CLK_SysTickDelay(1000000);
    PC4 = 0;
    PE0 = 1;
    PE1 = 1;
    PE2 = 1;
    PE3 = 1;
    PE4 = 1;
    PE5 = 1;
    PE6 = 1;
    PE7 = 1;

    // 3
    PC4 = 1;
    PE0 = 0;
    PE1 = 0;
    PE2 = 1;
    PE3 = 0;
    PE4 = 0;
    PE5 = 0;
    PE6 = 1;
    PE7 = 0;
    CLK_SysTickDelay(1000000);
    PC4 = 0;
    PE0 = 1;
    PE1 = 1;
    PE2 = 1;
    PE3 = 1;
    PE4 = 1;
    PE5 = 1;
    PE6 = 1;
    PE7 = 1;

    // 4
    PC4 = 1;
    PE0 = 0;
    PE1 = 0;
    PE2 = 0;
    PE3 = 1;
    PE4 = 0;
    PE5 = 1;
    PE6 = 1;
    PE7 = 0;
    CLK_SysTickDelay(1000000);
    PC4 = 0;
    PE0 = 1;
    PE1 = 1;
    PE2 = 1;
    PE3 = 1;
    PE4 = 1;
    PE5 = 1;
    PE6 = 1;
    PE7 = 1;

    // 5
    PC4 = 1;
    PE0 = 0;
    PE1 = 0;
    PE2 = 0;
    PE3 = 0;
    PE4 = 1;
    PE5 = 0;
    PE6 = 1;
    PE7 = 0;
    CLK_SysTickDelay(1000000);
    PC4 = 0;
    PE0 = 1;
    PE1 = 1;
    PE2 = 1;
    PE3 = 1;
    PE4 = 1;
    PE5 = 1;
    PE6 = 1;
    PE7 = 1;

    // 6
    PC4 = 1;
    PE0 = 0;
    PE1 = 0;
    PE2 = 0;
    PE3 = 0;
    PE4 = 1;
    PE5 = 0;
    PE6 = 0;
    PE7 = 0;
    CLK_SysTickDelay(1000000);
    PC4 = 0;
    PE0 = 1;
    PE1 = 1;
    PE2 = 1;
    PE3 = 1;
    PE4 = 1;
    PE5 = 1;
    PE6 = 1;
    PE7 = 1;

    // 7
    PC4 = 1;
    PE0 = 0;
    PE1 = 1;
    PE2 = 0;
    PE3 = 0;
    PE4 = 0;
    PE5 = 1;
    PE6 = 1;
    PE7 = 1;
    CLK_SysTickDelay(1000000);
    PC4 = 0;
    PE0 = 1;
    PE1 = 1;
    PE2 = 1;
    PE3 = 1;
    PE4 = 1;
    PE5 = 1;
    PE6 = 1;
    PE7 = 1;

    // 8
    PC4 = 1;
    PE0 = 0;
    PE1 = 0;
    PE2 = 0;
    PE3 = 0;
    PE4 = 0;
    PE5 = 0;
    PE6 = 0;
    PE7 = 0;
    CLK_SysTickDelay(1000000);
    PC4 = 0;
    PE0 = 1;
    PE1 = 1;
    PE2 = 1;
    PE3 = 1;
    PE4 = 1;
    PE5 = 1;
    PE6 = 1;
    PE7 = 1;

    // 9
    PC4 = 1;
    PE0 = 0;
    PE1 = 0;
    PE2 = 0;
    PE3 = 0;
    PE4 = 0;
    PE5 = 0;
    PE6 = 1;
    PE7 = 0;
    CLK_SysTickDelay(1000000);
    PC4 = 0;
    PE0 = 1;
    PE1 = 1;
    PE2 = 1;
    PE3 = 1;
    PE4 = 1;
    PE5 = 1;
    PE6 = 1;
    PE7 = 1;

    /*
    PC5 = 1;
    PE4 = 0;
    CLK_SysTickDelay(1000000);
    PC5 = 0;
    PE4 = 1;

    PC5 = 1;
    PE3 = 0;
    CLK_SysTickDelay(1000000);
    PC5 = 0;
    PE3 = 1;

    PC5 = 1;
    PE2 = 0;
    CLK_SysTickDelay(1000000);
    PC5 = 0;
    PE2 = 1;

    PC5 = 1;
    PE6 = 0;
    CLK_SysTickDelay(1000000);
    PC5 = 0;
    PE6 = 1;

    PC5 = 1;
    PE5 = 0;
    CLK_SysTickDelay(1000000);
    PC5 = 0;
    PE5 = 1;
    */
  }

  /*while(1)
  {
          PC4 = 1;
          PE0 = 0;
          CLK_SysTickDelay(1000000);
          PC4 = 0;
          PE0 = 1;

          PC5 = 1;
          PE6 = 0;
          CLK_SysTickDelay(1000000);
          PC5 = 0;
          PE6 = 1;

          PC6 = 1;
          PE4 = 0;
          CLK_SysTickDelay(1000000);
          PC6 = 0;
          PE4 = 1;

          PC7 = 1;
          PE2 = 0;
          CLK_SysTickDelay(1000000);
          PC7 = 0;
          PE2 = 1;
  }*/
}

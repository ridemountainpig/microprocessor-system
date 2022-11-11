//
// GPIO_7seg_keypad : 3x3 keypad inpt and display on 7-segment LEDs
//
#include <stdio.h>

#include "MCU_init.h"
#include "NUC100Series.h"
#include "SYS_init.h"
#include "Scankey.h"
#include "Seven_Segment.h"

// display an integer on four 7-segment LEDs
void Show(uint16_t value) {
  switch (value) {
    case 0:
      // 0
      PC4 = 1;
      PE0 = 0;

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
      break;
    case 1:
      // 1
      PC4 = 1;
      PE0 = 0;

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
      break;
    case 2:
      // 2
      PC4 = 1;
      PE0 = 1;

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
      break;
    case 3:
      // 3
      PC4 = 1;
      PE0 = 0;

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
      break;
    case 4:
      // 4
      PC4 = 1;
      PE0 = 0;

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
      break;
    case 5:
      // 5
      PC4 = 1;
      PE0 = 0;

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
      break;
    case 6:
      // 6
      PC4 = 1;
      PE0 = 0;

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
      break;
    case 7:
      // 7
      PC4 = 1;
      PE0 = 0;

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
      break;
    case 8:
      // 8
      PC4 = 1;
      PE0 = 0;

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
      break;
    case 9:
      // 9
      PC4 = 1;
      PE0 = 0;

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
      break;
  }
}

/*
 3
2 4
 7
6 0
 5
*/

int lightNumber;
int lightPlace;

int main(void) {
  uint16_t i;

  SYS_Init();

  OpenSevenSegment();
  OpenKeyPad();

  while (1) {
    i = ScanKey();
    Show(i);
  }

  PC4 = 0;
  PC5 = 0;
  PC6 = 0;
  PC7 = 0;

  PC4 = 1;
  PE4 = 0;
  lightNumber = 4;
  lightPlace = 4;

  while (0) {
    i = ScanKey();
    CLK_SysTickDelay(100000);

    if (i == 2) {
      switch (lightPlace) {
        case 0:
          PE0 = 1;
          PE4 = 0;
          lightPlace = 4;
          break;
        case 2:
          PE2 = 1;
          PE3 = 0;
          CLK_SysTickDelay(100000);
          lightPlace = 3;
          break;
        case 3:
          PE3 = 1;
          PE5 = 0;
          CLK_SysTickDelay(100000);
          lightPlace = 5;
          break;
        case 4:
          PE4 = 1;
          PE3 = 0;
          CLK_SysTickDelay(100000);
          lightPlace = 3;
          break;
        case 5:
          PE5 = 1;
          PE7 = 0;
          CLK_SysTickDelay(100000);
          lightPlace = 7;
          break;
        case 6:
          PE6 = 1;
          PE2 = 0;
          CLK_SysTickDelay(100000);
          lightPlace = 2;
          break;
        case 7:
          PE7 = 1;
          PE3 = 0;
          CLK_SysTickDelay(100000);
          lightPlace = 3;
          break;
      }
    }

    if (i == 8) {
      switch (lightPlace) {
        case 0:
          PE0 = 1;
          PE5 = 0;
          lightPlace = 5;
          break;
        case 2:
          PE2 = 1;
          PE6 = 0;
          CLK_SysTickDelay(100000);
          lightPlace = 6;
          break;
        case 3:
          PE3 = 1;
          PE7 = 0;
          CLK_SysTickDelay(100000);
          lightPlace = 7;
          break;
        case 4:
          PE4 = 1;
          PE0 = 0;
          CLK_SysTickDelay(100000);
          lightPlace = 0;
          break;
        case 5:
          PE5 = 1;
          PE3 = 0;
          CLK_SysTickDelay(100000);
          lightPlace = 3;
          break;
        case 6:
          PE6 = 1;
          PE5 = 0;
          CLK_SysTickDelay(100000);
          lightPlace = 5;
          break;
        case 7:
          PE7 = 1;
          PE5 = 0;
          CLK_SysTickDelay(100000);
          lightPlace = 5;
          break;
      }
    }

    if (i == 4) {
      switch (lightPlace) {
        case 0:
          PE0 = 1;
          PE6 = 0;
          lightPlace = 6;
          break;
        case 2:
          PE2 = 1;
          if (lightNumber == 4) {
            PC4 = 0;
          }
          if (lightNumber == 5) {
            PC5 = 0;
          }
          if (lightNumber == 6) {
            PC6 = 0;
          }
          if (lightNumber == 7) {
            PC7 = 0;
          }

          lightNumber++;
          if (lightNumber > 7) {
            lightNumber = 4;
          }

          if (lightNumber == 4) {
            PC4 = 1;
          }
          if (lightNumber == 5) {
            PC5 = 1;
          }
          if (lightNumber == 6) {
            PC6 = 1;
          }
          if (lightNumber == 7) {
            PC7 = 1;
          }

          PE4 = 0;
          CLK_SysTickDelay(100000);
          lightPlace = 4;
          break;
        case 3:
          PE3 = 1;
          PE2 = 0;
          CLK_SysTickDelay(100000);
          lightPlace = 2;
          break;
        case 4:
          PE4 = 1;
          PE2 = 0;
          CLK_SysTickDelay(100000);
          lightPlace = 2;
          break;
        case 5:
          PE5 = 1;
          PE6 = 0;
          CLK_SysTickDelay(100000);
          lightPlace = 6;
          break;
        case 6:
          PE6 = 1;

          if (lightNumber == 4) {
            PC4 = 0;
          }
          if (lightNumber == 5) {
            PC5 = 0;
          }
          if (lightNumber == 6) {
            PC6 = 0;
          }
          if (lightNumber == 7) {
            PC7 = 0;
          }

          lightNumber++;
          if (lightNumber > 7) {
            lightNumber = 4;
          }

          if (lightNumber == 4) {
            PC4 = 1;
          }
          if (lightNumber == 5) {
            PC5 = 1;
          }
          if (lightNumber == 6) {
            PC6 = 1;
          }
          if (lightNumber == 7) {
            PC7 = 1;
          }

          PE0 = 0;
          CLK_SysTickDelay(100000);
          lightPlace = 0;
          break;
      }
    }

    if (i == 6) {
      switch (lightPlace) {
        case 0:
          PE0 = 1;

          if (lightNumber == 4) {
            PC4 = 0;
          }
          if (lightNumber == 5) {
            PC5 = 0;
          }
          if (lightNumber == 6) {
            PC6 = 0;
          }
          if (lightNumber == 7) {
            PC7 = 0;
          }

          lightNumber--;
          if (lightNumber < 4) {
            lightNumber = 7;
          }

          if (lightNumber == 4) {
            PC4 = 1;
          }
          if (lightNumber == 5) {
            PC5 = 1;
          }
          if (lightNumber == 6) {
            PC6 = 1;
          }
          if (lightNumber == 7) {
            PC7 = 1;
          }

          PE6 = 0;
          lightPlace = 6;
          break;
        case 2:
          PE2 = 1;
          PE4 = 0;
          CLK_SysTickDelay(100000);
          lightPlace = 4;
          break;
        case 3:
          PE3 = 1;
          PE4 = 0;
          CLK_SysTickDelay(100000);
          lightPlace = 4;
          break;
        case 4:
          PE4 = 1;

          if (lightNumber == 4) {
            PC4 = 0;
          }
          if (lightNumber == 5) {
            PC5 = 0;
          }
          if (lightNumber == 6) {
            PC6 = 0;
          }
          if (lightNumber == 7) {
            PC7 = 0;
          }

          lightNumber--;
          if (lightNumber < 4) {
            lightNumber = 7;
          }

          if (lightNumber == 4) {
            PC4 = 1;
          }
          if (lightNumber == 5) {
            PC5 = 1;
          }
          if (lightNumber == 6) {
            PC6 = 1;
          }
          if (lightNumber == 7) {
            PC7 = 1;
          }

          PE2 = 0;
          CLK_SysTickDelay(100000);
          lightPlace = 2;
          break;
        case 5:
          PE5 = 1;
          PE0 = 0;
          CLK_SysTickDelay(100000);
          lightPlace = 0;
          break;
        case 6:
          PE6 = 1;
          PE0 = 0;
          CLK_SysTickDelay(100000);
          lightPlace = 0;
          break;
      }
    }
  }
}
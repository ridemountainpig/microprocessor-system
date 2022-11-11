//
// LCD_Bmp_Keypad: use 3x3 keypad to move bitmap on LCD
//
#include <stdio.h>

#include "LCD.h"
#include "MCU_init.h"
#include "NUC100Series.h"
#include "SYS_init.h"
#include "Scankey.h"
/*
unsigned char bmp16x16[256] = {
        0x00,0x00,0x40,0xE0,0xE0,0xE0,0xE0,0x70,0x7C,0xFE,0xF8,0x80,0x80,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x01,0x03,0x7F,0x3E,0x1E,0x07,0x07,0x07,0x03,0x03,0x02,0x00,
};
*/
unsigned char bmp16x16[32] = {0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
                              0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF,
                              0xFF, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
                              0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xFF};

void Buzz(void) {
  PB11 = 0;
  CLK_SysTickDelay(50000);
  PB11 = 1;
}
int dx = 0, dy = 0, px, py;
int check = 0;
int main(void) {
  int8_t x = 1, y = 1;
  int8_t keyin = 0;

  SYS_Init();
  init_LCD();
  clear_LCD();
  OpenKeyPad();
  PD14 = 0;

  while (1) {
    keyin = ScanKey();

    if (keyin == 2) {
      dx = 0;
      dy = -1;
    } else if (keyin == 4) {
      dx = -1;
      dy = 0;
    } else if (keyin == 6) {
      dx = 1;
      dy = 0;
    } else if (keyin == 8) {
      dx = 0;
      dy = 1;
    } else if (keyin == 5) {
      if (check == 0) {
        px = dx;
        py = dy;
        dx = 0;
        dy = 0;
        check = 1;
      } else {
        dx = px;
        dy = py;
        check = 0;
      }
    }

    if (x < 1) {
      Buzz();
      dx = 1;
    }
    if (x > 111) {
      Buzz();
      dx = -1;
    }
    if (y < 1) {
      Buzz();
      dy = 1;
    }
    if (y > 46) {
      Buzz();
      dy = -1;
    }

    x += dx;
    y += dy;

    draw_Bmp16x16(x, y, FG_COLOR, FG_COLOR, bmp16x16);
    CLK_SysTickDelay(500000);
    draw_Bmp16x16(x, y, BG_COLOR, BG_COLOR, bmp16x16);
    /*
    x = 64;
    y = 32;
    draw_Bmp16x16(x,y,FG_COLOR,FG_COLOR,bmp16x16);
    CLK_SysTickDelay(1000000);
    clear_LCD();
    x = 32;
    y = 32;
    draw_Bmp16x16(x,y,FG_COLOR,BG_COLOR,bmp16x16);
    CLK_SysTickDelay(1000000);
    clear_LCD();
    */
  }
}

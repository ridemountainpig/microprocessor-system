//
// TMR_Capture_SR04 : usi[ng Timer Capture to read Ultrasound Ranger SR-04
//
// EVB : Nu-LB-NUC140 (need to manually switch RSTCAPSEL)
// MCU : NUC140VE3CN
// Sensor: SR-04

// SR-04 connection
// Trig connected to PB8
// Echo connected to TC2/PB2 (TC0_PB15, TC1_PE5, TC2_PB2, TC3_PB3)

#include "LCD.h"
#include "MCU_init.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NUC100Series.h"
#include "SYS_init.h"

void Init_UART(void) {
  UART_Open(UART0, 9600);  // set UART0 baud rate
}

char Text[16];

unsigned char bmp16x16[32] = {0x00, 0x00, 0x40, 0xE0, 0xE0, 0xE0, 0xE0, 0x70,
                              0x7C, 0xFE, 0xF8, 0x80, 0x80, 0x00, 0x00, 0x00,
                              0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x7F, 0x3E,
                              0x1E, 0x07, 0x07, 0x07, 0x03, 0x03, 0x02, 0x00};

unsigned char bmp2_16x16[32] = {
    0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x7F, 0x3E, 0x1E, 0x07, 0x07,
    0x07, 0x03, 0x03, 0x02, 0x00, 0x00, 0x00, 0x40, 0xE0, 0xE0, 0xE0,
    0xE0, 0x70, 0x7C, 0xFE, 0xF8, 0x80, 0x80, 0x00, 0x00, 0x00

};

void Init_ADC(void) {
  ADC_Open(ADC, ADC_INPUT_MODE, ADC_OPERATION_MODE, ADC_CHANNEL_MASK);
  ADC_POWER_ON(ADC);
}

int32_t main(void) {
  char RX_Buffer[16];
  const char* d = ",";
  char* p;
  int img = 0;
  uint32_t x, y, z;
  SYS_Init();
  Init_ADC();
  init_LCD();
  clear_LCD();
  Init_UART();

  PD14 = 0;

  sprintf(RX_Buffer, "TX123");

  // print_Line(0, "VR");

  while (1) {
    UART_Read(UART0, RX_Buffer, 11);
    UART_Write(UART0, "Wait", 4);
    p = strtok(RX_Buffer, d);
    x = atoi(p);
    p = strtok(NULL, d);
    y = atoi(p);
    p = strtok(NULL, d);
    img = (img + atoi(p) + 1) % 2;
    x *= 0.017;
    if (x > 56) x += (x - 56) * 3.35;
    y *= 0.0075;
    if (y > 24) y += (y - 24) * 3.1;
    draw_Bmp16x16(x, y, FG_COLOR, FG_COLOR, bmp16x16);
    if (img == 0) {
      draw_Bmp16x16(x, y, FG_COLOR, FG_COLOR, bmp16x16);
    } else {
      draw_Bmp16x16(x, y, FG_COLOR, FG_COLOR, bmp2_16x16);
    }
    CLK_SysTickDelay(100000);
    clear_LCD();
  }
}

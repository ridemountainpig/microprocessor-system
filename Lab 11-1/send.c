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
#include <string.h>

#include "LCD.h"
#include "MCU_init.h"
#include "NUC100Series.h"
#include "SYS_init.h"

void Init_UART(void) {
  UART_Open(UART0, 9600);  // set UART0 baud rate
}

char Text[16];

void Init_ADC(void) {
  ADC_Open(ADC, ADC_INPUT_MODE, ADC_OPERATION_MODE, ADC_CHANNEL_MASK);
  ADC_POWER_ON(ADC);
}

int32_t main(void) {
  char RX_Buffer[100], X_Buffer[100], Y_Buffer[100], Z_Buffer[100];
  uint32_t x, y, z;
  SYS_Init();
  Init_ADC();
  init_LCD();
  clear_LCD();
  Init_UART();

  PD14 = 0;

  print_Line(0, "VR");

  while (1) {
    ADC_START_CONV(ADC);
    x = ADC_GET_CONVERSION_DATA(ADC, 0);
    y = ADC_GET_CONVERSION_DATA(ADC, 1);
    z = PC12;
    sprintf(X_Buffer, "%d", x);
    sprintf(Y_Buffer, "%d", y);
    sprintf(Z_Buffer, "%d", z);
    strcat(X_Buffer, ",");
    strcat(X_Buffer, Y_Buffer);
    strcat(X_Buffer, ",");
    strcat(X_Buffer, Z_Buffer);

    UART_Write(UART0, X_Buffer, 11);
    UART_Read(UART0, RX_Buffer, 4);

    sprintf(Text, "T = %5d", x);
    print_Line(1, Text);
    sprintf(Text, "T = %5d", y);
    print_Line(2, Text);
    sprintf(Text, "T = %5d", z);
    print_Line(3, Text);
  }
}

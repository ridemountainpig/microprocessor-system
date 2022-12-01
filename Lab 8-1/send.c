//
// UART0_RX : UART0 RX recieve and display Text
//
// Board : Nu-LB-NUC140
// MCU : NUC140VE3CN (LQFP100)
// UART0 : baudrate=115200, databit=8, stopbit=1, paritybit=0, flowcontrol=None

#include <math.h>
#include <stdio.h>
#include <string.h>

#include "MCU_init.h"
#include "NUC100Series.h"
#include "SYS_init.h"
#include "Scankey.h"
#include "LCD.h"

void Init_UART(void) {
  UART_Open(UART0, 9600);  // set UART0 baud rate
}

int32_t main() {
  char TX_Buffer[16];
  char RX_Buffer[16];
  uint32_t keyin = 0;

  SYS_Init();
  init_LCD();
  clear_LCD();
  Init_UART();

  PD14 = 0;
  print_Line(0, "test TX and RX:");

  while (1) {
    keyin = ScanKey();
    sprintf(TX_Buffer, "%d", keyin);

    if (keyin != 0) {
      print_Line(1, TX_Buffer);
      UART_Write(UART0, TX_Buffer, 1);
    }
  }
}

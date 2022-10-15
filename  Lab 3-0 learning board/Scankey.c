/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright (c) Nuvoton Technology Corp. All rights reserved. */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "Scankey.h"

#include <NUC100Series.h>
#include <stdio.h>

#include "GPIO.h"
#include "SYS_init.h"

void delay(void) {
  int j;
  for (j = 0; j < 1000; j++)
    ;
}

void OpenKeyPad(void) {
  GPIO_SetMode(PA, BIT0, GPIO_MODE_QUASI);
  GPIO_SetMode(PA, BIT1, GPIO_MODE_QUASI);
  GPIO_SetMode(PA, BIT2, GPIO_MODE_QUASI);
  GPIO_SetMode(PA, BIT3, GPIO_MODE_QUASI);
  GPIO_SetMode(PA, BIT4, GPIO_MODE_QUASI);
  GPIO_SetMode(PA, BIT5, GPIO_MODE_QUASI);
}

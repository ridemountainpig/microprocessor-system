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
#include "NUC100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "LCD.h"

unsigned char bmp16x16[256] = {
    0x00,0x00,0x40,0xE0,0xE0,0xE0,0xE0,0x70,0x7C,0xFE,0xF8,0x80,0x80,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x01,0x03,0x7F,0x3E,0x1E,0x07,0x07,0x07,0x03,0x03,0x02,0x00,
};


char Text[16];

void Init_ADC(void)
{
    ADC_Open(ADC, ADC_INPUT_MODE, ADC_OPERATION_MODE, ADC_CHANNEL_MASK);
    ADC_POWER_ON(ADC);
}

int32_t main(void)
{
    float xx;
    float yy;
    uint32_t x, y, z;
    SYS_Init();
    Init_ADC();
    init_LCD();
    clear_LCD();

    PD14 = 0;

    //print_Line(0, "VR");

    while (1)
    {
        ADC_START_CONV(ADC);
        x = ADC_GET_CONVERSION_DATA(ADC, 0);
        y = ADC_GET_CONVERSION_DATA(ADC, 1);
        z = PB0;

        if (x > 3200 && x < 3400 && y > 3200 && y < 3400)
        {
            clear_LCD();
            draw_Bmp16x16(56, 26, FG_COLOR, BG_COLOR, bmp16x16);
        }
        else
        {
            xx = x / 40 - 27;
            yy = y / 50 - 33;
            if (x > 3360 && x < 3400)
                xx -= 27;
            else if (x > 3400)
                xx += 36;
            clear_LCD();
            draw_Bmp16x16(xx, yy, FG_COLOR, BG_COLOR, bmp16x16);
        }
        /*
			sprintf(Text,"Tx = %5d", x);
	    print_Line(1, Text);
      
			sprintf(Text,"Ty = %5d", y);
	    print_Line(2, Text);
			
	    sprintf(Text,"T = %5d", z);
	    print_Line(3, Text);
      */
    }
}

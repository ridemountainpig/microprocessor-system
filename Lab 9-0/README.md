### This lab using GB0 and GB1 to send string message between each other.
### And use message to play tic tac toe

---

#### UART need to define in [MCU_init.h](https://github.com/ridemountainpig/microprocessor-system/blob/main/Libaray/MCU_init.h)

```
// Define UART READ WRTIE
#define MCU_INTERFACE_UART0
#define UART_CLOCK_SOURCE_HXT // HXT, LXT, PLL, HIRC
#define UART_CLOCK_DIVIDER     3
#define PIN_UART0_RX_PB0
#define PIN_UART0_TX_PB1
```

#include "stm8s.h"
#include "peripheral.h"

int main()
{
  CLK_SYSCLKConfig(CLK_PRESCALER_HSIDIV8); // select Clock = 2 MHz
  CLK_HSICmd(ENABLE);

  LED_Init();
  TIM4_Config();

  while(1){
    GPIO_WriteLow(LED_GPIO_PORT, (GPIO_Pin_TypeDef)LED_POSITIVE_GPIO_PINS);
    waitMs(BLINK_TIME);
    GPIO_WriteHigh(LED_GPIO_PORT, (GPIO_Pin_TypeDef)LED_POSITIVE_GPIO_PINS);
    waitMs(PERIOD - BLINK_TIME);
  }
}

#ifdef USE_FULL_ASSERT
void assert_failed(u8* file, u32 line) { while (1) {}; };
#endif
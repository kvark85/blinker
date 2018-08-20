#include "stm8s.h"
#include "peripheral.h"

int main()
{
  CLK_SYSCLKConfig(CLK_PRESCALER_HSIDIV8); // select Clock = 2 MHz
  CLK_HSICmd(ENABLE);

  LED_Init();
  TIM4_Config();

  while(1){
    INVERT_LED();
    waitMs(2000);
  }
}

#ifdef USE_FULL_ASSERT
void assert_failed(u8* file, u32 line) { while (1) {}; };
#endif
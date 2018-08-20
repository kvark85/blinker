/*
                        ИНИЦИАЛИЗАЦИЯ ПЕРИФЕРИИ
                               STM8F103				
                              12.07.2013
                                    */

#include "peripheral.h"

uint16_t msVar = 0;

//******************************************************************************
//-------------------------     led initialization     -------------------------
//******************************************************************************
void LED_Init(void) {
  GPIO_Init(LED_GPIO_PORT, (GPIO_Pin_TypeDef)LED_POSITIVE_GPIO_PINS, GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(LED_GPIO_PORT, (GPIO_Pin_TypeDef)LED_NEGATIVE_PINS, GPIO_MODE_OUT_PP_LOW_FAST);
}

//******************************************************************************
//-------------------------     TIM4 configuration     -------------------------
//******************************************************************************
void TIM4_Config(void)
{ /*
  - TIM4CLK is set to 2 MHz, the TIM4 Prescaler is equal to 16 so the TIM1 counter
   clock used is 1 MHz / 16 = 125000 Hz
  - With 125000 Hz we can generate time base:
  - We need to generate a time base equal to 1 ms
   so TIM4_PERIOD = (0.001 * 125000 - 1) = 124 */

  /* Time base configuration */
  TIM4_TimeBaseInit(TIM4_PRESCALER_16, TIM4_PERIOD);
  /* Clear TIM4 update flag */
  TIM4_ClearFlag(TIM4_FLAG_UPDATE);
  /* Enable update interrupt */
  TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);
  
  /* enable interrupts */
  enableInterrupts();

  /* Enable TIM4 */
  TIM4_Cmd(ENABLE);
}

//******************************************************************************
//------------------------------     ms delay     ------------------------------
//******************************************************************************
void waitMs(uint16_t val) {
  msVar = val;
  while(msVar);
}

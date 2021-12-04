/*
                        ИНИЦИАЛИЗАЦИЯ ПЕРИФЕРИИ
                               STM8F103
                              12.07.2013
                                    */

#ifndef _peripheral_
#define _peripheral_

#include "stm8s.h"   

#define TIM4_PERIOD             124

#define PERIOD                  2000
#define BLINK_TIME              200

//***************************************************************************//
//-----------------------------     LED START     ---------------------------//
//***************************************************************************//
#define LED_GPIO_PORT           GPIOD
#define LED_POSITIVE_GPIO_PINS  GPIO_PIN_5
#define LED_NEGATIVE_PINS       GPIO_PIN_4
#define INVERT_LED()            GPIO_WriteReverse(LED_GPIO_PORT, (GPIO_Pin_TypeDef)LED_POSITIVE_GPIO_PINS)


//***************************************************************************//
//-------------------------     function defines     ------------------------//
//***************************************************************************//
void LED_Init(void);
void TIM4_Config(void);
void waitMs(uint16_t);

#endif
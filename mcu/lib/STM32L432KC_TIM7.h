// STM32L432KC_TIM7.h
// Rebecca Kong
// rkong@hmc.edu
// 9/29/2026
// Header for TIM7 functions

#ifndef STM32L4_TIM7_H
#define STM32L4_TIM7_H

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

#define __IO volatile

// Base addresses
#define TIM7_BASE (0x40001400) // base address of TIM7


/**
  * @brief Reset and Clock Control
  */

typedef struct
{
  __IO uint32_t CR1;              /*!< TIM6 clock control register 1,                                 Address offset: 0x00 */
  __IO uint32_t CR2;              /*!< TIM6 clock control register 2,                                 Address offset: 0x04 */
  uint32_t      RESERVED;         /*!< Reserved,                                                      Address offset: 0x08 */
  __IO uint32_t DIER;             /*!< TIM6 interrupt enable register,                                Address offset: 0x0C */
  __IO uint32_t SR;               /*!< TIM6 status register,                                          Address offset: 0x10 */
  __IO uint32_t EGR;              /*!< TIM6 event generation register,                                Address offset: 0x14 */
  uint32_t      RESERVED;         /*!< Reserved,                                                      Address offset: 0x18 */
  __IO uint32_t CNT;              /*!< TIM6 counter,                                                  Address offset: 0x24 */
  __IO uint32_t PSC;              /*!< TIM6 prescaler,                                                Address offset: 0x28 */
  __IO uint32_t ARR;              /*!< TIM6 auto-reload register,                                     Address offset: 0x2C */                      
} TIM7_TypeDef;

#define TIM7 ((TIM7_TypeDef *) TIM7_BASE)

///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////

void enablePitch(void);
void runPitch(int frequency);

#endif
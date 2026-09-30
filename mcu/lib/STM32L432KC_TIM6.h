// STM32L432KC_TIM6.h
// Rebecca Kong
// rkong@hmc.edu
// 9/29/2026
// Header for TIM6 functions

#ifndef STM32L4_TIM6_H
#define STM32L4_TIM6_H

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

#define __IO volatile

// Base addresses
#define TIM6_BASE (0x40001000) // base address of TIM6


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
} TIM6_TypeDef;

#define TIM6 ((TIM6_TypeDef *) TIM6_BASE)

///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////

void enableDuration(void);
void runDuration(int duration);

#endif
// STM32L432KC_TIM6.c
// Source code for TIM6 functions
// Duration Timer (ms)

// shadow register is like one clk signal of buffer
#include "STM32L432KC_TIM6.h"

void enableHSI16(void) {
  // Turn on the HSI16 oscillator
  RCC->CR |= (1 << 8);
  //  Wait until the hardware reports that HSI16 is ready (stable)
  while ((RCC->CR >> 10 & 1) != 0);
}


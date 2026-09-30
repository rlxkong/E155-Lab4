// STM32L432KC_TIM6.c
// Rebecca Kong
// rkong@hmc.edu
// 9/29/2026
// Source code for TIM6 functions
// Duration Timer (ms)

#include "STM32L432KC_TIM6.h"
#include "STM32L432KC_RCC.h"

void enableDuration(void) {
    // Enable TIM6 on upper levels
    RCC->APB1ENR1 |= (1 << 4);

    // Use prescaler to make each period 1ms long 
    // Go from 4 MHz down to 1 kHz (divide by 4000-1)
    TIM6->PSC = 3999;

    // Auto-reload preload enable (shadow register acting as one clk signal of buffer)
    TIM6->CR1 |= (1 << 7);

    // Updates registers and resets counter given an overflow
    // Forces new prescaler and auto-reload values
    TIM6->EGR |= (1 << 0);

    // Since EGR forces update UIF is auto set to 1
    // Need to write 0 to prevent unnecessary interrupt flag
    TIM6->SR &= ~(1 << 0);

    // Internally enable counter
    TIM6->CR1 |= (1 << 0);
}

void runDuration(int duration){
    // Set ARR for given note
    // Subtract 1 as it takes one clock cycle to run
    TIM6->ARR = duration - 1;

    // Run UG in EGR to register event and restart ARR
    TIM6->EGR |= (1 << 0);

    // Since EGR forces update UIF is auto set to 1
    // Need to write 0 to prevent unnecessary interrupt flag
    TIM6->SR &= ~(1 << 0);

    // Internally enable counter
    TIM6->CR1 |= (1 << 0);   
}


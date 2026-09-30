// STM32L432KC_TIM7.c
// Rebecca Kong
// rkong@hmc.edu
// 9/29/2026
// Source code for TIM7 functions
// Pitch in Hz

// shadow register is like one clk signal of buffer
#include "STM32L432KC_TIM7.h"
#include "STM32L432KC_RCC.h"
#include <stdint.h>

void enablePitch(void) {
    // Enable TIM7 on upper levels
    RCC->APB1ENR1 |= (1 << 5);

    // Auto-reload preload enable (shadow register acting as one clk signal of buffer)
    TIM7->CR1 |= (1 << 7);

    // Updates registers and resets counter given an overflow
    // Forces new prescaler and auto-reload values
    TIM7->EGR |= (1 << 0);

    // Since EGR forces update UIF is auto set to 1
    // Need to write 0 to prevent unnecessary interrupt flag
    TIM7->SR &= ~(1 << 0);

    // Internally enable counter
    TIM7->CR1 |= (1 << 0);
}

void runPitch(int frequency) {
    uint32_t note_count = 0;

    if (frequnecy != 0){
        note_count = 4000000 / (2 * frequency);
    }

    // Set ARR for given note
    // Subtract 1 as it takes one clock cycle to run
    TIM6->ARR = note_count - 1;

    // Run UG in EGR to register event and restart ARR
    TIM6->EGR |= (1 << 0);

    // Since EGR forces update UIF is auto set to 1
    // Need to write 0 to prevent unnecessary interrupt flag
    TIM6->SR &= ~(1 << 0);

    // Internally enable counter
    TIM6->CR1 |= (1 << 0);   
}
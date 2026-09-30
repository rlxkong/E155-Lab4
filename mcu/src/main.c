// lab4_main.c
// Rebecca Kong
// rkong@hmc.edu
// 9/29/2026
// Fur Elise, E155 Lab 4


#include <stdio.h>
#include <stdlib.h>
// Include the device header
#include <stm32l432xx.h>

// RM headers
#include "STM32L432KC_GPIO.h"
#include "STM32L432KC_RCC.h"
#include "STM32L432KC_FLASH.h"

#define PIN_OUT 3 // PB3: green user LED (LD3) on the Nucleo-L432KC



// Pitch in Hz, duration in ms
const int notes[][2] = {
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{416,	125},
{494,	125},
{523,	250},
{  0,	125},
{330,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{523,	125},
{494,	125},
{440,	250},
{  0,	125},
{494,	125},
{523,	125},
{587,	125},
{659,	375},
{392,	125},
{699,	125},
{659,	125},
{587,	375},
{349,	125},
{659,	125},
{587,	125},
{523,	375},
{330,	125},
{587,	125},
{523,	125},
{494,	250},
{  0,	125},
{330,	125},
{659,	125},
{  0,	250},
{659,	125},
{1319,	125},
{  0,	250},
{623,	125},
{659,	125},
{  0,	250},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{416,	125},
{494,	125},
{523,	250},
{  0,	125},
{330,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{523,	125},
{494,	125},
{440,	500},
{  0,	0}};

int main(void) {
  configureFlash();

  // Turn on clock to GPIOB
  RCC->AHB2ENR |= (1 << 1);

  // initialize duration and pitch
  enableDuration();
  enablePitch();

  // Set PIN_OUT as output
  pinMode(PIN_OUT, GPIO_OUTPUT);

  // Output notes as waves
  int score_length = sizeof(notes)/sizeof(notes[0]);
  for(int i = 0; i < score_length; i++){
    // play each note for a given duration
    runDuration(notes[i][1]);

    // check that SR is 0 meaning no interrupt is pending
    while (!((TIM6->SR >> 0) & 1)){
      // play the corresponding frequency
      runPitch(notes[i][0]);
      while (!((TIM7->SR >> 0) & 1)){
        // output note
        togglePin(PIN_OUT);
      }
    }
  }

  return 0;
	
}


/*************************** End of file ****************************/
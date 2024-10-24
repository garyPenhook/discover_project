

           

#include "stm32f030x8.h"


void delay(volatile uint32_t delay);

int main(void) {
    // Enable the clock for GPIOC (bit 19 in RCC_AHBENR)
    RCC->AHBENR |= RCC_AHBENR_GPIOCEN;

    // Set PC8 as output (MODER8[1:0] = 01)
    GPIOC->MODER &= ~(GPIO_MODER_MODER8_Msk); // Clear current MODER8 setting
    GPIOC->MODER |= (1U << GPIO_MODER_MODER8_Pos); // Set MODER8 to 01 (output)

    // Set PC8 output type to push-pull (OTYPER8 = 0)
    GPIOC->OTYPER &= ~(GPIO_OTYPER_OT_8);

    // Set PC8 output speed to low (OSPEEDR8 = 00)
    GPIOC->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEEDR8_Msk);

    // Disable pull-up/pull-down for PC8 (PUPDR8 = 00)
    GPIOC->PUPDR &= ~(GPIO_PUPDR_PUPDR8_Msk);

    // Main loop
    for(;;) {
        // Toggle PC8 (ODR8)
        GPIOC->ODR ^= GPIO_ODR_8;

        // Simple delay
        delay(100000);
        
    }
}

void delay(volatile uint32_t delay) {
    while(delay--) {
        // Just wait
    }
}

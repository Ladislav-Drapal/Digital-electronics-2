#define LED_GREEN   PB5 // AVR pin where green LED is connected
#define SHORT_DELAY 500 // Delay in milliseconds
#define LONG_DELAY  2000// Delay in milliseconds
#define STOP_DELAY  1000// Delay in milliseconds
#ifndef F_CPU           // Preprocessor directive allows for conditional
                        // compilation. The #ifndef means "if not defined".
# define F_CPU 16000000 // CPU frequency in Hz required for delay
#endif                  // The #ifndef directive must be closed by #endif

#include <util/delay.h> // Functions for busy-wait delay loops
#include <avr/io.h>     // AVR device-specific IO definitions


int main(void)
{
    // Set pin as output in Data Direction Register
    // DDRB = DDRB or 0010 0000
    DDRB = DDRB | (1<<LED_GREEN);

    // Set pin LOW in Data Register (LED off)
    // PORTB = PORTB and 1101 1111
    PORTB = PORTB & ~(1<<LED_GREEN);

    // Infinite loop
    while (1)
    {
		PORTB = PORTB | (1<<LED_GREEN);
        // Pause several milliseconds – (DOT)
        _delay_ms(SHORT_DELAY);
		
		PORTB = PORTB & ~(1<<LED_GREEN);
		// Pause several milliseconds – (LED – off)
		_delay_ms(STOP_DELAY);
		
		PORTB = PORTB | (1<<LED_GREEN);
        // Pause several milliseconds –  (COMMA)
        _delay_ms(LONG_DELAY);
		
		PORTB = PORTB & ~(1<<LED_GREEN);
		// Pause several milliseconds – (LED – off)
		_delay_ms(STOP_DELAY);
    }

    // Will never reach this
    return 0;
}
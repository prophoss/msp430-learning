/*
 * Polling blinky program using XOR to toggle P1OUT/ on board LED
 * The delay is one I found on google and used to get this one going.
 * Brian Cooper 07-3-20203
 *
 * */

#include <msp430.h> 
/**
 * main.c   Blinky, but without a delay
 */
void _delay_ms(volatile unsigned int length){
    volatile unsigned int delay = 0;
    for(delay = 0; delay < length; delay++){
        _delay_cycles(1000);
    }
}

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	

	P1DIR = 1;                                         // pin direction set as input or output
	 // you must set P1SEL0 and P1SEL1 together to tell it what the pin is meant to do
	// since most pins have more than one function
	P1SEL0= 0;
	P1SEL1 = 0;
	PM5CTL0 &= ~LOCKLPM5;

	while(1)                                     // Forever loop
	{
	    P1OUT =1;
	    _delay_ms(1000);
	    P1OUT ^= P1OUT;
	  u  _delay_ms(1000);

	}
}

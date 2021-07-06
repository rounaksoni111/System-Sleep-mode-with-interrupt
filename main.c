// Sleep_mode_external_interrupt.c
 
 
 /*
#include <avr/sleep.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRB=0XFF;
    while (1) 
    {
		sei();							//Global Interrupt Enable
		MCUCR=(1<<ISC11)|(1<<ISC10);	//Interrupt on rising edge
		GICR=(1<<INT1);					//Local Interrupt (External Interrupt-1 enabled)
		
		PORTB=0XFF;
		_delay_ms(1000);
		PORTB=0;
		_delay_ms(1000);
		
		MCUCR|=(1<<SE);//Sleep enable with idle mode //|(1<<SM1)|(1<<SM0); for Power Saver Mode
		//sleep_enable();
		//set_sleep_mode(SLEEP_MODE_IDLE);
		//sleep_cpu();
		sleep_mode();	// Enter sleep mode.		
    }
}

ISR(INT1_vect)
{
	sleep_disable();
}
*/
 
 
 
 
 
 // Sleep_mode_external_interrupt.c
 
 
 
#include <avr/sleep.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRB=0XFF;
    while (1) 
    {
		sei();							//Global Interrupt Enabled
		MCUCR=(1<<ISC11); //Low Level External interrupt 
		GICR=(1<<INT1);					//Local interrupt enabled
		
		PORTB=0XFF;
		_delay_ms(1000);
		PORTB=0;
		_delay_ms(1000);
		
		MCUCR|=(1<<SE)|(1<<SM1)|(1<<SM0); //for Power Saver Mode
		//sleep_enable();
		//set_sleep_mode(SLEEP_MODE_IDLE);
		//sleep_cpu();
		sleep_mode();	// Now enter sleep mode.
    }
}

ISR(INT1_vect)
{
	sleep_disable();
}
 
 
 
 
 
 
 ///////////////////////////////END OF THE PROGRAM////////////////////////////
 
 
 
 
 

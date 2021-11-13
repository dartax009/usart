#include <avr/io.h>
#include "usart.h"


#ifndef __AVR_ATmega328P__
	#include <avr/iom328p.h>
#endif

void init_usart ()
{
	UCSR0A = 0x02;
	UBRR0H = 0;
	UBRR0L = (uint8_t) 0xCF;
	UCSR0B |= (1<<TXEN0) | (1<<RXEN0) | (1<<RXCIE0);
	UCSR0C |= (1<<USBS0) | (3<<UCSZ00);
}

void write_usart (char *mas, uint16_t n)
{
	for(uint16_t i=0; i<n; i++ )
	{
		while ( !(UCSR0A & (1<<UDRE0)) )
			;

		UDR0 = mas[i];
		if (mas[i] == '\0')
			break;
	}
	return;
}

void read_usart (void *mas, uint16_t n)
{
	for (uint16_t i=0; i<n; i++)
	{
		while ( !(UCSR0A & (1<<RXC0)) )
			;

		((uint8_t*)mas)[i] = UDR0;
	}
	return;
}
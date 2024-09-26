/*
 * Lab6 digital 2.c
 *
 * Created: 25/09/2024 08:44:50
 * Author : diego
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "Librerias/UART.h"
volatile uint8_t uart = 0;


int main(void)
{
	cli();
	init_uart();
	DDRD &= ~((1<<DDD2) | (1<<DDD3) | (1<<DDD4) | (1<<DDD5) | (1<<DDD6) | (1<<DDD7)); //ESTABLECE PB0 COMO ENTRADA (PushBottom1)
	PORTD |= (1<<PORTD2) | (1<<PORTD3) | (1<<PORTD4) | (1<<PORTD5) | (1<<PORTD6) | (1<<PORTD7);
	PCICR |= (1<<PCIE2); //habilitar interrupcion en el pcint0:7
	PCMSK2 |= (1<<PCINT18) | (1<<PCINT19) | (1<<PCINT20) | (1<<PCINT21) | (1<<PCINT22) | (1<<PCINT23);
	sei();
    /* Replace with your application code */
    while (1) 
    {
		if (uart == 1){
			_delay_ms(100);
			uart = 1;
		}
		if(uart == 1){
			if (!(PIND & (1<<PIND2))){
				writeUART('a');
				uart = 0;
			}else if (!(PIND & (1<<PIND3))){
				writeUART('b');
				uart = 0;
			}else if (!(PIND & (1<<PIND4))){
				writeUART('c');
				uart = 0;
			}else if (!(PIND & (1<<PIND5))){
				writeUART('d');
				uart = 0;
			}else if (!(PIND & (1<<PIND6))){
				writeUART('e');
				uart = 0;
			}else if (!(PIND & (1<<PIND7))){
				writeUART('f');
				uart = 0;
			}
		}
		do{
		}while(uart == 0);
    }
}
ISR(PCINT2_vect){
	uart = 1;
}

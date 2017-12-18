#include <avr\io.h>
#include <avr\interrupt.h>
#include <avr\signal.h>

void uart_init(void) {
	// set baud rate
	UBRRH = 0;
	UBRRL = 3;
	// set frame format: 8bit data, 1 stop bit, without parity checker
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	// enable receiver and transmitter
	UCSRB = (1<<TXEN)|(1<<RXEN);
}

void uart_send(char data) {
	// wait for empty transmit buffer
	while((UCSRA&(1<<UDRE))==0);
	// put data into buffer 
	UDR = data;
}

unsigned char uart_check(void){
	// byte checker
	return (UCSRA&(1<<RXC)); // >0 if byte got 
}

unsigned char uart_get(void){
	// return UART data
	return UDR;
}


int main(void) {
	uart_init();
	
	unsigned char c;
	long int i;
	//c = 'A';
	
	while(1) {
		if(uart_check()) {
			c = uart_get();
			if(c = 'A') {
				uart_send(0x01);
			}
			for(i=0; i<40000; i++); // delay		
		}
	}
}





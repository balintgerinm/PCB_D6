


#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <stdlib.h>
#include <util/delay.h>


uint8_t read_pin(uint8_t pin) {
  uint8_t res = !((PINB & (1 << pin)) >> pin);
  _delay_ms(100);
  return res;
}

void doAnimation() {

for (uint8_t i = 0; i < 6; i++) {
 PORTB &= ~(0x0f); 
   switch (rand() % 6) {
          case 0:
            PORTB |= 1 << PORT1; 
            PORTB |= 1 << PORT2; 
            PORTB |= 1 << PORT3; 
            break;
          case 1:
            PORTB |= 1 << PORT0;
            break;
          case 2:
            PORTB |= 1 << PORT1;
            break;
          case 3:
            PORTB |= 1 << PORT2;
            PORTB |= 1 << PORT0;
            break;
          case 4:
            PORTB |= 1 << PORT1;
            PORTB |= 1 << PORT2;
            break;
          case 5:
            PORTB |= 1 << PORT1;
            PORTB |= 1 << PORT2;
            PORTB |= 1 << PORT0;
            break;
          default:
            break;  
          };
          _delay_ms(40);
  }
  PORTB &= ~(0x0f); 
  _delay_ms(100);
}

uint8_t state = 0;
uint32_t cnt = 0;
ISR(PCINT0_vect) {
  
   if (read_pin(PINB4)) {
      doAnimation();  

   }
  else {
          PORTB &= ~(0x0f); 
          switch (rand() % 6)
          {
          case 0:
            PORTB |= 1 << PORT1; 
            PORTB |= 1 << PORT2; 
            PORTB |= 1 << PORT3; 
            break;
          case 1:
            PORTB |= 1 << PORT0;
            break;
          case 2:
            PORTB |= 1 << PORT1;
            break;
          case 3:
            PORTB |= 1 << PORT2;
            PORTB |= 1 << PORT0;
            break;
          case 4:
            PORTB |= 1 << PORT1;
            PORTB |= 1 << PORT2;
            break;
          case 5:
            PORTB |= 1 << PORT1;
            PORTB |= 1 << PORT2;
            PORTB |= 1 << PORT0;
            break;
          default:
            break;  
          }
  }
  
}



int main() {

  
  DDRB |= 1 << DDB3; // PB3 led
  DDRB |= 1 << DDB2; // PB2 led
  DDRB |= 1 << DDB1; // PB1 led
  DDRB |= 1 << DDB0; // PB0 led
  DDRB &= ~(1 << DDB4); // PB4 gomb
  DDRB &= ~(1 << DDB5); // PB5 photoellenallas
  PORTB |= 1 << PORTB4; // felhuzoellenallas
  PORTB |= 0x00;

  GIMSK |= 1 << PCIE; // globalis interrrput engedely a labakra.
  PCMSK |= 1 << PCINT4; // Gomb interrupt enable
  srand(0);
  sei(); 

  while (1) {
    cnt++;
    //PINB |= 0x0F;
    _delay_ms(100);
  }

  return 0;
}
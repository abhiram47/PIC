#include <pic18.h>

void delay() {
    for ( int i = 0; i < 300; i++) {
        for ( int j = 0; j < 300; j++);
    }
}

void main(void) {
    TRISD = 0x00;
    TRISC = 0xFF;

    while (1) {
        if (RC3 == 1) {
            PORTD = 0xFF;
       }  else if (RC2 == 1) {          

                PORTD = 0xFF;  
                delay();
                PORTD = 0x00;  
                delay();
            
        } else if (RC1 == 1) {
            
            for (int i = 0; i < 8; i++) {
                PORTD = 0x01 << i;  
                delay();
            }
        } else if (RC0 == 1) {
            
            for (int i = 7; i >= 0; i--) {
                PORTD = 0x01 << i;  
                delay();
            }
        } else {
            
            PORTD = 0x00;
        }
    }

    return;
}

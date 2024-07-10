/*
 * File:   led1.c
 * Author: Abhiram
 *
 * Created on 17 April, 2024, 11:02 AM
 */


#include <xc.h>
delay(){
for ( int i = 0; i < 100; i++) {
        for ( int j = 0; j< 100; j++);
    }
}

void main(void) {
    TRISC = 0X00;
    while(1){
        PORTC = 0XFF;
        delay();
        PORTC = 0X00;
        delay();
    }
    return;
}

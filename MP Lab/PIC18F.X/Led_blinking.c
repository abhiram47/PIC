/*
 * File:   TEST.c
 * Author: Abhiram
 *
 * Created on 11 April, 2024, 10:45 AM
 */


#include <pic18.h>
void delay(){
    for(int i = 0;i<500;i++ ){
        for(int j = 0;j<500;j++);
    }}
void main(void) {
    TRISB = 0X00;
    while(1){
            
            PORTB = 0XFF;
            delay();
            PORTB = 0X00;
            delay();
    }

    
    return;
}

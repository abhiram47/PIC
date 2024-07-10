/*
 * File:   test2.c
 * Author: Abhiram
 *
 * Created on 12 April, 2024, 9:33 AM
 */


#include <xc.h>
void delay(){
    for(int i = 0;i<100;i++ ){
        for(int j = 0;j<100;j++);
    }}

void main(void) {
    TRISD = 0X00;
    while(1){
        
            //PORTD = 0X00;
            //delay();
            PORTD = 0X01;
            delay();
            PORTD = 0X02;
            delay();
            PORTD = 0X04;
            delay();
            PORTD = 0X08;
            delay();
    
            PORTD = 0X10;
            delay();
            PORTD = 0X20;
            delay();
            PORTD = 0X40;
            delay();
            PORTD = 0X80;
            delay();
            
     
            
    }
    return;
}

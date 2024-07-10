/*
 * File:   motor.c
 * Author: Abhiram
 *
 * Created on 16 April, 2024, 3:54 PM
 */


#include <pic18.h>

delay(){
    for(int i =0;i<100;i++){
        for(int j =0;j<100;j++){
            
        }
            
    }
        
}

void main(void) {
    TRISC = 0X00;
    TRISD = 0X00;
    while(1){
        
        RC6 = 1;
        RC7 = 0;
        delay();
        
        RD6 = 0;
        RD7 = 1;
        delay();
    }
    return;
}

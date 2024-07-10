*
 * File:   push button & motor.c
 * Author: Abhiram
 *
 * Created on 17 April, 2024, 2:18 PM
 */


#include <xc.h>
delay(){
    for(int i = 0;i<100;i++){
        for(int j = 0;j<100;j++){
            
        }
    }
}


void main(void) {
    TRISD = 0X00;
    
    while(1){
        if(RC0 == 0){
           RD0 = 1;
           RD1 = 0;
           RD2 = 1;
           delay();
           
           RD5 = 1;
           RD6 = 1;
           RD7 = 0;
           delay();
          
    }   
        else if(RC1 == 0){
            
           RD0 = 0;
           RD1 = 1;
           RD2 = 1;
           delay();
           
           RD5 = 1;
           RD6 = 0;
           RD7 = 1;
           delay();
           
        }
        else if(RC2 == 0){
            
           RD0 = 1;
           RD1 = 0;
           RD2 = 1;
           delay();
           
           RD5 = 1;
           RD6 = 0;
           RD7 = 1;
           delay();
           
        }
            else if(RC3 == 0){
            
           RD0 = 0;
           RD1 = 1;
           RD2 = 1;
           delay();
           
           RD5 = 1;
           RD6 = 1;
           RD7 = 0;
           delay();
           
        }
        else{
            PORTD = 0X00;
        }
    }
    return;
}

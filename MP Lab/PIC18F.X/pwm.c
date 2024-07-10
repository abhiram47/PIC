/*
 * File:   pwm.c
 * Author: Abhiram
 *
 * Created on 13 May, 2024, 2:56 PM
 */


#include <xc.h>
delay(){
    for(int i =0;i<100;i++){
        for(int j =0;j<100;j++){
            
        }
    }
}

void command(char a){
    PORTD = a;
    RC0 = 0;
    RC1 = 1;
    delay();
    RC1 = 0;
}
void data(char b){
    PORTD = b;
    RC0 = 1;
    RC1 = 1;
    delay();
    RC1 = 0;
    
}
void String(const char str[]) {
    for(int i=0;str[i]!= '\0';i++){
        data(str[i]);
    }
}

void main(void) {
    ADCON1 = 0X0F;
    TRISC = 0X00;
    T2CON = 0X7F;
    CCP1CON = 0X0F;
    PR2 = 255;
    CCPR1L = 0XC0;
    
    TRISD = 0x00;
    TRISC = 0x00;
    TRISA = 0XFF;
    
    int count = 0;
    
    command(0x01); 
    command(0x06);                               
    command(0x0E);
    command(0x80);
    command(0x38);
    
  
    
    
    
    while(1){
        if(RA0 == 0){
        count++;
            if(count>3){
            count=0;
        }
    
        if(count == 1){
            
            CCPR1L = 0X3F;
            CCP1CON = 0X3F;
            command(0x01); //CLEAR DISPLAY
            String("25%");
            
            while(RA0 == 0);
        }
         if(count == 2){
            
            CCPR1L = 0X80;
            CCP1CON = 0X0F;
            command(0x01);
            String("50%");
           
            while(RA0 == 0);
        } if(count == 3){
            
            CCPR1L = 0XBF;
            CCP1CON = 0X3F;
            command(0x01);
            String("75%");
          
            while(RA0 == 0);
        }
    }
}
            
    return;
}

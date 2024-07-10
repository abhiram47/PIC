/*
 * File:   pushbuttonANDlcdANDmotor.c
 * Author: Abhiram
 *
 * Created on 17 April, 2024, 3:06 PM
 */


#include <xc.h>
delay(){
    for(int i = 0;i<100;i++){
        for(int j = 0;j<100;j++){
            
        }
    }
}
void command(char a){
    PORTA = 0X00;
    PORTB = a;
    RA0 = 0;
    RA1 = 1;
    delay();
    RA1 = 0;
}
void data(char b){
    PORTA = 0X00;
    PORTB = b;
    RA0 = 1;
    RA1 = 1;
    delay();
    RA1 = 0;  
}
void String(const char str[]) {
    for(int i=0;str[i]!= '\0';i++){
        data(str[i]);
    }
}

void main(void) {
    TRISC = 0XFF;
    TRISD = 0X00;
    TRISA = 0x00;
    TRISB = 0x00;
    ADCON1 = 0X0F;
    command(0x01); 
    command(0x06);                               
    command(0x0E);
    command(0x80);
    command(0x38);
    
    String("hello world");
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


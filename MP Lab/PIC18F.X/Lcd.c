/*
 * File:   Lcd.c
 * Author: Abhiram
 *
 * Created on 16 April, 2024, 2:14 PM
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
    TRISD = 0x00;
    TRISC = 0x00;
    
    command(0x01); 
    command(0x06);                               
    command(0x0E);
    command(0x80);
    command(0x38);
    
    String("hello world");
    while(1){
        
    }
    return;
}

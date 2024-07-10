/*
 * File:   ADC.c
 * Author: Abhiram
 *
 * Created on 16 April, 2024, 2:14 PM
 */


#include <xc.h>
#include <stdio.h>
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
    TRISA = 0XFF;
    TRISD = 0x00;
    TRISC = 0x00;
    
    ADCON0 = 0X01;
    ADCON1 = 0X00;
    ADCON2 = 0X86;
    
    command(0x01); 
    command(0x06);                               
    command(0x0E);
    command(0x80);
    command(0x38);
    
    //String("hello world");
    while(1){
        
        GODONE = 1;
    
    while(GODONE == 1);
    
    int a = ADRESL;
    a = a + (ADRESH<<8);
    /*
    int b[4];
    for(int i = 0;i<4;i++)
    {
        b[3-i]=(a%10)+48;
        a=a/10;
    }
    
    command(0xc0);
    
    for(int i = 0;i<4;i++)
    {
        data(b[i]);
    }
    */
    command(0xc0);  //cursor 2nd line
    
    char buffer[100];
    float voltage = (a*5)/1023.0;
    sprintf(buffer, "%f", voltage);
    String(buffer);
    
    }
    
    return;
}

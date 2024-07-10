/*
 * File:   reception&transmission.c
 * Author: Abhiram
 *
 * Created on 19 April, 2024, 4:30 PM
 */


#include <xc.h>

void transmit(char a){
   
    while(TXIF == 0);
    TXREG = a;
    TXIF = 0;
}

char recieve(void){
    while(RCIF == 0);
    return (RCREG);
}

void string(const char *p){
    while(*p != '\0'){
        transmit(*p);
        p++;
    }
}

void main(void) {
    TRISC = 0X80;
    TXSTA = 0X24;
    RCSTA = 0X90;
    SPBRG = 129;
    string("Hello World");
    while(1){
    char a;
    a = recieve();
    transmit(a);
    }
    return;
}
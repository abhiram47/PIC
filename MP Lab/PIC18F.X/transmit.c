/*
 * File:   transmit.c
 * Author: Abhiram
 *
 * Created on 19 April, 2024, 4:00 PM
 */


#include <xc.h>

void transmit(char a){
    TXREG = a;
    while(TXIF == 0);
    TXIF = 0;
}

void string(const char *p){
    while(*p != '\0'){
        transmit(*p);
        p++;
    }
}

void main(void) {
    TRISC = 0X40;
    TXSTA = 0X24;
    RCSTA = 0X90;
    SPBRG = 129;
    string("Hello World");
    while(1);
    return;
}



/*
 * File:   TEST.c
 * Author: Abhiram
 *
 * Created on 11 April, 2024, 10:34 AM
 */


#include <xc.h>

void main(void) {
    TRISD = 0X00;
    while(1){
    PORTD = 0XFF;
    }
    return;
}

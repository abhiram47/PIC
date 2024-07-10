/*
 * File:   Timer.c
 * Author: Abhiram
 *
 * Created on 24 April, 2024, 2:10 PM
 */


#include <xc.h>

void timer()
{
    while(TMR0IF == 0);
    TMR0L  = 60;
    TMR0IF = 0;
}

void main(void) {
    TRISE = 0X00;
    T0CON = 0XC7;
    while(1)
    {
       PORTE = 0X00;
       for(int i = 0; i<100 ;i++)
       {
           timer();
       }
      
       PORTE = 0XFF;
       
        for(int i = 0; i<100 ;i++)
       {
           timer();
       }
    }
    return;
}

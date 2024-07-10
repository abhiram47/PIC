/*
 * File:   Timer.c
 * Author: Abhiram
 *
 * Created on 24 April, 2024, 2:10 PM
 */


#include <xc.h>

void timer()
{
    while(TMR1IF == 0);
    TMR1L = 0X96;
    TMR1H = 0XE7;
    TMR1IF = 0;
}

void main(void) {
    TRISE = 0X00;
    T1CON = 0X71;
    while(1)
    {
       PORTE = 0X00;
       for(int i = 0; i<100 ;i++)
       {
           timer();
       }
       
       
       PORTE = 0XFF;
       
        for(int i = 0; i<60 ;i++)
       {
           timer();
       }
    }
    return;
}

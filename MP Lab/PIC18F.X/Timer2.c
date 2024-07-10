/*
 * File:   Timer.c
 * Author: Abhiram
 *
 * Created on 24 April, 2024, 2:10 PM
 */


#include <xc.h>

void timer()
{
    while(TMR2IF == 0);
    PR2  = 195;
    TMR2IF = 0;
}

void main(void) {
    TRISC = 0X00;
    T2CON = 0X7F;
    while(1)
    {
       PORTC = 0X00;
       for(int i = 0; i<100 ;i++)
       {
           timer();
       }
       
       
       PORTC = 0XFF;
       
        for(int i = 0; i<100 ;i++)
       {
           timer();
       }
    }
    return;
}

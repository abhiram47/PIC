/*
 * File:   TEST3.C
 * Author: Abhiram
 *
 * Created on 12 April, 2024, 10:18 AM
 */


#include <xc.h>
void delay(){
    for(int i = 0;i<100;i++ ){
        for(int j = 0;j<100;j++);
    }}

void main(void) {
      TRISD = 0X00;
    while(1){
        for(int i =0;i<=8;i++){
            PORTD = 0X01<<1;
            delay();
        }
    }
    return;
}

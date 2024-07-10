#include <pic18.h>

void delay() {
    for (unsigned int i = 0; i < 500; i++) {
        for (unsigned int j = 0; j < 500; j++);
    }
}

void main(void) {
    ADCON1 = 0X0F;
    TRISD = 0x00;
    TRISC = 0X00;
    TRISB = 0XFF;
    
    
    INTCON = 0XD0;
    
    

    while (1) {
        
            
            for (int i = 0; i < 8; i++) {
                PORTD = 0x01 << i;  
                delay();
            }
            
            

        
    }

    return;
}

void interrupt  __isr (void)
{
    if(INT0IF == 1)
    {
        for(int i = 0;i<20;i++)
        {
        PORTC =~PORTC;
      
        delay();
        
        }
        INT0IF = 0;
    }
    
}
/*
 * File:   Keypad.c
 * Author: Abhiram
 *
 * Created on 17 April, 2024, 3:58 PM
 */


#include <xc.h>
    
    char password[]="1234";
    char p[4];
    int k =0;
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
    p[k]=b;
    k++;
}
void String(const char str[]) {
    for(int i=0;str[i]!= '\0';i++){
        data(str[i]);
    }
}

void main(void) {
    
    int count = 0;
    TRISD = 0x00;
    TRISC = 0x00;
    TRISB = 0XF0;
    TRISA = 0X00;
    
    ADCON1 = 0X0F;
    command(0x01); 
    command(0x06);                               
    command(0x0E);
    command(0x80);
    command(0x38);
    
 
    
    while(1){

        PORTB = 0X0E;
        if(RB7 == 0){
            data('0');
            while(RB7 == 0);
    }
        
    
        if(RB6 == 0){
            data('1');
            while(RB6 == 0);
    }
        if(RB5 == 0){
             data('2');
            while(RB5 == 0);
    }
        if(RB4 == 0){
             data('3');
            while(RB4 == 0);
        
    }
        
        PORTB = 0X0D;
        if(RB7 == 0){
            data('4');
            while(RB7 == 0);
    }
        
    
        if(RB6 == 0){
            data('5');
            while(RB6 == 0);
    }
        if(RB5 == 0){
             data('6');
            while(RB5 == 0);
    }
        if(RB4 == 0){
             data('7');
            while(RB4 == 0);
        
    } 
        
        
        
        
         PORTB = 0X0B;
        if(RB7 == 0){
            data('8');
            while(RB7 == 0);
    }
        
    
        if(RB6 == 0){
            data('9');
            while(RB6 == 0);
    }
        if(RB5 == 0){
             data('A');
            while(RB5 == 0);
    }
        if(RB4 == 0){
             data('B');
            while(RB4 == 0);
        
    }
       
         
         
       
          PORTB = 0X07;
        if(RB7 == 0){
            data('C');
            while(RB7 == 0);
    }
        
    
        if(RB6 == 0){
            data('D');
            while(RB6 == 0);
    }
        if(RB5 == 0){
             data('E');
            while(RB5 == 0);
    }
        if(RB4 == 0){
             data('F');
            while(RB4 == 0);
        
    }
          
          if(k==4){
              
          
        
        for(int j = 0; j <= 3; j++){
           if(p[j] == password[j]){
               count++;
           }
        }
           
        if(count == 4){
            command(0XC0);
            String("Access Granted");
            RA0 = 1;
            RA1 = 0;
            RA2 = 1;
            delay();
            
        } else {
            
            command(0XC0);
            String("Access Denied");
        }   
          
          }
    
    }
    return;
}




























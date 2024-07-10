/*
 * File:   passwordUSINGreceptionANDtransmission.c
 * Author: Abhiram
 *
 * Created on 23 April, 2024, 2:49 PM
 */
/*

#include <xc.h>
char password[]= "1234";
char p[4];
int k=0;

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
void transmit(char a){
    TXREG = a;
    while(TXIF == 0);
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
    TRISC = 0X00;
    TRISD = 0X00;
    TRISB = 0XF0;
    ADCON1 = 0X0F;
    
    TRISC = 0X80;
    TXSTA = 0X24;
    RCSTA = 0X90;
    SPBRG = 129;
    
    int count = 0;
    
    command(0X01);
    command(0X06);
    command(0X0E);
    command(0X80);
    command(0X38);
    
    
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
            char a;
            a = recieve();
            transmit("Access Granted");
            RA0 = 1;
            RA1 = 0;
            RA2 = 1;
            delay();
            
        } else {
            
            command(0XC0);
            char a;
            a = recieve();
            transmit("Access denied");
           
        }   
          
          }
        }
    return;
}
*/



#include <xc.h>

char password[4]= "1234";

int count = 0;

delay(){
    for(int i =0;i<100;i++){
        for(int j =0;j<100;j++){
    }
  }
}

void transmit(char a){
    TXREG = a;
    while(TXIF == 0);
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
    //string("Hello World");
    while(1){
    char a;
    char p[4];
    count = 0;
    for(int i=0;i<4;i++){
        a = recieve();
    transmit(a);
    p[i]=a;
    }
    
    
    
  
              
          
        
        for(int j = 0; j <= 3; j++){
           if(p[j] == password[j]){
               count++;
           }
        }
           
        if(count == 4){
    

            string("\rAccess Granted");
           
        } else {
            
        

           string("\rAccess denied");
           
        } 
    
    }
          
        
    
    return;
}
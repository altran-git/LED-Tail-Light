/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.0 Professional
Automatic Program Generator
� Copyright 1998-2010 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 1/16/2014
Author  : 
Company : 
Comments: 


Chip type               : ATmega324P
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*****************************************************/

#include <mega324.h>
#include <stdint.h>
#include "delay.h"
#include "ledutil.h"

int i, a, k;
int counter = 0;
int loop = 1;
int ledspeed = 20;
volatile uint8_t portdhistory = 0xFF;

/*
This one-byte flag holds five channel direction bit flags
0x [nothing] [nothing] [nothing] [ch5] [ch4] [ch3] [ch2] [ch1]
*/
uint8_t ch1, ch2, ch3, ch4, ch5, ch6, ch7, ch8, ch9, ch10, ch11, ch12, ch13, ch14, ch15, ch16; /* The one-byte PWM level of each channel */
uint8_t direction1 = 0xFF;
uint8_t direction2 = 0xFF;

/* Count the number of times the ISR has run */
 volatile uint8_t ISRcounter = 0; 


// Pin change 24-31 interrupt service routine
interrupt [PC_INT3] void pin_change_isr3(void)
{
    uint8_t changedbits;
    changedbits = PIND ^ portdhistory;
    portdhistory = PIND;  
          
    /*
      REMOTE CONTROLLER
      A: PIND2
      B: PIND3
      C: PIND0
      D: PIND1
    */               
    
    /*PCINT24 changed (SPEED+) */
    if(changedbits & (1 << PIND0)){
        if((PIND & (1 << PIND0)) == 0){
            ledspeed = ledspeed - 5;
            if(ledspeed < 5)
                ledspeed = 5;
        }
        
    }
    
    /*PCINT25 changed (SPEED-) */
    if(changedbits & (1 << PIND1)){
        if((PIND & (1 << PIND1)) == 0){
            ledspeed = ledspeed + 5;
            if(ledspeed > 150)
                ledspeed = 150;
        }
    }
    
    /*PCINT26 changed (AUTO PATTERN)*/
    if(changedbits & (1 << PIND2)){
        if((PIND & (1 << PIND2)) == 0){
            TCCR2B=0x00;
            TIMSK2=0x00;
            counter++;
            
            if(loop == 1){
                loop = 0;
                counter = 0;
            }

            if(counter > 19)
                counter = 0;
        }
    }
    
    /*PCINT27 changed (PATTERN+)*/
    if(changedbits & (1 << PIND3)){
        if((PIND & (1 << PIND3)) == 0){
            TCCR2B=0x00;
            TIMSK2=0x00;
            counter = 0;
            loop = 1;
        }
    } 
}

// Timer2 overflow interrupt service routine
interrupt [TIM2_OVF] void timer2_ovf_isr(void)
{
    if(ISRcounter < ch1) CH1_ON;
    else CH1_OFF;
 
    if(ISRcounter < ch2) CH2_ON;
    else CH2_OFF;
 
    if(ISRcounter < ch3) CH3_ON;
    else CH3_OFF;
 
    if(ISRcounter < ch4) CH4_ON;
    else CH4_OFF;
 
    if(ISRcounter < ch5) CH5_ON;
    else CH5_OFF;
    
    if(ISRcounter < ch6) CH6_ON;
    else CH6_OFF;
    
    if(ISRcounter < ch7) CH7_ON;
    else CH7_OFF;
    
    if(ISRcounter < ch8) CH8_ON;
    else CH8_OFF;
    
    if(ISRcounter < ch9) CH9_ON;
    else CH9_OFF;
    
    if(ISRcounter < ch10) CH10_ON;
    else CH10_OFF;
    
    if(ISRcounter < ch11) CH11_ON;
    else CH11_OFF;
    
    if(ISRcounter < ch12) CH12_ON;
    else CH12_OFF;
    
    if(ISRcounter < ch13) CH13_ON;
    else CH13_OFF;
    
    if(ISRcounter < ch14) CH14_ON;
    else CH14_OFF;
    
    if(ISRcounter < ch15) CH15_ON;
    else CH15_OFF;
    
    if(ISRcounter < ch16) CH16_ON;
    else CH16_OFF;
 
    ISRcounter++;
}

// Declare your global variables here

void main(void)
{
// Declare your local variables here

// Crystal Oscillator division factor: 1
#pragma optsize-
CLKPR=0x80;
CLKPR=0x00;
#ifdef _OPTIMIZE_SIZE_
#pragma optsize+
#endif

// Input/Output Ports initialization
// Port A initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
PORTA=0x00;
DDRA=0xFF;

// Port B initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
PORTB=0x00;
DDRB=0xFF;

// Port C initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
PORTC=0x00;
DDRC=0xFF;

// Port D initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=In Func2=In Func1=In Func0=In 
// State7=1 State6=1 State5=1 State4=1 State3=T State2=T State1=T State0=T 
PORTD=0xF0;
DDRD=0xF0;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0A output: Disconnected
// OC0B output: Disconnected
TCCR0A=0x00;
TCCR0B=0x00;
TCNT0=0x00;
OCR0A=0x00;
OCR0B=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: 8000.000 kHz
// Mode: Normal top=0xFF
// OC2A output: Disconnected
// OC2B output: Disconnected
ASSR=0x00;
TCCR2A=0x00;
TCCR2B=0x01;
TCNT2=0x00;
OCR2A=0x00;
OCR2B=0x00;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
// Interrupt on any change on pins PCINT0-7: Off
// Interrupt on any change on pins PCINT8-15: Off
// Interrupt on any change on pins PCINT16-23: Off
// Interrupt on any change on pins PCINT24-31: On
EICRA=0x00;
EIMSK=0x00;
PCMSK3=0x0F;
PCICR=0x08;
PCIFR=0x08;

// Timer/Counter 0 Interrupt(s) initialization
TIMSK0=0x00;

// Timer/Counter 1 Interrupt(s) initialization
TIMSK1=0x00;

// Timer/Counter 2 Interrupt(s) initialization
TIMSK2=0x00;

// USART0 initialization
// USART0 disabled
UCSR0B=0x00;

// USART1 initialization
// USART1 disabled
UCSR1B=0x00;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
ADCSRB=0x00;
DIDR1=0x00;

// ADC initialization
// ADC disabled
ADCSRA=0x00;

// SPI initialization
// SPI disabled
SPCR=0x00;

// TWI initialization
// TWI disabled
TWCR=0x00;

// Global enable interrupts
#asm("sei")

ch1 = 0;
ch2 = TIME_OFFSET;
ch3 = 2 * TIME_OFFSET;
ch4 = 3 * TIME_OFFSET;
ch5 = 4 * TIME_OFFSET;
ch6 = 5 * TIME_OFFSET;
ch7 = 6 * TIME_OFFSET;
ch8 = 7 * TIME_OFFSET;
ch16 = 0;
ch15 = TIME_OFFSET;
ch14 = 2 * TIME_OFFSET;
ch13 = 3 * TIME_OFFSET;
ch12 = 4 * TIME_OFFSET;
ch11 = 5 * TIME_OFFSET;
ch10 = 6 * TIME_OFFSET;
ch9 = 7 * TIME_OFFSET;

while (1){
  switch(counter){
    case 0:
        if(loop == 1){
            a = 10;
            counter++;
        }
        else{
            a = 1;
        }
            
        for(i = 0; i < a; i++){
        CH1_OFF;
        CH8_OFF; 
        CH9_OFF;
        CH16_OFF;
        delay_ms(ledspeed+15);
        CH2_OFF;
        CH7_OFF; 
        CH10_OFF;
        CH15_OFF;
        delay_ms(ledspeed+15);
        CH3_OFF;
        CH6_OFF; 
        CH11_OFF;
        CH14_OFF;
        delay_ms(ledspeed+15);
        CH4_OFF;
        CH5_OFF; 
        CH12_OFF;
        CH13_OFF;
        delay_ms(ledspeed+15);
        CH4_ON;
        CH5_ON; 
        CH12_ON;
        CH13_ON;
        delay_ms(ledspeed+15);
        CH3_ON;
        CH6_ON; 
        CH11_ON;
        CH14_ON;
        delay_ms(ledspeed+15);
        CH2_ON;
        CH7_ON; 
        CH10_ON;
        CH15_ON;
        delay_ms(ledspeed+15);
        CH1_ON;
        CH8_ON; 
        CH9_ON;
        CH16_ON;
        delay_ms(ledspeed+15);
        }
    break;
    case 1:
        if(loop == 1){
            a = 6;
            counter++;
        }
        else{
            a = 1;
        }
        
        for(i = 0; i < a; i++){
        PORTAB_OFF;
        PORTC_OFF;
              
        CH16_ON;
        delay_ms(ledspeed);
        CH15_ON;
        delay_ms(ledspeed);
        CH14_ON;
        delay_ms(ledspeed);
        CH13_ON;
        delay_ms(ledspeed); 
        CH12_ON;
        delay_ms(ledspeed);
        CH11_ON;
        delay_ms(ledspeed);
        CH10_ON;
        
        delay_ms(ledspeed); 
        CH9_ON;
        delay_ms(ledspeed); 
        CH1_ON;
        delay_ms(ledspeed); 
        CH2_ON; 
        delay_ms(ledspeed); 
        CH3_ON; 
        delay_ms(ledspeed); 
        CH4_ON; 
        delay_ms(ledspeed); 
        CH5_ON; 
        delay_ms(ledspeed); 
        CH6_ON;  
        delay_ms(ledspeed); 
        CH7_ON; 
        delay_ms(ledspeed); 
        CH8_ON; 
        delay_ms(ledspeed);
        
        CH16_OFF;
        delay_ms(ledspeed);
        CH15_OFF;
        delay_ms(ledspeed);
        CH14_OFF;
        delay_ms(ledspeed);
        CH13_OFF;
        delay_ms(ledspeed); 
        CH12_OFF;
        delay_ms(ledspeed);
        CH11_OFF;
        delay_ms(ledspeed);
        CH10_OFF;
        
        delay_ms(ledspeed); 
        CH9_OFF;
        delay_ms(ledspeed); 
        CH1_OFF;
        delay_ms(ledspeed); 
        CH2_OFF;
        delay_ms(ledspeed); 
        CH3_OFF;
        delay_ms(ledspeed); 
        CH4_OFF;
        delay_ms(ledspeed); 
        CH5_OFF;
        delay_ms(ledspeed); 
        CH6_OFF; 
        delay_ms(ledspeed); 
        CH7_OFF;
        delay_ms(ledspeed); 
        CH8_OFF;
        delay_ms(ledspeed);
        }
    break;
    case 2:
        if(loop == 1){
            a = 12;
            counter++;
        }
        else{
            a = 1;
        }
        
        for(i = 0; i < a; i++){
        PORTAB_OFF;
        PORTC_OFF;
        
        CH1_ON;
        CH2_ON;
        CH5_ON;
        CH6_ON;
        CH11_ON;
        CH12_ON;
        CH15_ON;
        CH16_ON;
        delay_ms(ledspeed+65);
        CH1_OFF;
        CH5_OFF;
        CH12_OFF;
        CH16_OFF;
        CH3_ON;
        CH7_ON;
        CH10_ON;
        CH14_ON;
        delay_ms(ledspeed+65);
        CH2_OFF;
        CH6_OFF;
        CH11_OFF;
        CH15_OFF;
        CH4_ON;
        CH8_ON;
        CH9_ON;
        CH13_ON;
        delay_ms(ledspeed+65);
        CH3_OFF;
        CH7_OFF;
        CH10_OFF;
        CH14_OFF;
        CH1_ON;
        CH5_ON;
        CH12_ON;
        CH16_ON;
        delay_ms(ledspeed+65);
        }
    break;
    case 3:
        if(loop == 1){
            a = 10;
            counter++;
        }
        else{
            a = 1;
        }
        
        for(i = 0; i < a; i++){   
        PORTAB_OFF;
        PORTC_ON; 
        delay_ms(ledspeed+110);
        CH1_ON;
        CH2_ON;
        CH3_ON;
        CH4_ON;
        CH5_ON;
        CH6_ON;
        PORTC_OFF;
        delay_ms(ledspeed+110);
        CH1_OFF;
        CH2_OFF;
        CH3_OFF;
        CH4_OFF;
        CH5_OFF;
        CH6_OFF;
        CH7_ON;
        CH8_ON;
        delay_ms(ledspeed+110);
        }
    break;
    case 4:
        if(loop == 1){
            a = 3;
            counter++;
        }
        else{
            a = 1;
        }
        
        for(i = 0; i < a; i++){
        PORTAB_OFF;
        PORTC_OFF;
        
        CH8_TOGGLE;
        CH9_TOGGLE;
        delay_ms(ledspeed+30);
        CH8_TOGGLE;
        CH7_TOGGLE;
        CH9_TOGGLE;
        CH10_TOGGLE;
        delay_ms(ledspeed+30);
        CH7_TOGGLE;
        CH6_TOGGLE;
        CH10_TOGGLE;
        CH11_TOGGLE;
        delay_ms(ledspeed+30);
        CH6_TOGGLE;
        CH5_TOGGLE;
        CH11_TOGGLE;
        CH12_TOGGLE;
        delay_ms(ledspeed+30);
        CH5_TOGGLE;
        CH4_TOGGLE;
        CH12_TOGGLE;
        CH13_TOGGLE;
        delay_ms(ledspeed+30);
        CH4_TOGGLE;
        CH3_TOGGLE;
        CH13_TOGGLE;
        CH14_TOGGLE; 
        delay_ms(ledspeed+30);
        CH3_TOGGLE;
        CH2_TOGGLE;
        CH14_TOGGLE;
        CH15_TOGGLE;
        delay_ms(ledspeed+30);
        CH2_TOGGLE;
        CH1_TOGGLE;
        CH15_TOGGLE;
        CH16_TOGGLE;
        delay_ms(ledspeed+30);
        CH8_TOGGLE;
        CH9_TOGGLE; 
        delay_ms(ledspeed+30);
        CH8_TOGGLE;
        CH7_TOGGLE;
        CH9_TOGGLE;
        CH10_TOGGLE;
        delay_ms(ledspeed+30);
        CH7_TOGGLE;
        CH6_TOGGLE;
        CH10_TOGGLE;
        CH11_TOGGLE;
        delay_ms(ledspeed+30);
        CH6_TOGGLE;
        CH5_TOGGLE;
        CH11_TOGGLE;
        CH12_TOGGLE;
        delay_ms(ledspeed+30);
        CH5_TOGGLE;
        CH4_TOGGLE;
        CH12_TOGGLE;
        CH13_TOGGLE;
        delay_ms(ledspeed+30);
        CH4_TOGGLE;
        CH3_TOGGLE;
        CH13_TOGGLE;
        CH14_TOGGLE; 
        delay_ms(ledspeed+30);
        CH3_TOGGLE;
        CH2_TOGGLE;
        CH14_TOGGLE;
        CH15_TOGGLE;
        delay_ms(ledspeed+30);
        CH8_TOGGLE;
        CH9_TOGGLE; 
        delay_ms(ledspeed+30);
        CH8_TOGGLE;
        CH7_TOGGLE;
        CH9_TOGGLE;
        CH10_TOGGLE;
        delay_ms(ledspeed+30);
        CH7_TOGGLE;
        CH6_TOGGLE;
        CH10_TOGGLE;
        CH11_TOGGLE;
        delay_ms(ledspeed+30);
        CH6_TOGGLE;
        CH5_TOGGLE;
        CH11_TOGGLE;
        CH12_TOGGLE;
        delay_ms(ledspeed+30);
        CH5_TOGGLE;
        CH4_TOGGLE;
        CH12_TOGGLE;
        CH13_TOGGLE;
        delay_ms(ledspeed+30);
        CH4_TOGGLE;
        CH3_TOGGLE;
        CH13_TOGGLE;
        CH14_TOGGLE;
        delay_ms(ledspeed+30);
        CH8_TOGGLE;
        CH9_TOGGLE; 
        delay_ms(ledspeed+30);
        CH8_TOGGLE;
        CH7_TOGGLE;
        CH9_TOGGLE;
        CH10_TOGGLE;
        delay_ms(ledspeed+30);
        CH7_TOGGLE;
        CH6_TOGGLE;
        CH10_TOGGLE;
        CH11_TOGGLE;
        delay_ms(ledspeed+30);
        CH6_TOGGLE;
        CH5_TOGGLE;
        CH11_TOGGLE;
        CH12_TOGGLE;
        delay_ms(ledspeed+30);
        CH5_TOGGLE;
        CH4_TOGGLE;
        CH12_TOGGLE;
        CH13_TOGGLE;
        delay_ms(ledspeed+30);
        CH8_TOGGLE;
        CH9_TOGGLE; 
        delay_ms(ledspeed+30);
        CH8_TOGGLE;
        CH7_TOGGLE;
        CH9_TOGGLE;
        CH10_TOGGLE;
        delay_ms(ledspeed+30);
        CH7_TOGGLE;
        CH6_TOGGLE;
        CH10_TOGGLE;
        CH11_TOGGLE;
        delay_ms(ledspeed+30);
        CH6_TOGGLE;
        CH5_TOGGLE;
        CH11_TOGGLE;
        CH12_TOGGLE;
        delay_ms(ledspeed+30);
        CH8_TOGGLE;
        CH9_TOGGLE; 
        delay_ms(ledspeed+30);
        CH8_TOGGLE;
        CH7_TOGGLE;
        CH9_TOGGLE;
        CH10_TOGGLE;
        delay_ms(ledspeed+30);
        CH7_TOGGLE;
        CH6_TOGGLE;
        CH10_TOGGLE;
        CH11_TOGGLE;
        delay_ms(ledspeed+30);
        CH8_TOGGLE;
        CH9_TOGGLE; 
        delay_ms(ledspeed+30);
        CH8_TOGGLE;
        CH7_TOGGLE;
        CH9_TOGGLE;
        CH10_TOGGLE;
        delay_ms(ledspeed+30);
        CH8_TOGGLE;
        CH9_TOGGLE;
        delay_ms(ledspeed+30);
        PORTAB_ON;
        PORTC_ON;
        delay_ms(ledspeed+100);
        }
    break;
    case 5:
        if(loop == 1){
            a = 10;
            counter++;
        }
        else{
            a = 1;
        }
        
        for(i = 0; i < a; i++){
        PORTA = (1<<0);
        PORTB = (1<<7);
        PORTC = (1<<7);
        delay_ms(ledspeed+10);
        PORTA = (1<<1);
        PORTB = (1<<6);
        PORTC = (1<<6);;
        delay_ms(ledspeed+10);
        PORTA = (1<<2);
        PORTB = (1<<5);
        PORTC = (1<<5);
        delay_ms(ledspeed+10);
        PORTA = (1<<3);
        PORTB = (1<<4);
        PORTC = (1<<4);
        delay_ms(ledspeed+10);
        PORTA = (1<<4);
        PORTB = (1<<3);
        PORTC = (1<<3);
        delay_ms(ledspeed+10);
        PORTA = (1<<5);
        PORTB = (1<<2);
        PORTC = (1<<2);
        delay_ms(ledspeed+10);
        PORTA = (1<<6);
        PORTB = (1<<1);
        PORTC = (1<<1);
        delay_ms(ledspeed+10);
        PORTA = (1<<7);
        PORTB = (1<<0);
        PORTC = (1<<0);
        delay_ms(ledspeed+10);
        PORTA = (1<<6);
        PORTB = (1<<1);
        PORTC = (1<<1);
        delay_ms(ledspeed+10);
        PORTA = (1<<5);
        PORTB = (1<<2);
        PORTC = (1<<2);
        delay_ms(ledspeed+10);
        PORTA = (1<<4);
        PORTB = (1<<3);
        PORTC = (1<<3);
        delay_ms(ledspeed+10);
        PORTA = (1<<3);
        PORTB = (1<<4);
        PORTC = (1<<4);
        delay_ms(ledspeed+10);
        PORTA = (1<<2);
        PORTB = (1<<5);
        PORTC = (1<<5);
        delay_ms(ledspeed+10);
        PORTA = (1<<1); 
        PORTB = (1<<6);
        PORTC = (1<<6);
        delay_ms(ledspeed+10);
        } 
    break;
    case 6:
        if(loop == 1){
            a = 10;
            counter++;
        }
        else{
            a = 1;
        }
        
        for(i = 0; i < a; i++){
        PORTA = (1<<0); 
        PORTB = (1<<7);
        delay_ms(ledspeed+5); 
        PORTA = (1<<1); 
        PORTB = (1<<6);
        PORTC |= (1<<0)|(1<<1);
        delay_ms(ledspeed+5);
        PORTA = (1<<2);
        PORTB = (1<<5);
        PORTC &= ~((1<<0)|(1<<1));
        PORTC |= (1<<2)|(1<<3);
        delay_ms(ledspeed+5);
        PORTA = (1<<3); 
        PORTB = (1<<4);
        PORTC &= ~((1<<2)|(1<<3));
        PORTC |= (1<<4)|(1<<5);
        delay_ms(ledspeed+5);
        PORTA = (1<<4);
        PORTB = (1<<3);
        PORTC &= ~((1<<4)|(1<<5));
        PORTC |= (1<<6)|(1<<7);
        delay_ms(ledspeed+5); 
        PORTA = (1<<5);
        PORTB = (1<<2);
        PORTC &= ~((1<<6)|(1<<7));
        delay_ms(ledspeed+5);
        PORTA = (1<<6);
        PORTB = (1<<1);
        delay_ms(ledspeed+5); 
        PORTA = (1<<7); 
        PORTB = (1<<0);
        delay_ms(ledspeed+5);
        PORTA |= (1<<6);
        PORTB |= (1<<1);
        delay_ms(ledspeed+5); 
        PORTA |= (1<<5);
        PORTB |= (1<<2);
        delay_ms(ledspeed+5);
        PORTA |= (1<<4);
        PORTB |= (1<<3);
        PORTC |= (1<<6)|(1<<7);
        delay_ms(ledspeed+5);
        PORTA |= (1<<3);
        PORTB |= (1<<4);
        PORTC |= (1<<4)|(1<<5);
        delay_ms(ledspeed+5); 
        PORTA |= (1<<2); 
        PORTB |= (1<<5);
        PORTC |= (1<<2)|(1<<3);
        delay_ms(ledspeed+5); 
        PORTA |= (1<<1);
        PORTB |= (1<<6);
        PORTC |= (1<<0)|(1<<1);
        delay_ms(ledspeed+5);
        PORTA |= (1<<0); 
        PORTB |= (1<<7);
        delay_ms(ledspeed+5);
        } 
    break; 
    case 7:
        if(loop == 1){
            a = 4;
            counter++;
        }
        else{
            a = 1;
        }
        
        for(i = 0; i < a; i++){
        PORTAB_OFF;
        PORTC_OFF;
        
        CH8_ON;
        delay_ms(ledspeed);
        CH7_ON;
        delay_ms(ledspeed);
        CH6_ON;
        delay_ms(ledspeed);
        CH5_ON;
        delay_ms(ledspeed);
        CH4_ON;
        delay_ms(ledspeed);
        CH3_ON;
        delay_ms(ledspeed);
        CH2_ON;
        delay_ms(ledspeed);
        CH1_ON;
        delay_ms(ledspeed);
        CH2_OFF;
        PORTC_ON;
        delay_ms(ledspeed);

        PORTC_OFF;
        CH2_ON;
        CH3_OFF;
        delay_ms(ledspeed);
        CH3_ON;
        CH4_OFF;
        delay_ms(ledspeed);
        CH4_ON;
        CH5_OFF;
        delay_ms(ledspeed);
        CH5_ON;
        CH6_OFF;
        delay_ms(ledspeed);
        CH6_ON;
        CH7_OFF;
        delay_ms(ledspeed);
        CH7_ON;
        CH8_OFF;
        delay_ms(ledspeed);
        CH8_ON;
        CH7_OFF;
        delay_ms(ledspeed);
        CH7_ON;
        CH6_OFF;
        delay_ms(ledspeed);
        CH6_ON;
        CH5_OFF;
        delay_ms(ledspeed);
        CH5_ON;
        CH4_OFF;
        delay_ms(ledspeed);
        CH4_ON;
        CH3_OFF;
        delay_ms(ledspeed);
        CH3_ON;
        CH2_OFF;
        delay_ms(ledspeed);
        CH2_ON;
        CH1_OFF;
        PORTC_ON;
        delay_ms(ledspeed);
        
        PORTC_OFF;
        CH2_OFF;
        delay_ms(ledspeed);
        CH2_ON;
        CH3_OFF;
        delay_ms(ledspeed);
        CH3_ON;
        CH4_OFF;
        delay_ms(ledspeed);
        CH4_ON;
        CH5_OFF;
        delay_ms(ledspeed);
        CH5_ON;
        CH6_OFF;
        delay_ms(ledspeed);
        CH6_ON;
        CH7_OFF;
        delay_ms(ledspeed);
        CH7_ON;
        CH8_OFF;
        delay_ms(ledspeed);
        CH8_ON;
        CH7_OFF;
        delay_ms(ledspeed);
        CH7_ON;
        CH6_OFF;
        delay_ms(ledspeed);
        CH6_ON;
        CH5_OFF;
        delay_ms(ledspeed);
        CH5_ON;
        CH4_OFF;
        delay_ms(ledspeed);
        CH4_ON;
        CH3_OFF;
        delay_ms(ledspeed);
        CH3_ON;
        CH2_OFF;
        PORTC_ON;
        delay_ms(ledspeed); 
        
        PORTC_OFF;
        CH3_OFF;
        delay_ms(ledspeed);
        CH3_ON;
        CH4_OFF;
        delay_ms(ledspeed);
        CH4_ON;
        CH5_OFF;
        delay_ms(ledspeed);
        CH5_ON;
        CH6_OFF;
        delay_ms(ledspeed);
        CH6_ON;
        CH7_OFF;
        delay_ms(ledspeed);
        CH7_ON;
        CH8_OFF;
        delay_ms(ledspeed);
        CH8_ON;
        CH7_OFF;
        delay_ms(ledspeed);
        CH7_ON;
        CH6_OFF;
        delay_ms(ledspeed);
        CH6_ON;
        CH5_OFF;
        delay_ms(ledspeed);
        CH5_ON;
        CH4_OFF;
        delay_ms(ledspeed);
        CH4_ON;
        CH3_OFF;
        PORTC_ON;
        delay_ms(ledspeed);
        
        PORTC_OFF;
        CH4_OFF;
        delay_ms(ledspeed);
        CH4_ON;
        CH5_OFF;
        delay_ms(ledspeed);
        CH5_ON;
        CH6_OFF;
        delay_ms(ledspeed);
        CH6_ON;
        CH7_OFF;
        delay_ms(ledspeed);
        CH7_ON;
        CH8_OFF;
        delay_ms(ledspeed);
        CH8_ON;
        CH7_OFF;
        delay_ms(ledspeed);
        CH7_ON;
        CH6_OFF;
        delay_ms(ledspeed);
        CH6_ON;
        CH5_OFF;
        delay_ms(ledspeed);
        CH5_ON;
        CH4_OFF;
        PORTC_ON;
        delay_ms(ledspeed);
        
        PORTC_OFF;
        CH5_OFF;
        delay_ms(ledspeed);
        CH5_ON;
        CH6_OFF;
        delay_ms(ledspeed);
        CH6_ON;
        CH7_OFF;
        delay_ms(ledspeed);
        CH7_ON;
        CH8_OFF;
        delay_ms(ledspeed);
        CH8_ON;
        CH7_OFF;
        delay_ms(ledspeed);
        CH7_ON;
        CH6_OFF;
        delay_ms(ledspeed);
        CH6_ON;
        CH5_OFF;
        PORTC_ON;
        delay_ms(ledspeed);
        
        PORTC_OFF;
        CH6_OFF;
        delay_ms(ledspeed);
        CH6_ON;
        CH7_OFF;
        delay_ms(ledspeed);
        CH7_ON;
        CH8_OFF;
        delay_ms(ledspeed);
        CH8_ON;
        CH7_OFF;
        delay_ms(ledspeed);
        CH7_ON;
        CH6_OFF;
        PORTC_ON;
        delay_ms(ledspeed);
        
        PORTC_OFF;
        CH7_OFF;
        delay_ms(ledspeed);
        CH7_ON;
        CH8_OFF;
        delay_ms(ledspeed);
        CH8_ON;
        CH7_OFF;
        PORTC_ON;
        delay_ms(ledspeed);
        
        PORTC_OFF;
        CH8_OFF;  
        delay_ms(ledspeed);
        }
    
    break;
    case 8:
        if(loop == 1){
            a = 9;
            counter++;
        }
        else{
            a = 1;
        }
        
        for(i = 0; i < a; i++){
        CH1_ON;
        CH8_ON; 
        CH9_ON;
        CH16_ON;
        delay_ms(ledspeed+40);
        CH1_OFF;
        CH8_OFF;
        CH9_OFF;
        CH16_OFF; 
        CH2_ON;
        CH7_ON;
        CH10_ON;
        CH15_ON;
        delay_ms(ledspeed+40);
        CH2_OFF;
        CH7_OFF;
        CH10_OFF;
        CH15_OFF;
        CH3_ON;
        CH6_ON;
        CH11_ON;
        CH14_ON;
        delay_ms(ledspeed+40);
        CH3_OFF;
        CH6_OFF;
        CH11_OFF;
        CH14_OFF;
        CH4_ON;
        CH5_ON;
        CH12_ON;
        CH13_ON;
        delay_ms(ledspeed+40);
        CH4_OFF;
        CH5_OFF;
        CH12_OFF;
        CH13_OFF;
        CH3_ON;
        CH6_ON;
        CH11_ON;
        CH14_ON;
        delay_ms(ledspeed+40);
        CH3_OFF;
        CH6_OFF;
        CH11_OFF;
        CH14_OFF;
        CH2_ON;
        CH7_ON;
        CH10_ON;
        CH15_ON;
        delay_ms(ledspeed+40);
        CH2_OFF;
        CH7_OFF;
        CH10_OFF;
        CH15_OFF;
        }
            
    break;
    case 9:
        if(loop == 1){
            a = 8;
            counter++;
        }
        else{
            a = 1;
        }
        
        for(i = 0; i < a; i++){
        CH1_ON;
        CH7_ON;
        CH9_TOGGLE;
        delay_ms(ledspeed+30); 
        CH7_OFF;
        CH2_ON;
        CH8_ON;
        CH10_TOGGLE;
        delay_ms(ledspeed+30);
        CH8_OFF;
        CH3_ON;
        CH7_ON;
        delay_ms(ledspeed+30);    
        CH7_OFF;
        CH4_ON;
        CH8_ON;
        CH11_TOGGLE;
        delay_ms(ledspeed+30);
        CH8_OFF;
        CH5_ON;
        CH7_ON;
        CH12_TOGGLE;
        delay_ms(ledspeed+30);
        CH7_OFF;
        CH6_ON;
        CH8_ON;
        delay_ms(ledspeed+30);    
        CH8_OFF;
        CH6_OFF;
        CH7_ON;
        CH13_TOGGLE;
        
        delay_ms(ledspeed+30);
        CH7_OFF;
        CH5_OFF;
        CH8_ON;
        CH14_TOGGLE;
        delay_ms(ledspeed+30);
        CH8_OFF;
        CH4_OFF;
        CH7_ON;
        delay_ms(ledspeed+30);
        CH7_OFF;
        CH3_OFF;
        CH8_ON;
        CH15_TOGGLE;
        delay_ms(ledspeed+30);
        CH8_OFF;
        CH2_OFF;
        CH7_ON;
        CH16_TOGGLE;
        delay_ms(ledspeed+30); 
        CH7_OFF;
        CH1_OFF;
        CH8_ON;
        delay_ms(ledspeed+30);
        CH8_OFF;
        }
    break;
    case 10: 
        if(loop == 1){
            a = 18;
            counter++;
        }
        else{
            a = 1;
        }
        
        for(i = 0; i < a; i++){
        PORTA = 0x3E;
        PORTB = 0x7C;
        PORTC_OFF;
        delay_ms(ledspeed+90);
        PORTA = 0xC1;
        PORTB = 0x83;
        PORTC_ON;
        delay_ms(ledspeed+90);
        } 
    break;
    case 11:
        if(loop == 1){
            a = 5;
            counter++;
        }
        else{
            a = 1;
        }
        
        PORTAB_OFF;
        PORTC_OFF;
        
        for(i = 0; i < a; i++){
        CH8_ON;
        delay_ms(ledspeed+60); 
        CH8_OFF;
        CH7_ON;
        delay_ms(ledspeed+60);
        CH7_OFF;
        CH6_ON;
        delay_ms(ledspeed+60);
        CH6_OFF;
        CH15_ON;
        CH16_ON;
        delay_ms(ledspeed+60);
        CH15_OFF;
        CH16_OFF;
        CH5_ON;
        delay_ms(ledspeed+60);
        CH5_OFF;
        CH13_ON;
        CH14_ON;
        delay_ms(ledspeed+60);
        CH13_OFF;
        CH14_OFF;
        CH4_ON;
        delay_ms(ledspeed+60);
        CH4_OFF;
        CH11_ON;
        CH12_ON;
        delay_ms(ledspeed+60);
        CH11_OFF;
        CH12_OFF;
        CH3_ON;
        delay_ms(ledspeed+60);
        CH3_OFF;
        CH9_ON;
        CH10_ON;
        delay_ms(ledspeed+60);
        CH9_OFF;
        CH10_OFF;
        CH2_ON;
        delay_ms(ledspeed+60);
        CH2_OFF;
        CH1_ON;
        delay_ms(ledspeed+60);
        CH1_OFF;
        delay_ms(ledspeed+60);
        }
    break;
    case 12:
        if(loop == 1){
            a = 16;
            counter++;
        }
        else{
            a = 1;
        }
        
        for(i = 0; i < a; i++){
        CH1_ON;
        CH2_ON;
        CH3_ON;
        CH4_ON;
        CH5_ON;
        CH6_ON;
        CH13_ON;
        CH14_ON;
        CH15_ON;
        CH16_ON;
        delay_ms(ledspeed+90);
        CH1_OFF;
        CH2_OFF;
        CH3_OFF;
        CH4_OFF;
        CH5_OFF;
        CH6_OFF;
        CH13_OFF;
        CH14_OFF;
        CH15_OFF;
        CH16_OFF;   
        CH7_ON;
        CH8_ON;
        CH9_ON;
        CH10_ON;
        CH11_ON;
        CH12_ON;
        delay_ms(ledspeed+90);
        CH7_OFF;
        CH8_OFF;
        CH9_OFF;
        CH10_OFF;
        CH11_OFF;
        CH12_OFF;
        }

    break;
    case 13:
        if(loop == 1){
            a = 5;
            counter++;
        }
        else{
            a = 1;
        }
        
        for(i = 0; i < a; i++){
        PORTAB_OFF;
        PORTC_OFF;
        CH8_ON;
        CH9_ON;
        delay_ms(ledspeed+15);
        CH8_OFF;
        CH9_OFF;
        CH7_ON;
        CH10_ON;
        delay_ms(ledspeed+15);
        CH7_OFF;
        CH10_OFF;
        CH6_ON;
        CH11_ON;
        delay_ms(ledspeed+15);
        CH6_OFF;
        CH11_OFF;
        CH5_ON;
        CH12_ON;
        delay_ms(ledspeed+15);
        CH5_OFF;
        CH12_OFF;
        CH4_ON;
        CH13_ON;
        delay_ms(ledspeed+15);
        CH4_OFF;
        CH13_OFF;
        CH3_ON;
        CH14_ON;
        delay_ms(ledspeed+15);
        CH3_OFF;
        CH14_OFF;
        CH2_ON;
        CH15_ON;
        delay_ms(ledspeed+15);
        CH2_OFF;
        CH15_OFF;
        CH1_ON;
        CH16_ON;
        delay_ms(ledspeed+15);
        CH1_OFF;
        CH16_OFF;
        CH2_ON;
        CH15_ON;
        delay_ms(ledspeed+15);
        CH2_OFF;
        CH15_OFF;
        CH3_ON;
        CH14_ON;
        delay_ms(ledspeed+15);
        CH3_OFF;
        CH14_OFF;
        CH4_ON;
        CH13_ON;
        delay_ms(ledspeed+15);
        CH4_OFF;
        CH13_OFF;
        CH5_ON;
        CH12_ON;
        delay_ms(ledspeed+15);
        CH5_OFF;
        CH12_OFF;
        CH6_ON;
        CH11_ON;
        delay_ms(ledspeed+15);
        CH6_OFF;
        CH11_OFF;
        CH7_ON;
        CH10_ON;
        delay_ms(ledspeed+15);
        CH7_OFF;
        CH10_OFF;
        CH8_ON;
        CH9_ON;
        delay_ms(ledspeed+15);
        CH7_ON;
        CH10_ON;
        delay_ms(ledspeed+15);
        CH6_ON;
        CH11_ON;
        delay_ms(ledspeed+15);
        CH5_ON;
        CH12_ON;
        delay_ms(ledspeed+15);
        CH4_ON;
        CH13_ON;
        delay_ms(ledspeed+15);
        CH3_ON;
        CH14_ON;
        delay_ms(ledspeed+15);
        CH2_ON;
        CH15_ON;
        delay_ms(ledspeed+15);
        CH1_ON;
        CH16_ON;
        delay_ms(ledspeed+15);
        PORTAB_OFF;
        PORTC_OFF;
        delay_ms(ledspeed+15);
        PORTAB_ON;
        PORTC_ON; 
        delay_ms(ledspeed+15); 
        PORTAB_OFF;
        PORTC_OFF;
        delay_ms(ledspeed+15);
        PORTAB_ON;
        PORTC_ON;
        delay_ms(ledspeed+15);
        PORTAB_OFF;
        PORTC_OFF;
        delay_ms(ledspeed+15);
        PORTAB_ON;
        PORTC_ON;
        delay_ms(ledspeed+15);
        PORTAB_OFF;
        PORTC_OFF;
        delay_ms(ledspeed+15);
        PORTAB_ON;
        PORTC_ON; 
        delay_ms(ledspeed+15);
        PORTAB_OFF;
        PORTC_OFF;
        delay_ms(ledspeed+15);
        PORTAB_ON;
        PORTC_ON;
        delay_ms(ledspeed+15); 
        }    
    break;
    case 14:
        if(loop == 1){
            a = 8;
            counter++;
        }
        else{
            a = 1;
        }
        
        for(i = 0; i < a; i++){
        CH16_ON;
        delay_ms(ledspeed+5);
        CH16_OFF;
        CH15_ON;
        delay_ms(ledspeed+5);
        CH15_OFF;
        CH14_ON;
        delay_ms(ledspeed+5);
        CH14_OFF;
        CH13_ON;
        delay_ms(ledspeed+5);
        CH13_OFF;
        CH12_ON;
        delay_ms(ledspeed+5);
        CH12_OFF;
        CH11_ON;
        delay_ms(ledspeed+5);
        CH11_OFF;
        CH10_ON;
        delay_ms(ledspeed+5);
        CH10_OFF;
        CH9_ON;
        delay_ms(ledspeed+5);
        CH9_OFF;
        CH1_ON;
        delay_ms(ledspeed+5);
        CH1_OFF;
        CH2_ON;
        delay_ms(ledspeed+5);
        CH2_OFF;
        CH3_ON;
        delay_ms(ledspeed+5);
        CH3_OFF;
        CH4_ON;
        delay_ms(ledspeed+5);
        CH4_OFF;
        CH5_ON;
        delay_ms(ledspeed+5);
        CH5_OFF;
        CH6_ON;
        delay_ms(ledspeed+5);
        CH6_OFF;
        CH7_ON;
        delay_ms(ledspeed+5);
        CH7_OFF;
        CH8_ON;
        delay_ms(ledspeed+5);
        CH8_OFF;
        }
    break;
    case 15:
        if(loop == 1){
            a = 3;
            counter++;
        }
        else{
            a = 1;
        }
        
        for(i = 0; i < a; i++){
        CH8_ON;
        CH9_ON;
        delay_ms(ledspeed+40);
        CH8_OFF;
        CH9_OFF;
        CH7_ON;
        CH10_ON;
        delay_ms(ledspeed+40);
        CH7_OFF;
        CH10_OFF;
        CH6_ON;
        CH11_ON;
        delay_ms(ledspeed+40);
        CH6_OFF;
        CH11_OFF;
        CH5_ON;
        CH12_ON;
        delay_ms(ledspeed+40);
        CH1_ON;
        CH16_ON;
        delay_ms(ledspeed+40); 
        CH1_OFF;
        CH16_OFF;
        CH2_ON;
        CH15_ON;
        delay_ms(ledspeed+40);
        CH2_OFF;
        CH15_OFF;
        CH3_ON;
        CH14_ON;
        delay_ms(ledspeed+40);
        CH3_OFF;
        CH14_OFF;
        CH4_ON;
        CH13_ON;
        delay_ms(ledspeed+40);
        CH8_ON;
        CH9_ON;
        delay_ms(ledspeed+40);
        CH8_OFF;
        CH9_OFF;
        CH7_ON;
        CH10_ON;
        delay_ms(ledspeed+40);
        CH7_OFF;
        CH10_OFF;
        CH6_ON;
        CH11_ON;
        delay_ms(ledspeed+40);
        CH1_ON;
        CH16_ON;
        delay_ms(ledspeed+40); 
        CH1_OFF;
        CH16_OFF;
        CH2_ON;
        CH15_ON;
        delay_ms(ledspeed+40);
        CH2_OFF;
        CH15_OFF;
        CH3_ON;
        CH14_ON;
        delay_ms(ledspeed+40);
        CH8_ON;
        CH9_ON;
        delay_ms(ledspeed+40);
        CH8_OFF;
        CH9_OFF;
        CH7_ON;
        CH10_ON;
        delay_ms(ledspeed+40);
        CH1_ON;
        CH16_ON;
        delay_ms(ledspeed+40); 
        CH1_OFF;
        CH16_OFF;
        CH2_ON;
        CH15_ON;
        delay_ms(ledspeed+40);
        CH8_ON;
        CH9_ON;
        delay_ms(ledspeed+40);
        CH1_ON;
        CH16_ON;
        delay_ms(ledspeed+40);
        
        CH5_OFF;
        CH12_OFF;
        delay_ms(ledspeed+40);
        CH5_ON;
        CH12_ON;
        CH6_OFF;
        CH11_OFF;
        delay_ms(ledspeed+40);
        CH6_ON;
        CH11_ON;
        CH7_OFF;
        CH10_OFF;
        delay_ms(ledspeed+40);
        CH7_ON;
        CH10_ON;
        CH8_OFF;
        CH9_OFF;
        delay_ms(ledspeed+40); 
        
        CH4_OFF;
        CH13_OFF;
        delay_ms(ledspeed+40);
        CH4_ON;
        CH13_ON;
        CH3_OFF;
        CH14_OFF;
        delay_ms(ledspeed+40);
        CH3_ON;
        CH14_ON;
        CH2_OFF;
        CH15_OFF;
        delay_ms(ledspeed+40);
        CH2_ON;
        CH15_ON;
        CH1_OFF;
        CH16_OFF;
        delay_ms(ledspeed+40);
        
        CH5_OFF;
        CH12_OFF;
        delay_ms(ledspeed+40);
        CH5_ON;
        CH12_ON;
        CH6_OFF;
        CH11_OFF;
        delay_ms(ledspeed+40);
        CH6_ON;
        CH11_ON;
        CH7_OFF;
        CH10_OFF;
        delay_ms(ledspeed+40);
        
        CH4_OFF;
        CH13_OFF;
        delay_ms(ledspeed+40);
        CH4_ON;
        CH13_ON;
        CH3_OFF;
        CH14_OFF;
        delay_ms(ledspeed+40);
        CH3_ON;
        CH14_ON;
        CH2_OFF;
        CH15_OFF;
        delay_ms(ledspeed+40);
        
        CH5_OFF;
        CH12_OFF;
        delay_ms(ledspeed+40);
        CH5_ON;
        CH12_ON;
        CH6_OFF;
        CH11_OFF;
        delay_ms(ledspeed+40);
        
        CH4_OFF;
        CH13_OFF;
        delay_ms(ledspeed+40);
        CH4_ON;
        CH13_ON;
        CH3_OFF;
        CH14_OFF;
        delay_ms(ledspeed+40);
        
        CH5_OFF;
        CH12_OFF;
        delay_ms(ledspeed+40);
        
        CH4_OFF;
        CH13_OFF;
        delay_ms(ledspeed+40);
        }
    break;
    case 16:
        if(loop == 1){
            a = 5;
            counter++;
        }
        else{
            a = 1;
        }
        
        for(i = 0; i < a; i++){
        CH8_ON;
        CH9_ON;
        delay_ms(ledspeed+20);
        CH7_ON;
        CH10_ON;
        delay_ms(ledspeed+40);
        CH6_ON;
        CH11_ON;
        delay_ms(ledspeed+40);
        CH5_ON;
        CH12_ON;
        delay_ms(ledspeed+40);
        CH4_ON;
        CH13_ON;
        delay_ms(ledspeed+40);
        CH3_ON;
        CH14_ON;
        delay_ms(ledspeed+40);
        CH2_ON;
        CH15_ON;
        delay_ms(ledspeed+40);
        CH1_ON;
        CH16_ON;
        delay_ms(ledspeed+15);
        PORTAB_OFF;
        PORTC_OFF;
        delay_ms(ledspeed+15);
        PORTAB_ON;
        PORTC_ON;
        delay_ms(ledspeed+15);
        PORTAB_OFF;
        PORTC_OFF;
        delay_ms(ledspeed+15);
        PORTAB_ON;
        PORTC_ON;
        delay_ms(ledspeed+15);
        PORTAB_OFF;
        PORTC_OFF;
        delay_ms(ledspeed+15);
        PORTAB_ON;
        PORTC_ON;
        delay_ms(ledspeed+15);
        PORTAB_OFF;
        PORTC_OFF;
        delay_ms(ledspeed+15);
        PORTAB_ON;
        PORTC_ON;
        delay_ms(ledspeed+15);
        PORTAB_OFF;
        PORTC_OFF;
        delay_ms(ledspeed+15);
        PORTAB_ON;
        PORTC_ON;
        delay_ms(ledspeed+15);
        CH8_OFF;
        CH9_OFF;
        delay_ms(ledspeed+20);
        CH7_OFF;
        CH10_OFF;
        delay_ms(ledspeed+40);
        CH6_OFF;
        CH11_OFF;
        delay_ms(ledspeed+40);
        CH5_OFF;
        CH12_OFF;
        delay_ms(ledspeed+40);
        CH4_OFF;
        CH13_OFF;
        delay_ms(ledspeed+40);
        CH3_OFF;
        CH14_OFF;
        delay_ms(ledspeed+40);
        CH2_OFF;
        CH15_OFF;
        delay_ms(ledspeed+40);
        CH1_OFF;
        CH16_OFF;
        delay_ms(ledspeed+40);
        }
    break;
    case 17:
        if(loop == 1){
            a = 4;
            counter++;
        }
        else{
            a = 1;
        }
        
        for(i = 0; i < a; i++){
        for(k = 0; k < 4; k++){
        CH1_ON;
        CH9_ON;
        delay_ms(ledspeed);
        CH1_OFF;
        CH2_ON;
        CH9_OFF;
        CH10_ON;
        delay_ms(ledspeed);
        CH2_OFF;
        CH3_ON;
        CH10_OFF;
        CH11_ON;
        delay_ms(ledspeed);
        CH3_OFF;
        CH4_ON;
        CH11_OFF;
        CH12_ON;
        delay_ms(ledspeed);
        CH4_OFF;
        CH5_ON;
        CH12_OFF;
        CH13_ON;
        delay_ms(ledspeed);
        CH5_OFF;
        CH6_ON;
        CH13_OFF;
        CH14_ON;
        delay_ms(ledspeed);
        CH6_OFF;
        CH7_ON;
        CH14_OFF;
        CH15_ON;
        delay_ms(ledspeed);
        CH7_OFF;
        CH8_ON;
        CH15_OFF;
        CH16_ON;
        delay_ms(ledspeed);
        CH8_OFF;
        CH16_OFF;
        delay_ms(ledspeed);
        }
        for(k = 0; k < 3; k++){
        CH8_ON;
        CH16_ON;
        delay_ms(ledspeed);
        CH7_ON;
        CH15_ON;
        delay_ms(ledspeed);
        CH6_ON;
        CH14_ON;
        delay_ms(ledspeed);
        CH5_ON;
        CH13_ON;
        delay_ms(ledspeed);
        CH4_ON;
        CH12_ON;
        delay_ms(ledspeed);
        CH3_ON;
        CH11_ON;
        delay_ms(ledspeed); 
        CH2_ON;
        CH10_ON;
        delay_ms(ledspeed);
        CH1_ON;
        CH9_ON;
        delay_ms(ledspeed);
        CH1_OFF;
        CH9_OFF;
        delay_ms(ledspeed);
        CH2_OFF;
        CH10_OFF;
        delay_ms(ledspeed);
        CH3_OFF;
        CH11_OFF;
        delay_ms(ledspeed);
        CH4_OFF;
        CH12_OFF;
        delay_ms(ledspeed);
        CH5_OFF;
        CH13_OFF;
        delay_ms(ledspeed);
        CH6_OFF;
        CH14_OFF;
        delay_ms(ledspeed);
        CH7_OFF;
        CH15_OFF;
        delay_ms(ledspeed);
        CH8_OFF;
        CH16_OFF;
        delay_ms(ledspeed);
        }
        }
    break;
    case 18:
        if(loop == 1){
            a = 8;
            counter = 0; 
        }
        else{
            a = 1;
        }
        
        for(i = 0; i < a; i++){
        CH1_ON;
        delay_ms(ledspeed);
        CH1_OFF;
        CH2_ON;
        delay_ms(ledspeed);
        CH2_OFF;
        CH3_ON;
        delay_ms(ledspeed);
        CH3_OFF;
        CH4_ON;
        delay_ms(ledspeed);
        CH4_OFF;
        CH5_ON;
        delay_ms(ledspeed);
        CH5_OFF;
        CH6_ON;
        delay_ms(ledspeed);
        CH6_OFF;
        CH7_ON;
        delay_ms(ledspeed);
        CH7_OFF;
        CH8_ON;
        delay_ms(ledspeed);
        CH8_OFF;
        CH16_ON;
        delay_ms(ledspeed);
        CH16_OFF;
        CH15_ON;
        delay_ms(ledspeed);
        CH15_OFF;
        CH14_ON;
        delay_ms(ledspeed);
        CH14_OFF;
        CH13_ON;
        delay_ms(ledspeed);
        CH13_OFF;
        CH12_ON;
        delay_ms(ledspeed); 
        CH12_OFF;
        CH11_ON;
        delay_ms(ledspeed);
        CH11_OFF;
        CH10_ON;
        delay_ms(ledspeed);
        CH10_OFF;
        CH9_ON;
        delay_ms(ledspeed);
        CH9_OFF;
        CH10_ON;
        delay_ms(ledspeed);
        CH10_OFF;
        CH11_ON;
        delay_ms(ledspeed);
        CH11_OFF;
        CH12_ON;
        delay_ms(ledspeed);
        CH12_OFF;
        CH13_ON;
        delay_ms(ledspeed);
        CH13_OFF;
        CH14_ON;
        delay_ms(ledspeed);
        CH14_OFF;
        CH15_ON;
        delay_ms(ledspeed);
        CH15_OFF;
        CH16_ON;
        delay_ms(ledspeed);
        CH16_OFF;
        CH8_ON;
        delay_ms(ledspeed);
        CH8_OFF;
        CH7_ON;
        delay_ms(ledspeed);
        CH7_OFF;
        CH6_ON;
        delay_ms(ledspeed);
        CH6_OFF;
        CH5_ON;
        delay_ms(ledspeed);
        CH5_OFF;
        CH4_ON;
        delay_ms(ledspeed);
        CH4_OFF;
        CH3_ON;
        delay_ms(ledspeed);
        CH3_OFF;
        CH2_ON;
        delay_ms(ledspeed);
        CH2_OFF;
        CH1_ON;
        delay_ms(ledspeed);
        CH1_OFF;
        delay_ms(ledspeed); 
        }
    break; 
    case 19:
                    
        TCCR2B=0x01;
        TIMSK2=0x01;
        
        if(direction1 & 1) ch1++;       
        else ch1--; 
                
        if(direction1 & 0B00000010) ch2++;      
        else ch2--;  
               
        if(direction1 & 0B00000100) ch3++;      
        else ch3--; 
                
        if(direction1 & 0B00001000) ch4++;      
        else ch4--; 
                
        if(direction1 & 0B00010000) ch5++;     
        else ch5--;
        
        if(direction1 & 0B00100000) ch6++;       
        else ch6--; 
                
        if(direction1 & 0B01000000) ch7++;      
        else ch7--;  
               
        if(direction1 & 0B10000000) ch8++;      
        else ch8--; 
                
        if(direction2 & 0B00000001) ch9++;      
        else ch9--; 
                
        if(direction2 & 0B00000010) ch10++;     
        else ch10--;
        
        if(direction2 & 0B00000100) ch11++;      
        else ch11--; 
                
        if(direction2 & 0B00001000) ch12++;     
        else ch12--;
        
        if(direction2 & 0B00010000) ch13++;      
        else ch13--; 
                
        if(direction2 & 0B00100000) ch14++;     
        else ch14--;
        
        if(direction2 & 0B01000000) ch15++;      
        else ch15--; 
                
        if(direction2 & 0B10000000) ch16++;     
        else ch16--;          
    
        if(ch1 > 254) direction1 &= ~0B00000001;
        else if(ch1 < 1) direction1 |= 0B00000001;       
    
        if(ch2 > 254) direction1 &= ~0B00000010;
        else if(ch2 < 1) direction1 |= 0B00000010;       
    
        if(ch3 > 254) direction1 &= ~0B00000100;
        else if(ch3 < 1) direction1 |= 0B00000100;      
    
        if(ch4 > 254) direction1 &= ~0B00001000;
        else if(ch4 < 1) direction1 |= 0B00001000;       
    
        if(ch5 > 254) direction1 &= ~0B00010000;
        else if(ch5 < 1) direction1 |= 0B00010000;
        
        if(ch6 > 254) direction1 &= ~0B00100000;
        else if(ch6 < 1) direction1 |= 0B00100000;       
    
        if(ch7 > 254) direction1 &= ~0B01000000;
        else if(ch7 < 1) direction1 |= 0B01000000;       
    
        if(ch8 > 254) direction1 &= ~0B10000000;
        else if(ch8 < 1) direction1 |= 0B10000000;      
                                                  
        if(ch9 > 254) direction2 &= ~0B00000001;
        else if(ch9 < 1) direction2 |= 0B00000001;       
    
        if(ch10 > 254) direction2 &= ~0B00000010;
        else if(ch10 < 1) direction2 |= 0B00000010; 
        
        if(ch11 > 254) direction2 &= ~0B00000100;
        else if(ch11 < 1) direction2 |= 0B00000100;       
    
        if(ch12 > 254) direction2 &= ~0B00001000;
        else if(ch12 < 1) direction2 |= 0B00001000;
        
        if(ch13 > 254) direction2 &= ~0B00010000;
        else if(ch13 < 1) direction2 |= 0B00010000;       
    
        if(ch14 > 254) direction2 &= ~0B00100000;
        else if(ch14 < 1) direction2 |= 0B00100000;
        
        if(ch15 > 254) direction2 &= ~0B01000000;
        else if(ch15 < 1) direction2 |= 0B01000000;       
    
        if(ch16 > 254) direction2 &= ~0B10000000;
        else if(ch16 < 1) direction2 |= 0B10000000;
 
        delay_ms(1);
        
    break;
    default:
        
    
    break;
  }

}

}

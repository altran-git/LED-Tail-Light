#ifndef _LEDUTIL_
#define _LEDUTIL_

#pragma used+

#define CH1_ON do{(PORTA |= (1<<0)); (PORTB |= (1<<7));} while(0)
#define CH2_ON do{(PORTA |= (1<<1)); (PORTB |= (1<<6));} while(0)
#define CH3_ON do{(PORTA |= (1<<2)); (PORTB |= (1<<5));} while(0)
#define CH4_ON do{(PORTA |= (1<<3)); (PORTB |= (1<<4));} while(0)
#define CH5_ON do{(PORTA |= (1<<4)); (PORTB |= (1<<3));} while(0)
#define CH6_ON do{(PORTA |= (1<<5)); (PORTB |= (1<<2));} while(0)
#define CH7_ON do{(PORTA |= (1<<6)); (PORTB |= (1<<1));} while(0)
#define CH8_ON do{(PORTA |= (1<<7)); (PORTB |= (1<<0));} while(0)

#define CH9_ON (PORTC |= (1<<0))
#define CH10_ON (PORTC |= (1<<1))
#define CH11_ON (PORTC |= (1<<2))
#define CH12_ON (PORTC |= (1<<3))
#define CH13_ON (PORTC |= (1<<4))
#define CH14_ON (PORTC |= (1<<5))
#define CH15_ON (PORTC |= (1<<6))
#define CH16_ON (PORTC |= (1<<7))

#define CH1_OFF do{(PORTA &= ~(1<<0)); (PORTB &= ~(1<<7));} while(0)
#define CH2_OFF do{(PORTA &= ~(1<<1)); (PORTB &= ~(1<<6));} while(0)
#define CH3_OFF do{(PORTA &= ~(1<<2)); (PORTB &= ~(1<<5));} while(0)
#define CH4_OFF do{(PORTA &= ~(1<<3)); (PORTB &= ~(1<<4));} while(0)
#define CH5_OFF do{(PORTA &= ~(1<<4)); (PORTB &= ~(1<<3));} while(0)
#define CH6_OFF do{(PORTA &= ~(1<<5)); (PORTB &= ~(1<<2));} while(0)
#define CH7_OFF do{(PORTA &= ~(1<<6)); (PORTB &= ~(1<<1));} while(0)
#define CH8_OFF do{(PORTA &= ~(1<<7)); (PORTB &= ~(1<<0));} while(0)

#define CH9_OFF (PORTC &= ~(1<<0))
#define CH10_OFF (PORTC &= ~(1<<1))
#define CH11_OFF (PORTC &= ~(1<<2))
#define CH12_OFF (PORTC &= ~(1<<3))
#define CH13_OFF (PORTC &= ~(1<<4))
#define CH14_OFF (PORTC &= ~(1<<5))
#define CH15_OFF (PORTC &= ~(1<<6))
#define CH16_OFF (PORTC &= ~(1<<7))

#define CH1_TOGGLE do{(PORTA ^= (1<<0)); (PORTB ^= (1<<7));} while(0)
#define CH2_TOGGLE do{(PORTA ^= (1<<1)); (PORTB ^= (1<<6));} while(0)
#define CH3_TOGGLE do{(PORTA ^= (1<<2)); (PORTB ^= (1<<5));} while(0)
#define CH4_TOGGLE do{(PORTA ^= (1<<3)); (PORTB ^= (1<<4));} while(0)
#define CH5_TOGGLE do{(PORTA ^= (1<<4)); (PORTB ^= (1<<3));} while(0)
#define CH6_TOGGLE do{(PORTA ^= (1<<5)); (PORTB ^= (1<<2));} while(0)
#define CH7_TOGGLE do{(PORTA ^= (1<<6)); (PORTB ^= (1<<1));} while(0)
#define CH8_TOGGLE do{(PORTA ^= (1<<7)); (PORTB ^= (1<<0));} while(0)

#define CH9_TOGGLE (PORTC ^= (1<<0))
#define CH10_TOGGLE (PORTC ^= (1<<1))
#define CH11_TOGGLE (PORTC ^= (1<<2))
#define CH12_TOGGLE (PORTC ^= (1<<3))
#define CH13_TOGGLE (PORTC ^= (1<<4))
#define CH14_TOGGLE (PORTC ^= (1<<5))
#define CH15_TOGGLE (PORTC ^= (1<<6))
#define CH16_TOGGLE (PORTC ^= (1<<7))

#define PORTAB_ON do{(PORTA |= ((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7))); (PORTB |= ((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7)));} while(0)
#define PORTC_ON PORTC |= ((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7))

#define PORTAB_OFF do{(PORTA &= ~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7))); (PORTB &= ~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7)));} while(0)
#define PORTC_OFF PORTC &= ~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7))

#define TIME_OFFSET 30; 
#pragma used-

#endif

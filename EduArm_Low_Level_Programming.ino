/*
* Project_VXL.c
*
* Created: 12/12/2024 10:37:46
* Author : Nguyen Hoai Nam
*/
#define F_CPU 16000000UL

#define MIN_S0 460
#define MAX_S0 2520
#define MIN_S1 480
#define MAX_S1 2430
#define MIN_S2 730
#define MAX_S2 2390
#define MIN_S3 480
#define MAX_S3 2480
#define MIN_S4 560
#define MAX_S4 2410
#define MIN_S5 1040
#define MAX_S5 1714

#define MIN_A0 0
#define MAX_A0 1023
#define MIN_A1 245
#define MAX_A1 963
#define MIN_A2 0
#define MAX_A2 530
#define MIN_A3 187
#define MAX_A3 904
#define MIN_A4 0
#define MAX_A4 1023
#define MIN_A5 0
#define MAX_A5 1023

#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <math.h>

enum State {
  S0_ON,
  S0_OFF,
  S1_ON,
  S1_OFF,
  S2_ON,
  S2_OFF,
  S3_ON,
  S3_OFF,
  S4_ON,
  S4_OFF,
  S5_ON,
  S5_OFF
};

volatile State state = S5_OFF;
uint16_t top0, top1, top2, top3, top4, top5;

ISR(TIMER1_COMPA_vect) {
  switch (state) {
    case S0_ON:
      {
        PORTD &= ~(1 << PORTD2);
        OCR1A = 6600 - top0;
        state = S0_OFF;
        break;
      }
    case S0_OFF:
      {
        PORTD |= 1 << PORTD3;
        OCR1A = top1;
        state = S1_ON;
        break;
      }
    case S1_ON:
      {
        PORTD &= ~(1 << PORTD3);
        OCR1A = 6600 - top1;
        state = S1_OFF;
        break;
      }
    case S1_OFF:
      {
        PORTD |= 1 << PORTD4;
        OCR1A = top2;
        state = S2_ON;
        break;
      }
    case S2_ON:
      {
        PORTD &= ~(1 << PORTD4);
        OCR1A = 6600 - top2;
        state = S2_OFF;
        break;
      }
    case S2_OFF:
      {
        PORTD |= 1 << PORTD5;
        OCR1A = top3;
        state = S3_ON;
        break;
      }
    case S3_ON:
      {
        PORTD &= ~(1 << PORTD5);
        OCR1A = 6600 - top3;
        state = S3_OFF;
        break;
      }
    case S3_OFF:
      {
        PORTD |= 1 << PORTD6;
        OCR1A = top4;
        state = S4_ON;
        break;
      }
    case S4_ON:
      {
        PORTD &= ~(1 << PORTD6);
        OCR1A = 6600 - top4;
        state = S4_OFF;
        break;
      }
    case S4_OFF:
      {
        PORTD |= 1 << PORTD7;
        OCR1A = top5;
        state = S5_ON;
        break;
      }
    case S5_ON:
      {
        PORTD &= ~(1 << PORTD7);
        OCR1A = 7000 - top5;
        state = S5_OFF;
        break;
      }
    case S5_OFF:
      {
        PORTD |= 1 << PORTD2;
        OCR1A = top0;
        state = S0_ON;
        break;
      }
    default:
      {
      }
  }
}

void init_adc() {
  //Select reference vontage: AVcc
  ADMUX |= 1 << REFS0;
  //Disable digital input on ADC5..0
  DIDR0 |= 0x3F;
  //Select prescaler = 128; 1 ADC cycle about 8 us
  ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);
  //Enable ADC
  ADCSRA |= 1 << ADEN;
}

uint16_t read_adc(uint8_t channel) {
  uint16_t result = 0xFFFF;
  switch (channel) {
    case 0:
      {
        //Select channel
        ADMUX = 0x40;
        //Start conversion
        ADCSRA |= 1 << ADSC;
        //Waiting for conversion...
        while ((ADCSRA & (1 << ADIF)) == 0)
          ;
        //Read result
        result = ADCL + (ADCH << 8);
        //Clear flag bit (Note: write 1 to clear)
        ADCSRA |= 1 << ADIF;
        break;
      }
    case 1:
      {
        //Select channel
        ADMUX = 0x41;
        //Start conversion
        ADCSRA |= 1 << ADSC;
        //Waiting for conversion...
        while ((ADCSRA & (1 << ADIF)) == 0)
          ;
        result = ADCL + (ADCH << 8);
        //Clear flag bit (Note: write 1 to clear)
        ADCSRA |= 1 << ADIF;
        break;
      }
    case 2:
      {
        //Select channel
        ADMUX = 0x42;
        //Start conversion
        ADCSRA |= 1 << ADSC;
        //Waiting for conversion...
        while ((ADCSRA & (1 << ADIF)) == 0)
          ;
        result = ADCL + (ADCH << 8);
        //Clear flag bit (Note: write 1 to clear)
        ADCSRA |= 1 << ADIF;
        break;
      }
    case 3:
      {
        //Select channel
        ADMUX = 0x43;
        //Start conversion
        ADCSRA |= 1 << ADSC;
        //Waiting for conversion...
        while ((ADCSRA & (1 << ADIF)) == 0)
          ;
        result = ADCL + (ADCH << 8);
        //Clear flag bit (Note: write 1 to clear)
        ADCSRA |= 1 << ADIF;
        break;
      }
    case 4:
      {
        //Select channel
        ADMUX = 0x44;
        //Start conversion
        ADCSRA |= 1 << ADSC;
        //Waiting for conversion...
        while ((ADCSRA & (1 << ADIF)) == 0)
          ;
        result = ADCL + (ADCH << 8);
        //Clear flag bit (Note: write 1 to clear)
        ADCSRA |= 1 << ADIF;
        break;
      }
    case 5:
      {
        //Select channel
        ADMUX = 0x45;
        //Start conversion
        ADCSRA |= 1 << ADSC;
        //Waiting for conversion...
        while ((ADCSRA & (1 << ADIF)) == 0)
          ;
        result = ADCL + (ADCH << 8);
        //Clear flag bit (Note: write 1 to clear)
        ADCSRA |= 1 << ADIF;
        break;
      }
    default:;
  }
  return result;
}

long convert(long val, long in_min, long in_max, long out_min, long out_max) {
  if (val < in_min) return out_min;
  else {
    if (val > in_max) return out_max;
  }
  long out = out_min + (val - in_min) * (out_max - out_min) / (in_max - in_min);
  return out;
}


int main(void) {
  Serial.begin(9600);
  init_adc();
  //CTC (mode 4 with TOP define by OCR1A); Prescale: 8
  TCCR1B |= (1 << WGM12) | (1 << CS11);
  uint16_t a0 = read_adc(0);
  uint16_t a1 = read_adc(1);
  uint16_t a2 = read_adc(2);
  uint16_t a3 = read_adc(3);
  uint16_t a4 = read_adc(4);
  uint16_t a5 = read_adc(5);

  top0 = 2 * convert(a0, MIN_A0, MAX_A0, MAX_S0, MIN_S0);
  top1 = 2 * convert(a1, MIN_A1, MAX_A1, MAX_S1, MIN_S1);
  top2 = 2 * convert(a2, MIN_A2, MAX_A2, MIN_S2, MAX_S2);
  top3 = 2 * convert(a3, MIN_A3, MAX_A3, MIN_S3, MAX_S3);
  top4 = 2 * convert(a4, MIN_A4, MAX_A4, MIN_S4, MAX_S4);
  top5 = 2 * convert(a5, MIN_A5, MAX_A5, MIN_S5, MAX_S5);

  //Set pin 2 - pin 7 is output
  DDRD |= 0xFC;
  //Enable ISR OCR1A
  TIMSK1 |= 1 << OCIE1A;
  sei();

  while (1) {
    uint16_t a0 = read_adc(0);
    uint16_t a1 = read_adc(1);
    uint16_t a2 = read_adc(2);
    uint16_t a3 = read_adc(3);
    uint16_t a4 = read_adc(4);
    uint16_t a5 = read_adc(5);

    top0 = 2 * convert(a0, MIN_A0, MAX_A0, MAX_S0, MIN_S0);
    top1 = 2 * convert(a1, MIN_A1, MAX_A1, MAX_S1, MIN_S1);
    top2 = 2 * convert(a2, MIN_A2, MAX_A2, MIN_S2, MAX_S2);
    top3 = 2 * convert(a3, MIN_A3, MAX_A3, MIN_S3, MAX_S3);
    top4 = 2 * convert(a4, MIN_A4, MAX_A4, MIN_S4, MAX_S4);
    top5 = 2 * convert(a5, MIN_A5, MAX_A5, MIN_S5, MAX_S5);

    Serial.println("A0: " + String(top0) + "\tA1: " + String(a1) + "\tA2: " + String(a2) + "\tA3: " + String(a3) + "\tA4: " + String(a4) + "\tA5: " + String(a5));

    _delay_ms(10);
  }
}

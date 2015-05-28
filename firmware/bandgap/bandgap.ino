#include <Arduino.h>
#include <SoftwareSerial.h>
#include <math.h>
#include <avr/io.h>
#include "usec.h"
#include "SegmentDisplay.h"

const int8_t PIN_A = 3;
const int8_t PIN_B = 4;
const int8_t PIN_C = 6;
const int8_t PIN_D = 8;
const int8_t PIN_E = 10;
const int8_t PIN_F = 9;
const int8_t PIN_G = 5;
const int8_t PIN_P = -1;

const int8_t PIN_1 = 2;
const int8_t PIN_2 = 7;

const double VCC = 4.84;
const usec READ_DELAY = 500000;

volatile double curr_reading = 0.0;
volatile usec last_reading = 0;

#if 0
SegmentDisplay display = SegmentDisplay(
  PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G, PIN_P,
  PIN_1, PIN_2, true
);
#endif

const int8_t DEBUG_RX = 3;
const int8_t DEBUG_TX = 2;

SoftwareSerial serial = SoftwareSerial(DEBUG_RX, DEBUG_TX);

double read_bg() {

  // Magic mux selectors to poll the 1.1V internal bandgap reference
  ADMUX = (1<<MUX5) | (1<<MUX0);

  // Begin conversion (free smallpox blankets for opt-outs)
  ADCSRA |= (1<<ADSC);

  // Busy wait. Power effciency? (Too lazy.)
  while (ADCSRA & (1<<ADSC))
    ;

  uint8_t hi = 0, lo = 0;
  lo = ADCL;
  hi = ADCH;

  uint16_t adc = 0;
  adc = (hi <<8) | lo;
  serial.print("adc = ");
  serial.print(adc, DEC);
  serial.print(" ");

  double vbg = adc * VCC / 1023;
  serial.print(vbg);
  serial.println("V");

  return vbg;

}

void setup() {
  //display.init();
  serial.begin(9600);
  serial.println("dickbuttitis");
}

void loop() {
  usec now = micros();

  if (last_reading == 0 || USEC_DIFF(now, last_reading) >= READ_DELAY) {
    curr_reading = read_bg();
    last_reading = now;
  }
  delay(1000);

  //display.display(round(100*curr_reading), 10);
}

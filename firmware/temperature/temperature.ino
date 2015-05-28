#include <Arduino.h>
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

const int8_t TMP36_VCC = 0;
const int8_t TMP36_OUT = 1;

const double  BANDGAP = 1.095;
const usec READ_DELAY = 1000000;

const uint16_t ADC_MAX       = 1023;
const  uint8_t ADMUX_BANDGAP = (1<<MUX5) | (1<<MUX0);
const  uint8_t ADMUX_PA1     = (1<<MUX0);

double curr_vcc     = 4.62;
double curr_reading = 0.0;
usec   last_reading = 0;

SegmentDisplay display = SegmentDisplay(
  PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G, PIN_P,
  PIN_1, PIN_2, true
);

//#include <SoftwareSerial.h>
//const int8_t DEBUG_RX = 3;
//const int8_t DEBUG_TX = 2;
//SoftwareSerial serial = SoftwareSerial(DEBUG_RX, DEBUG_TX);

uint16_t aread(bool readBandgap) {

  if (readBandgap) {
    // Magic mux selector to poll the 1.1V internal bandgap reference
    ADMUX = ADMUX_BANDGAP;
  } else {
    // Otherwise, hit pin PA1/ADC1
    ADMUX = ADMUX_PA1;
  }

  // Pause a bit to allow things to stabilize
  delay(1);

  // Begin conversion (free smallpox blankets for opt-outs)
  ADCSRA |= (1<<ADSC);

  // Busy wait. Power effciency? (Too lazy.)
  while (ADCSRA & (1<<ADSC))
    ;

  // Slurp up ADC value
  uint8_t hi = 0, lo = 0;
  lo = ADCL;
  hi = ADCH;

  uint16_t adc = (hi << 8) | lo;
  //serial.print("adc = ");
  //serial.print(adc, DEC);
  //serial.println(" ");

  return adc;
}

double read_vcc() {

  uint16_t adc = aread(true);
  double vcc = BANDGAP * ADC_MAX / adc;
  //serial.print("vcc = ");
  //serial.print(vcc);
  //serial.println("V");

  return vcc;

}

double read_tmp36(double vcc) {

  uint16_t adc = aread(false);
  double vtemp = vcc * adc / ADC_MAX;

  //serial.print("vtemp = ");
  //serial.print(vtemp);
  //serial.println("V");

  return vtemp;
}

double to_centigrade(double reading) {
  return 100 * reading - 50;
}

double to_fahrenheit(double reading) {
  return 180 * reading - 58;
}

void setup() {
  pinMode(TMP36_VCC, OUTPUT);
  pinMode(TMP36_OUT, INPUT);
  digitalWrite(TMP36_VCC, HIGH);
  display.init();
  //serial.begin(9600);
  //serial.println("dickbutts");
}

void loop() {
  usec now = micros();

  if (last_reading == 0 || USEC_DIFF(now, last_reading) >= READ_DELAY) {
    last_reading = now;
    curr_vcc = read_vcc();
    curr_reading = read_tmp36(curr_vcc);
  }

  display.display(round(to_fahrenheit(curr_reading)), 10);

  //display.display(round(100.0*curr_reading), 10);
  //serial.print(curr_reading);
  //serial.println("V");

  //serial.print("temp = ");
  //serial.print(to_fahrenheit(curr_reading));
  //serial.print("C / ");
  //serial.print(to_centigrade(curr_reading));
  //serial.println("F");

}

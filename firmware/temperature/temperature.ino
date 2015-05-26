#include <Arduino.h>
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

const size_t NUM_READINGS = 8;

const int BLINK_DELAY = 50; //ms

const double VCC = 5.0;
const int ADC_PRECISION = 10;

SegmentDisplay display = SegmentDisplay(
  PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G, PIN_P,
  PIN_1, PIN_2, -1, -1, true
);

double adc_to_centigrade(int adc) {
  return 100*adc*(VCC / (1 << ADC_PRECISION)) - 50;
}

double read_tmp36() {
  int32_t sum = 0;

  // Power up sensor and wait for warm-up
  digitalWrite(TMP36_VCC, HIGH);
  delay(50);

  // Take a couple of readings
  for (size_t i=0; i<NUM_READINGS; i++) {
    sum += analogRead(TMP36_OUT);
    delay(5);
  }

  // Power down
  digitalWrite(TMP36_VCC, LOW);

  // Return average
  return adc_to_centigrade(sum / NUM_READINGS);
}

void setup() {
  pinMode(TMP36_VCC, OUTPUT);
  pinMode(TMP36_OUT, INPUT);
  display.init();
}

void loop() {
  //usec t = (millis() / 1000) % 100;
  int t = (int)read_tmp36();
  display.display(t % 100, 10);
}

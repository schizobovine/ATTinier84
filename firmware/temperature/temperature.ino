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

const int8_t DIG_1 = 2;
const int8_t DIG_2 = 7;

const int8_t TMP36_VCC = 0;
const int8_t TMP36_OUT = 1;

const size_t NUM_READINGS = 8;

const int BLINK_DELAY = 50; //ms

SegmentDisplay display = SegmentDisplay(
  PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G, PIN_P,
  DIG_1, DIG_2, -1, -1, true
);

void test_display() {

  // Initialize display to known state by setting all pins to high impedance
  SET_Z(PIN_A);
  SET_Z(PIN_B);
  SET_Z(PIN_C);
  SET_Z(PIN_D);
  SET_Z(PIN_E);
  SET_Z(PIN_F);
  SET_Z(PIN_G);
  SET_Z(PIN_P);
  SET_Z(DIG_1);
  SET_Z(DIG_2);

  // Digit 1 test individual segments
  SET_L(DIG_1);
  SET_H(PIN_A); delay(BLINK_DELAY); SET_Z(PIN_A);
  SET_H(PIN_B); delay(BLINK_DELAY); SET_Z(PIN_B);
  SET_H(PIN_C); delay(BLINK_DELAY); SET_Z(PIN_C);
  SET_H(PIN_D); delay(BLINK_DELAY); SET_Z(PIN_D);
  SET_H(PIN_E); delay(BLINK_DELAY); SET_Z(PIN_E);
  SET_H(PIN_F); delay(BLINK_DELAY); SET_Z(PIN_F);
  SET_H(PIN_G); delay(BLINK_DELAY); SET_Z(PIN_G);
  SET_H(PIN_P); delay(BLINK_DELAY); SET_Z(PIN_P);
  SET_Z(DIG_1);

  // Digit 2 test individual segments
  SET_L(DIG_2);
  SET_H(PIN_A); delay(BLINK_DELAY); SET_Z(PIN_A);
  SET_H(PIN_B); delay(BLINK_DELAY); SET_Z(PIN_B);
  SET_H(PIN_C); delay(BLINK_DELAY); SET_Z(PIN_C);
  SET_H(PIN_D); delay(BLINK_DELAY); SET_Z(PIN_D);
  SET_H(PIN_E); delay(BLINK_DELAY); SET_Z(PIN_E);
  SET_H(PIN_F); delay(BLINK_DELAY); SET_Z(PIN_F);
  SET_H(PIN_G); delay(BLINK_DELAY); SET_Z(PIN_G);
  SET_H(PIN_P); delay(BLINK_DELAY); SET_Z(PIN_P);
  SET_Z(DIG_2);

}

int read_tmp36() {
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
  return sum / NUM_READINGS;
}

void setup() {

  pinMode(TMP36_VCC, OUTPUT);
  pinMode(TMP36_OUT, INPUT);

}

void loop() {

  // Test display
  test_display();

  delay(1000);
}

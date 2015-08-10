#include <Arduino.h>

const int8_t LED_A = 8;
const int8_t LED_K = 9;

void setup() {
  pinMode(LED_A, OUTPUT);
  pinMode(LED_K, INPUT);
  digitalWrite(LED_A, LOW);
  digitalWrite(LED_K, LOW);
}

void loop() {
  digitalWrite(LED_A, HIGH);
  delay(10);
  digitalWrite(LED_A, LOW);
  delay(20);
}

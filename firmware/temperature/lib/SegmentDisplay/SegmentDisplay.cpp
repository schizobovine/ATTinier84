//
// SegmentDisplay.ino
//
// Arduino library to encapsulate segmented displays, typically of the 7-8
// segment, 1-4 digit varities.
//
// Author: Sean Caulfield <sean@yak.net>
// License: GPL v2
//

#include <Arduino.h>
#include "SegmentDisplay.h"

SegmentDisplay::SegmentDisplay(
  int8_t a, int8_t b, int8_t c, int8_t d,
  int8_t e, int8_t f, int8_t g, int8_t p,
  int8_t dig1
) {
  SegmentDisplay(a, b, c, d, e, f, g, p, dig1, -1, -1, -1, true);
}

SegmentDisplay::SegmentDisplay(
  int8_t a, int8_t b, int8_t c, int8_t d,
  int8_t e, int8_t f, int8_t g, int8_t p,
  int8_t dig1, int8_t dig2
) {
  SegmentDisplay(a, b, c, d, e, f, g, p, dig1, dig2, -1, -1, true);
}

SegmentDisplay::SegmentDisplay(
  int8_t a, int8_t b, int8_t c, int8_t d,
  int8_t e, int8_t f, int8_t g, int8_t p,
  int8_t dig1, int8_t dig2, int8_t dig3
) {
  SegmentDisplay(a, b, c, d, e, f, g, p, dig1, dig2, dig3, -1, true);
}

SegmentDisplay::SegmentDisplay(
  int8_t a, int8_t b, int8_t c, int8_t d,
  int8_t e, int8_t f, int8_t g, int8_t p,
  int8_t dig1, int8_t dig2, int8_t dig3, int8_t dig4
) {
  SegmentDisplay(a, b, c, d, e, f, g, p, dig1, dig2, dig3, dig4, true);
}

SegmentDisplay::SegmentDisplay(
  int8_t a, int8_t b, int8_t c, int8_t d,
  int8_t e, int8_t f, int8_t g, int8_t p,
  int8_t dig1,
  boolean _cc
) {
  SegmentDisplay(a, b, c, d, e, f, g, p, dig1, -1, -1, -1, _cc);
}

SegmentDisplay::SegmentDisplay(
  int8_t a, int8_t b, int8_t c, int8_t d,
  int8_t e, int8_t f, int8_t g, int8_t p,
  int8_t dig1, int8_t dig2,
  boolean _cc
) {
  SegmentDisplay(a, b, c, d, e, f, g, p, dig1, dig2, -1, -1, _cc);
}

SegmentDisplay::SegmentDisplay(
  int8_t a, int8_t b, int8_t c, int8_t d,
  int8_t e, int8_t f, int8_t g, int8_t p,
  int8_t dig1, int8_t dig2, int8_t dig3,
  boolean _cc
) {
  SegmentDisplay(a, b, c, d, e, f, g, p, dig1, dig2, dig3, -1, _cc);
}

SegmentDisplay::SegmentDisplay(
  int8_t a, int8_t b, int8_t c, int8_t d,
  int8_t e, int8_t f, int8_t g, int8_t p,
  int8_t dig1, int8_t dig2, int8_t dig3, int8_t dig4,
  boolean _cc
) {
  this->pin_a = a;
  this->pin_b = b;
  this->pin_c = c;
  this->pin_d = d;
  this->pin_e = e;
  this->pin_f = f;
  this->pin_g = g;
  this->pin_p = p;
  this->dig_1 = dig1;
  this->dig_2 = dig2;
  this->dig_3 = dig3;
  this->dig_4 = dig4;
  this->cc = _cc;
}

void SegmentDisplay::init() {

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

}

void SegmentDisplay::test() {
  const int BLINK_DELAY = 50; //ms

  if (dig_1 > 0) {
    SET_L(dig_1);
    SET_H(pin_a); delay(blink_delay); SET_Z(pin_a);
    SET_H(pin_b); delay(blink_delay); SET_Z(pin_b);
    SET_H(pin_c); delay(blink_delay); SET_Z(pin_c);
    SET_H(pin_d); delay(blink_delay); SET_Z(pin_d);
    SET_H(pin_e); delay(blink_delay); SET_Z(pin_e);
    SET_H(pin_f); delay(blink_delay); SET_Z(pin_f);
    SET_H(pin_g); delay(blink_delay); SET_Z(pin_g);
    SET_H(pin_p); delay(blink_delay); SET_Z(pin_p);
    SET_Z(dig_1);
  }

  if (dig_2 > 0) {
    SET_L(dig_2);
    SET_H(pin_a); delay(blink_delay); SET_Z(pin_a);
    SET_H(pin_b); delay(blink_delay); SET_Z(pin_b);
    SET_H(pin_c); delay(blink_delay); SET_Z(pin_c);
    SET_H(pin_d); delay(blink_delay); SET_Z(pin_d);
    SET_H(pin_e); delay(blink_delay); SET_Z(pin_e);
    SET_H(pin_f); delay(blink_delay); SET_Z(pin_f);
    SET_H(pin_g); delay(blink_delay); SET_Z(pin_g);
    SET_H(pin_p); delay(blink_delay); SET_Z(pin_p);
    SET_Z(dig_2);
  }

  if (dig_3 > 0) {
    SET_L(dig_3);
    SET_H(pin_a); delay(blink_delay); SET_Z(pin_a);
    SET_H(pin_b); delay(blink_delay); SET_Z(pin_b);
    SET_H(pin_c); delay(blink_delay); SET_Z(pin_c);
    SET_H(pin_d); delay(blink_delay); SET_Z(pin_d);
    SET_H(pin_e); delay(blink_delay); SET_Z(pin_e);
    SET_H(pin_f); delay(blink_delay); SET_Z(pin_f);
    SET_H(pin_g); delay(blink_delay); SET_Z(pin_g);
    SET_H(pin_p); delay(blink_delay); SET_Z(pin_p);
    SET_Z(dig_3);
  }

  if (dig_4 > 0) {
    SET_L(dig_4);
    SET_H(pin_a); delay(blink_delay); SET_Z(pin_a);
    SET_H(pin_b); delay(blink_delay); SET_Z(pin_b);
    SET_H(pin_c); delay(blink_delay); SET_Z(pin_c);
    SET_H(pin_d); delay(blink_delay); SET_Z(pin_d);
    SET_H(pin_e); delay(blink_delay); SET_Z(pin_e);
    SET_H(pin_f); delay(blink_delay); SET_Z(pin_f);
    SET_H(pin_g); delay(blink_delay); SET_Z(pin_g);
    SET_H(pin_p); delay(blink_delay); SET_Z(pin_p);
    SET_Z(dig_4);
  }

}

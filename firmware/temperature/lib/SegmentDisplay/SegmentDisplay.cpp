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
#include "usec.h"
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
  //this->init();
}

void SegmentDisplay::init() {

  // Initialize display to known state by setting all pins to high impedance
  SET_Z(pin_a);
  SET_Z(pin_b);
  SET_Z(pin_c);
  SET_Z(pin_d);
  SET_Z(pin_e);
  SET_Z(pin_f);
  SET_Z(pin_g);
  SET_Z(pin_p);

  SET_Z(dig_1);
  SET_Z(dig_2);
  SET_Z(dig_3);
  SET_Z(dig_4);

}

void SegmentDisplay::test() {
  int pwm_delay = 50; //ms

  if (dig_1 >= 0) {
    SET_L(dig_1);
    SET_H(pin_a); delay(pwm_delay); SET_Z(pin_a);
    SET_H(pin_b); delay(pwm_delay); SET_Z(pin_b);
    SET_H(pin_c); delay(pwm_delay); SET_Z(pin_c);
    SET_H(pin_d); delay(pwm_delay); SET_Z(pin_d);
    SET_H(pin_e); delay(pwm_delay); SET_Z(pin_e);
    SET_H(pin_f); delay(pwm_delay); SET_Z(pin_f);
    SET_H(pin_g); delay(pwm_delay); SET_Z(pin_g);
    SET_H(pin_p); delay(pwm_delay); SET_Z(pin_p);
    SET_Z(dig_1);
  }

  if (dig_2 >= 0) {
    SET_L(dig_2);
    SET_H(pin_a); delay(pwm_delay); SET_Z(pin_a);
    SET_H(pin_b); delay(pwm_delay); SET_Z(pin_b);
    SET_H(pin_c); delay(pwm_delay); SET_Z(pin_c);
    SET_H(pin_d); delay(pwm_delay); SET_Z(pin_d);
    SET_H(pin_e); delay(pwm_delay); SET_Z(pin_e);
    SET_H(pin_f); delay(pwm_delay); SET_Z(pin_f);
    SET_H(pin_g); delay(pwm_delay); SET_Z(pin_g);
    SET_H(pin_p); delay(pwm_delay); SET_Z(pin_p);
    SET_Z(dig_2);
  }

  if (dig_3 >= 0) {
    SET_L(dig_3);
    SET_H(pin_a); delay(pwm_delay); SET_Z(pin_a);
    SET_H(pin_b); delay(pwm_delay); SET_Z(pin_b);
    SET_H(pin_c); delay(pwm_delay); SET_Z(pin_c);
    SET_H(pin_d); delay(pwm_delay); SET_Z(pin_d);
    SET_H(pin_e); delay(pwm_delay); SET_Z(pin_e);
    SET_H(pin_f); delay(pwm_delay); SET_Z(pin_f);
    SET_H(pin_g); delay(pwm_delay); SET_Z(pin_g);
    SET_H(pin_p); delay(pwm_delay); SET_Z(pin_p);
    SET_Z(dig_3);
  }

  if (dig_4 >= 0) {
    SET_L(dig_4);
    SET_H(pin_a); delay(pwm_delay); SET_Z(pin_a);
    SET_H(pin_b); delay(pwm_delay); SET_Z(pin_b);
    SET_H(pin_c); delay(pwm_delay); SET_Z(pin_c);
    SET_H(pin_d); delay(pwm_delay); SET_Z(pin_d);
    SET_H(pin_e); delay(pwm_delay); SET_Z(pin_e);
    SET_H(pin_f); delay(pwm_delay); SET_Z(pin_f);
    SET_H(pin_g); delay(pwm_delay); SET_Z(pin_g);
    SET_H(pin_p); delay(pwm_delay); SET_Z(pin_p);
    SET_Z(dig_4);
  }

}

void SegmentDisplay::test2() {
  int pwm_delay = 300; //ms

  if (dig_1 >= 0) {
    for (int8_t i=0; i<10; i++) {
      setSegments(i);
      SET_L(dig_1);
      delay(pwm_delay);
      SET_Z(dig_1);
    }
  }

  if (dig_2 >= 0) {
    for (int8_t i=0; i<10; i++) {
      setSegments(i);
      SET_L(dig_2);
      delay(pwm_delay);
      SET_Z(dig_2);
    }
  }

  if (dig_3 >= 0) {
    for (int8_t i=0; i<10; i++) {
      setSegments(i);
      SET_L(dig_3);
      delay(pwm_delay);
      SET_Z(dig_3);
    }
  }

  if (dig_4 >= 0) {
    for (int8_t i=0; i<10; i++) {
      setSegments(i);
      SET_L(dig_4);
      delay(pwm_delay);
      SET_Z(dig_4);
    }
  }

}

void SegmentDisplay::display(int n, usec timeout) {
  int8_t dig1val = 0;
  int8_t dig2val = 0;
  int8_t dig3val = 0;
  int8_t dig4val = 0;

  dig1val = n % 10;
  n /= 10;
  dig2val = n % 10;
  n /= 10;
  dig3val = n % 10;
  n /= 10;
  dig4val = n % 10;

  if (dig_1 >= 0) {
    setSegments(dig1val);
    SET_PIN(dig_1, OUTPUT, (cc ? LOW : HIGH));
    delay(timeout);
    SET_Z(dig_1);
  }

  if (dig_2 >= 0 && (dig2val > 0 || dig3val > 0 || dig4val > 0)) {
    setSegments(dig2val);
    SET_PIN(dig_2, OUTPUT, (cc ? LOW : HIGH));
    delay(timeout);
    SET_Z(dig_2);
  }

  if (dig_3 >= 0 && (dig3val > 0 || dig4val > 0)) {
    setSegments(dig3val);
    SET_PIN(dig_3, OUTPUT, (cc ? LOW : HIGH));
    delay(timeout);
    SET_Z(dig_3);
  }

  if (dig_4 >= 0 && dig4val > 0) {
    setSegments(dig4val);
    SET_PIN(dig_4, OUTPUT, (cc ? LOW : HIGH));
    delay(timeout);
    SET_Z(dig_4);
  }

}

void SegmentDisplay::setSegments(int8_t value) {
  if (value >= 0 and value < 10) {
    uint8_t mask = LOOKUP_DIGIT_MASK(value);
    SET_PIN(pin_a, ((mask & SEG_A) ? OUTPUT : INPUT), (cc ? HIGH : LOW));
    SET_PIN(pin_b, ((mask & SEG_B) ? OUTPUT : INPUT), (cc ? HIGH : LOW));
    SET_PIN(pin_c, ((mask & SEG_C) ? OUTPUT : INPUT), (cc ? HIGH : LOW));
    SET_PIN(pin_d, ((mask & SEG_D) ? OUTPUT : INPUT), (cc ? HIGH : LOW));
    SET_PIN(pin_e, ((mask & SEG_E) ? OUTPUT : INPUT), (cc ? HIGH : LOW));
    SET_PIN(pin_f, ((mask & SEG_F) ? OUTPUT : INPUT), (cc ? HIGH : LOW));
    SET_PIN(pin_g, ((mask & SEG_G) ? OUTPUT : INPUT), (cc ? HIGH : LOW));
    SET_PIN(pin_p, ((mask & SEG_P) ? OUTPUT : INPUT), (cc ? HIGH : LOW));
  }
}

// vi: syntax=arduino

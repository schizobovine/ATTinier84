#ifndef __SEGMENTDISPLAYLIB_H__
#define __SEGMENTDISPLAYLIB_H__

#include <Arduino.h>
#include "usec.h"

#define SET_PIN(pin, mode, value) \
  do { \
    if ((pin) >= 0) { \
      pinMode((pin), (mode)); \
      digitalWrite((pin), (value)); \
    } \
  } while (0)

#define SET_H(pin) SET_PIN((pin), OUTPUT, HIGH)
#define SET_L(pin) SET_PIN((pin), OUTPUT, LOW)
#define SET_Z(pin) SET_PIN((pin), INPUT, HIGH)

/*
 *  Digit Layout
 *
 *       B       
 *     -----
 *    |     |
 * A->|     |<-C
 *    |  G  |
 *     -----
 *    |     |
 * F->|     |<-D
 *    |     |
 *     ----- *<-P
 *       E
 */

/* Symbolic masks for each segment */
#define SEG_A (1 << 0)
#define SEG_B (1 << 1)
#define SEG_C (1 << 2)
#define SEG_D (1 << 3)
#define SEG_E (1 << 4)
#define SEG_F (1 << 5)
#define SEG_G (1 << 6)
#define SEG_P (1 << 7)

/* Combine masks to make each digit */
#define DIGIT_0 (SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F)
#define DIGIT_1 (SEG_C | SEG_D)
#define DIGIT_2 (SEG_B | SEG_C | SEG_G | SEG_F | SEG_E)
#define DIGIT_3 (SEG_B | SEG_C | SEG_G | SEG_D | SEG_E)
#define DIGIT_4 (SEG_A | SEG_G | SEG_C | SEG_D)
#define DIGIT_5 (SEG_B | SEG_A | SEG_G | SEG_D | SEG_E)
#define DIGIT_6 (SEG_B | SEG_A | SEG_G | SEG_F | SEG_E | SEG_D)
#define DIGIT_7 (SEG_B | SEG_C | SEG_D)
#define DIGIT_8 (SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G)
#define DIGIT_9 (SEG_A | SEG_B | SEG_C | SEG_G | SEG_D)

/* Finally, a lookup macro that horribly abuses the ternary operator */
#define LOOKUP_DIGIT_MASK(digit) \
  ((digit) == 0 ? DIGIT_0 : \
  ((digit) == 1 ? DIGIT_1 : \
  ((digit) == 2 ? DIGIT_2 : \
  ((digit) == 3 ? DIGIT_3 : \
  ((digit) == 4 ? DIGIT_4 : \
  ((digit) == 5 ? DIGIT_5 : \
  ((digit) == 6 ? DIGIT_6 : \
  ((digit) == 7 ? DIGIT_7 : \
  ((digit) == 8 ? DIGIT_8 : \
  ((digit) == 9 ? DIGIT_9 : 0))))))))))

class SegmentDisplay {
  public:

    // Constructors
    SegmentDisplay(
      int8_t pin_a, int8_t pin_b, int8_t pin_c, int8_t pin_d,
      int8_t pin_e, int8_t pin_f, int8_t pin_g, int8_t pin_p,
      int8_t dig_1
    );
    SegmentDisplay(
      int8_t pin_a, int8_t pin_b, int8_t pin_c, int8_t pin_d,
      int8_t pin_e, int8_t pin_f, int8_t pin_g, int8_t pin_p,
      int8_t dig_1, int8_t dig_2
    );
    SegmentDisplay(
      int8_t pin_a, int8_t pin_b, int8_t pin_c, int8_t pin_d,
      int8_t pin_e, int8_t pin_f, int8_t pin_g, int8_t pin_p,
      int8_t dig_1, int8_t dig_2, int8_t dig_3
    );
    SegmentDisplay(
      int8_t pin_a, int8_t pin_b, int8_t pin_c, int8_t pin_d,
      int8_t pin_e, int8_t pin_f, int8_t pin_g, int8_t pin_p,
      int8_t dig_1, int8_t dig_2, int8_t dig_3, int8_t dig_4
    );
    SegmentDisplay(
      int8_t pin_a, int8_t pin_b, int8_t pin_c, int8_t pin_d,
      int8_t pin_e, int8_t pin_f, int8_t pin_g, int8_t pin_p,
      int8_t dig_1,
      boolean cc
    );
    SegmentDisplay(
      int8_t pin_a, int8_t pin_b, int8_t pin_c, int8_t pin_d,
      int8_t pin_e, int8_t pin_f, int8_t pin_g, int8_t pin_p,
      int8_t dig_1, int8_t dig_2,
      boolean cc
    );
    SegmentDisplay(
      int8_t pin_a, int8_t pin_b, int8_t pin_c, int8_t pin_d,
      int8_t pin_e, int8_t pin_f, int8_t pin_g, int8_t pin_p,
      int8_t dig_1, int8_t dig_2, int8_t dig_3,
      boolean cc
    );
    SegmentDisplay(
      int8_t pin_a, int8_t pin_b, int8_t pin_c, int8_t pin_d,
      int8_t pin_e, int8_t pin_f, int8_t pin_g, int8_t pin_p,
      int8_t dig_1, int8_t dig_2, int8_t dig_3, int8_t dig_4,
      boolean cc
    );

    void init();
    void test();
    void test2();
    void display(int n, usec timeout);

  private:

    // Segments
    int8_t pin_a = 0;
    int8_t pin_b = 0;
    int8_t pin_c = 0;
    int8_t pin_d = 0;
    int8_t pin_e = 0;
    int8_t pin_f = 0;
    int8_t pin_g = 0;
    int8_t pin_p = 0;

    // Digits
    int8_t dig_1 = 0;
    int8_t dig_2 = 0;
    int8_t dig_3 = 0;
    int8_t dig_4 = 0;

    // Direction of LED digits (true if common cathode, false if common anode)
    bool cc = true;

    // Current display buffer
    int num;

    void setSegments(int8_t value);
    
};

#endif

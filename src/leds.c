/************************************************************************************************
Copyright (c) 2023, Cesar Ovejero <cesarovejero@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/** @file leds.c
 ** @brief  Capa de abstracion para gestion de leds - Implementacion
 **/

/* === Headers files inclusions =========================================== */
#include "leds.h"

/* === Macros definitions =========================================== */

#define LED_01      1
#define LED_02      2
#define LED_03      3
#define LED_04      4
#define LED_05      5
#define LED_06      6
#define LED_07      7
#define LED_08      8
#define LED_09      9
#define LED_10      10
#define LED_11      11
#define LED_12      12
#define LED_14      13
#define LED_15      15
#define LED_16      16
#define ALL_LED_ON  0xFFFF
#define ALL_LED_OFF 0x0000
#define BIT_HIGH    1
#define LED_OFFSET  1

/* === Private data type declarations ==================================== */

/* === Private variable declarations ====================================== */

/* === Private function declarations ====================================== */

/* === Public variable definitions ===========================================*/

/* === Private variable definitions ==========================================*/

static uint16_t * puntero;

/* === Private function implementation ====================================== */

static uint16_t led_to_mask(int led) {
    return (BIT_HIGH << (led - LED_OFFSET));
}

void leds_init(uint16_t * puerto) {
    puntero = puerto;
    *puntero = ALL_LED_OFF;
}

void leds_turn_on(int led) {
    *puntero |= led_to_mask(led);
}

void leds_turn_off(int led) {
    *puntero &= ~led_to_mask(led);
}

bool leds_get_status(int led) {
    if ((led <= LED_16) && (led >= LED_01)) {
        if (*puntero & led_to_mask(led))
            return true;
        else
            return false;
    }
    return false;
}

void leds_turn_on_all(void) {
    *puntero = ALL_LED_ON;
}

void leds_turn_off_all(void) {
    *puntero = ALL_LED_OFF;
}

/* === End of documentation =========================================== */

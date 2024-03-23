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

#ifndef LEDS_H
#define LEDS_H

/** @file leds.h
 ** @brief Capa de abstracion para gestion de leds
 **/

/* === Headers files inclusions ===================================== */

#include <stdint.h>
#include <stdbool.h>

/* === Cabecera C++ ===================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions ===================================== */

/* === Public data type declarations ===================================== */

/* === Public variable declarations ===================================== */

/* === Public function declarations ===================================== */

/**
 * @brief Funcion para inicializar leds
 *
 * @param port puerto a inicializar
 */
void leds_init(uint16_t * puerto);

/**
 * @brief Funcion para encender un LED
 *
 * @param led numero de bit correspondiente al led
 */
void leds_turn_on(int led);

/**
 * @brief Funcion para apagar un LED
 *
 * @param led numero de bit correspondiente al led
 */
void leds_turn_off(int led);

/**
 * @brief Funcion para consultar estado de LED
 *
 * @param led numero de bit correspondiente al led
 */
bool leds_get_status(int led);

/**
 * @brief Funcion para encender todos los LED
 *
 *
 */
void leds_turn_on_all(void);

/**
 * @brief Funcion para apagar todos los LED
 *
 *
 */
void leds_turn_off_all(void);

/* === End of documentation ===================================== */

#ifdef __cplusplus
}
#endif

#endif /* LEDS_H */

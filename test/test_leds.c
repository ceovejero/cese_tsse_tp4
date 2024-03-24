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

/** @file test_leds.c
 ** @brief Conjunto de Tests para la API de LEDs.
 **/

/* === Headers files inclusions ===================================== */

#include "unity.h"
#include "leds.h"

/* === Macros definitions =========================================== */

#define LED_01           1
#define LED_02           2
#define LED_03           3
#define LED_04           4
#define LED_05           5
#define LED_06           6
#define LED_07           7
#define LED_08           8
#define LED_09           9
#define LED_10           10
#define LED_11           11
#define LED_12           12
#define LED_14           13
#define LED_15           15
#define LED_16           16
#define LED_17           17
#define LED_18           18
#define ALL_LED_ON       0xFFFF
#define ALL_LED_OFF      0x0000
#define BIT_HIGH         1
#define LED_OFFSET       1
#define LED_TO_MASK(led) (BIT_HIGH << led - LED_OFFSET)

/* === Private data type declarations ==================================== */

/* === Private variable declarations ====================================== */

static uint16_t leds_virtuales;

/* === Private function declarations ====================================== */

/* === Public variable definitions ===========================================*/

/* === Private variable definitions ==========================================*/

/* === Private function implementation ====================================== */

void setUp(void) {
    leds_init(&leds_virtuales);
}

/// @brief Test 1
/// Al iniciar el controlador, los leds deben quedar en 0
/// sin importar el estado anterior.
void test_todos_los_leds_inician_apagados(void) {

    leds_virtuales = ALL_LED_ON;
    leds_init(&leds_virtuales);
    TEST_ASSERT_EQUAL_UINT16(ALL_LED_OFF, leds_virtuales);
}

/// @brief Test 2
/// Con todos los leds apagados prender el led 3 y verificar que
/// el bit 2 se pone en 1 y el resto de bit permanece en 0.
void test_prender_un_led(void) {

    leds_turn_on(LED_03);
    // El bit 2 está en alto
    TEST_ASSERT_BIT_HIGH(LED_03 - 1, leds_virtuales);
    // Todos los otros bits estan en bajo
    TEST_ASSERT_BITS_LOW(~(LED_TO_MASK(LED_03)), leds_virtuales);
}

/// @brief Test 3
/// Apagar un led prendido y ver que efectivamente se apaga
/// y que el resto no cambia.
void test_apagar_un_led(void) {

    leds_init(&leds_virtuales);
    leds_turn_on(LED_03);
    leds_turn_off(LED_03);
    TEST_ASSERT_EQUAL_UINT16(ALL_LED_OFF, leds_virtuales);
}

/// @brief Test 4
/// Encender 2 Leds y Apagar 1 -
/// Verificar que solo quede uno encendido.
void test_apagar_y_prender_varios_leds(void) {

    leds_turn_on(LED_05);
    leds_turn_on(LED_07);
    leds_turn_on(LED_05);
    leds_turn_off(LED_05);
    leds_turn_off(LED_09);

    TEST_ASSERT_EQUAL_UINT16(LED_TO_MASK(LED_07), leds_virtuales);
}

/// @brief Test 5
/// Con todos los leds apagados prender un led y verificar que
/// al consultar el estado del mismo me informa que esta encendido.
void test_consultar_estado_de_led(void) {
    leds_init(&leds_virtuales);
    leds_turn_on(LED_05);
    TEST_ASSERT_EQUAL_UINT16(LED_TO_MASK(LED_05), leds_virtuales);
    TEST_ASSERT_TRUE(leds_get_status(LED_05));
}

/// @brief Test 6
/// Prender todos los leds que estan apagados y
/// verificar que todos encendidos
void test_encender_todos_y_verificar_todos_encendidos(void) {

    leds_turn_on_all();
    TEST_ASSERT_EQUAL_UINT16(ALL_LED_ON, leds_virtuales);
}

/// @brief Test 7
/// Apagar todos los leds que estan encendidos y
/// verificar que todos apagados
void test_apagar_todos_y_verificar_todos_apagados(void) {

    leds_turn_off_all();
    TEST_ASSERT_EQUAL_UINT16(ALL_LED_OFF, leds_virtuales);
}

/// @brief Test 8
/// Coprobar valores prohibidos, en el encendido
///
void test_encender_leds_no_validos(void) {

    leds_init(&leds_virtuales);

    TEST_ASSERT_FALSE(leds_turn_on(LED_18));
}

/// @brief Test 9
/// Coprobar valores prohibidos, en el apagado
///
void test_apagar_leds_no_validos(void) {

    leds_init(&leds_virtuales);
    leds_turn_on(LED_18);

    TEST_ASSERT_FALSE(leds_turn_off(LED_18));
}

/// @brief Test 10
/// Coprobar valores prohibidos,
/// en la consulta de estado de leds
void test_consultar_estado_de_leds_no_validos(void) {

    leds_init(&leds_virtuales);
    leds_turn_on(LED_18);

    TEST_ASSERT_FALSE(leds_get_status(LED_18));
}

/// @brief Test 11
/// Encender valores de limite
///
void test_encender_limites(void) {
    leds_init(&leds_virtuales);
    leds_turn_on(LED_01 - 1);
    TEST_ASSERT_FALSE(leds_turn_on(LED_01 - 1));
}

/// @brief Test 12
/// Apagar valores de limite
///
void test_apagar_limites(void) {
    leds_init(&leds_virtuales);
    leds_turn_on(LED_16 + 1);
    TEST_ASSERT_FALSE(leds_turn_on(LED_16 + 1));
}

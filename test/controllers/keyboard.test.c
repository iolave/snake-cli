#include <unity.h>
#include "../../src/controllers/keyboard.c"

void test_controller_keyboard_calculateDirection(void) {
    // UP
    TEST_ASSERT_EQUAL_INT(0, calculateDirection(CONTROLLER_UP).x);
    TEST_ASSERT_EQUAL_INT(1, calculateDirection(CONTROLLER_UP).y);
    // DOWN
    TEST_ASSERT_EQUAL_INT(0, calculateDirection(CONTROLLER_DOWN).x);
    TEST_ASSERT_EQUAL_INT(-1, calculateDirection(CONTROLLER_DOWN).y);
    // LEFT
    TEST_ASSERT_EQUAL_INT(-1, calculateDirection(CONTROLLER_LEFT).x);
    TEST_ASSERT_EQUAL_INT(0, calculateDirection(CONTROLLER_LEFT).y);
    // RIGHT
    TEST_ASSERT_EQUAL_INT(1, calculateDirection(CONTROLLER_RIGHT).x);
    TEST_ASSERT_EQUAL_INT(0, calculateDirection(CONTROLLER_RIGHT).y);
}
#include <stdio.h>
#include <unity.h>
#include "./controllers/keyboard.test.c"

void setUp() {}
void tearDown() {}

int main() {
    UNITY_BEGIN();
    
    // TESTING src/controller/keyboard.c
    RUN_TEST(test_controller_keyboard_calculateDirection);

    return UNITY_END();
}
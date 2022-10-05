#include <unity.h>
#include "./controllers/keyboard.test.c"
#include "./lib/snake.test.c"

void setUp() {}
void tearDown() {}

int main() {
    UNITY_BEGIN();
    
    // TESTING src/controller/keyboard.c
    RUN_TEST(test_controller_keyboard_calculateDirection);
    
    // TESTING src/snake/snake.c
    RUN_TEST(test_lib_snake_freeSnake);
    RUN_TEST(test_lib_snake_snakeLength);
    RUN_TEST(test_lib_snake_feedSnake);
    RUN_TEST(test_lib_snake_moveSnake_nonFed);
    RUN_TEST(test_lib_snake_moveSnake_fed);
    RUN_TEST(test_lib_snake_generateXyPoint);
    return UNITY_END();
}
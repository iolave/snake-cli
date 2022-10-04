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
    RUN_TEST(test_snake_snake_freeSnake);
    RUN_TEST(test_snake_snake_snakeLength);
    RUN_TEST(test_snake_snake_feedSnake);
    RUN_TEST(test_snake_snake_moveSnake_nonFed);
    RUN_TEST(test_snake_snake_moveSnake_fed);
    return UNITY_END();
}
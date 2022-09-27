#include <unity.h>
#include <stdlib.h>
#include <snake.h>

void test_snake_snake_snakeLength(void) {
    int i;          // For counter
    int foodAmt;    // The amount of food to feed the snake

    // Creating a snake and the amount of food to feed it
    struct Snake *snake;

    // Feeding the snake 100 times
    foodAmt = 100;
    snake = NULL;
    for(i = 0;i < foodAmt;i = i + 1) feedSnake(&snake);
    TEST_ASSERT_EQUAL_INT(foodAmt, snakeLength(snake));

    // Feeding the snake 0 times
    foodAmt = 0;
    snake = NULL;
    for(i = 0;i < foodAmt;i = i + 1) feedSnake(&snake);
    TEST_ASSERT_EQUAL_INT(foodAmt, snakeLength(snake));

    free(snake);
}
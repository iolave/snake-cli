#include <unity.h>
#include <snake.h>

void test_snake_snake_freeSnake(void) {
    struct Snake *snakeHead = NULL;

    feedSnake(&snakeHead);
    freeSnake(&snakeHead);
    TEST_ASSERT_NULL(snakeHead);
    
    return;
}

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
    freeSnake(&snake);

    // Feeding the snake 0 times
    foodAmt = 0;
    snake = NULL;
    for(i = 0;i < foodAmt;i = i + 1) feedSnake(&snake);
    TEST_ASSERT_EQUAL_INT(foodAmt, snakeLength(snake));
    freeSnake(&snake);
}

void test_snake_snake_feedSnake(void) {
    struct Snake *snakeHead;
    
    /*
     * When feeding the snake for the first time
     * it should set the head node (x,y) postiton 
     * to (0,0).
     */
    snakeHead = NULL;
    feedSnake(&snakeHead);

    TEST_ASSERT_EQUAL_INT(0,snakeHead->x);
    TEST_ASSERT_EQUAL_INT(0,snakeHead->y);
    freeSnake(&snakeHead);


    /*
     * When feeding the snake every other time
     * it should set the head node postition to
     * the previous head (x,y) postition
     * position.
     */
    // Testing a snake from scratch
    snakeHead = NULL; 
    feedSnake(&snakeHead);
    feedSnake(&snakeHead);

    TEST_ASSERT_EQUAL_INT(snakeHead->next->x,snakeHead->x);
    TEST_ASSERT_EQUAL_INT(snakeHead->next->y,snakeHead->y);
    freeSnake(&snakeHead);


    // Testing a snake from in a random (x,y) position
    snakeHead = NULL; 
    feedSnake(&snakeHead);
    snakeHead->x = 65;
    snakeHead->y = 32;
    feedSnake(&snakeHead);
    
    TEST_ASSERT_EQUAL_INT(snakeHead->next->x,snakeHead->x);
    TEST_ASSERT_EQUAL_INT(snakeHead->next->y,snakeHead->y);
    freeSnake(&snakeHead);
}


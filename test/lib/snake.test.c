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

// TODO
void test_snake_snake_feedSnake(void) {
    // // Defining a snake to be fed
    struct Snake *snakeHead = NULL;
    struct Snake *newNode = malloc(sizeof(struct Snake));

    Before feeding
    newNode->x = 0;
    newNode->y = 0;
    newNode->next = snakeHead;
    snakeHead = newNode;

    newNode->x = 0;
    newNode->y = 1;
    newNode->next = snakeHead;
    snakeHead = newNode;

    newNode->x = 0;
    newNode->y = 2;
    newNode->next = snakeHead;
    snakeHead = newNode;
    
    // Node added when fed
    newNode->x = snakeHead->x;
    newNode->y = snakeHead->y;
    newNode->next = snakeHead;
    snakeHead = newNode;

    TEST_ASSERT_EQUAL_INT(0, 1);

    free(snakeHead);
    free(newNode);
}
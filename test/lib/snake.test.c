#include <unity.h>
#include <stdlib.h>
#include <stdio.h>
#include <snake.h>
#include <unistd.h>

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
    TEST_ASSERT_EQUAL_INT(0, 1);
}

void test_snake_snake_freeSnake(void) {
    struct Snake *snakeHead = malloc(sizeof(struct Snake));
    snakeHead->x=0;
    snakeHead->y=1;
    snakeHead->next=NULL;

    // printf("%p\n", snakeHead);
    // printf("%d,%d\n", snakeHead->x, snakeHead->y);
    struct Snake *ptr = snakeHead;
    freeSnake(snakeHead);
    sleep(2);
    printf("%d\n", snakeLength(ptr));

    
    // TEST_ASSERT_EMPTY(&snakeHead);
    // printf("%p\n", snakeHead);

    // int i;
    // struct Snake *snakeHead = NULL;
    // struct Snake *snakePtr = NULL;
    // struct Snake *newNode = NULL;
    // int snakeLength = 3;

    // for(i = 0;i < snakeLength;i = i + 1) {
    //     newNode = malloc(sizeof(struct Snake));
    //     newNode->x = i;
    //     newNode->y = 0;
    //     newNode->next = snakeHead;
    //     snakeHead = newNode;
    // }
    
    // freeSnake(snakeHead);
    // TEST_ASSERT_EMPTY(snakeHead->next);
    // snakePtr = snakeHead;
    // for(i = snakeLength - 1;i >= 0;i = i - 1) {
    //     TEST_ASSERT_EQUAL_INT(i, snakePtr->x);
    //     TEST_ASSERT_EQUAL_INT(0, snakePtr->y);
    //     if (i != 0) TEST_ASSERT_NOT_NULL(snakePtr->next);
    //     else TEST_ASSERT_NULL(snakePtr->next);
    //     snakePtr=snakePtr->next;
    // }
}
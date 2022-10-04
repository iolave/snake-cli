#include <unity.h>
#include <snake.h>
#include "../generators/snake.c"

void test_snake_snake_freeSnake(void) {
    struct Snake *snakeHead = NULL;

    feedSnake(&snakeHead);
    freeSnake(&snakeHead);
    TEST_ASSERT_NULL(snakeHead);
    
    return;
}

void test_snake_snake_snakeLength(void) {
    int foodAmt;    // The amount of food to feed the snake

    // Creating a snake and the amount of food to feed it
    struct Snake *snake = NULL;

    // Feeding the snake 100 times
    foodAmt = 100;
    snake = generateMultipleNodesSnake(foodAmt);
    TEST_ASSERT_EQUAL_INT(foodAmt, snakeLength(snake));
    freeSnake(&snake);

    // Feeding the snake 0 times
    foodAmt = 0;
    snake = generateMultipleNodesSnake(foodAmt);
    TEST_ASSERT_EQUAL_INT(foodAmt, snakeLength(snake));
    freeSnake(&snake);
}

void test_snake_snake_feedSnake(void) {
    struct Snake *snakeHead = NULL;
    
    /*
     * When feeding the snake for the first time
     * it should set the head node (x,y) postiton 
     * to (0,0).
     */
    snakeHead = generateMultipleNodesSnake(0);
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
    snakeHead = generateMultipleNodesSnake(23);
    feedSnake(&snakeHead);
    
    TEST_ASSERT_EQUAL_INT(snakeHead->next->x,snakeHead->x);
    TEST_ASSERT_EQUAL_INT(snakeHead->next->y,snakeHead->y);
    freeSnake(&snakeHead);
}

void test_snake_snake_moveSnake_nonFed(void) {
    struct Snake *oldSnake = NULL;
    struct Snake *oldSnakeHead = NULL;
    struct Snake *snake = NULL;
    struct Snake *snakeHead = NULL;
    
    struct XYVector vector;
    int foodAmt;

    // Feeding the snake 100 times and moving it
    foodAmt = 100;
    vector.x = 0;
    vector.y = 1;
    snakeHead = generateMultipleNodesSnake(foodAmt);
    oldSnakeHead = generateMultipleNodesSnake(foodAmt);
    moveSnake(&snakeHead, vector);
    
    // TODO validation
    snake = snakeHead;
    oldSnake = oldSnakeHead;

    // Snake first's node have to match old snake first node 
    // with the given vector added (x + vector.x, y + vector.y)
    TEST_ASSERT_EQUAL_INT(snake->x, oldSnake->x + vector.x);
    TEST_ASSERT_EQUAL_INT(snake->y, oldSnake->y + vector.y);
    snake = snake->next;

    // Left snake's nodes have to match the oldSnake's nodes
    while(snake != NULL) {
        TEST_ASSERT_EQUAL_INT(snake->x, oldSnake->x);
        TEST_ASSERT_EQUAL_INT(snake->y, oldSnake->y);
        snake = snake->next;
        oldSnake = oldSnake->next;
    }

    // Freeing snakes
    freeSnake(&snake);
    freeSnake(&oldSnake);
}

void test_snake_snake_moveSnake_fed(void) {
    struct Snake *oldSnake = NULL;
    struct Snake *oldSnakeHead = NULL;
    struct Snake *snake = NULL;
    struct Snake *snakeHead = NULL;
    
    struct XYVector vector;
    int foodAmt;

    // Feeding the snake 100 times and moving it
    foodAmt = 100;
    vector.x = 0;
    vector.y = 1;
    snakeHead = generateMultipleNodesSnake(foodAmt);
    snakeHead->x = snakeHead->next->x;
    snakeHead->y = snakeHead->next->y;
    oldSnakeHead = generateMultipleNodesSnake(foodAmt);
    oldSnakeHead->x = oldSnakeHead->next->x;
    oldSnakeHead->y = oldSnakeHead->next->y;
    moveSnake(&snakeHead, vector);
    
    // TODO validation
    snake = snakeHead;
    oldSnake = oldSnakeHead;

    // Snake first's node have to match old snake first node 
    // with the given vector added (x + vector.x, y + vector.y)
    TEST_ASSERT_EQUAL_INT(snake->x, oldSnake->x + vector.x);
    TEST_ASSERT_EQUAL_INT(snake->y, oldSnake->y + vector.y);
    snake = snake->next;

    // Left snake's nodes have to match the oldSnake's nodes
    while(snake != NULL) {
        TEST_ASSERT_EQUAL_INT(snake->x, oldSnake->x);
        TEST_ASSERT_EQUAL_INT(snake->y, oldSnake->y);
        snake = snake->next;
        oldSnake = oldSnake->next;
    }

    // Freeing snakes
    freeSnake(&snake);
    freeSnake(&oldSnake);
}
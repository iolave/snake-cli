#include <unity.h>
#include <snake.h>
#include "../generators/snake.c"

void test_lib_snake_freeSnake(void) {
    struct Snake *snakeHead = NULL;

    feedSnake(&snakeHead);
    freeSnake(&snakeHead);
    TEST_ASSERT_NULL(snakeHead);
    
    return;
}

void test_lib_snake_generateXyVector(void) {
    struct XYVector point;
    int expectedX = 34;
    int expectedY = -167;

    point = generateXyVector(expectedX, expectedY);
    TEST_ASSERT_EQUAL_INT(expectedX, point.x);
    TEST_ASSERT_EQUAL_INT(expectedY, point.y);

    return;
}

void test_lib_snake_addXyVectors(void) {
    struct XYVector vector;
    int expectedX = 34;
    int expectedY = -167;

    vector = addXyVectors(generateXyVector(expectedX,expectedY), generateXyVector(expectedX,expectedY));
    TEST_ASSERT_EQUAL_INT(expectedX * 2, vector.x);
    TEST_ASSERT_EQUAL_INT(expectedY * 2, vector.y);

    return;
}

void test_lib_snake_equalXyVectors(void) {
    struct XYVector vector1;
    struct XYVector vector2;
    int x = 34;
    int y = -167;

    // Test true case
    vector1 = generateXyVector(x, y);
    vector2 = generateXyVector(x, y);
    TEST_ASSERT_TRUE(equalXyVectors(vector1, vector2));
    
    // Test false case
    vector1 = generateXyVector(x, y);
    vector2 = generateXyVector(x-1, y-1);
    TEST_ASSERT_FALSE(equalXyVectors(vector1, vector2));
    return;
}

void test_lib_snake_snakeLength(void) {
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

void test_lib_snake_feedSnake(void) {
    struct Snake *snakeHead = NULL;
    
    /*
     * When feeding the snake for the first time
     * it should set the head node (x,y) postiton 
     * to (0,0).
     */
    snakeHead = generateMultipleNodesSnake(0);
    feedSnake(&snakeHead);

    TEST_ASSERT_TRUE(equalXyVectors(generateXyVector(0, 0), snakeHead->position));
    freeSnake(&snakeHead);


    /*
     * When feeding the snake every other time
     * it should set the head node postition to
     * the previous head (x,y) postition
     * position.
     */
    snakeHead = generateMultipleNodesSnake(23);
    feedSnake(&snakeHead);
    
    TEST_ASSERT_TRUE(equalXyVectors(snakeHead->next->position, snakeHead->position));
    freeSnake(&snakeHead);
}

void test_lib_snake_moveSnake_nonFed(void) {
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
    TEST_ASSERT_EQUAL_INT(snake->position.x, oldSnake->position.x + vector.x);
    TEST_ASSERT_EQUAL_INT(snake->position.y, oldSnake->position.y + vector.y);
    snake = snake->next;

    // Left snake's nodes have to match the oldSnake's nodes
    while(snake != NULL) {
        TEST_ASSERT_EQUAL_INT(snake->position.x, oldSnake->position.x);
        TEST_ASSERT_EQUAL_INT(snake->position.y, oldSnake->position.y);
        snake = snake->next;
        oldSnake = oldSnake->next;
    }

    // Freeing snakes
    freeSnake(&snake);
    freeSnake(&oldSnake);
}

void test_lib_snake_moveSnake_fed(void) {
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
    snakeHead->position.x = snakeHead->next->position.x;
    snakeHead->position.y = snakeHead->next->position.y;
    oldSnakeHead = generateMultipleNodesSnake(foodAmt);
    oldSnakeHead->position.x = oldSnakeHead->next->position.x;
    oldSnakeHead->position.y = oldSnakeHead->next->position.y;
    moveSnake(&snakeHead, vector);
    
    // TODO validation
    snake = snakeHead;
    oldSnake = oldSnakeHead;

    // Snake first's node have to match old snake first node 
    // with the given vector added (x + vector.x, y + vector.y)
    TEST_ASSERT_EQUAL_INT(snake->position.x, oldSnake->position.x + vector.x);
    TEST_ASSERT_EQUAL_INT(snake->position.y, oldSnake->position.y + vector.y);
    snake = snake->next;

    // Left snake's nodes have to match the oldSnake's nodes
    while(snake != NULL) {
        TEST_ASSERT_EQUAL_INT(snake->position.x, oldSnake->position.x);
        TEST_ASSERT_EQUAL_INT(snake->position.y, oldSnake->position.y);
        snake = snake->next;
        oldSnake = oldSnake->next;
    }

    // Freeing snakes
    freeSnake(&snake);
    freeSnake(&oldSnake);
}
#include <unity.h>
#include "../../src/lib/snake.h"
#include "../../src/game/validations.c"

struct XYVector normalizePlanePoint(struct XYVector point, struct XYVector screenDims) {
    struct XYVector normalizedPoint;

    normalizedPoint.x = (screenDims.x / 2) + point.x;
    normalizedPoint.y = (screenDims.y / 2) + (point.y * -1);

    return normalizedPoint;
}

void test_game_validations_isSnakeWithingBoundaries_outbound(void) {
    struct XYVector boundaries = generateXyVector(10, 10);
    struct XYVector nodePosition = generateXyVector(6, 0);

    nodePosition = normalizePlanePoint(nodePosition, boundaries);

    TEST_ASSERT_FALSE(isSnakeWithingBoundaries(nodePosition, boundaries));
    return;
}

void test_game_validations_isSnakeWithingBoundaries_inbound(void) {
    struct XYVector boundaries = generateXyVector(10, 10);
    struct XYVector nodePosition = generateXyVector(4, 0);

    nodePosition = normalizePlanePoint(nodePosition, boundaries);

    TEST_ASSERT_TRUE(isSnakeWithingBoundaries(nodePosition, boundaries));
    return;
}

void test_game_validations_checkOppositeDirectionVectors_true(void) {
    struct XYVector newVector; 
    struct XYVector currentVector;

    newVector = generateXyVector(1, 0);
    currentVector = generateXyVector(-1, 0);
    TEST_ASSERT_TRUE(checkOppositeDirectionVectors(newVector, currentVector));

    newVector = generateXyVector(-1, 0);
    currentVector = generateXyVector(1, 0);
    TEST_ASSERT_TRUE(checkOppositeDirectionVectors(newVector, currentVector));

    newVector = generateXyVector(0, 1);
    currentVector = generateXyVector(0, -1);
    TEST_ASSERT_TRUE(checkOppositeDirectionVectors(newVector, currentVector));

    newVector = generateXyVector(0, -1);
    currentVector = generateXyVector(0, 1);
    TEST_ASSERT_TRUE(checkOppositeDirectionVectors(newVector, currentVector));
    return;
}

void test_game_validations_checkOppositeDirectionVectors_false(void) {
    struct XYVector newVector; 
    struct XYVector currentVector;

    newVector = generateXyVector(1, 0);
    currentVector = generateXyVector(1, 0);
    TEST_ASSERT_FALSE(checkOppositeDirectionVectors(newVector, currentVector));

    newVector = generateXyVector(0, 1);
    currentVector = generateXyVector(0, 1);
    TEST_ASSERT_FALSE(checkOppositeDirectionVectors(newVector, currentVector));
    return;
}

void test_game_validations_isOverlappingSnake_true(void) {
    struct Snake *snakeHead = generateMultipleNodesSnake(100);
    snakeHead->position = generateXyVector(0, 0);

    TEST_ASSERT_TRUE(isOverlappingSnake(snakeHead));
    return;
}

void test_game_validations_isOverlappingSnake_false(void) {
    struct Snake *snakeHead = NULL; 
    
    snakeHead = generateMultipleNodesSnake(100);
    snakeHead->position = generateXyVector(-9999, -9999);

    TEST_ASSERT_FALSE(isOverlappingSnake(snakeHead));
    
    snakeHead = generateMultipleNodesSnake(1);
    TEST_ASSERT_FALSE(isOverlappingSnake(snakeHead));

    snakeHead = generateMultipleNodesSnake(2);
    TEST_ASSERT_FALSE(isOverlappingSnake(snakeHead));

    freeSnake(&snakeHead);
    return;
}

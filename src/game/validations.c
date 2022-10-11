#include "../lib/snake.h"

/**
 * Validates Snake's XYVector normalized position within 
 * game boundaries.
 * 
 * @param normPos Normalized node position.
 * @param boundaries Game screen boundaries.
 * 
 * @returns 0 (false) or 1 (true)
*/
int validateNodePosition(struct XYVector normPos, struct XYVector boundaries) {
    if (normPos.x >= boundaries.x) return 0;
    if (normPos.y >= boundaries.y) return 0;
    if (normPos.x <= 0) return 0;
    if (normPos.y <= 0) return 0;

    return 1;
}

/**
 * Checks wether a direction vector is pointing to
 * the opposite direction.
 * 
 * @param newVector XYVector: Direction vector to test against a 
 * current direction vector.
 * @param currentVector XYVector: Current direction vector.
 * 
 * @returns 0 (false) or 1 (true)
 */
int checkOppositeDirectionVectors(struct XYVector newVector, struct XYVector currentVector) {
    if (newVector.x > 0 && currentVector.x < 0) return 1;
    if (newVector.x < 0 && currentVector.x > 0) return 1;
    if (newVector.y > 0 && currentVector.y < 0) return 1;
    if (newVector.y < 0 && currentVector.y > 0) return 1;

    return 0;
}

/**
 * Checks wether a snake is overlapping over itself
 * 
 * @param snakeHead Snake: Snake to check wether it
 * is overlapped or not. 
 * 
 * @returns 0 (false) or 1 (true)
 */
int checkOverlappingSnake(struct Snake *snakeHead) {
    struct Snake *snakePtr = snakeHead;

    snakePtr = snakePtr->next;
    while(snakePtr != NULL) {
        if(equalXyVectors(snakePtr->position, snakeHead->position)) return 1;
        snakePtr = snakePtr->next;
    }

    return 0;
}

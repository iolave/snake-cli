#include "../lib/vector.h"

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
 * @param newVector Direction vector to test against a 
 * current direction vector.
 * @param currentVector Current direction vector.
 */
int checkOppositeDirectionVectors(struct XYVector newVector, struct XYVector currentVector) {
    if (newVector.x > 0 && currentVector.x < 0) return 1;
    if (newVector.x < 0 && currentVector.x > 0) return 1;
    if (newVector.y > 0 && currentVector.y < 0) return 1;
    if (newVector.y < 0 && currentVector.y > 0) return 1;

    return 0;
}
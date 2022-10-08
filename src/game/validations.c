#include "../lib/vector.h"

/**
 * Validates Snake's XYVector normalized position within 
 * game boundaries.
 * 
 * @param normPos Normalized node position
 * @param boundaries Game screen boundaries
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
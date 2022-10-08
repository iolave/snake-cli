#include "vector.h"

struct XYVector generateXyVector(int x, int y) {
    struct XYVector point;
    point.x = x;
    point.y = y;

    return(point);
}

struct XYVector addXyVectors(struct XYVector vector1, struct XYVector vector2) {
    struct XYVector newXyVector;

    newXyVector.x = vector1.x + vector2.x;
    newXyVector.y = vector1.y + vector2.y;

    return newXyVector;
}

int equalXyVectors(struct XYVector vector1, struct XYVector vector2) {
    if(vector1.x != vector2.x) return 0;
    if(vector1.y != vector2.y) return 0;
    return 1;
}
#ifndef VECTOR_H_
#define VECTOR_H_

struct XYVector {
    int x;
    int y;
};

struct XYVector generateXyVector(int x, int y);
struct XYVector addXyVectors(struct XYVector vector1, struct XYVector vector2);
int equalXyVectors(struct XYVector vector1, struct XYVector vector2);

#endif

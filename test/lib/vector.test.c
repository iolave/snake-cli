#include <unity.h>
#include "../../src/lib/vector.h"

void test_lib_vector_generateXyVector(void) {
    struct XYVector point;
    int expectedX = 34;
    int expectedY = -167;

    point = generateXyVector(expectedX, expectedY);
    TEST_ASSERT_EQUAL_INT(expectedX, point.x);
    TEST_ASSERT_EQUAL_INT(expectedY, point.y);

    return;
}

void test_lib_vector_addXyVectors(void) {
    struct XYVector vector;
    int expectedX = 34;
    int expectedY = -167;

    vector = addXyVectors(generateXyVector(expectedX,expectedY), generateXyVector(expectedX,expectedY));
    TEST_ASSERT_EQUAL_INT(expectedX * 2, vector.x);
    TEST_ASSERT_EQUAL_INT(expectedY * 2, vector.y);

    return;
}

void test_lib_vector_equalXyVectors(void) {
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
#include <unity.h>
#include "../../src/lib/vector.h"
#include "../../src/game/validations.c"

struct XYVector normalizePlanePoint(struct XYVector point, struct XYVector screenDims) {
    struct XYVector normalizedPoint;

    normalizedPoint.x = (screenDims.x / 2) + point.x;
    normalizedPoint.y = (screenDims.y / 2) + (point.y * -1);

    return normalizedPoint;
}

void test_game_validations_validateNodePosition_outbound(void) {
    struct XYVector boundaries = generateXyVector(10, 10);
    struct XYVector nodePosition = generateXyVector(6, 0);

    nodePosition = normalizePlanePoint(nodePosition, boundaries);

    TEST_ASSERT_FALSE(validateNodePosition(nodePosition, boundaries));
    return;
}

void test_game_validations_validateNodePosition_inbound(void) {
struct XYVector boundaries = generateXyVector(10, 10);
    struct XYVector nodePosition = generateXyVector(4, 0);

    nodePosition = normalizePlanePoint(nodePosition, boundaries);

    TEST_ASSERT_TRUE(validateNodePosition(nodePosition, boundaries));
    return;
}

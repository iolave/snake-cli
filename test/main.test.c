#include <unity.h>
#include "./lib/vector.test.c"
#include "./lib/snake.test.c"
#include "./game/validations.test.c"
#include "./controllers/keyboard.test.c"

void setUp() {}
void tearDown() {}

int main() {
    UNITY_BEGIN();
    
    // TESTING src/lib/vector.c
    RUN_TEST(test_lib_vector_generateXyVector);
    RUN_TEST(test_lib_vector_addXyVectors);
    RUN_TEST(test_lib_vector_equalXyVectors);

    // TESTING src/lib/snake.c
    RUN_TEST(test_lib_snake_freeSnake);
    RUN_TEST(test_lib_snake_snakeLength);
    RUN_TEST(test_lib_snake_feedSnake);
    RUN_TEST(test_lib_snake_moveSnake_nonFed);
    RUN_TEST(test_lib_snake_moveSnake_fed);

    // TESTING src/controller/keyboard.c
    RUN_TEST(test_controller_keyboard_calculateDirection);
    
    // TESTING src/game/validations.c
    RUN_TEST(test_game_validations_validateNodePosition_outbound);
    RUN_TEST(test_game_validations_validateNodePosition_inbound);
    RUN_TEST(test_game_validations_checkOppositeDirectionVectors_true);
    RUN_TEST(test_game_validations_checkOppositeDirectionVectors_false);
    RUN_TEST(test_game_validations_checkOverlappingSnake_true);
    RUN_TEST(test_game_validations_checkOverlappingSnake_false);

    return UNITY_END();
}
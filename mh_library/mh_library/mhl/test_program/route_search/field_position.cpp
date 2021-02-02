#include "field_position.hpp"

/**
 * @brief Construct a new Field Position object
 *
 */
test_program::route_search::FieldPosition::FieldPosition() : x_(0), y_(0) {}

/**
 * @brief Construct a new Field Position object
 *
 * @param x 位置X
 * @param y 位置Y
 */
test_program::route_search::FieldPosition::FieldPosition(int32_t x, int32_t y)
    : x_(x), y_(y) {}

/**
 * @brief Destroy the Field Position object
 *
 */
test_program::route_search::FieldPosition::~FieldPosition() {}

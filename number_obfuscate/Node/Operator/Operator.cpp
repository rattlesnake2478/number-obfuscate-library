#include "Operator.h"

const std::string RSnake::PlusOperator::NAME = std::string("plus");
const std::string RSnake::MinusOperator::NAME = std::string("minus");

const int64_t
RSnake::PlusOperator::
perform (const int64_t lh, const int64_t rh) {
    return lh + rh;
}

const int64_t
RSnake::PlusOperator::
reverse (const int64_t lh, const int64_t total) {
    return total - lh;
}

const int64_t
RSnake::MinusOperator::
perform (const int64_t lh, const int64_t rh) {
    return lh - rh;
}

const int64_t
RSnake::MinusOperator::
reverse (const int64_t lh, const int64_t total) {
    return lh - total;
}

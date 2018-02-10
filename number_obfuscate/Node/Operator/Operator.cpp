#include "Operator.h"

const std::string RSnake::PlusOperator::NAME = std::string("plus");
const std::string RSnake::MinusOperator::NAME = std::string("minus");
const std::string RSnake::MulOperator::NAME = std::string("mul");
const std::string RSnake::DivOperator::NAME = std::string("div");

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

const int64_t
RSnake::MulOperator::
perform (const int64_t lh, const int64_t rh) {
    return lh * rh;
}

const int64_t
RSnake::MulOperator::
reverse (const int64_t lh, const int64_t total) {
    if (0 == lh) {
        additional_ = total;
        return 0;
    }
    additional_ = total%lh;
    return total / lh;
}

const int64_t
RSnake::DivOperator::
perform (const int64_t lh, const int64_t rh) {
    return lh / rh;
}

const int64_t
RSnake::DivOperator::
reverse (const int64_t lh, const int64_t total) {
    int64_t result = lh / total;
    additional_ = - (lh%total)/result;
    return result;
}

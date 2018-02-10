#include <random>

#include "Node.h"
#include "Operator/OperatorFactory.h"

const std::string
RSnake::Node::
getString() const {
    if (operator_) {
        return std::string("(")
               + left_->getString()
               + operator_->getStringRepresentation()
               + right_->getString()
               + std::string(")");
    }
    if (balance_ >= 0 ) {
        return std::to_string(balance_);
    } else {
        return std::string("(") + std::to_string(balance_) + std::string(")");
    }
}

void
RSnake::Node::
explode() {
    if (operator_) {
        // already exploded
        return;
    }

    operator_ = RSnake::OperatorFactory::getRandomOperator();

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int64_t> uni(INT32_MIN, INT32_MAX);

    auto value = uni(rng);
    left_ = std::make_unique<Node>(value);
    right_ = std::make_unique<Node>(operator_->reverse(value, balance_));
}

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
               + operator_->getAdditionalString()
               + std::string(")");
    }
    if (NodeState::KNOWN == state_) {
        return config_.knownVariableName;
    }
    if (NodeState::UNKNOWN == state_) {
        return config_.unknownVariableName;
    }
    if (balance_ >= 0 ) {
        return std::to_string(balance_);
    } else {
        return std::string("(") + std::to_string(balance_) + std::string(")");
    }
}

void
RSnake::Node::
explode(uint8_t deep) {
    if (0 == deep) {
        // end of exploding
        return;
    }

    if (NodeState::NUMERIC != state_) {
        // we cannot explode non-numeric node
        return;
    }
    if (operator_) {
        // node already exploded
        return;
    }

    // TODO: Move generator to static member
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int64_t> uni(config_.min, config_.max);
    std::uniform_int_distribution<uint8_t> sti(0, 100);

    auto guess = sti(rng);
    NodeState state = NodeState::NUMERIC;
    auto value = uni(rng);
    if (guess < 20) {
        state = NodeState::KNOWN;
        value = config_.knownVariableValue;
    }

    operator_ = RSnake::OperatorFactory::guessOperator(value, balance_);

    left_ = std::make_unique<Node>(value, config_, state);
    right_ = std::make_unique<Node>(operator_->reverse(value, balance_), config_);
    left_->explode(--deep);
    right_->explode(deep);
}

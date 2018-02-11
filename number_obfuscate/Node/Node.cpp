#include <random>

#include "Node.h"
#include "Operator/OperatorFactory.h"
#include "Decorator/DecoratorFactory.h"

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
    auto prefix = std::string();
    if (NodeState::UNKNOWN == state_) {
        prefix = config_.unknownVariableName + std::string("*");
    }
    auto decorator = DecoratorFactory::getRandomDecorator(balance_, config_);
    if (balance_ >= 0 ) {
        return prefix + decorator->decorateValue(balance_);
    } else {
        return prefix + std::string("(") + decorator->decorateValue(balance_) + std::string(")");
    }
}

void
RSnake::Node::
explode(uint8_t deep) {
    if (0 == deep) {
        // end of exploding
        return;
    }

    if (NodeState::KNOWN == state_) {
        // we cannot explode known state node
        return;
    }
    if (operator_) {
        // node already exploded
        return;
    }

    int64_t leftValue = 0;
    auto states = guessLeftNodeAndGetStates(leftValue, state_);
    operator_ = RSnake::OperatorFactory::guessOperator(leftValue, balance_);
    auto rightValue = operator_->reverse(leftValue, balance_);

    left_ = std::make_unique<Node>(leftValue, config_, states.first);
    right_ = std::make_unique<Node>(rightValue, config_, states.second);
    left_->explode(--deep);
    right_->explode(deep);
}

const std::pair<RSnake::NodeState, RSnake::NodeState>
RSnake::Node::
guessLeftNodeAndGetStates(int64_t &leftValue, NodeState baseState) const {

    auto leftState = NodeState::NUMERIC;
    auto rightState = NodeState::NUMERIC;
    if (NodeState::UNKNOWN == baseState) {
        leftState = NodeState::UNKNOWN;
        rightState = NodeState::UNKNOWN;
    }

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int64_t> uni(config_.min, config_.max);
    std::uniform_int_distribution<uint8_t> sti(0, 100);

    leftValue = uni(rng);

    auto guess = sti(rng);

    if (NodeState::NUMERIC == baseState) {
        if(guess < KNOWN_PROBABILITY) {
            leftState = NodeState::KNOWN;
            leftValue = config_.knownVariableValue;
        } else if (guess > KNOWN_PROBABILITY && guess < KNOWN_PROBABILITY + UNKNOWN_PROBABILITY) {
            leftState = NodeState::UNKNOWN;
            leftValue = 0;
        }
    }

    return std::make_pair(leftState, rightState);
};
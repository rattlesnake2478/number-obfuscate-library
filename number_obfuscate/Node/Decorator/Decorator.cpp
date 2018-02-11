#include <cmath>

#include "Decorator.h"

const bool
RSnake::EmptyDecorator::
testValue(const int64_t value) const {
    return true; // All values acceptable for empty decorator
};

const std::string
RSnake::EmptyDecorator::
decorateValue (const int64_t value) const {
    if (value == config_.knownVariableValue) {
        return config_.knownVariableName;
    }
    return std::to_string(value); // no decoration
};

const bool
RSnake::LogDecorator::
testValue(const int64_t value) const {
    return value > 0 && value < 5; // Not more than 10^5
};

const std::string
RSnake::LogDecorator::
decorateValue (const int64_t value) const {
    auto decorated = (int64_t)pow(10, value);
    return std::string("log10(") + std::to_string(decorated) + std::string(")");
};

const bool
RSnake::PowerDecorator::
testValue(int64_t value) const {
    if (0 == value) {
        return false; // no null powering
    }
    if (config_.knownVariableValue * config_.knownVariableValue == value) {
        return true; // power known value
    }
    auto temp = sqrt(value);
    auto rounded = (int64_t)temp;
    return 0.001 > fabs(temp - rounded);
};

const std::string
RSnake::PowerDecorator::
decorateValue (int64_t value) const {
    if (config_.knownVariableValue * config_.knownVariableValue == value) {
        return config_.knownVariableName + std::string("*") + config_.knownVariableName;
    }
    auto decorated = (int64_t)sqrt(value);
    return std::to_string(decorated) + std::string("*") + std::to_string(decorated);
};

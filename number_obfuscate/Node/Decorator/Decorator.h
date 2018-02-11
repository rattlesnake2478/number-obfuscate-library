#ifndef NUMBER_OBFUSCATE_DECORATOR_H
#define NUMBER_OBFUSCATE_DECORATOR_H

#include "AbstractDecorator.h"

namespace RSnake {

class EmptyDecorator : public AbstractDecorator {
public:
    explicit EmptyDecorator(ObfuscateConfig config): AbstractDecorator(config) {};
    const bool testValue(int64_t value) const;
    const std::string decorateValue (int64_t value) const;
};

class LogDecorator : public AbstractDecorator {
public:
    explicit LogDecorator(ObfuscateConfig config): AbstractDecorator(config) {};
    const bool testValue(int64_t value) const;
    const std::string decorateValue (int64_t value) const;
};

class PowerDecorator : public AbstractDecorator {
public:
    explicit PowerDecorator(ObfuscateConfig config): AbstractDecorator(config) {};
    const bool testValue(int64_t value) const;
    const std::string decorateValue (int64_t value) const;
};

}// End namespace RSnake

#endif //NUMBER_OBFUSCATE_DECORATOR_H

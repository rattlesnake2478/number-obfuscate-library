#ifndef NUMBER_OBFUSCATE_ABSTRACTDECORATOR_H
#define NUMBER_OBFUSCATE_ABSTRACTDECORATOR_H

#include <string>

#include "../ObfuscateConfig.h"

namespace RSnake {

class AbstractDecorator {

protected:
    ObfuscateConfig config_;
public:
    AbstractDecorator() {};
    explicit AbstractDecorator(ObfuscateConfig config): config_(config) {};

    virtual const bool testValue(int64_t value) const = 0;
    virtual const std::string decorateValue(int64_t value) const = 0;

}; // end class AbstractDecorator

}// End namespace RSnake

#endif //NUMBER_OBFUSCATE_ABSTRACTDECORATOR_H

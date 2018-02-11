#ifndef NUMBER_OBFUSCATE_DECORATORFACTORY_H
#define NUMBER_OBFUSCATE_DECORATORFACTORY_H

#include <memory>

#include "Decorator.h"

namespace RSnake {

class DecoratorFactory {
public:
    static const std::shared_ptr<AbstractDecorator> getRandomDecorator(int64_t value, const ObfuscateConfig &config);
};
}// End namespace RSnake


#endif //NUMBER_OBFUSCATE_DECORATORFACTORY_H

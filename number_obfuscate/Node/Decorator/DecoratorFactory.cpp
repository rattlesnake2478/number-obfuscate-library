#include <vector>

#include "DecoratorFactory.h"

const std::shared_ptr<RSnake::AbstractDecorator>
RSnake::DecoratorFactory::
getRandomDecorator(const  int64_t value, const RSnake::ObfuscateConfig &config) {
    static const std::vector<std::shared_ptr<AbstractDecorator>> decorators = {
        std::shared_ptr<AbstractDecorator>(new PowerDecorator(config)),
        std::shared_ptr<AbstractDecorator>(new LogDecorator(config)),
        std::shared_ptr<AbstractDecorator>(new EmptyDecorator(config))
    };

    for (const auto & element: decorators) {
        if (element->testValue(value)) {
            return element;
        }
    }

    throw std::runtime_error("At least one decorator should be provided");
}
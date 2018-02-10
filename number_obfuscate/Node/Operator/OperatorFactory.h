#ifndef NUMBER_OBFUSCATE_OPERATORFACTORY_H
#define NUMBER_OBFUSCATE_OPERATORFACTORY_H

#include <vector>
#include <random>

#include "OperatorInterface.h"
#include "Operator.h"

namespace RSnake {

class OperatorFactory {
public:

    // Retrieve random operator
    static const std::shared_ptr<OperatorInterface> getRandomOperator() {
        const std::vector<std::string> OPERATORS = {
            PlusOperator::NAME,
            MinusOperator::NAME
        };

        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> uni(0, OPERATORS.size() - 1);

        auto index = uni(rng);
        return getOperatorByName(OPERATORS[index]);
    }

    // Get operator name
    static const std::shared_ptr<OperatorInterface> getOperatorByName(const std::string & name) {
        if (name == PlusOperator::NAME) {
            return std::shared_ptr<OperatorInterface>(new PlusOperator());
        }
        if (name == MinusOperator::NAME) {
            return std::shared_ptr<OperatorInterface>(new MinusOperator());
        }

        throw std::runtime_error(std::string("Unsupported operator name provided for operator factory - ") + name);
    }

}; // end class TransformerInterface

} //end namespace RSnake
#endif //NUMBER_OBFUSCATE_OPERATORFACTORY_H

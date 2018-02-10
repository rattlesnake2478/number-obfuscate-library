#ifndef NUMBER_OBFUSCATE_OPERATORFACTORY_H
#define NUMBER_OBFUSCATE_OPERATORFACTORY_H

#include <memory>

#include "AbstractOperator.h"
#include "Operator.h"

namespace RSnake {

class OperatorFactory {
public:

    static const std::shared_ptr<AbstractOperator> getRandomOperator();
    static const std::shared_ptr<AbstractOperator> guessOperator(int64_t lh, int64_t total);
    static const std::shared_ptr<AbstractOperator> getOperatorByName(const std::string & name);

}; // end class TransformerInterface

} //end namespace RSnake
#endif //NUMBER_OBFUSCATE_OPERATORFACTORY_H

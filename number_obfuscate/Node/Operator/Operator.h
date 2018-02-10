#ifndef NUMBER_OBFUSCATE_OPERATOR_H
#define NUMBER_OBFUSCATE_OPERATOR_H

#include "OperatorInterface.h"

namespace RSnake {

class PlusOperator: public OperatorInterface {
public:
    static const std::string NAME;
    const std::string getStringRepresentation() const {return std::string("+");};
    const int64_t perform (int64_t lh, int64_t rh);
    const int64_t reverse (int64_t lh, int64_t total);
};

class MinusOperator: public OperatorInterface {
public:
    static const std::string NAME;
    const std::string getStringRepresentation() const {return std::string("-");};
    const int64_t perform (int64_t lh, int64_t rh);
    const int64_t reverse (int64_t lh, int64_t total);
};

}// End namespace RSnake
#endif //NUMBER_OBFUSCATE_OPERATOR_H

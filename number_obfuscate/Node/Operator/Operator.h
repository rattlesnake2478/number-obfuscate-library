#ifndef NUMBER_OBFUSCATE_OPERATOR_H
#define NUMBER_OBFUSCATE_OPERATOR_H

#include "AbstractOperator.h"

namespace RSnake {

class PlusOperator: public AbstractOperator {
public:
    static const std::string NAME;
    const std::string getStringRepresentation() const {return std::string("+");};
    const int64_t perform (int64_t lh, int64_t rh);
    const int64_t reverse (int64_t lh, int64_t total);
};

class MinusOperator: public AbstractOperator {
public:
    static const std::string NAME;
    const std::string getStringRepresentation() const {return std::string("-");};
    const int64_t perform (int64_t lh, int64_t rh);
    const int64_t reverse (int64_t lh, int64_t total);
};

class MulOperator: public AbstractOperator {
public:
    static const std::string NAME;
    const std::string getStringRepresentation() const {return std::string("*");};
    const int64_t perform (int64_t lh, int64_t rh);
    const int64_t reverse (int64_t lh, int64_t total);
};

class DivOperator: public AbstractOperator {
public:
    static const std::string NAME;
    const std::string getStringRepresentation() const {return std::string("/");};
    const int64_t perform (int64_t lh, int64_t rh);
    const int64_t reverse (int64_t lh, int64_t total);
};

}// End namespace RSnake
#endif //NUMBER_OBFUSCATE_OPERATOR_H

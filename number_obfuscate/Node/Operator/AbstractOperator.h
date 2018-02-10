#ifndef NUMBER_OBFUSCATE_TRANSFORMERINTERFACE_H
#define NUMBER_OBFUSCATE_TRANSFORMERINTERFACE_H

#include <string>

namespace RSnake {

class AbstractOperator {
protected:
    int64_t additional_ = 0;

public:

    // return string representation of operator
    virtual const std::string getStringRepresentation() const = 0;

    //perform operation
    virtual const int64_t perform (int64_t lh, int64_t rh) = 0;

    // perform reverse operation
    virtual const int64_t reverse (int64_t lh, int64_t total) = 0;

    const std::string getAdditionalString() const {
        if (0 == additional_) return std::string();
        if (0 < additional_) return std::string("+") + std::to_string(additional_);
        if (0 > additional_) return std::string("+(") + std::to_string(additional_) + std::string(")");
    }

}; // end class TransformerInterface

} //end namespace RSnake
#endif //NUMBER_OBFUSCATE_TRANSFORMERINTERFACE_H

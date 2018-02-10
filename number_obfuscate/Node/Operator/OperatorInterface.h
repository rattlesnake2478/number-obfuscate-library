#ifndef NUMBER_OBFUSCATE_TRANSFORMERINTERFACE_H
#define NUMBER_OBFUSCATE_TRANSFORMERINTERFACE_H

#include <string>

namespace RSnake {

class OperatorInterface {
public:

    // return string representation of operator
    virtual const std::string getStringRepresentation() const = 0;

    //perform operation
    virtual const int64_t perform (int64_t lh, int64_t rh) = 0;

    // perform reverse operation
    virtual const int64_t reverse (int64_t lh, int64_t total) = 0;

}; // end class TransformerInterface

} //end namespace RSnake
#endif //NUMBER_OBFUSCATE_TRANSFORMERINTERFACE_H

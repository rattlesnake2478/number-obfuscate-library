#include "number_obfuscate.h"

#include <iostream>

namespace RSnake {

const std::string
NumberObfuscate::
generateString(const int64_t value) {

    auto rootNode = std::make_shared<Node>(value);
    rootNode->explode();
    return rootNode->getString();
}

}// End namespace RSnake
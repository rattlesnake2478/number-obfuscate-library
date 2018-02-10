#ifndef NUMBER_OBFUSCATE_LIBRARY_H
#define NUMBER_OBFUSCATE_LIBRARY_H

#include <cstdint>
#include <string>
#include "Node/Node.h"

namespace RSnake {

class NumberObfuscate {
public:
    const std::string generateString (int64_t value);
};

} //end namespace RSnake

#endif
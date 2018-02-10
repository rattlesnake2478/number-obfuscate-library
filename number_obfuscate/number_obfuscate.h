#ifndef NUMBER_OBFUSCATE_LIBRARY_H
#define NUMBER_OBFUSCATE_LIBRARY_H

#include <cstdint>
#include <string>
#include "Node/Node.h"

namespace RSnake {

class NumberObfuscate {
private:
    ObfuscateConfig config_;
public:
    NumberObfuscate() {};
    explicit NumberObfuscate(const ObfuscateConfig & config): config_(config) {};
    const std::string generateString (int64_t value);
};

} //end namespace RSnake

#endif
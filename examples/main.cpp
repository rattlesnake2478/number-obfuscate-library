#include <number_obfuscate.h>
#include <iostream>

int main(int argc, char *argv[]) {
    auto numberObfuscate = new RSnake::NumberObfuscate();
    std::cout << numberObfuscate->generateString(64) << std::endl;
    return 0;
}

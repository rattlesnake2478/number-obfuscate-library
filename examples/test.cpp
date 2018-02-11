#include <iostream>

#include <matheval.h>
#include <number_obfuscate.h>

int main(int argc, char *argv[]) {
    auto config = RSnake::ObfuscateConfig(std::string("x"), std::string("y"));
    auto numberObfuscate = new RSnake::NumberObfuscate(config);
    const int64_t required = 64;

    uint32_t cnt = 0;
    uint32_t numTests = 10;

    for (uint32_t i = 0; i < numTests; i++) {
        auto expression = numberObfuscate->generateString(required);
        auto f = evaluator_create ((char *)expression.c_str());

        auto result = (int64_t)evaluator_evaluate_x_y(f, config.knownVariableValue, 89);
        if (result != required) {
            ++cnt;
            std::cout << "Result: " << result << std::endl;
            std::cout << expression << std::endl;
        }
    }
    std::cout << "Total: " << cnt << " of " <<  numTests << std::endl;

    return 0;
}

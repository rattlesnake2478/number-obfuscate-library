#ifndef NUMBER_OBFUSCATE_OBFUSCATECONFIG_H
#define NUMBER_OBFUSCATE_OBFUSCATECONFIG_H

namespace RSnake {

struct ObfuscateConfig {
    std::string knownVariableName = "i";
    std::string unknownVariableName = "j";
    int64_t knownVariableValue = 5;
    uint8_t deep = 5;
    const int64_t min = INT16_MIN;
    const int64_t max = INT16_MAX;

    ObfuscateConfig() {};
    explicit ObfuscateConfig(const uint8_t deepVal): deep(deepVal) {}
    explicit ObfuscateConfig(const uint8_t deepVal, const int64_t knownVal)
            : deep(deepVal), knownVariableValue(knownVal) {}
    ObfuscateConfig(const std::string & known, const std::string & unknown)
            : knownVariableName(known), unknownVariableName(unknown) {}
    ObfuscateConfig(const uint8_t deepVal, const int64_t knownVal, const std::string & known, const std::string & unknown)
            : deep(deepVal), knownVariableValue(knownVal), knownVariableName(known), unknownVariableName(unknown) {}
};

} //end namespace RSnake
#endif //NUMBER_OBFUSCATE_OBFUSCATECONFIG_H

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE mainTest
#include <boost/test/unit_test.hpp>

#include <matheval.h>
#include <number_obfuscate.h>

BOOST_AUTO_TEST_CASE( expression_should_match_test ) {
    auto config = RSnake::ObfuscateConfig(std::string("x"), std::string("y"));
    auto numberObfuscate = RSnake::NumberObfuscate(config);
    const int64_t requiredNumber = 64;
    const int64_t unknownValue = 75;

    auto expression = numberObfuscate.generateString(requiredNumber);
    auto f = evaluator_create ((char *)expression.c_str());
    auto result = (int64_t)evaluator_evaluate_x_y(f, config.knownVariableValue, unknownValue);

    BOOST_CHECK_EQUAL(requiredNumber, result);
}

BOOST_AUTO_TEST_CASE( expression_should_depend_on_known_test ) {
    auto config = RSnake::ObfuscateConfig(std::string("x"), std::string("y"));
    auto numberObfuscate = RSnake::NumberObfuscate(config);
    const int64_t requiredNumber = 64;
    const int64_t unknownValue = 75;

    auto expression = numberObfuscate.generateString(requiredNumber);
    auto f = evaluator_create ((char *)expression.c_str());
    auto correct = (int64_t)evaluator_evaluate_x_y(f, config.knownVariableValue, unknownValue);
    auto inCorrect = (int64_t)evaluator_evaluate_x_y(f, config.knownVariableValue - 600, unknownValue);

    BOOST_CHECK_EQUAL(requiredNumber, correct);
    BOOST_CHECK_EQUAL(false, requiredNumber == inCorrect);
}

BOOST_AUTO_TEST_CASE( expression_should_independ_on_unknown_test ) {
    auto config = RSnake::ObfuscateConfig(std::string("x"), std::string("y"));
    auto numberObfuscate = RSnake::NumberObfuscate(config);
    const int64_t requiredNumber = 64;
    const int64_t unknownValue = 75;

    auto expression = numberObfuscate.generateString(requiredNumber);
    auto f = evaluator_create ((char *)expression.c_str());
    auto correct1 = (int64_t)evaluator_evaluate_x_y(f, config.knownVariableValue, unknownValue);
    auto correct2 = (int64_t)evaluator_evaluate_x_y(f, config.knownVariableValue, unknownValue - 100);

    BOOST_CHECK_EQUAL(requiredNumber, correct1);
    BOOST_CHECK_EQUAL(requiredNumber, correct2);
}
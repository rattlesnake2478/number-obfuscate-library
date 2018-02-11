#include <random>

#include "OperatorFactory.h"

const std::shared_ptr<RSnake::AbstractOperator>
RSnake::OperatorFactory::
getRandomOperator() {
    const std::vector<std::string> OPERATORS = {
        PlusOperator::NAME,
        MinusOperator::NAME,
//        MulOperator::NAME  //TODO: investigate unknown value type issue - with mul we have powered unknown value
    };

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<unsigned long> uni(0, OPERATORS.size() - 1);

    auto index = uni(rng);
    return getOperatorByName(OPERATORS[index]);
}

const std::shared_ptr<RSnake::AbstractOperator>
RSnake::OperatorFactory::
guessOperator(const int64_t lh, const int64_t total) {
    // TODO: investigate SIGFPE errors with dividing by zero
    /*if (total && abs(lh) > abs(total)) {
        return std::shared_ptr<AbstractOperator>(new DivOperator());
    }*/

    return getRandomOperator();
}

const std::shared_ptr<RSnake::AbstractOperator>
RSnake::OperatorFactory::
getOperatorByName(const std::string & name) {
    if (name == PlusOperator::NAME) {
        return std::shared_ptr<AbstractOperator>(new PlusOperator());
    }
    if (name == MinusOperator::NAME) {
        return std::shared_ptr<AbstractOperator>(new MinusOperator());
    }
    if (name == MulOperator::NAME) {
        return std::shared_ptr<AbstractOperator>(new MulOperator());
    }


    throw std::runtime_error(std::string("Unsupported operator name provided for operator factory - ") + name);
}
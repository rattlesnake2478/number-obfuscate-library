#ifndef NUMBER_OBFUSCATE_ABSTRACTNODE_H
#define NUMBER_OBFUSCATE_ABSTRACTNODE_H

#include <memory>

#include "ObfuscateConfig.h"
#include "Operator/AbstractOperator.h"

namespace RSnake {

enum NodeState {
    NUMERIC = 1,
    KNOWN,
    UNKNOWN
};

class Node {

    static const uint8_t KNOWN_PROBABILITY = 20; //percent
    static const uint8_t UNKNOWN_PROBABILITY = 20; //percent

private:
    NodeState state_;
    ObfuscateConfig config_;
    int64_t balance_;
    std::unique_ptr<Node> left_;
    std::unique_ptr<Node> right_;
    std::shared_ptr<AbstractOperator> operator_;

    const std::pair<NodeState, NodeState> guessLeftNodeAndGetStates(int64_t &leftValue, NodeState baseState) const;

public:
    Node(const int64_t balance, const ObfuscateConfig & config, NodeState state = NodeState::NUMERIC)
            : balance_(balance), config_(config), state_(state) {};

    const std::string getString() const;
    void explode() { explode(config_.deep); };
    void explode(uint8_t deep);


}; //end class Node

}// end namespace RSnake
#endif //NUMBER_OBFUSCATE_ABSTRACTNODE_H

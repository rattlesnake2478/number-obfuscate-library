#ifndef NUMBER_OBFUSCATE_ABSTRACTNODE_H
#define NUMBER_OBFUSCATE_ABSTRACTNODE_H

#include <memory>

#include "ObfuscateConfig.h"
#include "Operator/OperatorInterface.h"

namespace RSnake {

enum NodeState {
    NUMERIC = 1,
    KNOWN,
    UNKNOWN
};

class Node {

private:
    NodeState state_;
    ObfuscateConfig config_;
    int64_t balance_;
    std::unique_ptr<Node> left_;
    std::unique_ptr<Node> right_;
    std::shared_ptr<OperatorInterface> operator_;

public:
    Node(const int64_t balance, const ObfuscateConfig & config, NodeState state = NodeState::NUMERIC)
            : balance_(balance), config_(config), state_(state) {};

    const std::string getString() const;
    void explode() { explode(config_.deep); };
    void explode(uint8_t deep);

}; //end class Node

}// end namespace RSnake
#endif //NUMBER_OBFUSCATE_ABSTRACTNODE_H

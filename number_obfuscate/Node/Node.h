#ifndef NUMBER_OBFUSCATE_ABSTRACTNODE_H
#define NUMBER_OBFUSCATE_ABSTRACTNODE_H

#include "Operator/OperatorInterface.h"
#include <memory>

namespace RSnake {

class Node {
private:
    int64_t balance_;
    std::unique_ptr<Node> left_;
    std::unique_ptr<Node> right_;
    std::shared_ptr<OperatorInterface> operator_;

public:
    Node(const int64_t balance): balance_(balance) {};
    Node(const int64_t balance, std::shared_ptr<OperatorInterface> op): balance_(balance), operator_(op) {};

    const std::string getString() const;
    void explode();

}; //end class Node

}// end namespace RSnake
#endif //NUMBER_OBFUSCATE_ABSTRACTNODE_H

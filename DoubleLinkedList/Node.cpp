#include "Node.hpp"


Node::Node(){
    this->pNext = nullptr;
    this->pPrev = nullptr;
}

Node::Node(const Circle* other){
    this->m_data = *other;
    this->pPrev = NULL;
    this->pNext = NULL;
}

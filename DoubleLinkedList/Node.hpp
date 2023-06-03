#pragma once
#include "Circle.hpp"


class Node{
public:
    Node* pPrev;
    Node* pNext;
    Circle m_data;
public:
    Node();
    Node(const Circle* other);
    
};

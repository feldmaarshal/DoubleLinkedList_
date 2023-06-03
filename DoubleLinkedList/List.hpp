#pragma once
#include "Node.hpp"
#include <iostream>
#include <string>
#include <sstream>
using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using std::endl;
using std::string;

class List {
private:
    
    Node * head;
    Node * tail;
    unsigned int size;
    
    void pop_front();
    void pop_back();
    
    Node* getAt(int index);
    void insert(int index, const Circle* other);
    void erase(Node* pNode);
    
    void swap(Node* first, Node* second);
    
public:
    List();
    ~List();
    
    void push_front(const Circle* other);
    void push_back(const Circle* other);
    
    
    void clear();
    
    bool if_del(Circle* other);
    int all_if_del(Circle* other);
    
    void sort(); // !
    
    unsigned int Get_size(){ return size;};
    Node* operator[](int index);
};

ostream& operator <<(ostream& os, List& list);
istream& operator >>(istream& os, List& list);

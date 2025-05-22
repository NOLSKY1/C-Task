
#include "Category.h"
#include <iostream>

using namespace std;

CategoryNode::CategoryNode() {
    data = nullptr;
    next = nullptr;
    cout << "Constructeur par defaut appele (category node)" << endl;
}

CategoryNode::CategoryNode(Category* category) {
    data = category;
    next = nullptr;
    cout << "Constructeur avec parametre appele (category node)" << endl;
}

CategoryNode::CategoryNode(const CategoryNode& node) {
    data = node.data;
    next = node.next;
    cout << "Constructeur de recopie appele (category node)" << endl;
}

CategoryNode::~CategoryNode() {
    delete data;
    cout << "Destructeur appele (category node)" << endl;
}

CategoryNode& CategoryNode::operator=(const CategoryNode& node) {
    delete data; 
    data = node.data;
    next = node.next;
    cout << "Operateur d'affectation appele (category node)" << endl;
    return *this;
}

Category* CategoryNode::getData() const {
    return data;
}

CategoryNode* CategoryNode::getNext() const {
    return next;
}

void CategoryNode::setNext(CategoryNode* node) {
    this->next = node;
}

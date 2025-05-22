#include "node.h"
#include <iostream>

using namespace std;

Node::Node()
{
    data = nullptr;
    next = nullptr;
    cout << "Constructeur par defaut appele (node)" << endl;
}
Node::Node(Role *role)
{
    data = role;
    next = nullptr;
    cout << "Constructeur avec parametre appele (node)" << endl;
}
Node::Node(const Node &node)
{
    data = node.data;
    next = node.next;
    cout << "Constructeur de recopie appele (node)" << endl;
}
Node::~Node()
{
    delete data;
    cout << "Destructeur appele (node)" << endl;
}
Node &Node::operator=(const Node &node)
{
    delete data;
    data = node.data;
    next = node.next;
    return *this;
    cout << "Operateur d'affectation" << endl;
}
Role *Node::getData() const
{
    return data;
}
Node *Node::getNext() const
{
    return next;
}
void Node::setNext(Node *node)
{
    // Node * courant = next;
    //  in this part i delete all nodes that are linked to mine (no memory leak)
    // while(courant !=nullptr){
    //    Node * nodeToDelete = courant;
    //     courant = courant->next;
    //     delete nodeToDelete;
    // }
    this->next = node;
}

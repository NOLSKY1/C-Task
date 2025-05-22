#ifndef Node_h
#define Node_h
#include"../Role/Role.h"


class Node{
    private:
    Role * data ;
    Node * next ;

    public:
    Node();
    Node( Role *);
    Node(const Node &);
    ~Node();
    Node & operator=(const Node &);
    Role * getData() const ;
    Node * getNext() const ;
    void setNext(Node *);

};




#endif
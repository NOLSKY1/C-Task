#ifndef CATEGORY_NODE_H
#define CATEGORY_NODE_H

class Category;
class CategoryNode {
private:
    Category* data;
    CategoryNode* next;

public:
    CategoryNode();
    CategoryNode(Category*);
    CategoryNode(const CategoryNode&);
    ~CategoryNode();
    CategoryNode& operator=(const CategoryNode&);
    Category* getData() const;
    CategoryNode* getNext() const;
    void setNext(CategoryNode*);
};

#endif

#include"Category.h"
#include<iostream>
#include<cstring>
#include"../Role/Role.h"
#include<regex>
#include "CategoryNode.h"

using namespace std;

int Category::idInc=0;
CategoryNode* Category::head = nullptr;

Category::Category (){
    name = new char[40];
    strcpy(name,"Default category");
    description = new char[40];
    strcpy(description,"This is a default category");
    slug = Role::GenerateSlug(name);
    idInc++;
    id=idInc;
    //cout<<"Constructeur par defaut appele (Category)"<<endl;
}
Category::Category(const char * name_ , const char * description_){
    name = new char[strlen(name_)+1];
    strcpy(name,name_);
    description = new char[strlen(description_)+1];
    strcpy(description,description_);
    slug=Role::GenerateSlug(name_);
    idInc++;
    id=idInc;
    //cout<<"Constructeur avec parametre appele (Category)"<<endl;
}
Category::Category(const Category & C){
    name = new char[strlen(C.name)+1];
    strcpy(name,C.name);
    description = new char[strlen(C.description)+1];
    strcpy(description,C.description);
    slug =Role::GenerateSlug(C.name);
    idInc++;
    id=idInc;
    //cout<<"Constructeur de recopie appele (Category)"<<endl;
}
Category & Category::operator=(const Category & C){
    delete[] name;
    name = new char[strlen(C.name)+1];
    strcpy(name,C.name);
    delete[]description;
    description = new char[strlen(C.description)+1];
    strcpy(description,C.description);
    delete[]slug;
    slug =Role::GenerateSlug(C.name);
    //cout<<"Operateur d'affectation appele (Category)"<<endl;
    return *this;
}
ostream & operator<<(ostream & ostr,Category & C){
    ostr<<"Category id: "<<C.id<<endl;
    ostr<<"Name: "<<C.name<<endl;
    ostr<<"Description: "<<C.description<<endl;
    ostr<<"Slug: "<<C.slug<<endl;
    return ostr ;
}

int Category::getId() const{
    return id;
}   
const char * Category::getName() const{
    return name;
}
const char * Category::getDescription() const{
    return description;
}
const char * Category::getSlug() const{
    return slug;
}

void Category::setId(const int & id_) {
    if(id_<0){
        throw invalid_argument("Id cant be under 1.");
    }
    this->id=id_;
}
void Category::setName(const char * name_){
    if(name_ == nullptr || strlen(name_)==0){
        throw invalid_argument("Name is required.");
    }
    const regex namePattern("^(delux|regular|busines)$", std::regex_constants::icase);
    if(!regex_match(name_,namePattern)){
        throw invalid_argument("Enter type (delux, regular, busines):");
    }
    delete []name;
    name = new char [strlen(name_)+1];
    strcpy(name,name_);
    slug = Role::GenerateSlug(name_);
}
void Category::setDescription(const char * description_){
    if(description_ == nullptr || strlen(description_)==0){
        throw invalid_argument("Description is required.");
    }
    const regex descriptionPattern(R"(^[A-Za-z0-9 .,\'\"()\-]{10,255}$)");
    if(!regex_match(description_,descriptionPattern)){
        throw invalid_argument("The description must be between 10 and 255 characters.");
    }
    delete []description;
    description = new char[strlen(description_)+1];
    strcpy(description,description_);
}
void Category::setSlug( const char * slug_){
    delete[]slug;
    slug = new char[strlen(slug_)+1];
    strcpy(slug,slug_);
}

void Category::createCategory(Category *category){
    CategoryNode * newNode = new CategoryNode(category);
    newNode->setNext(Category::head);
    Category::head = newNode;
    cout<<"Category added successfully"<<endl;
}
void Category::removeCategory(Category *category){
    // im checking if list is empty
    if(Category::head ==nullptr){
        cout<<"List already empty "<<endl;
        return;
    }
    //checking the first node
    if(Category::head->getData()->getId()==category->getId()){
        CategoryNode * toDelete = Category::head;
        Category::head = head->getNext();
        delete toDelete;
        cout<<"Category deleted successfully"<<endl;
        return ;
    }
    // Searching for the node in list 
    CategoryNode * courant=Category::head;
    while(courant->getNext()!=nullptr){
        CategoryNode * nextNode = courant->getNext(); // always checking the next <one step ahead hh>
        if(nextNode->getData()->getId()==category->getId()){
            courant->setNext(nextNode->getNext());
            delete nextNode;
            cout<<"Category deleted successfully"<<endl;
            return;
        }
        courant = courant->getNext();
    }
    cout<<"Category not found"<<endl;
}
void Category::showCategories(){
    if(Category::head==nullptr){
        cout<<"List of categories is empty"<<endl;
        return;
    }
    CategoryNode * courant= Category::head ;
    while (courant !=nullptr){
        Category * c = courant->getData(); 
        cout<<"Category id: "<<c->getId()<<", Name: "<<c->getName()<<endl;
        courant = courant->getNext();
    }
}
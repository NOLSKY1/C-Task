#include "Permission.h"
#include<iostream>
#include<cstring>
#include "../Role/Role.h"
#include<regex>
using namespace std;

int Permission::idInc = 0;

 Permission::Permission(){
    name = new char[20];
    strcpy(name,"Ban ppl");
    description = new char[20];
    strcpy(description, "permission for ban");
    slug = Role::GenerateSlug(name);
    idInc++;
    id=idInc;
    cout<<"Constructeur par defaut appele (permission)"<<endl ;
}
 Permission::Permission(const char * name_, const char *description_){
    name = new char[strlen(name_)+1];
    strcpy(name,name_);
    description = new char[strlen(description_)+1];
    strcpy(description,description_);
    slug= Role::GenerateSlug(name_);
    idInc++;
    id=idInc;
    cout<<"Constructeur avec parametres appele (permission)"<<endl ;
}
 Permission::Permission(const Permission & P){
    name = new char[strlen(P.name)+1];
    strcpy(name,P.name);
    description = new char[strlen(P.description)+1];
    strcpy(description,P.description);
    slug = Role::GenerateSlug(P.name);
    idInc++;
    id=idInc;
    cout<<"Constructeur de recopie appele (permission)"<<endl ;
}  
 Permission::~Permission(){
    delete[]name;
    delete[]description;
    delete[]slug;
    cout<<"Destructeur appele (permission)"<<endl;
}
 void Permission::afficher() const {
    cout<<"Id: "<<id<<endl;
    cout<<"Name of permission: "<<name<<endl;
    cout<<"Description: "<<description<<endl;
    cout<<"Slug: "<<slug<<endl;
}
 Permission & Permission::operator=(const Permission & P){
    delete[]name;
    name = new char[strlen(P.name)+1];
    strcpy(name,P.name);
    delete[]description;
    description = new char[strlen(P.description)+1];
    strcpy(description,P.description);
    delete[]slug;
    slug = Role::GenerateSlug(P.name);
    cout<<"Operateur d'affectation appele (permission)"<<endl;
    return *this;
}
ostream & operator<<(ostream &  ostr, Permission & P){
    ostr<<"Id: "<<P.id<<endl;
    ostr<<"Name of permission: "<<P.name<<endl;
    ostr<<"Description: "<<P.description<<endl;
    ostr<<"Slug: "<<P.slug<<endl;
    return ostr;
}
istream & operator>>(istream & istr , Permission & P){
    cout<<"Enter permission name ";
    istr>>P.name;
    cout<<"Enter description ";
    istr>>P.description;
    P.slug = Role::GenerateSlug(P.name);
    return istr;
}
//getters 
int Permission::getId(){
    return id;
}
const char * Permission::getName(){
    return name;
}
const char * Permission::getDescription(){
    return description;
}
const char * Permission::getSlug(){
    return slug;
}
//setters
void Permission::setName( const char * name_){
    if(name_ ==nullptr || strlen(name_)==0){
        throw invalid_argument("Name is required ");
    }
    if(strlen(name_)<3){
        throw invalid_argument("Name must contain 3 characters or more.");
    }
    delete[]name;
    name=new char[strlen(name_)+1];
    strcpy(name,name_);
    slug = Role::GenerateSlug(name_);
}
void Permission::setDescription( const char * description_){
    if(description_==nullptr || strlen(description_)==0){
        throw invalid_argument("Description is required");
    }
    const regex descriptionPattern(R"(^[\w\s.,'"()\-]{10,255}$)");
    if(!regex_match(description_,descriptionPattern)){
        throw invalid_argument("Description must contain min of 10 characters");
    }
    delete[]description;
    description = new char [strlen(description_)+1];
    strcpy(description,description_);
}
void Permission::setId(int id_){
    if(id_<=0){
        throw invalid_argument("Id need to be 1 or more ");
    }
    this->id=id_;
}

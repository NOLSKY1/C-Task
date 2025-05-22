#include"Role.h"
#include<iostream>
#include<cstring>
#include<regex>
using namespace std;

int Role::idInc=0;
bool Role::isLetterOrdigit(char c){
        return (c>='a' && c<='z') ||
                (c>='A' && c<='Z')||
                (c>='0' && c<='9');
    }
 char Role::toLoweCase(char c){
        if(c>='A' && c<='Z'){
            return c+32 ;
        }
        return c;
    }
 char * Role::GenerateSlug(const char * input){
    string result ="";
    int lastWasSpace=0;
    int i=0;
    while(input[i]!='\0'){
        char c=input[i];
        if(isLetterOrdigit(c)){
            result+=toLoweCase(c);
        }
        else if (c==' '){
            if(!lastWasSpace && result.length() >0){
                result+="-";
                lastWasSpace=1;
            }
        }
        i++;
    }
    if(!result.empty() && result[result.length()-1]=='-'){
        result = result.substr(0,result.length()-1);
    }
    char * myslug = new char[result.length() +1];
    strcpy(myslug,result.c_str());

    return myslug;
}

Role::Role(){
    name = new char [10];
    strcpy(name,"Client");
    description = new char[50];
    strcpy(description,"this is a client role");
    slug = GenerateSlug(name);
    idInc++;
    id=idInc;
    cout<<"Constructeur par defaut appele (role)"<<endl ;
}
Role::Role(const char *name_ , const char * description_ ){
    name = new char[strlen(name_)+1];
    strcpy(name,name_);
    description = new char[strlen(description_)+1];
    strcpy(description,description_);
    slug = GenerateSlug(name_);
    idInc++;
    id=idInc;
    cout<<"Constructeur avec parametre appele (role)"<<endl;
}
Role::Role(const Role & R){
    name = new char[strlen(R.name)+1];
    strcpy(name,R.name);
    description = new char [strlen(R.description)+1];
    strcpy(description,R.description);
    slug =GenerateSlug(R.name);
    idInc++;
    id=idInc;
    cout<<"Constructeur de recopie appele (role)"<<endl;
}
Role::~Role(){
    delete[]name;
    delete[]description;
    delete[]slug;
    cout<<"Destructeur appele (role)"<<endl;
}
void Role::afficher() const{
    cout<<"Id: "<<id<<endl;
    cout<<"Name of role: "<<name<<endl;
    cout<<"Description: "<<description<<endl;
    cout<<"Slug: "<<slug<<endl;
}
Role & Role::operator=(const Role & R){
    delete []name;
    name = new char[strlen(R.name)+1];
    strcpy(name,R.name);
    delete []description;
    description = new char [strlen(R.description)+1];
    strcpy(description,R.description);
    delete[]slug;
    slug=GenerateSlug(R.name);
    cout<<"Operateur d'affectation appele (role)"<<endl;
    return *this;
}
ostream & operator<<(ostream &  ostr, Role & R){
    ostr<<"Id: "<<R.id<<endl;
    ostr<<"Name of role: "<<R.name<<endl;
    ostr<<"Description: "<<R.description<<endl;
    ostr<<"Slug: "<<R.slug<<endl;
    return ostr;
}
istream & operator>>(istream & istr , Role & R){
    cout<<"Enter Role name ";
    istr>>R.name;
    cout<<"Enter description ";
    istr>>R.description;
    R.slug = Role::GenerateSlug(R.name);
    return istr;
}
//getters 
int Role::getId(){
    return id;
}
const char * Role::getName(){
    return name;
}
const char * Role::getDescription(){
    return description;
}
const char * Role::getSlug(){
    return slug;
}
//setters
void Role::setName( const char * name_){
    if(name_ ==nullptr || strlen(name_)==0){
        throw invalid_argument("Name is required ");
    }
    const regex namePattern("^(client|client manager|product manager|admin|director|worker)$",regex_constants::icase);
    if(!regex_match(name_,namePattern)){
        throw invalid_argument("Respect name format");
    }
    delete[]name;
    name=new char[strlen(name_)+1];
    strcpy(name,name_);
    slug = Role::GenerateSlug(name_);
}
void Role::setDescription( const char * description_){
    if(description_==nullptr || strlen(description_)==0){
        throw invalid_argument("Description is required");
    }
    const regex descriptionPattern(R"(^[A-Za-z0-9 .,\'\"()\-]{10,255}$)");
    if(!regex_match(description_,descriptionPattern)){
        throw invalid_argument("Description must contain min of 10 characters");
    }
    delete[]description;
    description = new char [strlen(description_)+1];
    strcpy(description,description_);
}
void Role::setId(const int& id_){
    if(id_<=0){
        throw invalid_argument("Id need to be 1 or more ");
    }
    this->id=id_;
}



#include"User.h"
#include<iostream>
#include<cstring>
#include<regex>
using namespace std; 

int User::idInc = 0;

User::User(){
    firstname = new char[10];
    strcpy(firstname,"naoufal");
    lastname = new char[10];
    strcpy(lastname,"maakoul");
    email = new char[30] ;
    strcpy(email ,"naoufalmaakoul@gmail.com");
    token = "mytoken";
    idInc++;
    id=idInc;
    cout<<"Constructeur par defaut appele (User Mere)"<<endl;

}
User::User( const char * firstname_ , const char *lastname_ , const char *email_ ,  const string &token_ ){
    firstname = new char[strlen(firstname_)+1];
    strcpy(firstname,firstname_);
    lastname = new char[strlen(lastname_)+1];
    strcpy(lastname,lastname_);
    email = new char[strlen(email_)+1];
    strcpy(email,email_);
    token = token_;
    idInc++;
    id=idInc;
    cout<<"Constructeur avec parametre appele (User Mere)"<<endl;
}
User::~User(){
    delete[]firstname;
    delete[]lastname;
    delete[]email;
    cout<<"Destructeur appele (User Mere)"<<endl;
}
User::User(const User & U){
    firstname = new char[strlen(U.firstname)+1];
    strcpy(firstname ,U.firstname);
    lastname = new char[strlen(U.lastname)+1];
    strcpy(lastname,U.lastname);
    email = new char[strlen(U.email)+1];
    strcpy(email , U.email);
    token = U.token;
    idInc++;
    id=idInc;
    cout<<"Constructeur de recopie appele (User Mere)"<<endl;
}
User & User::operator=(const User & U){
    delete[]firstname;
    firstname = new char[strlen(U.firstname)+1];
    strcpy(firstname ,U.firstname);
    delete[]lastname;
    lastname = new char[strlen(U.lastname)+1];
    strcpy(lastname,U.lastname);
    delete[]email;
    email = new char[strlen(U.email)+1];
    strcpy(email , U.email);
    token=U.token;
    cout<<"Operateur d'affectation appele (User Mere)"<<endl;
    return *this;
}
void User::afficher() const {
    cout <<"Id: "<<id<<endl;
    cout <<"First name: "<<firstname<<endl;
    cout <<"last name: "<<lastname<<endl;
    cout <<"Email: "<<email<<endl;
    cout <<"Token: "<<token<<endl;
}

ostream & operator<<(ostream & ostr ,User & U){
    ostr<<"Your id: "<<U.id<<endl;
    ostr << "Your first name is: "<<U.firstname<<endl;
    ostr<<"Your last name is: "<<U.lastname<<endl;
    ostr << "Your email is: "<<U.email<<endl;
    ostr << "Your token is: "<<U.token<<endl;
    return ostr;
    
}
istream & operator>>(istream & istr,User & U){
    cout <<"Enter your first name ";
    istr>>U.firstname;
    cout<<"Enter your last name";
    istr>>U.lastname;
    cout<<"Enter your email";
    istr>>U.email;
    cout<<"Enter your token ";
    istr>>U.token;
    return istr;
}



int User::getId() const {
    return id;
}
const char * User::getFirstname() const{
    return firstname ;
}
const char * User::getLastname() const{
    return lastname;
}
const char * User::getEmail() const{
    return email;
}
const string & User::getToken() const{
    return token;
}


void User::setId(const int & id_){
    if(id_<0){
        throw invalid_argument("Id must be 1 or more.");
    }
    this->id=id_;
}
void User::setFirstname(const char *firstname_){
    if(firstname_==nullptr || strlen(firstname_)<=0){
        throw invalid_argument("First name is required");
    }
    if(strlen(firstname_)<=3){
        throw invalid_argument("First name must contain a min of 3 letters ");
    }
    
    delete[]firstname;
    firstname = new char [strlen(firstname_)+1];
    strcpy(firstname,firstname_);
}
void User::setLastname(const char * lastname_){
    if(lastname_==nullptr || strlen(lastname_)==0){
        throw  invalid_argument("Last name is required");
    }
    if(strlen(lastname_)<=3){
        throw invalid_argument("First name must contain a min of 3 letters ");
    }
    delete[]lastname;
    lastname = new char[strlen(lastname_)+1];
    strcpy(lastname,lastname_);
}
void User::setEmail(const char *email_){
    if(email_==nullptr || strlen(email_)==0){
        throw invalid_argument("Email is required");
    }
    const regex pattern(R"((\w+)(\.\w+)*@(\w+)(\.\w+)+)");
    if(!regex_match(email_,pattern)){
        throw invalid_argument("Invalid email format");
    }
    delete[]email;
    email = new char[strlen(email_)+1];
    strcpy(email,email_);
}
void User::setToken(const string & token_){
    if(token_.empty()){
        throw invalid_argument("Token is required");
    }
    this->token = token_;
}
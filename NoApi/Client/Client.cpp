#include"Client.h"
#include<iostream>
using namespace std;



Client::Client(){
    cout<<"Constructeur par defaut appele (classe fille Client)"<<endl;
}
Client::Client(const char * firstname_, const char * lastname_, const char * email_,  const string &token_):User(firstname_,lastname_,email_,token_){
    cout<<"Constructeur avec parametre appele (classe fille Client)"<<endl;
}
Client::Client(const Client &C):User(C){
    cout<<"Constructeur de recopie appele (classe fille Client)"<<endl;
}
Client::~Client(){
    cout<<"Destructeur appele (classe fille Client)"<<endl ; 
}
Client & Client::operator=(const Client & C){
    User::operator=(C);
    cout<<"Operateur d'affectation appelee (classe fille Client)"<<endl;
    return * this;
}
void Client::afficher() const {
    cout<<"WELCOME CLIENT: "<<endl;
    User::afficher();
}
ostream & operator<<(ostream & ostr ,Client & C){
    ostr<<"WELCOME CLIENT: "<<endl;
    ostr<<"Your id: "<<C.getId()<<endl;
    ostr << "Your first name is: "<<C.getFirstname()<<endl;
    ostr<<"Your last name is: "<<C.getLastname()<<endl;
    ostr << "Your email is: "<<C.getEmail()<<endl;
    ostr << "Your token is: "<<C.getToken()<<endl;
    return ostr;
}
istream & operator>>(istream & istr,Client & C){
    cout<<"WELCOME (press 0 to quite) "<<endl;
    while(true){
        string firstname_ ;
        cout <<"Enter your first name ";
        istr>>firstname_;
        if(firstname_=="0"){
            break;
        }
        try{
            C.setFirstname(firstname_.c_str());
        }catch(const invalid_argument &e){
            cout<<e.what()<<endl;
            continue;
        }

        string lastname_;
        cout <<"Enter your last name ";
        istr>>lastname_;
        if(lastname_=="0"){
            break;
        }
        try{
            C.setLastname(lastname_.c_str());
        }catch(const invalid_argument &e){
            cout<<e.what()<<endl;
            continue;
        }

        string email_;
        cout <<"Enter your email ";
        istr>>email_;
        if(email_=="0"){
            break;
        }
        try{
            C.setEmail(email_.c_str());
        }catch(const invalid_argument &e){
            cout<<e.what()<<endl;
            continue;
        }
        break;
    }
    return istr;
}
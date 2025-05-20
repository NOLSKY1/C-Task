#include "Personnel.h"
#include<iostream>

using namespace std;


 Personnel::Personnel(){
    cout<<"Constructeur  par default appele (classe fille Personnel)"<<endl;
 }
Personnel::Personnel( const char *firstname_ , const char * lastname_ , const char * email_,  const string & token_):User(firstname_,lastname_,email_,token_){
    cout<<"Constructeur  avec parametre appele (classe fille Personnel)"<<endl;
}
Personnel::Personnel(const Personnel & P):User(P){
    cout<<"Constructeur de recopie appele (classe fille Personnel)"<<endl;
}
Personnel::~Personnel(){
    cout<<"Destructeur appele (classe fille Personnel)"<<endl;
}
Personnel & Personnel::operator=(const Personnel & P){
    User::operator=(P);
    cout<<"Operateur d'affectation appele (classe fille Personnel)"<<endl;
    return *this;
}
void Personnel::afficher() const{
    cout<<"Personnel: "<<endl;
    User::afficher();
}
ostream & operator<<(ostream & ostr ,Personnel & P){
    ostr<<"WELCOME PERSONNEL: "<<endl;
    ostr<<"Your id: "<<P.getId()<<endl;
    ostr << "Your first name is: "<<P.getFirstname()<<endl;
    ostr<<"Your last name is: "<<P.getLastname()<<endl;
    ostr << "Your email is: "<<P.getEmail()<<endl;
    ostr << "Your token is: "<<P.getToken()<<endl;
    return ostr;
    
}
istream & operator>>(istream & istr,Personnel & P){
    cout<<"WELCOME (press 0 to quite) "<<endl;
    while(true){
        string firstname_ ;
        cout <<"Enter your first name ";
        istr>>firstname_;
        if(firstname_=="0"){
            break;
        }
        try{
            P.setFirstname(firstname_.c_str());
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
            P.setLastname(lastname_.c_str());
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
            P.setEmail(email_.c_str());
        }catch(const invalid_argument &e){
            cout<<e.what()<<endl;
            continue;
        }
        break;
    }
    return istr;
}
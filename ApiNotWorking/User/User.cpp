
#include"User.h"
#include"../ApiClient/ApiClient.h"
#include"../Token/Token.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include"../json.hpp"
#include <regex>
using namespace std;


//Constructor
User::User(){
    firstname = new char[10];
    strcpy(firstname,"naoufal");
    lastname = new char[10];
    strcpy(lastname,"maakoul");
    email = nullptr;
    token="";


}
User::~User(){
    delete[]firstname;
    delete[]lastname;
    delete[]email;
}
//Getters
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
//Setters
void User::setFirstname(const char *firstname_){
    if(firstname_==nullptr || strlen(firstname_)==0){
        throw invalid_argument("First name is required");
    }
    delete[]firstname;
    firstname = new char [strlen(firstname_)+1];
    strcpy(firstname,firstname_);
}
void User::setLastname(const char * lastname_){
    if(lastname_==nullptr || strlen(lastname_)==0){
        throw  invalid_argument("Last name is required");
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
void User::setFullNameResponse(const string & response){
    string fullname=ApiClient::extract(response,"fullname");
    if(!fullname.empty()){
        size_t space = fullname.find(' ');//this one will return position of the space
        if(space !=string::npos){
            setFirstname(fullname.substr(0,space).c_str());// Converts C++ string → C-style string since im using char* in setter
            setLastname(fullname.substr(space+1).c_str());
        }
    }
}
//Pre login
bool User::preLogin(){
    string token_ = Token::readTokenFile();
    string response = ApiClient::Get("/user",token_);
    if(!response.empty() && response.find("\"id\"") !=string::npos){
        setToken(token_);
        setFullNameResponse(response);
        return true;
    }
    return false;
}

string User::login(){
    string login ,password;
    cout<<"->Login: (type 0 to quite) \n";
    while(true){
        cout<<"Enter email or username: ";
        getline(cin,login);
        if(login=="0"){
            cout<<"Exiting login"<<endl;
            return "";
        }
        cout<<"Enter password: ";
        getline(cin,password);
        try{
            if(password.empty()){
                throw invalid_argument("Password is required");
            }
            string payload ;
            if(login.find("@")==string::npos){
            // hna we re sure its an email 
            const regex emailPattern(R"((\w+)(\.\w+)*@(\w+)(\.\w+)+)");
            if(!regex_match(login,emailPattern)){
                throw invalid_argument("Invalid email format.");
            } 
            payload ="{\"email\":\"" + login + "\",\"password\":\"" + password + "\"}";
        }
        else{
            // we re dealing with a username (validation dyalo)
            if(login.length()<3){
                throw invalid_argument("Username must be at least 3 characters long. ");
            }
            payload = "{\"username\":\"" + login + "\",\"password\":\"" + password + "\"}";
        }

        string response = ApiClient::Post("/login",payload,"");
        setFullNameResponse(response);
        
        string token_=ApiClient::extract(response , "token");
        if(!token_.empty()){
            setToken(token_);
            ofstream file("token.txt");
            file<<token_;
            return token_;
        }
        cout<<"Error: Login failed. Please check your credentials." << endl;
        }catch( const invalid_argument &e){
            cout<<e.what()<<endl;
        }
    }
    
}
void User::logout(){
    if(token.empty()){
        cout<<"Erro 404"<<endl;
        return;
    }
    ApiClient::Post("/logout","",token);
    token.clear();
    cout<<"User logged out"<<endl;
}
string User::signup(){
    string fullname ,emailInput,username ,password,confirm;
    cout<<"Create an account (type 0 to cancel):\n";
    while(true){
        try{
            cout<<"-> Fullname: ";
            getline(cin,fullname);
            if(fullname=="0") return "";
            if(fullname.empty()) throw invalid_argument("Fullname is required");

            cout << "-> Username: ";
            getline(cin, username); 
            if (username == "0") return "";
            if(username.length()<8) throw invalid_argument("Username must be at least 8 characters.");

            cout << "-> Email: ";
            getline(cin, emailInput);
            if (emailInput == "0") return "";
            const regex emailPattern(R"(^[\w\.-]+@[\w\.-]+\.\w+$)");
            if(!regex_match(emailInput,emailPattern)) throw invalid_argument("Invalid email format."); 

            cout << "-> Password: ";
            getline(cin, password);
            if (password == "0") return "";
            const regex passwordPattern(R"(^(?=.*[A-Za-z])(?=.*\d)(?=.*[^A-Za-z\d]).{8,}$)");
            if(!regex_match(password,passwordPattern)) throw invalid_argument("Password must be at least 8 characters and include letters, numbers, and symbols.");

            cout << "Confirm Password: ";
            getline(cin,confirm);
            if(password!=confirm) throw invalid_argument("Passwords do not match.");

            string payload = "{";
            payload += "\"fullname\":\"" + fullname + "\",";
            payload += "\"username\":\"" + username + "\",";
            payload += "\"email\":\"" + emailInput + "\",";
            payload += "\"password\":\"" + password + "\"}";

            string response = ApiClient::Post("/register",payload,"");
            if(response.find("\"errors\"")!=string::npos){
                cout << "Sign-Up Failed: Validation errors from server.\n";
                return "";
            }
            string token_ = ApiClient::extract(response,"token");
            if(!token_.empty()){
                setToken(token_);
                setFullNameResponse(response);
                setEmail(emailInput.c_str());
                ofstream file("token.txt");
                file<<token_;
                cout<<"Sign-up successful!"<<endl;
                return token_;
            }
            else{
                cout << "Sign-Up failed: No token returned.";
                return "";
            }
            }catch(const invalid_argument &e){
                cout<<e.what()<<endl;
            }
    }
}





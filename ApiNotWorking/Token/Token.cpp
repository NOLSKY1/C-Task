#include"Token.h"
#include<fstream>
#include<iostream>
using namespace std;



const string Token_file = "token.txt";

void Token::writeTokenFile(const string& token){
    ofstream file(Token_file);
    if(file.is_open()){
        file <<token ;
        file.close();
    }
    else{
        cerr<<"Failed to write token to file."<<endl ;
    }
}
string Token::readTokenFile(){
    ifstream file(Token_file);
    string token;
    if(file.is_open()){
        getline(file,token);
        file.close();
    }
    return token;
}
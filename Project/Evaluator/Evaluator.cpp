#include "Evaluator.h"
#include<iostream>
#include"../Output/Output.h"
#include"../ProductManager/ProductManager.h"

using namespace std;

void Evaluator::boot(){
    try{
        bootstrap();
    }catch(const exception &e){
        cout<< e.what()<<endl;
    }
}

void Evaluator::bootstrap(){
    if(user.preLogin()){
        auth();
        return ;
    }
    Output::Header() ; // Welcome page

    while(true){
        int choice;
        Output::startUp();
        cin >>choice;
        switch (choice)
        {
        case 1: {
            string t = user.login();
            if(!t.empty()) auth(); // redirect to admin area
            break;
        }
        case 2: {
            string t = user.signup();
            if(!t.empty()) {
                auth();
            }
            else{
                Output::clear();
                cout<<"--> Something went wrong during sign up, please scroll to the top to see the error."<<endl;
            }
            break;
        }
        default:
            cout<< "-- Wrong choice, try again !"<<endl;
            break;
        }
        
    }
    

}
void Evaluator::auth(){
    Output::clear();
    Output::Header();

    while(true){
        Output::adminPage(user);
        int choice;
        cin>>choice;
        switch (choice)
        {
        case 3:  ProductManager::createCategory();
                 shutDown(0);
                 break;
            
        case 6:  user.logout();
                 shutDown(0);
                 break;
        
        default: shutDown(0);
                 break;
        }
    }

}
void Evaluator::shutDown(const int & code){
    if(code ==0){
        cout<<"- -- - SEE YOU LATER - -- -"<<endl;
    }
    else{
        cout<<"--> Something went wrong"<<endl;
    }
    exit(code);
}
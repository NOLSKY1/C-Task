#include "ProductManager.h"
#include <iostream>
#include  "../Personnel/Personnel.h"

using namespace std;


ProductManager::ProductManager(){
    cout<<"Constructeur  par default appele (classe fille PM)"<<endl;
}
ProductManager::ProductManager(const char *firstname_ , const char * lastname_, const char * email_,  const string & token_)
              :Personnel(firstname_,lastname_,email_,token_){
    cout<<"Constructeur  avec parametres appele (classe fille PM)"<<endl;
}
ProductManager::ProductManager(const ProductManager & PM){
    cout<<"Constructeur de recopie appele (classe fille PM)"<<endl;
}
ProductManager::~ProductManager(){
    cout<<"Destructeur appele (classe fille PM)"<<endl;
}
ProductManager & ProductManager::operator=(const ProductManager & PM){
    Personnel::operator=(PM);
    cout<<"Operateur d'affectation appele (classe fille PM)"<<endl;
    return *this;
}
void ProductManager::afficher() const {
    cout<<"Product manager: ";
    Personnel::afficher();
}
void ProductManager::createCategory(){
    Category * c = new Category();
    cout<<"ADD CATEGORY (enter 0 to quite)"<<endl;
    while(true){
        string categoryName;
        cout<<"Enter the name of category ";
        cin >>categoryName;
        if(categoryName=="0"){
            cout<<"See u later"<<endl;
            return;
        }
        try{
            c->setName(categoryName.c_str());
            c->setSlug(Role::GenerateSlug(categoryName.c_str()));
            break ;
        }catch(const invalid_argument &e){
            cout<< e.what()<<endl;
            continue ;
        }
    }
    while(true){
        string categoryDescription;
        cout<<"Enter the description of category ";
        cin >>categoryDescription;
        if(categoryDescription=="0"){
            cout<<"See u later"<<endl;
            return;
        }
        try{
            c->setDescription(categoryDescription.c_str());
            break ;
        }catch(const invalid_argument &e){
            cout<< e.what()<<endl;
            continue ;
        }
    }
    Category::createCategory(c);
    
}

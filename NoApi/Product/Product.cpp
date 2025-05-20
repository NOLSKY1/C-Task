#include "Product.h"
#include<iostream>
#include<cstring>
#include"../Role/Role.h"
using namespace std;



int Product::idInc = 0;

Product::Product(){
    title = new char[10];
    strcpy(title,"new product");
    price=0.00;
    discount=0;
    tag= new char[10];
    strcpy(tag,"new tag");
    category = new char[10];
    strcpy(category,"new category");
    quantity =1;
    imagePath ="path image here";
    idInc++;
    id = idInc;
    slug = Role::GenerateSlug(title);
    cout<<"Constructeur par defaut appelee (Product)"<<endl;
}
Product::Product(const char * title_,const char * slug_,const double & price_,const double & discount_ ,const char * tag_,const char * category_ ,const int & quantity_,const string & imagePath_){
    title = new char[strlen(title_)+1];
    strcpy(title,title_);
    slug=Role::GenerateSlug(title_);
    price = price_;
    discount =discount_;
    tag= new char[strlen(tag_)+1];
    strcpy(tag,tag_);
    category = new char[strlen(category_)+1];
    strcpy(category,category_);
    quantity = quantity_;
    imagePath = imagePath_;
    idInc++;
    id = idInc;
    cout<<"Constructeur avec parametres appelee (Product)"<<endl;
}
Product::Product(const Product & P){
    title = new char[ strlen(P.title)+1];
    strcpy(title,P.title);
    slug =Role::GenerateSlug(P.title);
    price =P.price;
    discount = P.discount;
    tag = new char[ strlen(P.tag)+1];
    strcpy(tag,P.tag);
    category = new char[ strlen(P.category)+1];
    strcpy(category , P.category);
    quantity = P.quantity;
    imagePath=P.imagePath;
    idInc++;
    id = idInc;
    cout<<"Constructeur de recopie (Product)"<<endl;
}
Product::~Product(){
    delete[]title;
    delete[]slug;
    delete[]tag ;
    delete[]category;
    cout<<"Destructeur appelee (Product)";
}
Product & Product::operator=(const Product & P){
    delete[]title;
    title = new char[ strlen(P.title)+1];
    strcpy(title,P.title);
    delete[]slug;
    slug =Role::GenerateSlug(P.title);
    price =P.price;
    discount = P.discount;
    delete[] tag;
    tag = new char[ strlen(P.tag)+1];
    strcpy(tag,P.tag);
    delete[]category;
    category = new char[ strlen(P.category)+1];
    strcpy(category , P.category);
    imagePath=P.imagePath;
    idInc++;
    id = idInc;
    cout<<"Constructeur operateur affectation (Product)"<<endl;
    return *this;
}
ostream & operator<<(ostream & ostr ,Product & P){
    ostr<<"Product id: "<<P.id<<endl;
    ostr<<"Title: "<<P.title<<endl;
    ostr<<"Slug: "<<P.slug<<endl;
    ostr<<"Price: "<<P.price<<endl;
    ostr<<"Discount: "<<P.discount<<endl;
    ostr<< "Tag: "<<P.tag <<endl;
    ostr<<"Category"<<P.category<<endl;
    ostr<<"Quantity: "<<P.quantity<<endl;
    ostr<<"Image path: "<<P.imagePath<<endl;
    return ostr ;
}
 istream & operator>>(istream & istr,Product & P){
    cout<<"Enter the titleof product "<<endl;
    istr>>P.title;
    cout<<"Enter the price"<<endl;
    istr>>P.price;
    cout<<"Enter the discount"<<endl;
    istr>>P.discount;
    cout<<"Enter a Tag "<<endl;
    istr>>P.tag;
    cout<<"Enter the category"<<endl;
    istr>>P.category;
    cout<<"Enter the quantity "<<endl;
    istr>>P.quantity;
    cout<<"Enter Image path"<<endl;
    istr>>P.imagePath;
    P.slug = Role::GenerateSlug(P.title);
    return istr;
}

//Getters
int Product::getId() const {
    return id;
} 
const char * Product::getTitle() const{
    return title;
}
const char * Product::getSlug() const{
    return slug ;
}
double Product::getPrice()const{
    return price ; 
}
double Product::getDiscount()const{
    return discount;
}
const char * Product::getTag()const{
    return tag;
}
const char* Product::getCategory()const{
    return category;
}
int Product::getQuantity()const{
    return quantity;
}
string Product::getImagePath()const {
    return imagePath;
}

//Setters

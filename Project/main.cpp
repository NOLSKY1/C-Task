#include "User/User.h"
#include "Role/Role.h"
#include "Permission/Permission.h"
#include <iostream>
#include "Token/Token.h"
#include "Personnel/Personnel.h"
#include "Client/Client.h"
#include "Product/Product.h"
#include "Category/Category.h"
#include "ProductManager/ProductManager.h"
#include "Output/Output.h"
#include "Evaluator/Evaluator.h"
using namespace std;

int main()
{
    // User u1,u2("manal","maakoul","manal@gmai.com","mytoken1") ,u3(u2) , u4;
    // u1.afficher();
    // u2.afficher();
    // u3.afficher();
    // cout<<u4;
    // u4 = u2;
    // cout<<u4;
    // Role R,R1("Client Manager","this is a client manager role ") , r3;
    // R.afficher();
    // cout<<R1;
    // cout<<r3;
    // r3=R1;
    // cout<<r3;
    // cin>>r3;
    // r3.afficher();
    // Role r;
    // cout<<r;
    // try{
    //     r.setName("Admin");
    // }catch(const invalid_argument &e){
    //     cout<< e.what()<<endl;
    // }
    // cout<<r;

    // User u;
    // cout<<u;
    // try{
    //     u.setEmail("nadoad");
    // }catch(const invalid_argument &e){
    //     cout<< e.what()<<endl;
    // }

    // Permission p("delete account","to delete ppl") ,p3;
    // cout<<p<<endl;
    // cout<<p3;
    // cout<<p3;
    // p3=p;
    // cout<<p3;
    // try{
    //    p.setDescription("");
    // }catch(const invalid_argument &e){
    //    cout<< e.what()<<endl;
    // }

    // string token="mytoken here";
    // Token::writeTokenFile(token);
    // string mytoken=Token::readTokenFile();
    // cout<<mytoken<<endl;
    // Personnel P("manal","maakoul","manal@gmai.com","mytoken1") ,p3(P),p4;
    // cout<<P<<endl;
    // cout<<p3;
    // cin>>p4;
    // cout<<p4;//
    // Client C , C1("manal","maakoul","manal@gmai.com","mytoken1"),C4;
    // cout<<C<<endl;
    // cout<<C1;
    // cout<<C4<<endl;
    // cin>>C4;
    // cout<<C4;
    // User *client;
    // client = new Client;
    // client->afficher();
    // delete client;

    // I NEED TO TEST THE METHODS IN PRODUCT CLASS
    // g++ main.cpp User/User.cpp Role/Role.cpp Permission/Permission.cpp
    //  Token/Token.cpp Personnel/Personnel.cpp Client/Client.cpp
    // Product/Product.cpp -o main

    // Category c ;// c1("restlux","this is main category"),c2=c1;

    // cout<<c;
    // cout<<c1;
    // cout<<c2;

    // Category C , c1("best","tyhis is the best") , c3;
    // cout <<C<<endl;
    // cout<<c1<<endl;
    // cout<<c3;
    // c3=c1;
    // cout<<c3;

    // Category c;
    // Product p,p1("Coca",100,0,"",c,1,"image.jpg"),P3;
    // cout<<p;
    // cout<<p1;
    // cout<<P3;
    // cout<<P3<<endl;
    // P3=p1;
    // cout<<P3;
    // cin>>P3;
    // cout<<P3;
    // Product p ;
    // cin >>p;
    // cout<<p;
    // Role *r = new Role("admin","admin role");
    // cout<<r;
    // User u;
    // u.addRole(r);
    // u.showRoles();
    // u.removeRole(r);
    // u.showRoles();
    // g++ main.cpp User/User.cpp User/node.cpp
    // Role/Role.cpp Permission/Permission.cpp Token/Token.cpp
    // Personnel/Personnel.cpp Client/Client.cpp Product/Product.cpp
    // Category/Category.cpp Category/CategoryNode.cpp
    // ProductManager/ProductManager.cpp
    // Output/Output.cpp -o main.exe

    // ProductManager p1;
    // p1.afficher();
    // p1.createCategory();
    // Category::showCategories();
    // Output::startUp();
    // User u;
    // string token = u.login();
    // if (!token.empty()) {
    //    cout << "Login successful! Token: " << token << endl;
    // } else {
    //    cout << "Login failed." << endl;
    //}
    ////if(u.preLogin()){
    //    cout<<"ur preloged in"<<endl;
    //}
    // else {
    //   cout<<"someth went wrong "<<endl;
    //}

    Evaluator e;
    e.boot();

    /*Compile command :
     g++ main.cpp
     ApiClient/ApiClient.cpp
     User/User.cpp User/node.cpp
     Role/Role.cpp Permission/Permission.cpp
     Token/Token.cpp
     Personnel/Personnel.cpp
     Client/Client.cpp
     Product/Product.cpp
     Category/Category.cpp
     Category/CategoryNode.cpp
     ProductManager/ProductManager.cpp
     Output/Output.cpp Evaluator/Evaluator.cpp
     -o main.exe -I ApiClient -I User -I Token -lcurl


*/
}

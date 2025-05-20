#ifndef Client_h
#define Client_h
#include"../User/User.h"

class Client:public User {


    public:
    Client();
    Client(const char * , const char * , const char * ,  const string &);
    Client(const Client &);
    ~Client();
    Client & operator=(const Client &);
    void afficher() const ;
    friend ostream & operator<<(ostream & ,Client &);
    friend istream & operator>>(istream & ,Client &);


};







#endif
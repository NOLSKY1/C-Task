#ifndef User_h
#define User_h
#include<string>
using namespace std;


class User{
    private :
    char * firstname;
    char *lastname;
    char* email ;
    string token ;



    public:
    User();
    ~User();
    const char * getFirstname() const; 
    const char * getLastname() const; 
    const char *getEmail() const; 
    const string & getToken() const; 

    void setFirstname(const char *);
    void setLastname(const char *);
    void setEmail(const char *);
    void setToken(const string &);

    bool preLogin();
    string login();
    void logout();
    string signup();
    void setFullNameResponse(const string & response);


};



#endif
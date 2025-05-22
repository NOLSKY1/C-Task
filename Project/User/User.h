#ifndef User_h
#define User_h
#include <string>
#include "node.h"
using namespace std;
class User
{

private:
    int id;
    char *firstname;
    char *lastname;
    char *email;
    string token;
    static int idInc;
    Node *head; // first node in my linkded list (in class we called it <list>)

public:
    User();
    User(const char *, const char *, const char *, const string &);
    virtual ~User();
    User(const User &);
    User &operator=(const User &);
    virtual void afficher() const; // since we re overiding it after
    friend ostream &operator<<(ostream &, User &);
    friend istream &operator>>(istream &, User &);
    void addRole(Role *); // Insertion debut
    void removeRole(Role *);
    bool hasRole(const char *);
    void showRoles() const;

    int getId() const;
    const char *getFirstname() const;
    const char *getLastname() const;
    const char *getEmail() const;
    const string &getToken() const;

    void setId(const int &);
    void setFirstname(const char *);
    void setLastname(const char *);
    void setEmail(const char *);
    void setToken(const string &);

    bool preLogin();
    string login();
    void logout();
    string signup();
    void setFullNameResponse(const string &response);
};

#endif
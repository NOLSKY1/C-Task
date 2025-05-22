#ifndef Permission_h
#define Permission_h
#include <iostream>
using namespace std;

class Permission
{
private:
    int id;
    char *name;
    char *description;
    char *slug;
    static int idInc;

public:
    Permission();
    Permission(const char *, const char *);
    Permission(const Permission &);
    ~Permission();
    void afficher() const;
    Permission &operator=(const Permission &);
    friend ostream &operator<<(ostream &, Permission &);
    friend istream &operator>>(istream &, Permission &);

    // getters
    int getId();
    const char *getName();
    const char *getDescription();
    const char *getSlug();

    // setters
    void setName(const char *);
    void setDescription(const char *);
    void setId(int);
};

#endif
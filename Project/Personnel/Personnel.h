#ifndef Personnel_h
#define Personnel_h
#include "../User/User.h"

class Personnel : public User
{

public:
    Personnel();
    Personnel(const char *, const char *, const char *, const string &);
    Personnel(const Personnel &);
    virtual ~Personnel();
    Personnel &operator=(const Personnel &);
    virtual void afficher() const;
    friend ostream &operator<<(ostream &, Personnel &);
    friend istream &operator>>(istream &, Personnel &);
};

#endif
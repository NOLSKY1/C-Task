#ifndef Personnel_h
#define Personnel_h
#include"../User/User.h"

class Personnel:public User{
    
    public:
    Personnel();
    Personnel( const char * , const char * , const char * ,  const string & );
    Personnel(const Personnel &);
    ~Personnel();
    Personnel & operator=(const Personnel &);
    void afficher() const;
    friend ostream & operator<<(ostream & ,Personnel &);
    friend istream & operator>>(istream & ,Personnel &);
};




#endif 
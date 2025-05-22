#ifndef Role_h
#define Role_h
#include <iostream>
using namespace std;
class Role
{
private:
    int id;
    char *name;
    char *description;
    char *slug;
    static int idInc;

public:
    Role();
    Role(const char *, const char *);
    Role(const Role &);
    ~Role();
    void afficher() const;
    Role &operator=(const Role &);
    friend ostream &operator<<(ostream &, Role &);
    friend istream &operator>>(istream &, Role &);

    // methods to make slug
    static bool isLetterOrdigit(char c);
    static char toLoweCase(char c);
    static char *GenerateSlug(const char *);

    // getters
    int getId();
    const char *getName();
    const char *getDescription();
    const char *getSlug();

    // setters
    void setName(const char *);
    void setDescription(const char *);
    void setId(const int &);
};

#endif
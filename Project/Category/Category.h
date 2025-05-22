#ifndef Category_h
#define Category_h
#include <iostream>
using namespace std;
#include "CategoryNode.h"
class Category
{
private:
    int id;
    char *name;
    char *description;
    char *slug;
    static int idInc;
    static CategoryNode * head ;

public:
    Category();
    Category(const char *, const char *);
    Category(const Category &);
    Category &operator=(const Category &);
    friend ostream &operator<<(ostream &, Category &);
    friend istream &operator>>(istream &, Category &);
    static void createCategory(Category *);
    static void removeCategory(Category *);
    static void showCategories();
    

    // Getters
    int getId() const;
    const char *getName() const;
    const char *getDescription() const;
    const char *getSlug() const;

    // Setters
    void setId(const int &);
    void setName(const char *);
    void setDescription(const char *);
    void setSlug(const  char *);
};

#endif

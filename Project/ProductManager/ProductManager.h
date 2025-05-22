#ifndef ProductManager_
#define PrdoductManager_
#include "../Personnel/Personnel.h"
#include "../Category/Category.h"
class ProductManager : public Personnel
{

public:
    ProductManager();
    ProductManager(const char *firstname_, const char *lastname_, const char *email_, const string &token_);
    ProductManager(const ProductManager &);
    ~ProductManager();
    ProductManager &operator=(const ProductManager &);
    void afficher() const;
    static void createCategory();
    // void deleteCategory(); not implemented yet
    // void showCategories();
};

#endif
#ifndef Product_h
#define Product_h
#include<string>
#include"../Category/Category.h"
using namespace std;

class Product{
    private:
    int id ;
    char * title;
    char* slug ;
    double price;
    double discount;
    char * tag;
    Category category;
    int quantity;
    string imagePath;
    static int idInc;


    public:
    Product();
    Product(const char *,const double &,const double &,const char *,const Category & ,const int &,const string &);
    Product(const Product &);
    ~Product();
    Product & operator=(const Product &);
    friend ostream & operator<<(ostream & ,Product &);
    friend istream & operator>>(istream & ,Product &);

    //Getters
    int getId() const ;
    const char * getTitle() const;
    const char * getSlug() const;
    double getPrice()const;
    double getDiscount()const;
    const char * getTag()const;
    Category  getCategory()const;
    int getQuantity()const;
    string getImagePath()const ;
    
    //Setters
    void setId(const int &);
    void setTitle(const char *);
    void setPrice(const double &);
    void setDiscount(const double &);
    void setTag(const char *);
    void setCategory( const Category &);
    void setQuantity(const int &);
    void setImagePath(const string &);





};





#endif 
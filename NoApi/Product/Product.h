#ifndef Product_h
#define Product_h
#include<string>
using namespace std;

class Product{
    private:
    int id ;
    char * title;
    char* slug ;
    double price;
    double discount;
    char * tag;
    char * category;
    int quantity;
    string imagePath;
    static int idInc;


    public:
    Product();
    Product(const char *,const char *,const double &,const double &,const char *,const char * ,const int &,const string &);
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
    const char* getCategory()const;
    int getQuantity()const;
    string getImagePath()const ;
    
    //Setters
    void setId(const int &);
    void setTitle(const char *);
    void setSlug(const char *);
    void setPrice(const double &);
    void setDiscount(const double &);
    void setTag(const char *);
    void setCategory(const char *);
    void setQuantity(const int &);
    void setImagePath(const string &);





};





#endif 
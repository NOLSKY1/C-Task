#include "Product.h"
#include <iostream>
#include <cstring>
#include "../Role/Role.h"
#include <regex>
using namespace std;

int Product::idInc = 0;

Product::Product()
{
    title = new char[20];
    strcpy(title, "new product");
    price = 0;
    discount = 0;
    tag = new char[10];
    strcpy(tag, "new tag");
    // category.setName("restlux");
    quantity = 1;
    imagePath = "path image here";
    idInc++;
    id = idInc;
    slug = Role::GenerateSlug(title);
    cout << "Constructeur par defaut appelee (Product)" << endl;
}
Product::Product(const char *title_, const double &price_, const double &discount_, const char *tag_, const Category &category_, const int &quantity_, const string &imagePath_)
{
    title = new char[strlen(title_) + 1];
    strcpy(title, title_);
    slug = Role::GenerateSlug(title_);
    price = price_;
    discount = discount_;
    tag = new char[strlen(tag_) + 1];
    strcpy(tag, tag_);
    category = category_;
    quantity = quantity_;
    imagePath = imagePath_;
    idInc++;
    id = idInc;
    cout << "Constructeur avec parametres appelee (Product)" << endl;
}
Product::Product(const Product &P)
{
    title = new char[strlen(P.title) + 1];
    strcpy(title, P.title);
    slug = Role::GenerateSlug(P.title);
    price = P.price;
    discount = P.discount;
    tag = new char[strlen(P.tag) + 1];
    strcpy(tag, P.tag);
    category = P.category;
    quantity = P.quantity;
    imagePath = P.imagePath;
    idInc++;
    id = idInc;
    cout << "Constructeur de recopie (Product)" << endl;
}
Product::~Product()
{
    delete[] title;
    delete[] slug;
    delete[] tag;
    cout << "Destructeur appelee (Product)" << endl;
}
Product &Product::operator=(const Product &P)
{
    delete[] title;
    title = new char[strlen(P.title) + 1];
    strcpy(title, P.title);
    delete[] slug;
    slug = Role::GenerateSlug(P.title);
    price = P.price;
    discount = P.discount;
    delete[] tag;
    tag = new char[strlen(P.tag) + 1];
    strcpy(tag, P.tag);
    category = P.category;
    imagePath = P.imagePath;
    cout << "Constructeur operateur affectation (Product)" << endl;
    return *this;
}
ostream &operator<<(ostream &ostr, Product &P)
{
    ostr << "Product id: " << P.id << endl;
    ostr << "Title: " << P.title << endl;
    ostr << "Slug: " << P.slug << endl;
    ostr << "Price: " << P.price << endl;
    ostr << "Discount: " << P.discount << endl;
    ostr << "Tag: " << P.tag << endl;
    ostr << "Category: " << P.category.getName() << endl;
    ostr << "Quantity: " << P.quantity << endl;
    ostr << "Image path: " << P.imagePath << endl;
    return ostr;
}
istream &operator>>(istream &istr, Product &P)
{
    cout << "ADD PRODUCT  (press 0 to quite) " << endl;
    while (true)
    {
        string titleInput;
        cout << "Enter the title of product ";
        istr >> titleInput;
        if (titleInput == "0")
        {
            break;
        }
        try
        {
            P.setTitle(titleInput.c_str());
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << endl;
            continue;
        }
        string priceInput;
        cout << "Enter the price ";
        istr >> priceInput;
        try
        {
            if (priceInput.empty())
            {
                throw invalid_argument("Price is required.");
            }
            double priceConvert = stod(priceInput);
            P.setPrice(priceConvert);
        }
        catch (const invalid_argument &e)
        {
            cout << "Error " << e.what() << endl;
            continue;
        }
        string discountInput;
        cout << "Enter the discount ";
        istr >> discountInput;
        try
        {
            if (discountInput.empty())
            {
                throw invalid_argument("Discount is required.");
            }
            double discountConvert = stod(discountInput);
            P.setDiscount(discountConvert);
        }
        catch (const invalid_argument &e)
        {
            cout << "Error " << e.what() << endl;
            continue;
        }
        string tagInput;
        cout << "Enter a Tag ";
        istr >> tagInput;
        if (tagInput == "0")
        {
            break;
        }
        try
        {
            P.setTag(tagInput.c_str());
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << endl;
            continue;
        }
        string quantityInput;
        cout << "Enter the quantity ";
        istr >> quantityInput;
        try
        {
            if (quantityInput.empty())
            {
                throw invalid_argument("Discount is required.");
            }
            int quantityConvert = stoi(quantityInput);
            P.setQuantity(quantityConvert);
        }
        catch (const invalid_argument &e)
        {
            cout << "Error " << e.what() << endl;
            continue;
        }
        string imagePathInput;
        cout << "Enter Image path ";
        istr >> imagePathInput;
        try
        {
            P.setImagePath(imagePathInput);
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << endl;
            continue;
        }
        break;
    }
    cout << "Product add successfuly" << endl;
    return istr;
}

// Getters
int Product::getId() const
{
    return id;
}
const char *Product::getTitle() const
{
    return title;
}
const char *Product::getSlug() const
{
    return slug;
}
double Product::getPrice() const
{
    return price;
}
double Product::getDiscount() const
{
    return discount;
}
const char *Product::getTag() const
{
    return tag;
}
Category Product::getCategory() const
{
    return category;
}
int Product::getQuantity() const
{
    return quantity;
}
string Product::getImagePath() const
{
    return imagePath;
}

// Setters
void Product::setId(const int &id_)
{
    if (id_ <= 0)
    {
        throw invalid_argument("Id needs to be 1 or more.");
    }
    this->id = id_;
}
void Product::setTitle(const char *title_)
{
    if (title_ == nullptr || strlen(title_) == 0)
    {
        throw invalid_argument("Title is required.");
    }
    const regex titlePattern("^(?=(?:.*[A-Za-z]){4})[A-Za-z0-9 ]+$");
    if (!regex_match(title_, titlePattern))
    {
        throw invalid_argument("The title must contain at least 4 letters and may include only letters, numbers, and spaces.");
    }
    delete[] title;
    title = new char[strlen(title_) + 1];
    strcpy(title, title_);
    slug = Role::GenerateSlug(title_);
}
void Product::setPrice(const double &price_)
{
    if (price_ < 0)
    {
        throw invalid_argument("Price needs to be positif.");
    }
    this->price = price_;
}
void Product::setDiscount(const double &discount_)
{
    if (discount_ < 0 || discount_ > 100)
    {
        throw invalid_argument("Discount must be between 0 and 100%.");
    }
    this->discount = discount_;
}
void Product::setTag(const char *tag_)
{
    if (tag_ == nullptr || strlen(tag_) == 0)
    {
        throw invalid_argument("Tag is required.");
    }
    const regex tagPattern(R"(^(?=(?:.*[A-Za-z]){4})[A-Za-z0-9 &'\\-]+$)");
    if (!regex_match(tag_, tagPattern))
    {
        throw invalid_argument("The tag must contain at least 4 letters and may only include letters, numbers, spaces, ampersands (&), apostrophes ('), and hyphens (-).");
    }
    delete[] tag;
    tag = new char[strlen(tag_) + 1];
    strcpy(tag, tag_);
}
void Product::setQuantity(const int &quantity_)
{
    if (quantity_ < 0)
    {
        throw invalid_argument("Quantity must be positif");
    }
    this->quantity = quantity_;
}
void Product::setImagePath(const string &imagePath_)
{
    if (imagePath_.empty())
    {
        throw invalid_argument("Image is required.");
    }
    this->imagePath = imagePath_;
}
void Product::setCategory(const Category &category_)
{
    this->category = category_;
}
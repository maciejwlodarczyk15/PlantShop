#ifndef ROSLINY_PRODUCT_H
#define ROSLINY_PRODUCT_H

#include <string>

class Product {
private:
    int id;
    std::string name;
    float price;
public:
    Product(int id, const std::string &name, float price);


    virtual ~Product();

    int getId() const;

    const std::string &getName() const;

    float getPrice() const;

    virtual std::string productInfo()=0;
    virtual float getTotalPrice()=0;

    bool operator==(const Product &rhs) const;

    bool operator!=(const Product &rhs) const;

};


#endif //ROSLINY_PRODUCT_H

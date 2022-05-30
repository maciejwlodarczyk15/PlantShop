#include "model/Product.h"

Product::~Product() {

}

int Product::getId() const {
    return id;
}

const std::string &Product::getName() const {
    return name;
}

float Product::getPrice() const {
    return price;
}



bool Product::operator==(const Product &rhs) const {
    return id == rhs.id &&
           name == rhs.name &&
           price == rhs.price;
}

bool Product::operator!=(const Product &rhs) const {
    return !(rhs == *this);
}

Product::Product(int id, const std::string &name, float price) : id(id), name(name), price(price) {}

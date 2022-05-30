#include "model/Seed.h"
#include <sstream>

std::string Seed::productInfo() {
    std::stringstream sout;

    sout << "Seedle. id: " << getId() << ",name:" << getName() << ",price per 100g: " << getPrice()
         << ",weight: " << weight << ",total price: " << getTotalPrice();
    return sout.str();
}

float Seed::getTotalPrice() {
    return weight*getPrice()/100;
}

Seed::Seed(int id, const std::string &name, float price, float weight) : Product(id, name, price), weight(weight) {}

float Seed::getWeight() const {
    return weight;
}
#include "model/Seedle.h"
#include <sstream>

Seedle::Seedle(int id, const std::string &name, float price, int ammount) : Product(id, name, price),
                                                                            ammount(ammount) {}

std::string Seedle::productInfo() {
    std::stringstream sout;
    sout << "Seedle. id: " << getId() <<",name: " << getName() << ",price per 1: " << getPrice()
         << ", ammount: " << ammount  << ",total price: " << getTotalPrice();
    return sout.str();
}

float Seedle::getTotalPrice() {
    return ammount*getPrice();
}

int Seedle::getAmmount() const {
    return ammount;
}

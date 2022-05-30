#include "repositories/ProductRepository.h"
#include "model/Product.h"
#include "exceptions/ProductException.h"

ProductRepository::ProductRepository() {}

ProductRepository::~ProductRepository() {

}

shared_ptr<Product> ProductRepository::find(int id) {
    for(auto &p : items)
    {
        if(p->getId()==id)
            return p;
    }
    throw ProductDoesntExistsException("Product with such id doesnt exist");
}

bool ProductRepository::idExists(int id) {
    for(auto &p : items)
    {
        if(p->getId()==id)
            return true;
    }
    return false;
}

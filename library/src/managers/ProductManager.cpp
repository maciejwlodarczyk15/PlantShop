#include <sstream>

#include "managers/ProductManager.h"
#include "repositories/ProductRepository.h"
#include "model/Seed.h"
#include "model/Seedle.h"
#include "exceptions/ProductException.h"
#include "managers/OrderManager.h"

ProductManager::ProductManager(const std::shared_ptr<ProductRepository> &productRepo) : productRepo(productRepo) {}

void ProductManager::createProductSeed(int id, std::string name, float price, float weight) {
    if(productRepo->idExists(id))
        throw ProductIdExistsException("Product with such id already exists");
    if(price <=0)
        throw WrongValuesForProduct("Can not create product. Price can not be equal or below zero");
    if(price <=0)
        throw WrongValuesForProduct("Can not create product.Price can not be equal or below zero");
    if(weight <=0)
        throw WrongValuesForProduct("Can not create product. Weight can not be equal or below zero");

    productRepo->add(std::make_shared<Seed>(id,name,price,weight));
}

void ProductManager::createProductSeedle(int id, std::string name, float price, int amount) {
    if(productRepo->idExists(id))
        throw ProductIdExistsException("Product with such id already exists");
    if(price <=0)
        throw WrongValuesForProduct("Can not create product. Price can not be equal or below zero");
    if(amount <=0)
        throw WrongValuesForProduct("Can not create product. Amount can not be equal or below zero");

    productRepo->add(make_shared<Seedle>(id,name,price,amount));

}



void ProductManager::deleteProduct(int id,shared_ptr<OrderManager> orderManager) {
    if(!productRepo->idExists(id))
        throw ProductDoesntExistsException("Can not delete product. Product with such id does not exists");

    if(orderManager->isProductOrdered(id))
        throw ProductCanNotBeDeletedException("Can not delete product. There are orders for that product");
    productRepo->remove(productRepo->find(id));
}

std::string ProductManager::productReport() {
    stringstream sout;
    sout << "Products report: \n";
    list<shared_ptr<Product>> products =productRepo->getAll();
    for(auto p : products)
    {
        sout << p->productInfo() << "\n";
    }
    return sout.str();
}

shared_ptr<Product> ProductManager::getProduct(int id) {
    if(!productRepo->idExists(id))
        throw ProductDoesntExistsException("Product with such id does not exist");
    return productRepo->find(id);
}

bool ProductManager::productExists(int id) {
    return productRepo->idExists(id);
}

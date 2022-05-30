#ifndef ROSLINY_PRODUCTREPOSITORY_H
#define ROSLINY_PRODUCTREPOSITORY_H


#include "model/Repository.h"
#include <memory>

class Product;

class ProductRepository :public Repository<shared_ptr<Product>>{
public:
ProductRepository();
virtual ~ProductRepository();

shared_ptr<Product> find(int id);

bool idExists(int id);
};


#endif //ROSLINY_PRODUCTREPOSITORY_H

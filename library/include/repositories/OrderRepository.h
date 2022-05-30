#ifndef ROSLINY_ORDERREPOSITORY_H
#define ROSLINY_ORDERREPOSITORY_H


#include "model/Repository.h"
#include <memory>

class Order;
class Product;
class Client;

class OrderRepository : public Repository<shared_ptr<Order>>{
public:
OrderRepository();
virtual ~OrderRepository();

shared_ptr<Order> find(int id) override;
bool idExists(int id);

list<shared_ptr<Order>> getOrdersForProduct(shared_ptr<Product> product);

void setClientForOrder(shared_ptr<Client> client, shared_ptr<Order> order);
int getClientIdForOrder(int id);
};


#endif //ROSLINY_ORDERREPOSITORY_H

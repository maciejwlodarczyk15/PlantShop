#include "repositories/OrderRepository.h"
#include "model/Order.h"
#include "exceptions/OrderException.h"
#include "model/Client.h"

OrderRepository::OrderRepository() {}

OrderRepository::~OrderRepository() {

}

shared_ptr<Order> OrderRepository::find(int id) {
    for(auto &o : items)
    {
        if(o->getId() == id)
            return o;
    }
    throw OrderDoesntExistsException("Order doesnt exists");
}

bool OrderRepository::idExists(int id) {
    for(auto &o : items)
    {
        if(o->getId() == id)
            return true;
    }
    return false;
}

list<shared_ptr<Order>> OrderRepository::getOrdersForProduct(shared_ptr<Product> product) {
    list<shared_ptr<Order>> orders;
    for(auto &o : items)
    {
        if(o->getProduct()==product)
            orders.push_back(o);
    }
    return orders;
}

void OrderRepository::setClientForOrder(shared_ptr<Client> client, shared_ptr<Order> order) {
    order->setClientForOrder(client);
}

int OrderRepository::getClientIdForOrder(int id) {
    return find(id)->getClient()->getId();
}

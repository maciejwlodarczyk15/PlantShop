#include "model/Order.h"
#include "model/Product.h"
#include "model/Client.h"
#include <sstream>

Order::Order(int id, const std::string &orderDate, const std::shared_ptr<Product> &product) : id(id),
                                                                                              orderDate(orderDate),
                                                                                              product(product)
{
    client = nullptr;
}

Order::~Order() {

}

int Order::getId() const {
    return id;
}

const std::string &Order::getOrderDate() const {
    return orderDate;
}

const std::shared_ptr<Product> &Order::getProduct() const {
    return product;
}

const std::shared_ptr<Client> &Order::getClient() const {
    return client;
}

std::string Order::orderInfo() {
    std::stringstream sout;
    sout << "Order id: " << id << ", date: " << orderDate << " \n" << product->productInfo() << "\n" << client->shortClientInfo();
    return sout.str();
}

void Order::setClientForOrder(std::shared_ptr<Client> client) {
    this->client = client;
}

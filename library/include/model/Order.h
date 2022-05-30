#ifndef ROSLINY_ORDER_H
#define ROSLINY_ORDER_H

#include <memory>

class Client;
class Product;

class Order {
private:
    int id;
    std::string orderDate;
    std::shared_ptr<Product> product;
    std::shared_ptr<Client> client;
public:
    Order(int id, const std::string &orderDate, const std::shared_ptr<Product> &product);
    virtual ~Order();

    int getId() const;
    const std::string &getOrderDate() const;
    const std::shared_ptr<Product> &getProduct() const;
    const std::shared_ptr<Client> &getClient() const;

    void setClientForOrder(std::shared_ptr<Client> client);
    std::string orderInfo();
};


#endif //ROSLINY_ORDER_H

#ifndef ROSLINY_ORDERMANAGER_H
#define ROSLINY_ORDERMANAGER_H

#include <memory>

class ProductManager;
class ProductManager;
class OrderRepository;
class ClientManager;
class Order;

class OrderManager {
private:
    std::shared_ptr<OrderRepository> orderRepo;
public:
    OrderManager(const std::shared_ptr<OrderRepository> &orderRepo);
    void createOrder(int id, std::string date, int productId, int clientId,
                     std::shared_ptr<ProductManager> productManager, std::shared_ptr<ClientManager> clientManager);
    void deleteOrder(int id, std::shared_ptr<ClientManager> clientManager);
    std::string orderReport();
    std::shared_ptr<Order> getOrder(int id);
    bool isProductOrdered(int id);
};


#endif //ROSLINY_ORDERMANAGER_H

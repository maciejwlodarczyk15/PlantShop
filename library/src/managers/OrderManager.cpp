#include <sstream>
#include "managers/OrderManager.h"
#include "model/Order.h"

#include "exceptions/OrderException.h"
#include "exceptions/ProductException.h"
#include "exceptions/ClientException.h"

#include "repositories/ProductRepository.h"
#include "repositories/ClientRepository.h"
#include "repositories/OrderRepository.h"
#include "managers/ClientManager.h"
#include "managers/ProductManager.h"
#include "model/Product.h"


OrderManager::OrderManager(const std::shared_ptr<OrderRepository> &orderRepo) : orderRepo(orderRepo) {}


void OrderManager::createOrder(int id, std::string date, int productId, int clientId,std::shared_ptr<ProductManager> productManager,
                               std::shared_ptr<ClientManager> clientManager) {
    //shared_ptr<Client> client;
    if(orderRepo->idExists(id))
        throw OrderIdExistsException("Order with such id already exists");
    if(!productManager->productExists(productId))
        throw ProductDoesntExistsException("Can not create order. Product with such id doesnt exist");

    if(!clientManager->clientExists(clientId))
        throw ClientDoesntExistsException("Cannot create order. Client with such id does not exist");

    orderRepo->add(make_shared<Order>(id,date,productManager->getProduct(productId)));
    orderRepo->setClientForOrder(clientManager->getClient(clientId), orderRepo->find(id));
    clientManager->addOrderToClient(orderRepo->find(id),clientId);
}


void OrderManager::deleteOrder(int id, std::shared_ptr<ClientManager> clientManager) {
    if(!orderRepo->idExists(id))
        throw OrderDoesntExistsException("Can not delete order. Order with such id does not exists");
    //orderRepo->find(id)->getClient()->deleteOrder(orderRepo->find(id));
    clientManager->removeOrderFromClient(orderRepo->find(id),orderRepo->getClientIdForOrder(id));
    orderRepo->remove(orderRepo->find(id));
}

std::string OrderManager::orderReport() {
    stringstream sout;
    sout << "Orders report: \n";
    list<shared_ptr<Order>> orders =orderRepo->getAll();
    for(auto o : orders)
    {
        sout << o->orderInfo() << "\n";
    }
    return sout.str();
}

std::shared_ptr<Order> OrderManager::getOrder(int id) {
    if(!orderRepo->idExists(id))
        throw OrderDoesntExistsException("Can not find order. Such order does not exist");
    return orderRepo->find(id);
}

bool OrderManager::isProductOrdered(int id) {
    list<shared_ptr<Order>> orders = orderRepo->getAll();
    for(auto o:orders)
    {
        if(o->getProduct()->getId()==id)
            return true;
    }
    return false;
}
#include <iostream>
#include <memory>

#include "managers/ClientManager.h"
#include "managers/ProductManager.h"
#include "managers/OrderManager.h"
#include "exceptions/ClientException.h"
#include "exceptions/OrderException.h"
#include "exceptions/ProductException.h"
#include "repositories/ClientRepository.h"
#include "repositories/ProductRepository.h"
#include "repositories/OrderRepository.h"

using  namespace std;

int main()
{

    shared_ptr<ClientManager> clientManager = make_shared<ClientManager>(make_shared<ClientRepository>());
    clientManager->createClient(1, "Monika", "Olkiewicz", "23847298491984701");
    clientManager->createClient(2, "Aleksandra", "Malka", "43636798491984701");

    shared_ptr<ProductManager> productManager = make_shared<ProductManager>(make_shared<ProductRepository>());
    productManager->createProductSeed(3, "carrot", 3.5, 200);
    productManager->createProductSeedle(4, "apple", 8.5, 6);

    shared_ptr<OrderManager> manager = make_shared<OrderManager>(make_shared<OrderRepository>());

    manager->createOrder(5,"01.01.2020",4,1, productManager,clientManager);
    manager->createOrder(6,"01.01.2020",3,2,productManager,clientManager);

    cout << clientManager->clientReport() << endl;
    cout << productManager->productReport() << endl;
    cout << manager->orderReport() << endl;

    manager->deleteOrder(5, clientManager);
    manager->deleteOrder(6, clientManager);

    productManager->deleteProduct(3, manager);
    productManager->deleteProduct(4, manager);

    clientManager->deleteClient(1);
    clientManager->deleteClient(2);

    cout << clientManager->clientReport() << endl;
    cout << productManager->productReport() << endl;
    cout << manager->orderReport() << endl;

    return 0;
}
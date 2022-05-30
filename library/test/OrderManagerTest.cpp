#include <boost/test/unit_test.hpp>
#include "repositories/ClientRepository.h"
#include "repositories/OrderRepository.h"
#include "repositories/ProductRepository.h"
#include "exceptions/ClientException.h"
#include "exceptions/OrderException.h"
#include "exceptions/ProductException.h"
#include "managers/ClientManager.h"
#include "managers/ProductManager.h"
#include "managers/OrderManager.h"


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(OrderManagerTest)
    {
        shared_ptr<ClientManager> clientManager = make_shared<ClientManager>(make_shared<ClientRepository>());
        clientManager->createClient(1, "Monika", "Olkiewicz", "23847298491984701");

        shared_ptr<ProductManager> productManager = make_shared<ProductManager>(make_shared<ProductRepository>());
        productManager->createProductSeed(3, "carrot", 3.5, 200);

        shared_ptr<OrderManager> manager = make_shared<OrderManager>(make_shared<OrderRepository>());

        manager->createOrder(5,"01.01.2020",3,1,productManager, clientManager);
        manager->createOrder(6,"01.05.2020",3,1,productManager, clientManager);

        BOOST_CHECK_THROW(manager->createOrder(5,"01.01.2020",3,1,productManager, clientManager),OrderIdExistsException);
        BOOST_CHECK_THROW(manager->createOrder(1,"01.01.2020",10,1,productManager, clientManager),ProductDoesntExistsException);
        BOOST_CHECK_THROW(manager->createOrder(3,"01.01.2020",3,40,productManager, clientManager),ClientDoesntExistsException);
        BOOST_TEST_MESSAGE(manager->orderReport());

        BOOST_CHECK_THROW(clientManager->deleteClient(1),ClientCanNotBeDeletedException);

        BOOST_CHECK_THROW(productManager->deleteProduct(3,manager),ProductCanNotBeDeletedException);
        BOOST_CHECK_THROW(productManager->deleteProduct(40, manager),ProductDoesntExistsException);

        BOOST_CHECK_THROW(manager->deleteOrder(40,clientManager),OrderDoesntExistsException);

        manager->deleteOrder(5,clientManager);
        manager->deleteOrder(6,clientManager);

        BOOST_CHECK_THROW(manager->getOrder(5),OrderDoesntExistsException);
        BOOST_CHECK_THROW(manager->getOrder(6),OrderDoesntExistsException);
        BOOST_TEST_MESSAGE(manager->orderReport());


    }

BOOST_AUTO_TEST_SUITE_END()
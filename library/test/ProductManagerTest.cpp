#include <boost/test/unit_test.hpp>
#include "repositories/ClientRepository.h"
#include "repositories/OrderRepository.h"
#include "repositories/ProductRepository.h"
#include "exceptions/ClientException.h"
#include "exceptions/OrderException.h"
#include "exceptions/ProductException.h"
#include "managers/ProductManager.h"
#include "managers/OrderManager.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ProductManagerTest) {
        shared_ptr<ProductManager> manager = make_shared<ProductManager>(make_shared<ProductRepository>());
        shared_ptr<OrderManager> orderManager = make_shared<OrderManager>(make_shared<OrderRepository>());
        manager->createProductSeed(3, "carrot", 3.5, 200);
        manager->createProductSeedle(4,"apple", 3.5, 4);

        BOOST_CHECK_THROW(manager->createProductSeed(3,"onion",20,30),ProductIdExistsException);
        BOOST_CHECK_THROW(manager->createProductSeed(30,"onion",0,30),WrongValuesForProduct);
        BOOST_CHECK_THROW(manager->createProductSeed(30,"onion",-5,30),WrongValuesForProduct);
        BOOST_CHECK_THROW(manager->createProductSeed(30,"onion",20,0),WrongValuesForProduct);
        BOOST_CHECK_THROW(manager->createProductSeed(30,"onion",20,-2),WrongValuesForProduct);

        BOOST_CHECK_THROW(manager->createProductSeedle(3,"onion",20,30),ProductIdExistsException);
        BOOST_CHECK_THROW(manager->createProductSeedle(30,"onion",0,30),WrongValuesForProduct);
        BOOST_CHECK_THROW(manager->createProductSeedle(30,"onion",-5,30),WrongValuesForProduct);
        BOOST_CHECK_THROW(manager->createProductSeedle(30,"onion",20,0),WrongValuesForProduct);
        BOOST_CHECK_THROW(manager->createProductSeedle(30,"onion",20,-2),WrongValuesForProduct);

        BOOST_TEST_MESSAGE(manager->productReport());

        BOOST_CHECK_THROW(manager->deleteProduct(40,orderManager),ProductDoesntExistsException);
        manager->deleteProduct(3,orderManager);
        manager->deleteProduct(4,orderManager);

        BOOST_CHECK_THROW(manager->getProduct(3),ProductDoesntExistsException);
        BOOST_CHECK_THROW(manager->getProduct(4),ProductDoesntExistsException);
        BOOST_TEST_MESSAGE(manager->productReport());
    }
BOOST_AUTO_TEST_SUITE_END()
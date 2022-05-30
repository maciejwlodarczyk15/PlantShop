#include <boost/test/unit_test.hpp>

#include "OrderRepository.h"
#include "Order.h"
#include "exceptions/OrderException.h"
#include "Client.h"
#include "Seed.h"
#include "Seedle.h"
#include "Product.h"

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(OrderRepositoryTest)
    {
        shared_ptr<OrderRepository> repo = make_shared<OrderRepository>();
        BOOST_CHECK_EQUAL(repo->getAll().empty(), true);

        shared_ptr<Product> p1 = make_shared<Seed>(1, "carrot", 3.5, 200);
        shared_ptr<Product> p2 = make_shared<Seedle>(2, "apple", 3.5, 4);
        shared_ptr<Client> client = make_shared<Client>(4, "Mariusz", "Pudzianowski", "010485960");

        shared_ptr<Order> order1 = make_shared<Order>(3,"03.01.2019", p1);
        order1->setClientForOrder(client);

        shared_ptr<Order> order2 = make_shared<Order>(7,"04.01.2019", p2);
        order2->setClientForOrder(client);

        repo->add(order1);
        BOOST_CHECK_EQUAL(repo->getAll().size(), 1);

        repo->add(order2);
        BOOST_CHECK_EQUAL(repo->getAll().size(), 2);

        BOOST_CHECK_EQUAL(repo->find(3)->getOrderDate(),"03.01.2019");
        BOOST_CHECK_EQUAL(repo->find(7)->getOrderDate(),"04.01.2019");

        repo->remove(order1);
        BOOST_CHECK_EQUAL(repo->getAll().size(), 1);
        BOOST_CHECK_THROW(repo->find(3), OrderDoesntExistsException);

        repo->remove(order2);
        BOOST_CHECK_EQUAL(repo->getAll().empty(), true);
        BOOST_CHECK_THROW(repo->find(7), OrderDoesntExistsException);


    }

BOOST_AUTO_TEST_SUITE_END()
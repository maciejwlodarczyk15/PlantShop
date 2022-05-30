#include <boost/test/unit_test.hpp>
#include "Client.h"
#include "Order.h"
#include "Seed.h"

BOOST_AUTO_TEST_SUITE(TestSuiteCorect)

    BOOST_AUTO_TEST_CASE(ClientTest)
    {
        shared_ptr<Client> client = make_shared<Client>(4, "Mariusz", "Pudzianowski", "010485960");

        BOOST_CHECK_EQUAL(client->getOrders().empty(), true);
        BOOST_CHECK_EQUAL(client->getId(), 4 );
        BOOST_CHECK_EQUAL(client->getName(), "Mariusz");
        BOOST_CHECK_EQUAL(client->getLastName(), "Pudzianowski");
        BOOST_CHECK_EQUAL(client->getPhoneNumber(), "010485960");

        shared_ptr<Seed> seed = make_shared<Seed>(1, "carrot", 3.5, 200);
        shared_ptr<Order> order = make_shared<Order>(3,"03.01.2019", seed);
        order->setClientForOrder(client);
        client->addOrder(order);

        BOOST_CHECK_EQUAL(client->getOrders().size(), 1);
        BOOST_TEST_MESSAGE(client->clientInfo());

        client->deleteOrder(order);

        BOOST_CHECK_EQUAL(client->getOrders().empty(), true);
        BOOST_TEST_MESSAGE(client->clientInfo());

    }

BOOST_AUTO_TEST_SUITE_END()
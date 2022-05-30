#include <boost/test/unit_test.hpp>

#include "Seed.h"
#include "Order.h"
#include "Client.h"

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(OrderTest)
    {
        shared_ptr<Seed> seed = make_shared<Seed>(1, "carrot", 3.5, 200);
        Order order(2,"03.01.2019", seed);
        shared_ptr<Client> client = make_shared<Client>(4, "Mariusz", "Pudzianowski", "010485960");
        order.setClientForOrder(client);

        BOOST_CHECK_EQUAL(order.getId(), 2);
        BOOST_CHECK_EQUAL(order.getOrderDate(), "03.01.2019");
        BOOST_CHECK_EQUAL(order.getClient(), client);
        BOOST_CHECK_EQUAL(order.getProduct(), seed);

        BOOST_TEST_MESSAGE(order.orderInfo());

    }

BOOST_AUTO_TEST_SUITE_END()
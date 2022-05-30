#include <boost/test/unit_test.hpp>
#include "model/Seedle.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(SeedleTest)
    {
        shared_ptr<Seedle> seedle = make_shared<Seedle>(1, "apple", 3.5, 4);

        BOOST_CHECK_EQUAL(seedle->getId(),1);
        BOOST_CHECK_EQUAL(seedle->getName(), "apple");
        BOOST_CHECK_EQUAL(seedle->getPrice(), 3.5);
        BOOST_CHECK_EQUAL(seedle->getAmmount(), 4);
        BOOST_CHECK_EQUAL(seedle->getTotalPrice(), 14);
        BOOST_TEST_MESSAGE(seedle->productInfo());
    }
BOOST_AUTO_TEST_SUITE_END()
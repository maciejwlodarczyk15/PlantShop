#include <boost/test/unit_test.hpp>
#include "model/Seed.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(SeedTest)
    {
        shared_ptr<Seed> seed = make_shared<Seed>(1, "carrot", 3.5, 200);

        BOOST_CHECK_EQUAL(seed->getId(),1);
        BOOST_CHECK_EQUAL(seed->getName(), "carrot");
        BOOST_CHECK_EQUAL(seed->getPrice(), 3.5);
        BOOST_CHECK_EQUAL(seed->getWeight(), 200);
        BOOST_CHECK_EQUAL(seed->getTotalPrice(), 7);
        BOOST_TEST_MESSAGE(seed->productInfo());
    }
BOOST_AUTO_TEST_SUITE_END()
#include <boost/test/unit_test.hpp>

#include "ProductRepository.h"
#include "exceptions/ProductException.h"
#include "Seed.h"
#include "Seedle.h"
#include "Product.h"

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ProductRepositoryTest)
    {
        shared_ptr<ProductRepository> repo = make_shared<ProductRepository>();
        BOOST_CHECK_EQUAL(repo->getAll().empty(), true);

        shared_ptr<Product> p1 = make_shared<Seed>(1, "carrot", 3.5, 200);
        shared_ptr<Product> p2 = make_shared<Seedle>(2, "apple", 3.5, 4);

        repo->add(p1);
        BOOST_CHECK_EQUAL(repo->getAll().size(), 1);

        repo->add(p2);
        BOOST_CHECK_EQUAL(repo->getAll().size(), 2);

        BOOST_CHECK_EQUAL(repo->idExists(1),true);
        BOOST_CHECK_EQUAL(repo->idExists(50),false);

        BOOST_CHECK_EQUAL(repo->find(1)->getName(),"carrot");
        BOOST_CHECK_EQUAL(repo->find(2)->getName(),"apple");

        repo->remove(p1);
        BOOST_CHECK_EQUAL(repo->getAll().size(), 1);
        BOOST_CHECK_THROW(repo->find(1), ProductDoesntExistsException);

        repo->remove(p2);
        BOOST_CHECK_EQUAL(repo->getAll().empty(), true);
        BOOST_CHECK_THROW(repo->find(2), ProductDoesntExistsException);




    }

BOOST_AUTO_TEST_SUITE_END()
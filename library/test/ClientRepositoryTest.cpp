#include <boost/test/unit_test.hpp>
#include "ClientRepository.h"
#include "Client.h"
#include "exceptions/ClientException.h"

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ClientRepositoryTest)
    {
        shared_ptr<ClientRepository> repo = make_shared<ClientRepository>();
        BOOST_CHECK_EQUAL(repo->getAll().empty(), true);

        shared_ptr<Client> c1 = make_shared<Client>(3, "Mariusz", "Pudzianowski", "01048596");
        shared_ptr<Client> c2 = make_shared<Client>(10, "Alina", "Maciałkowska", "564319447");

        repo->add(c1);
        BOOST_CHECK_EQUAL(repo->getAll().size(), 1);

        repo->add(c2);
        BOOST_CHECK_EQUAL(repo->getAll().size(), 2);

        BOOST_CHECK_EQUAL(repo->find(3)->getName(),"Mariusz");
        BOOST_CHECK_EQUAL(repo->find(10)->getName(),"Alina");
        BOOST_CHECK_EQUAL(repo->idExists(3),true);
        BOOST_CHECK_EQUAL(repo->idExists(50),false);

        repo->remove(c1);
        BOOST_CHECK_EQUAL(repo->getAll().size(), 1);
        BOOST_CHECK_THROW(repo->find(3), ClientDoesntExistsException);

        repo->remove(c2);
        BOOST_CHECK_EQUAL(repo->getAll().empty(), true);
        BOOST_CHECK_THROW(repo->find(10), ClientDoesntExistsException);
    }

BOOST_AUTO_TEST_SUITE_END()
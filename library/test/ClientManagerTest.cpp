#include <boost/test/unit_test.hpp>
#include "repositories/ClientRepository.h"
#include "repositories/OrderRepository.h"
#include "repositories/ProductRepository.h"
#include "exceptions/ClientException.h"
#include "exceptions/OrderException.h"
#include "exceptions/ProductException.h"
#include "managers/ClientManager.h"


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ClientManagerTest)
    {
        shared_ptr<ClientManager> manager = make_shared<ClientManager>(make_shared<ClientRepository>());

        manager->createClient(1, "Monika", "Olkiewicz", "23847298491984701");
        manager->createClient(2, "Sara", "Olkiewicz", "238984701");
        BOOST_CHECK_THROW(manager->createClient(1,"Ola", "Laskiewicz", "4204810"),ClientIdExistsException);
        BOOST_TEST_MESSAGE(manager->clientReport());

        BOOST_CHECK_THROW(manager->deleteClient(20),ClientDoesntExistsException);
        manager->deleteClient(1);
        manager->deleteClient(2);

        BOOST_CHECK_THROW(manager->getClient(1),ClientDoesntExistsException);
        BOOST_CHECK_THROW(manager->getClient(2),ClientDoesntExistsException);
        BOOST_TEST_MESSAGE(manager->clientReport());
    }



BOOST_AUTO_TEST_SUITE_END()
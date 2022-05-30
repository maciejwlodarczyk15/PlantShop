#include "managers/ClientManager.h"

#include <sstream>

#include "repositories/ClientRepository.h"
#include "exceptions/ClientException.h"
#include "model/Client.h"

ClientManager::ClientManager(const std::shared_ptr<ClientRepository> &clientRepo) : clientRepo(clientRepo) {}



void ClientManager::createClient(int id, std::string name, std::string lastName, std::string phoneNumber) {
    if(clientRepo->idExists(id))
        throw ClientIdExistsException("Client with such id already exists");
    clientRepo->add(std::make_shared<Client>(id, name, lastName, phoneNumber));
}

void ClientManager::deleteClient(int id) {
    if(!clientRepo->idExists(id))
        throw ClientDoesntExistsException("Can not delete client. Client with such id does not exists");
    if(!(clientRepo->find(id)->getOrders().empty()))
        throw ClientCanNotBeDeletedException("Can not delete client. Client still has orders");
    clientRepo->remove(clientRepo->find(id));
}

std::string ClientManager::clientReport() {
    stringstream sout;
    sout << "Clients report: \n";
    list<shared_ptr<Client>> clients =clientRepo->getAll();
    for(auto c : clients)
    {
        sout << c->clientInfo() << "\n";
    }
    return sout.str();
}

std::shared_ptr<Client> ClientManager::getClient(int id) {
    if(!clientRepo->idExists(id))
        throw ClientDoesntExistsException("Client with such id does not exist");
    return clientRepo->find(id);
}

void ClientManager::addOrderToClient(std::shared_ptr<Order> order, int id) {
    clientRepo->find(id)->addOrder(order);

}

void ClientManager::removeOrderFromClient(std::shared_ptr<Order> order,int id) {
    clientRepo->find(id)->deleteOrder(order);
}

bool ClientManager::clientExists(int id) {
    return clientRepo->idExists(id);
}

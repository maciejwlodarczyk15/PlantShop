#include "repositories/ClientRepository.h"
#include "model/Client.h"
#include "exceptions/ClientException.h"

ClientRepository::ClientRepository() {}

ClientRepository::~ClientRepository() {

}

shared_ptr<Client> ClientRepository::find(int id) {
    for(auto &c : items)
    {
        if(c->getId()==id)
            return c;
    }
    throw ClientDoesntExistsException("Client with such id doesnt exists");
}

bool ClientRepository::idExists(int id) {
    for(auto c : items)
    {
        if(id == c->getId())
            return true;
    }
    return false;
}
#ifndef ROSLINY_CLIENTREPOSITORY_H
#define ROSLINY_CLIENTREPOSITORY_H


#include "model/Repository.h"
#include <memory>

class Client;

class ClientRepository : public Repository<shared_ptr<Client>> {
public:
ClientRepository();
virtual ~ClientRepository();

shared_ptr<Client> find(int id);

bool idExists(int id);
};


#endif //ROSLINY_CLIENTREPOSITORY_H

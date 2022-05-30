#ifndef ROSLINY_CLIENTMANAGER_H
#define ROSLINY_CLIENTMANAGER_H


#include <memory>
class ClientRepository;
class Client;
class Order;

class ClientManager {
private:
    std::shared_ptr<ClientRepository> clientRepo;
public:
    ClientManager(const std::shared_ptr<ClientRepository> &clientRepo);
    void createClient(int id, std::string name, std::string lastName, std::string phoneNumber);
    void deleteClient(int id);
    std::string clientReport();
    std::shared_ptr<Client> getClient(int id);
    void addOrderToClient(std::shared_ptr<Order> order,int id);
    void removeOrderFromClient(std::shared_ptr<Order> order,int id);
    bool clientExists(int id);
};


#endif //ROSLINY_CLIENTMANAGER_H

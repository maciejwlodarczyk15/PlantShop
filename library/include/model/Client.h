#ifndef ROSLINY_CLIENT_H
#define ROSLINY_CLIENT_H

#include <string>
#include <memory>
#include <list>

class Order;

using namespace std;

class Client {
private:
    int id;
    string name;
    string lastName;
    string phoneNumber;
    list<shared_ptr<Order>> orders;
public:
    Client(int id, const string &name, const string &lastName, const string &phoneNumber);
    virtual ~Client();

    int getId() const;
    const string &getName() const;
    const string &getLastName() const;
    const string &getPhoneNumber() const;
    const list<shared_ptr<Order>> &getOrders() const;

    void addOrder(shared_ptr<Order> order);
    void deleteOrder(shared_ptr<Order> order);

    string shortClientInfo();
    string clientInfo();
};


#endif //ROSLINY_CLIENT_H

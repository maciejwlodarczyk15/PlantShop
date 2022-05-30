#include "model/Client.h"
#include "model/Order.h"
#include <sstream>

Client::Client(int id, const string &name, const string &lastName, const string &phoneNumber) : id(id), name(name),
                                                                                                lastName(lastName),
                                                                                                phoneNumber(
                                                                                                        phoneNumber) {}

Client::~Client() {

}

int Client::getId() const {
    return id;
}

const string &Client::getName() const {
    return name;
}

const string &Client::getLastName() const {
    return lastName;
}

const string &Client::getPhoneNumber() const {
    return phoneNumber;
}

string Client::shortClientInfo() {
    stringstream sout;
    sout << "Client id: " << id << "  name: " << name << ", last name: " << lastName << ",phone number: " << phoneNumber;
    return sout.str();
}

string Client::clientInfo() {
    stringstream sout;
    sout << shortClientInfo();
    sout << "\nOrders: \n";
    if(orders.empty())
    {
        sout << "None";
        return sout.str();
    }
    for(auto &o : orders)
    {
        sout << o->orderInfo() << "\n \n";
    }
    return sout.str();
}

void Client::addOrder(shared_ptr<Order> order) {
    orders.push_back(order);
}

void Client::deleteOrder(shared_ptr<Order> order) {
    orders.remove(order);
}

const list<shared_ptr<Order>> &Client::getOrders() const {
    return orders;
}

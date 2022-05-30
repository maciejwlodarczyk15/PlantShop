#include "exceptions/OrderException.h"

OrderException::OrderException(const string &message) : logic_error(message) {

}

string OrderException::message() const {
    return std::__cxx11::string();
}

OrderDoesntExistsException::OrderDoesntExistsException(const string &message) : OrderException(message) {}

OrderIdExistsException::OrderIdExistsException(const string &message) : OrderException(message) {}

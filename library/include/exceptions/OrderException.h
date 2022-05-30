#ifndef ROSLINY_ORDEREXCEPTION_H
#define ROSLINY_ORDEREXCEPTION_H


#include <exception>
#include <string>
#include <stdexcept>

using namespace std;

class OrderException : public logic_error{
public:
    explicit OrderException(const string &message);
    virtual string message()const;
};


class OrderDoesntExistsException : public OrderException
{
public:
    explicit OrderDoesntExistsException(const string &message);
};

class OrderIdExistsException : public OrderException
{
public:
    explicit OrderIdExistsException(const string &message);
};


#endif //ROSLINY_ORDEREXCEPTION_H

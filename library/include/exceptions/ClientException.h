#ifndef ROSLINY_CLIENTEXCEPTION_H
#define ROSLINY_CLIENTEXCEPTION_H


#include <exception>
#include <string>
#include <stdexcept>

using namespace std;

class ClientException : public logic_error{
public:
    explicit ClientException(const string &message);
    virtual string message()const;
};

class ClientDoesntExistsException : public ClientException
{
public:
    explicit ClientDoesntExistsException(const string &message);
};

class ClientIdExistsException : public ClientException
{
public:
    explicit ClientIdExistsException(const string &message);
};

class ClientCanNotBeDeletedException : public ClientException
{
public:
    explicit ClientCanNotBeDeletedException(const string &message);
};


#endif //ROSLINY_CLIENTEXCEPTION_H

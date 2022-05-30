#ifndef ROSLINY_PRODUCTEXCEPTION_H
#define ROSLINY_PRODUCTEXCEPTION_H


#include <exception>
#include <string>
#include <stdexcept>

using namespace std;

class ProductException : public logic_error{
public:
    explicit ProductException(const string &message);
    virtual string message()const;
};

class ProductDoesntExistsException : public ProductException
{
public:
    explicit ProductDoesntExistsException(const string &message);
};

class ProductIdExistsException : public ProductException
{
public:
    explicit ProductIdExistsException(const string &message);
};

class ProductCanNotBeDeletedException : public ProductException
{
public:
    explicit ProductCanNotBeDeletedException(const string &message);
};

class WrongValuesForProduct: public ProductException
{
public:
    explicit WrongValuesForProduct(const string &message);
};


#endif //ROSLINY_PRODUCTEXCEPTION_H

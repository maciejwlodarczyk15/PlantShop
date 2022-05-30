#include "exceptions/ProductException.h"

ProductException::ProductException(const string &message) : logic_error(message) {

}

string ProductException::message() const {
    return what();
}

ProductDoesntExistsException::ProductDoesntExistsException(const string &message) : ProductException(message) {}

ProductIdExistsException::ProductIdExistsException(const string &message) : ProductException(message) {}

ProductCanNotBeDeletedException::ProductCanNotBeDeletedException(const string &message) : ProductException(message) {}

WrongValuesForProduct::WrongValuesForProduct(const string &message) : ProductException(message) {}
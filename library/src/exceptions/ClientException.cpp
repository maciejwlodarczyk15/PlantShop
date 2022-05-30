#include "exceptions/ClientException.h"

ClientException::ClientException(const string &message) : logic_error(message) {

}

string ClientException::message() const {
    return what();
}

ClientDoesntExistsException::ClientDoesntExistsException(const string &message) : ClientException(message) {}

ClientIdExistsException::ClientIdExistsException(const string &message) : ClientException(message) {}

ClientCanNotBeDeletedException::ClientCanNotBeDeletedException(const string &message) : ClientException(message) {}
#include "Validator.h"
#include <string>
#include <exception>

using namespace std;
ValidationException::ValidationException(std::string _message) {
    message = _message;
}

std::string ValidationException::getMessage() const {
        return this->message;
    }

RepositoryException::RepositoryException(std::string _message) {
    message = _message;
}

std::string RepositoryException::getMessage() const {
    return this->message;
}

InputException::InputException(std::string _message) {
    message = _message;
}

std::string InputException::getMessage() const {
    return this->message;
}

void MovieValidator::validate(Movie& m) {
        string errors;
        errors = "";
        if (m.get_id() < 0)
            errors += string("The movie's id cannot be negative!\n");
        if (m.get_genre().size() < 2)
            errors += string("The movie's genre cannot be smaller then 2!\n");
        if (m.get_title().size() < 2)
            errors += string("The movie's title cannot be smaller then 2!\n");
        if (m.get_trailer().size() < 2)
            errors += string("The movie's trailer cannot be smaller then 2!\n");
        if (m.get_likes() < 0)
            errors += string("The likes  cannot be negative!\n");
        if(m.get_year() > 2100 || m.get_year() < 1800)
            errors += string("Year not valid!\n");
        if (errors.size() > 0)
            throw ValidationException(errors);
}



#pragma once

#include <string>
#include "Movie.h"

class ValidationException {
private:
    std::string message;

public:
    ValidationException(std::string _message);
    std::string getMessage() const;
};

class RepositoryException {
private:
    std::string message;

public:
    RepositoryException(std::string _message);
    std::string getMessage() const;
};

class InputException {
private:
    std::string message;

public:
    InputException(std::string _message);
    std::string getMessage() const;
};

class MovieValidator {
public:
    static void validate(Movie& m);
    };
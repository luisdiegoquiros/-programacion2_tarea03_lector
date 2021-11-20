#ifndef EXCEPCIONPERSONAINVALIDA_H
#define EXCEPCIONPERSONAINVALIDA_H

#include <exception>

class ExcepcionPersonaInvalida : public std::exception
{
    public:
    ExcepcionPersonaInvalida() noexcept = default;
    ~ExcepcionPersonaInvalida() = default;

    virtual const char* what() const noexcept {
        return "La persona en la posición específicada es inválida.";
    }

};

#endif
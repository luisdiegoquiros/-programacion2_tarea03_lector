#ifndef EXCEPCIONPERSONANOEXISTE_H
#define EXCEPCIONPERSONANOEXISTE_H

#include <exception>

class ExcepcionPersonaNoExiste : public std::exception
{
    public:
    ExcepcionPersonaNoExiste() noexcept = default;
    ~ExcepcionPersonaNoExiste() = default;

    virtual const char* what() const noexcept {
        return "No se puede leer la persona en la posición específicada.";
    }

};

#endif
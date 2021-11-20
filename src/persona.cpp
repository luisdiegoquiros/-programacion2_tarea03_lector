#include "persona.h"
#include <cstring>
#include <string>
#include <iostream>

Persona::Persona(int id, std::string nombre, std::string apellido, std::string correo)
{
    this->id = id;
    strcpy(this->nombre, nombre.c_str());
    strcpy(this->apellido, apellido.c_str());
    strcpy(this->correo, correo.c_str());
}

Persona::Persona()
{
    this->id = 0;
    strcpy(this->nombre, "");
    strcpy(this->apellido, "");
    strcpy(this->correo, "");
}

int Persona::obtenerId()
{
    return this->id;
}

std::string Persona::obtenerNombre()
{
    std::string nombreString{nombre};
    return nombreString;
}

std::string Persona::obtenerApellido()
{
    std::string apellidoString{apellido};
    return apellidoString;
}

std::string Persona::obtenerCorreo()
{
    std::string correoString{correo};
    return correoString;
}

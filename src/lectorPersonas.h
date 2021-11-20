#ifndef LECTORPERSONAS_H
#define LECTORPERSONAS_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "persona.h"

class LectorPersonas
{

    std::string nombreArchivo;
    std::ifstream archivoEntrada;

public:
    LectorPersonas(std::string nombreArchivo);

    void abrirArchivo();
    Persona leerPersonaPosicion(int posicion);
    void cerrar();
};

#endif
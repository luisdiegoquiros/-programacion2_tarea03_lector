#ifndef ESCRITORPERSONAS_H
#define ESCRITORPERSONAS_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "persona.h"

class EscritorPersonas {

    std::ofstream archivoSalida;

    public:
    EscritorPersonas(std::string nombreArchivo);
    
    void agregarPersona(Persona &persona);
    void agregarVariasPersonas(std::vector<Persona> &vectorPersonas);
    bool cerrar();

};

#endif
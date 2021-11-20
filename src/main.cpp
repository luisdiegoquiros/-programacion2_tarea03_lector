#ifndef UNIT_TEST

#include <iostream>
#include <fstream>
#include <string>

#include "excepciones/excepcionNoSePuedeAbrirArchivo.h"
#include "excepciones/excepcionPersonaNoExiste.h"
#include "excepciones/excepcionPersonaInvalida.h"
#include "lectorPersonas.h"

using namespace std;

int main()
{

    LectorPersonas lector{"personas.dat"};

    //Se intenta abrir el archivo
    try
    {
        lector.abrirArchivo();
    }
    catch (const ExcepcionNoSePuedeAbrirArchivo excepcion)
    {
        std::cerr << "Error leyendo el archivo. " << excepcion.what() << '\n';
        return -1;
    }

    //Leer las personas en una posición
    try
    {
        Persona persona = lector.leerPersonaPosicion(14);

        //Imprime información de la persona
        std::cout << persona.obtenerId() << " :: ";
        std::cout << persona.obtenerNombre() << " :: ";
        std::cout << persona.obtenerApellido() << " :: ";
        std::cout << persona.obtenerCorreo() << std::endl;
    }
    catch (const ExcepcionPersonaNoExiste excepcion)
    {
        std::cerr << "Error leyendo la persona en la posición especificada. \n"
                  << excepcion.what() << '\n';
        return -1;
    }
    catch (const ExcepcionPersonaInvalida excepcion)
    {
        std::cerr << "Error leyendo la persona en la posición especificada. \n"
                  << excepcion.what() << '\n';
        return -1;
    }

    //Se cierra el archivo
    lector.cerrar();
}


#endif
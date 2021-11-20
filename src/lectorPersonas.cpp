#include "lectorPersonas.h"
#include "excepciones/excepcionNoSePuedeAbrirArchivo.h"
#include "excepciones/excepcionPersonaNoExiste.h"
#include "excepciones/excepcionPersonaInvalida.h"

LectorPersonas::LectorPersonas(std::string nombreArchivo)
{
    this->nombreArchivo = nombreArchivo;
}

bool LectorPersonas::abrirArchivo()
{
    archivoEntrada.open(nombreArchivo, std::ios::in | std::ios::binary);

    if (!archivoEntrada.is_open())
    {
        throw ExcepcionNoSePuedeAbrirArchivo();
    }

    return archivoEntrada.is_open();
}

Persona LectorPersonas::leerPersonaPosicion(int posicion)
{
    
    Persona personaLeida;

    // Posición de la persona que se va a leer
    long posicionPersona = sizeof(Persona) * (posicion);

    archivoEntrada.seekg(0, std::ios::end);
    long tamanioArchivo = archivoEntrada.tellg();

    // ¿Vamos a caer afuera?
    if (posicionPersona > tamanioArchivo)
    {
        throw ExcepcionPersonaNoExiste();
    }

    archivoEntrada.seekg(posicionPersona);
    archivoEntrada.read((char *) &personaLeida, sizeof(Persona));

    // ¿La persona leída es válida?
    if (personaLeida.obtenerId() == 0)
    {
        throw ExcepcionPersonaInvalida();
    }

    return personaLeida;


}

bool LectorPersonas::cerrar()
{
    archivoEntrada.close();

    return !archivoEntrada.is_open();
}


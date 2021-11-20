#include "lectorPersonas.h"
#include "excepciones/excepcionNoSePuedeAbrirArchivo.h"
#include "excepciones/excepcionPersonaNoExiste.h"

LectorPersonas::LectorPersonas(std::string nombreArchivo)
{
    this->nombreArchivo = nombreArchivo;
}

void LectorPersonas::abrirArchivo()
{
    archivoEntrada.open(nombreArchivo, std::ios::in | std::ios::binary);

    if (!archivoEntrada.is_open())
    {
        throw ExcepcionNoSePuedeAbrirArchivo();
    }
}

Persona LectorPersonas::leerPersonaPosicion(int posicion)
{
    
    Persona personaLeida;

    // Posición de la persona que se va a leer
    long posicionPersona = sizeof(Persona) * (posicion);

    archivoEntrada.seekg(0, std::ios::end);
    long tamanioArchivo = archivoEntrada.tellg();

    // Vamos a caer afuera?
    if (posicionPersona > tamanioArchivo)
    {
        throw ExcepcionPersonaNoExiste();
    }

    archivoEntrada.seekg(posicionPersona);
    archivoEntrada.read((char *) &personaLeida, sizeof(Persona));

    return personaLeida;


}

void LectorPersonas::cerrar()
{
    archivoEntrada.close();
}


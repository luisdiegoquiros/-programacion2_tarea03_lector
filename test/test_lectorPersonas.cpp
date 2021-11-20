#include <gtest/gtest.h>
#include <string>

#include "../src/persona.h"
#include "../src/lectorPersonas.h"
#include "../src/escritorPersonas-ProgramaEscritor.h"
#include "../src/excepciones/excepcionNoSePuedeAbrirArchivo.h"
#include "../src/excepciones/excepcionPersonaNoExiste.h"
#include "../src/excepciones/excepcionPersonaInvalida.h"

using namespace std;

namespace
{
    TEST(LectorPersonas, Prueba_LeerPersonaPosicion)
    {
        //Se crean las personas
        Persona personaPruebaUno{11, "nombre01", "apellido01", "prueba01@prueba.com"};
        Persona personaPruebaDos{12, "nombre02", "apellido02", "prueba02@prueba.com"};
        Persona personaPruebaTres{13, "nombre03", "apellido03", "prueba03@prueba.com"};

        std::vector<Persona> personas;
        personas.push_back(personaPruebaUno);
        personas.push_back(personaPruebaDos);
        personas.push_back(personaPruebaTres);

        //Se escriben las personas
        EscritorPersonas escritor{"pruebaVariasPersonas.dat"};
        escritor.agregarVariasPersonas(personas);
        escritor.cerrar();

        // Leer persona en posición específica
        LectorPersonas lector{"pruebaVariasPersonas.dat"};
        lector.abrirArchivo();
        Persona personaLeida = lector.leerPersonaPosicion(1);
        lector.cerrar();

        EXPECT_EQ(personaLeida.obtenerId(), 12);
        EXPECT_EQ(personaLeida.obtenerNombre(), "nombre02");
        EXPECT_EQ(personaLeida.obtenerApellido(), "apellido02");
        EXPECT_EQ(personaLeida.obtenerCorreo(), "prueba02@prueba.com");
    }

    TEST(LectorPersonas, Prueba_ExcepcionNoSePuedeAbrirArchivo)
    {
        EXPECT_THROW(
            {
                LectorPersonas lector{"NO://no_existo.dat"};
                lector.abrirArchivo();
            },
            ExcepcionNoSePuedeAbrirArchivo);
    }

    TEST(LectorPersonas, Prueba_ExcepcionPersonaInvalida)
    {
        //Se crean las personas
        Persona personaPruebaUno{11, "nombre01", "apellido01", "prueba01@prueba.com"};
        Persona personaPruebaDos{0, "nombre02", "apellido02", "prueba02@prueba.com"};

        std::vector<Persona> personas;
        personas.push_back(personaPruebaUno);
        personas.push_back(personaPruebaDos);

        //Se escriben las personas
        EscritorPersonas escritor{"pruebaExcepcionPersonaInvalida.dat"};
        escritor.agregarVariasPersonas(personas);
        escritor.cerrar();

        // Leer persona en posición específica
        LectorPersonas lector{"pruebaExcepcionPersonaInvalida.dat"};
        lector.abrirArchivo();

        EXPECT_THROW(
            {
                Persona personaLeida = lector.leerPersonaPosicion(1);
                lector.cerrar();
            },
            ExcepcionPersonaInvalida);
    }

    TEST(LectorPersonas, Prueba_ExcepcionPersonaNoExiste)
    {
        //Se crean las personas
        Persona personaPruebaUno{11, "nombre01", "apellido01", "prueba01@prueba.com"};
        Persona personaPruebaDos{12, "nombre02", "apellido02", "prueba02@prueba.com"};

        std::vector<Persona> personas;
        personas.push_back(personaPruebaUno);
        personas.push_back(personaPruebaDos);

        //Se escriben las personas
        EscritorPersonas escritor{"pruebaExcepcionPersonaNoExiste.dat"};
        escritor.agregarVariasPersonas(personas);
        escritor.cerrar();

        // Leer persona en posición específica
        LectorPersonas lector{"pruebaExcepcionPersonaNoExiste.dat"};
        lector.abrirArchivo();

        EXPECT_THROW(
            {
                Persona personaLeida = lector.leerPersonaPosicion(25);
                lector.cerrar();
            },
            ExcepcionPersonaNoExiste);
    }

    TEST(LectorPersonas, Prueba_Cerrar)
    {
        LectorPersonas lector{"pruebaAbrirCerrar.dat"};
        lector.abrirArchivo();
        bool seCerroBien = lector.cerrar();

        EXPECT_EQ(seCerroBien, true);
    }

    TEST(LectorPersonas, Prueba_AbrirArchivo)
    {
        LectorPersonas lector{"pruebaAbrirCerrar.dat"};
        bool seAbrioBien = lector.abrirArchivo();
        lector.cerrar();

        EXPECT_EQ(seAbrioBien, true);
    }
}
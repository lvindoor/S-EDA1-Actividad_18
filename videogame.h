#ifndef VIDEOJGAME_H
#define VIDEOGAME_H

#include "civilizacion.h"
#include <vector>

class Videogame {

    std::string nombreUsuario;
    vector<Civilizacion> civilizaciones;

public:

    Videogame(); // constructor
    void agregarCivilizacion(const Civilizacion &c); // sobrecarga

    void mostrar();

    void insertar(const Civilizacion &c, size_t pos);
    size_t size();
    Civilizacion front();
    Civilizacion back();
    void inicializar(const Civilizacion &c, size_t n);
    void eliminar(const Civilizacion&);

    /* Ordenamientos */

    void ordenarNombre();
    void ordenarX();
    void ordenarY();
    void ordenarPuntuacion();

    Civilizacion* buscar(const Civilizacion &c);

    friend Videogame& operator<<(Videogame &v, const Civilizacion &c)
    {
        v.agregarCivilizacion(c);

        return v;
    }
};

#endif

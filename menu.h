#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>

#include "civilizacion.h"

#ifdef _WIN32
#define CLEAN_SCREEN "cls"
#else
#define CLEAN_SCREEN "clear"
#endif // _WIN32

/* Opciones Menu */
enum {
    AGREGAR_CIVILIZACION = 1,
    ELEGIR_CIVILIZACION,
    SALIR
};

/* Opciones Sub-Menu -> Elegir Civilizacion */
enum {
    AGREGAR_ALDEANO = 1,
    ELIMINAR_ALDEANO,
    CLASIFICAR_ALDEANO,
    BUSCAR_ALDEANO,
    MODIFICAR_ALDEANO,
    MOSTRAR_ALDEANOS,
    REGRESAR
};

/* Opciones Sub-Menu -> Agregar Aldeano */
enum {
    AGREGAR_ALDEANO_INICIO = 1,
    AGREGAR_ALDEANO_FINAL
};

/* Opciones Sub-Menu -> Eliminar Aldeano */
enum {
    ELIMINAR_ALDEANO_NOMBRE = 1,
    ELIMINAR_ALDEANO_SALUD,
    ELIMINAR_ALDEANO_EDAD
};

/* Opciones Sub-Menu -> Clasificar Aldeano */
enum {
    CLASIFICAR_ALDEANO_NOMBRE = 1,
    CLASIFICAR_ALDEANO_SALUD,
    CLASIFICAR_ALDEANO_EDAD
};

/* Opciones Sub-Menu -> Modificar */
enum {
    MODIFICAR_NOMBRE = 1,
    MODIFICAR_EDAD,
    MODIFICAR_SALUD
};

class Menu {
private:
    vector<Civilizacion> civilizaciones; // creamos la lista de vectores
    Civilizacion c; // creamos el objeto como aux
    Aldeano a; // creamos el objeto como aux
    size_t opc; // opcion menu
    bool continuarMenu; // bandera para continuar con el menu

    /* Metodos privados */
    void avanza(); // limpia pantalla
    void subMenu(Civilizacion &c); // submenu

public:
    Menu(); // constructor
    void correr(); // función del menu principal

};

#endif

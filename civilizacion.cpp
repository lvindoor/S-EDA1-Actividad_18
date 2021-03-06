#include "civilizacion.h"

/** Funciones **/

void Civilizacion::mostrar() {

    /* Imprimimos la clase */
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        cout << "\t" << *it << endl;
    }
}

/* Agregar */
void Civilizacion::agregarInicio(const Aldeano &a) {
    aldeanos.push_front(a);
}
void Civilizacion::agregarFinal(const Aldeano &a) {
    aldeanos.push_back(a);
}

/* Eliminar */
void Civilizacion::eliminarNombre(const string &nombre) {
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++) { // buscamos el nombre
        Aldeano &a = *it; // obtenemos la direccion

        if(nombre == a.getNombre()){ // ¿Nombre igual?
            aldeanos.erase(it); // borramos la direccion de memoria
            break;
        }
    }
}
bool comparador(const Aldeano &a) { // Funcion de funcion sin declarar -> eliminarEdad()
    return (a.getEdad() >= MAYOR_EDAD); // borramos de la lista si es mayo de 60
}
void Civilizacion::eliminarEdad() {
    aldeanos.remove_if(comparador); // borramos segun la comparacion
}
void Civilizacion::eliminarSalud(float salud) { // mandamos la salud a borrar
    aldeanos.remove_if([salud](const Aldeano &a){ return a.getSalud() < salud;}); // mandamos el filtro en funciona lambda
}

/* Ordenamientos */
void Civilizacion::ordenarNombre() {
    aldeanos.sort(); // funciona debido a la comparación lazy
}
void Civilizacion::ordenarEdad() {
    /* Ordenar = funcion lambda + atributo a ordenar descendente */
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getEdad() > a2.getEdad();});
}
void Civilizacion::ordenarSalud() {
    /* Ordenar = funcion lambda + atributo a ordenar descendente */
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getSalud() > a2.getSalud();});
}

/* Buscar */
Aldeano* Civilizacion::buscar(const string &nombre) {

    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++) { // buscamos el nombre
        Aldeano &a = *it; // obtenemos la direccion

        if(nombre == a.getNombre()){ // ¿Nombre igual?
            return &a; // retornamos la direccion del nodo encontrado
        }
    }
    return nullptr; // retornamos posicion nula si no encontro nada
}

/* Getters */

string Civilizacion::getNombre() const {
    return nombre;
}

int Civilizacion::getX() const {
    return x;
}

int Civilizacion::getY() const {
    return y;
}

float Civilizacion::getPuntuacion() const {
    return puntuacion;
}

/* Setters */

void Civilizacion::setNombre(const string &n) {
    nombre = n;
}

void Civilizacion::setX(const int &_x) {
    x = _x;
}

void Civilizacion::setY(const int &_y) {
    y = _y;
}

void Civilizacion::setPuntuacion(const float &p) {
    puntuacion = p;
}

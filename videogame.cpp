#include "videogame.h"
#include <fstream>
#include <algorithm>

Videogame::Videogame() { } // constructor

void Videogame::agregarCivilizacion(const Civilizacion &c) { // sobrecarga
    civilizaciones.push_back(c);
}

void Videogame::mostrar() {

    cout << left;
    cout << setw(20) << "\tNombre ";
    cout << setw(11) << "Posicion X";
    cout << setw(20) << "Posicion Y";
    cout << "Puntuacion";
    cout << endl;

    /* Imprimimos la clase */
    for (size_t i = 0; i < civilizaciones.size(); i++) {
        Civilizacion &c = civilizaciones[i];
        cout << "\t" << c;
    }
}

void Videogame::respaldar_tabla() {

    ofstream archivo("civilizaciones_tabla.txt");
    if (archivo.is_open()) {
        archivo << left;
        archivo << setw(20) << "\tNombre";
        archivo << setw(11) << "Posicion X";
        archivo << setw(20) << "Posicion Y";
        archivo << "Puntuacion";
        archivo << endl;
        for (size_t i = 0; i < civilizaciones.size(); i++) {
            Civilizacion &c = civilizaciones[i];
            archivo << c;
        }
    }
    archivo.close();
}
void Videogame::respaldar() {

    ofstream archivo("civilizaciones.txt");
    if (archivo.is_open()) {
        for (size_t i = 0; i < civilizaciones.size(); i++) {
            Civilizacion &c = civilizaciones[i];
            archivo << c.getNombre() << endl;
            archivo << c.getX() << endl;
            archivo << c.getY() << endl;
            archivo << c.getPuntuacion() << endl;
        }
    }
    archivo.close();
}

void Videogame::recuperar() {

    ifstream archivo("civilizaciones.txt");
    if (archivo.is_open()) {
        string temp;
        int x;
        int y;
        float puntuacion;
        Civilizacion c;

        while (true)
        {
            getline(archivo, temp); // nombre
            if (archivo.eof()) {
                break;
            }
            getline(archivo, temp); // nombre
            c.setNombre(temp);

            getline(archivo, temp);
            x = stoi(temp); // // string-to-int
            c.setX(x);

            getline(archivo, temp);
            y = stoi(temp); // // string-to-int
            c.setY(y);

            getline(archivo, temp); // fuerza
            puntuacion = stof(temp);  // string-to-float
            c.setPuntuacion(puntuacion);

            agregarCivilizacion(c);
        }

    }
    archivo.close();
}

void Videogame::insertar(const Civilizacion &c, size_t pos) {
    civilizaciones.insert(civilizaciones.begin()+pos, c);
}

size_t Videogame::size() {
    return civilizaciones.size(); // retorna tamaño de objeto
}

Civilizacion Videogame::front() {
    return civilizaciones.front(); // retorna el primer valor
}

Civilizacion Videogame::back() {
    return civilizaciones.back(); // retorna el ultimo valor
}

void Videogame::inicializar(const Civilizacion &c, size_t n) {
    civilizaciones = vector<Civilizacion>(n, c);
}

void Videogame::eliminar(const Civilizacion &c) {
    civilizaciones.erase(std::remove(civilizaciones.begin(), civilizaciones.end(), c), civilizaciones.end());
}

void Videogame::ordenarNombre() {
    sort(civilizaciones.begin(), civilizaciones.end());
}

void Videogame::ordenarX() {
    /* Ordenar = funcion lambda + atributo a ordenar */
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getX() < c2.getX();});
}

void Videogame::ordenarY() {
    /* Ordenar = funcion lambda + atributo a ordenar */
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion y1, Civilizacion y2){return y1.getY() < y2.getY();});
}

void Videogame::ordenarPuntuacion() {
    /* Ordenar = funcion lambda + atributo a ordenar */
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getPuntuacion() < c2.getPuntuacion();});
}


Civilizacion* Videogame::buscar(const Civilizacion &c) {
    // vector<Civilizacion>::iterator
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);

    if (it == civilizaciones.end()) {
        return nullptr;
    }
    else {
        return &(*it);
    }
}

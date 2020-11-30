#include "menu.h"

using namespace std;

Menu::Menu() { // inicializamos clase Menu
    opc = 0;
    continuarMenu = true;
}

void Menu::correr() {
    do {
        cout << endl;
        cout << "\t--------------------------------------------" << endl;
        cout << "\t                  MENU                      " << endl;
        cout << "\t--------------------------------------------" << endl << endl;
        cout << "\t1-. Agregar Civilizacion" << endl;
        cout << "\t2-. Elegir Civilizacion" << endl;
        cout << "\t3-. Salir" << endl;;
        cout << endl << "\topcion : ";
        cin >> opc; cin.ignore();

        if(opc!=SALIR) {
            cout << endl << "\tPresione entrar para continuar ..." << endl;
            cin.get();
            system(CLEAN_SCREEN);
            cout << endl << endl;
        }

        /* Evaluamos */
        switch(opc) {
            case AGREGAR_CIVILIZACION: {
                cin >> c; // pedimos datos y guardamos
                civilizaciones.push_back(c); // agregamos al arreglo
            }
            break;

            case ELEGIR_CIVILIZACION: {
                size_t opc; // opcion local
                cout << endl;
                cout << "\t--------------------------------------------" << endl;
                cout << "\t           ESCOGER CIVILIZACION             " << endl;
                cout << "\t--------------------------------------------" << endl << endl;
                if(civilizaciones.empty()) { // ¿Hay civilizaciones?
                    cout << "\t NO HAY CIVILIZACIONES" << endl;
                } else {
                    for(size_t i=0;i<civilizaciones.size();i++) { // iteramos con las civilizaciones
                        c = civilizaciones[i];
                        cout << "\t" << i+1 << ".- " << c.getNombre() << endl;
                    }
                    cout << "\t0.- Regresar" << endl; // opcion de return
                    cout << endl << "\topcion : ";
                    cin >> opc; cin.ignore();
                    /* Validamos que sea opcion valida */
                    if(opc > civilizaciones.size() or opc<0) {
                        cout << "\nOpcion invalida" << endl;
                    } else if(opc != 0) {
                        c = civilizaciones[--opc]; // accedemos a la posicion
                        avanza(); // limpiamos pantalla
                        subMenu(c); // mandamos al submenu
                    } else if(opc == 0) {
                        break; // cerramos el submenu
                    }
                }

            }
            break;

            case SALIR:
                continuarMenu = false;
                break;

            default: {
                cout << "\tOpcion Invalida" << endl;
            }
        }

        if(continuarMenu) {
            avanza();
        }

    } while(continuarMenu);
}

void Menu::subMenu(Civilizacion &c) {

    size_t opc = 0; // opcion menu - local
    bool continuarMenu = true; // bandera para continuar con el menu - local
    /* Variables temporales */
    string tempString;
    size_t tempInt;
    float tempFloat;

    do {
        cout << endl;
        cout << "\t--------------------------------------------" << endl;
        cout << "\t                  MENU                     " << endl;
        cout << "\t--------------------------------------------" << endl << endl;
        cout << "\t1-. Agregar Aldeano" << endl;
        cout << "\t2-. Eliminar Aldeano" << endl;
        cout << "\t3-. Clasificar Aldeanos" << endl;
        cout << "\t4-. Buscar Aldeano" << endl;
        cout << "\t5-. Modificar Aldeano" << endl;
        cout << "\t6-. Mostrar Aldeanos" << endl;
        cout << "\t7-. Regresar" << endl;
        cout << endl << "\topcion : ";
        cin >> opc; cin.ignore();

        if(opc!=REGRESAR or opc!=BUSCAR_ALDEANO) {
            avanza();
        }

        /* Evaluamos */
        switch(opc) {
            case AGREGAR_ALDEANO: {
                size_t opc; // opcion local
                cout << endl;
                cout << "\t--------------------------------------------" << endl;
                cout << "\t              AGREGAR ALDEANO               " << endl;
                cout << "\t--------------------------------------------" << endl << endl;
                cout << "\t1-. Agregar Inicio" << endl;
                cout << "\t2-. Agregar Final" << endl;
                cout << endl << "\topcion : ";
                cin >> opc; cin.ignore();
                cout << endl;
                cin >> a; cin.ignore(); // capturamos el aldeano

                /* Evaluamos */
                switch(opc) {
                    case AGREGAR_ALDEANO_INICIO:
                        c.agregarInicio(a); // insertamos al inicio
                        break;
                    case AGREGAR_ALDEANO_FINAL:
                        c.agregarFinal(a); // insertamos al final
                        break;
                    default:
                        cout << "\tOpcion Invalida" << endl;
                }
            }
            break;

            case ELIMINAR_ALDEANO: {
                size_t opc; // creamos una opcion para el submenu - local
                cout << endl;
                cout << "\t--------------------------------------------" << endl;
                cout << "\t            ELIMINAR ALDEANO                " << endl;
                cout << "\t--------------------------------------------" << endl << endl;
                cout << "\t1-. Nombre " << endl;
                cout << "\t2-. Edad     -> Mayor a 60" << endl;
                cout << "\t3-. Salud    -> Escoger" << endl << endl;
                cout << "\topcion : ";
                cin >> opc; cin.ignore();
                cout << endl << endl;
                /* Evaluamos */
                switch(opc) {
                    case ELIMINAR_ALDEANO_NOMBRE:
                        cout << "\tEscriba el nombre del aldeano a borrar..." << endl << endl;
                        cout << "\tNombre : ";
                        getline(cin,tempString); // pedimos el nombre
                        c.eliminarNombre(tempString); // eliminamos por nombre
                        break;
                    case ELIMINAR_ALDEANO_EDAD:
                        c.eliminarEdad(); // eliminamos por edad
                        break;
                    case ELIMINAR_ALDEANO_SALUD:
                        cout << "\tEscriba la salud promedio del aldeano a borrar..." << endl << endl;
                        cout << "\tSalud : ";
                        cin >> tempFloat; cin.ignore();
                        c.eliminarSalud(tempFloat); // eliminamos por salud
                        break;
                    default:
                        cout << "\tOpcion Invalida" << endl;
                }
            }
            break;

            case CLASIFICAR_ALDEANO: {
                size_t opc; // creamos una opcion para el submenu - local
                cout << endl;
                cout << "\t--------------------------------------------" << endl;
                cout << "\t               CLASIFICACIONES              " << endl;
                cout << "\t--------------------------------------------" << endl << endl;
                cout << "\t1-. Nombre   -> ascendente" << endl;
                cout << "\t2-. Edad     -> descendente" << endl;
                cout << "\t3-. Salud    -> descendente" << endl;
                cout << endl << "\topcion : ";
                cin >> opc; cin.ignore();
                /* Evaluamos */
                switch(opc) {
                    case CLASIFICAR_ALDEANO_NOMBRE:
                        c.ordenarNombre();
                        break;
                    case CLASIFICAR_ALDEANO_EDAD:
                        c.ordenarEdad();
                        break;
                    case CLASIFICAR_ALDEANO_SALUD:
                        c.ordenarSalud();
                        break;
                    default:
                        cout << "\tOpcion Invalida" << endl;
                }
            }
            break;

            case BUSCAR_ALDEANO: {
                Aldeano* busqueda;
                cout << "\tEscriba el nombre del aldeano a buscar..." << endl << endl;
                cout << "\tNombre : ";
                getline(cin,tempString); // pedimos la nombre
                busqueda = c.buscar(tempString); // agregamos al modelo
                cout << endl;
                if(busqueda == nullptr) {
                    cout << "\tNo encontrado" << endl;
                } else {
                    cout << "\t" << *busqueda << endl;
                }
            }
            break;

            case MODIFICAR_ALDEANO: {
                size_t opc; // creamos una opcion para el submenu - local
                Aldeano* busqueda;
                cout << endl;
                cout << "\t--------------------------------------------" << endl;
                cout << "\t            MODIFICAR ALDEANO               " << endl;
                cout << "\t--------------------------------------------" << endl << endl;
                cout << "\tEscriba el nombre del aldeano a buscar..." << endl << endl;
                cout << "\tNombre : ";
                getline(cin,tempString); // pedimos nombre
                busqueda = c.buscar(tempString); // agregamos al modelo
                cout << endl;
                if(busqueda == nullptr) {
                    cout << "\tNo encontrado" << endl;
                } else {
                    cout << "\t" << *busqueda << endl;
                    cout << "\tEscoga el campo a Modificar" << endl << endl;
                    cout << "\t1.- Nombre" << endl;
                    cout << "\t2.- Edad" << endl;
                    cout << "\t3.- Salud" << endl << endl;
                    cout << "\topcion : ";
                    cin >> opc; cin.ignore();
                    cout << endl;
                    avanza();
                    switch(opc) {
                        case MODIFICAR_NOMBRE:
                            cout << "\tNombre   : ";
                            getline(cin, tempString);
                            busqueda->setNombre(tempString);
                            break;
                        case MODIFICAR_EDAD:
                            cout << "\tEdad     : ";
                            cin >> tempInt;
                            busqueda->setEdad(tempInt);
                            break;
                        case MODIFICAR_SALUD:
                            cout << "\tSalud   : ";
                            cin >> tempFloat;
                            busqueda->setSalud(tempFloat);
                            break;
                        default:
                        cout << "\tOpcion Invalida" << endl;
                    }
                }
            }
            break;

            case MOSTRAR_ALDEANOS: {
                cout << endl;
                cout << "\t--------------------------------------------" << endl;
                cout << "\t           TODOS LOS ALDEANOS               " << endl;
                cout << "\t--------------------------------------------" << endl << endl;
                c.mostrar(); // mandamos los aldeanos de la civilizacion
            }
            break;

            case REGRESAR: {
                continuarMenu = false;
            }
            break;

            default: {
                cout << "\tOpcion Invalida" << endl;
            }
        }

        if(continuarMenu) {
            avanza();
        }

    } while(continuarMenu);
}

void Menu::avanza() { // Limpia pantalla y avanza
    cout << endl << "\tPresione entrar para continuar ..." << endl;
    cin.get();
    system(CLEAN_SCREEN);
    cout << endl << endl;
}

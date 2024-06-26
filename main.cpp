#include <iostream>
#include <string>
#include "Autoridades.h"
#include "Sistema.h"

using namespace std;

void mostrar_menu() {
    cout << "Seleccione el tipo de incidente:" << endl;
    cout << "1. Robo" << endl;
    cout << "2. Incendio" << endl;
    cout << "3. Herido" << endl;
    cout << "4. Buscar autoridades" << endl; // Nueva opción
    cout << "5. Salir" << endl;
    cout << "Ingrese una opción: ";
}

int main() {
    // Crear instancias de las autoridades
    Policia* policia = new Policia(101, "Centro", "Patrulla en el centro de la ciudad", 1234);
    Bombero* bombero = new Bombero(201, "Barrio X", "Apagando incendio en el barrio", 3);
    Paramedico* paramedico = new Paramedico(301, "Hospital Z", "Atendiendo emergencia médica", 456);
    Policia* policia2=new Policia(102,"Sur","Colonia Sur",2400);
    Bombero* bombero2=new Bombero(201,"Centro","Bajando gato de un arbol",2044);

    // Crear instancia del sistema
    Sistema sistema;

    // Agregar las autoridades al sistema
    sistema.agregar_autoridad(policia);
    sistema.agregar_autoridad(bombero);
    sistema.agregar_autoridad(paramedico);
    sistema.agregar_autoridad(policia2);
    sistema.agregar_autoridad(bombero2);
    

    // Mostrar registros de autoridades
    sistema.imprimir_autoridades();

    // Variables para la entrada del usuario
    string ubicacion, fecha, hora;
    int opcion;
    bool salir = false;

    while (!salir) {
        mostrar_menu();
        cin >> opcion;
        cin.ignore(); // Para ignorar el salto de línea

        switch (opcion) {
            case 1:
                cout << "Ingrese la ubicacion del incidente: ";
                getline(cin, ubicacion);
                cout << "Ingrese la fecha del incidente (dd/mm/yyyy): ";
                getline(cin, fecha);
                cout << "Ingrese la hora del incidente (hh:mm): ";
                getline(cin, hora);

                sistema.set_ubicacion_incidente(ubicacion);
                sistema.set_descripcion_incidente("Robo en un banco");
                sistema.set_fecha(fecha);
                sistema.set_hora(hora);

                sistema.registrar_historial();
                sistema.alertar_autoridades();
                sistema.evaluar_nivel();

                policia->atender_llamada();
                policia->encender_cirena();
                policia->investigar();

                sistema.finalizar_emergencia();
                break;

            case 2:
                cout << "Ingrese la ubicacion del incidente: ";
                getline(cin, ubicacion);
                cout << "Ingrese la fecha del incidente (dd/mm/yyyy): ";
                getline(cin, fecha);
                cout << "Ingrese la hora del incidente (hh:mm): ";
                getline(cin, hora);

                sistema.set_ubicacion_incidente(ubicacion);
                sistema.set_descripcion_incidente("Incendio en una casa");
                sistema.set_fecha(fecha);
                sistema.set_hora(hora);

                sistema.registrar_historial();
                sistema.alertar_autoridades();
                sistema.evaluar_nivel();

                bombero->atender_llamada();
                bombero->encender_cirena();
                bombero->apagar_fuego();

                sistema.finalizar_emergencia();
                break;

            case 3:
                cout << "Ingrese la ubicacion del incidente: ";
                getline(cin, ubicacion);
                cout << "Ingrese la fecha del incidente (dd/mm/yyyy): ";
                getline(cin, fecha);
                cout << "Ingrese la hora del incidente (hh:mm): ";
                getline(cin, hora);

                sistema.set_ubicacion_incidente(ubicacion);
                sistema.set_descripcion_incidente("Herido en la calle");
                sistema.set_fecha(fecha);
                sistema.set_hora(hora);

                sistema.registrar_historial();
                sistema.alertar_autoridades();
                sistema.evaluar_nivel();

                paramedico->atender_llamada();
                paramedico->encender_cirena();
                paramedico->atender_heridos();

                sistema.finalizar_emergencia();
                break;

            case 4:
                int buscar;
                cout << "Digite el número de autoridad a buscar: ";
                cin >> buscar;
                sistema.buscar_autoridad(buscar - 1); // Ajustar el índice para que coincida con el arreglo
                break;

            case 5:
                salir = true;
                break;

            default:
                cout << "Opción no válida. Por favor, intente de nuevo." << endl;
        }
    }

    // Liberar memoria
    delete policia;
    delete bombero;
    delete paramedico;

    return 0;
}

#ifndef SISTEMA_H
#define SISTEMA_H



#include <iostream>
#include <string>
#include "Autoridades.h"
using namespace std;


/*
Este es el sistema general es el que se 
va a encargar de la parte de crear las 
autoridades y de manejar el sistema 
para crear el sistema de agregar incidentes y agregar autoridades ademas de administrar el estatus.


*/
class Sistema{
private:
    Autoridades* autoridad[100]; // Array de punteros a Autoridades
    string ubicacion_incidente;
    string descripcion_incidente;
    string fecha;
    string hora;
    string nivel_gravedad; 
    string estatus;
    int n_autoridades;
		
public:
    Sistema() : n_autoridades(0), estatus("No iniciado") {} // Constructor por default 

    // Constructor 
    Sistema(string ubi_in, string des_in, string fec, string hor_in, string niv, string est)
        : ubicacion_incidente(ubi_in), descripcion_incidente(des_in), fecha(fec), hora(hor_in), nivel_gravedad(niv), estatus(est), n_autoridades(0) {}

    // Getters 
    string get_ubicacion_incidente() { return ubicacion_incidente; }
    string get_descripcion_incidente() { return descripcion_incidente; }
    string get_fecha() { return fecha; }
    string get_hora() { return hora; }
    string get_nivel_gravedad() { return nivel_gravedad; }
    string get_estatus() { return estatus; }
    int get_n_autoridades() { return n_autoridades; }
		
    // Setters
    void set_ubicacion_incidente(string ubi_in) { ubicacion_incidente = ubi_in; }
    void set_descripcion_incidente(string des_in) { descripcion_incidente = des_in; }
    void set_fecha(string fec) { fecha = fec; }
    void set_hora(string hor_in) { hora = hor_in; }
    void set_nivel_gravedad(string niv) { nivel_gravedad = niv; }
    void set_estatus(string est) { estatus = est; }
    void set_n_autoridades(int n_auto) { n_autoridades = n_auto; }
		
    // Funciones extras
    void alertar_autoridades() {
        cout << "Las autoridades han sido alertadas y van en camino a la ubicacion " << get_ubicacion_incidente() << endl;
        estatus = "En progreso"; // Actualizamos el estatus
    }

    void agregar_autoridades(Autoridades* nueva_autoridad) {
        if (n_autoridades < 100) {
            autoridad[n_autoridades] = nueva_autoridad;
            n_autoridades++;
        }
    }

    void registrar_historial() {
        cout << "Se ha registrado el incidente en " << get_ubicacion_incidente() << " el dia " << get_fecha() << " a la hora: " << get_hora() << " y el incidente es: " << get_descripcion_incidente() << endl;
    }

    void evaluar_nivel() {
        if (n_autoridades > 50) {
            nivel_gravedad = "Alto";
        } else {
            nivel_gravedad = "Bajo";
        }
        cout << "Nivel de gravedad: " << nivel_gravedad << endl; // Mostramos el nivel de gravedad
    }

    void finalizar_emergencia() {
        cout << "La emergencia ha finalizado con exito" << endl;
        estatus = "Finalizada"; // Actualizamos el estatus
        cout << "Estatus: " << estatus << endl; // Mostramos el estatus
    }
};

#endif

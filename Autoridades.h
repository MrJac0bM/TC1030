/*
Author:Jacob Espejel Guiza
Matricula:A01712021




EN ESTE CODIGO VAMOS A REALIZAR LAS DIFERNTES FUNCIONES Y CARACTERISTICAS:

-Diseñar una clase padre que se llame Autoridades que herede subclases como Paramedicos,Policia y bOMBEROS
-Implementar metodos virtuales para que pueda existir el polimorfismo entre ellas 
-Ademas se implementara tanto los atributos heredados como los propios de las claes
-Ademas de tener sobreescrituraccomo en este ejemplo:
atender_llamada y encender _cirena  y tener sobrecarga de constructores


*/
#ifndef AUTORIDADES_H
#define AUTORIDADES_H

#include <iostream>
#include <string>



using namespace std;



/*
La clase autoridad sera una clase abstracta ya que:
Etsa incluye metodos virtuales ya que sus subclases tendran los metodos virtuales que etiene la clase madre
*/
class Autoridades {
private:
    int n_brigadista;
    string lugar;
    string descripcion;
    bool cirena_encendida; 
public:
	Autoridades();
    Autoridades(int n_brig, string lug, string des, bool cir):n_brigadista(n_brig), lugar(lug), descripcion(des), cirena_encendida(cir) {}
    
    // Getters 
    int get_n_brigadista() { return n_brigadista; }
    string get_lugar() { return lugar; }
    string get_descripcion() { return descripcion; }
    bool get_cirena_encendida() { return cirena_encendida; }
    
    // Setters 
    void set_n_brigadista(int n_brig) { n_brigadista = n_brig; }
    void set_lugar(string lug) { lugar = lug; }
    void set_descripcion(string des) { descripcion = des; }
    void set_cirena_encendida(bool cir) { cirena_encendida = cir; }
    
    // Funciones adicionales virtuales puras
    virtual void atender_llamada() = 0;
    virtual bool encender_cirena() = 0;
};


class Policia: public Autoridades {
private:
    int n_insignia;
public:
	Policia();
    Policia(int n_brig, string lug, string des, int n_ins): Autoridades(n_brig, lug, des, false), n_insignia(n_ins) {}

    // Getters y setters heredados de la clase base Autoridades
    int get_n_brigadista() { return Autoridades::get_n_brigadista(); }
    string get_lugar() { return Autoridades::get_lugar(); }
    string get_descripcion() { return Autoridades::get_descripcion(); }
    bool get_cirena_encendida() { return Autoridades::get_cirena_encendida(); }
    void set_n_brigadista(int n_brig) { Autoridades::set_n_brigadista(n_brig); }
    void set_lugar(string lug) { Autoridades::set_lugar(lug); }
    void set_descripcion(string des) { Autoridades::set_descripcion(des); }
    void set_cirena_encendida(bool cir) { Autoridades::set_cirena_encendida(cir); }

    // Getter y setter específicos de Policia
    int get_n_insignia() { return n_insignia; }
    void set_n_insignia(int n_ins) { n_insignia = n_ins; }

    // Implementación del método virtual
    void atender_llamada() override {
        cout << "Atendiendo llamada como policía" << endl;
    }

    bool encender_cirena() override {
        set_cirena_encendida(true); 
        return true; 
    }

    // Nuevas funciones específicas de la clase Policia
    void investigar() {
        cout << "La policía está investigando el crimen" << endl;
    }

    void patrullar() {
        cout << "La policía está patrullando por " << get_lugar() << endl;
    }
};


class Bombero:public Autoridades{
	private:
	int n_carro;
	public:
	Bombero();
	Bombero(int n_brig, string lug, string des, int carr):Autoridades(n_brig,lug,des,false),n_carro(carr){}
		

    //Getter especificos clase Bombero 
    int get_n_carro(){return n_carro;}
    void set_n_carro(int carr){n_carro=carr;}
    
    //Implementacion funciones virutales puras 
    void atender_llamada() override {
        cout << "Atendiendo llamada como bombero" << endl;
    }

    bool encender_cirena() override {
        set_cirena_encendida(true); 
        return true; 
    }


    // Nuevas funciones específicas de la clase Policia
	void apagar_fuego(){
		cout<<"Los bomberos estan apagando el fuego en "<<get_lugar()<<endl;
	}   
};

class Paramedico:public Autoridades{
	private:
	int n_ambulancia;
	public:
	Paramedico();
	Paramedico(int n_brig, string lug, string des, int amb):Autoridades(n_brig,lug,des,false), n_ambulancia(amb){}
	

	//Geters y setter especificos de la clase Paramedicos 
	int get_n_ambulancia(){return n_ambulancia;}
	void set_n_ambulancia(int amb){n_ambulancia=amb;}
	
	// Implementacion funciones virtuales puras 
	void atender_llamada() override {
        cout << "Atendiendo llamada como paramedico" << endl;
    }

    bool encender_cirena() override {
        set_cirena_encendida(true); 
        return true; 
    }
    
    //Implementacion funcion especifica de paramedicos
    void atender_heridos(){
    	cout<<"Los paramedicos estan atendiendo a los heridos en"<<get_lugar()<<endl;
	}

};

#endif

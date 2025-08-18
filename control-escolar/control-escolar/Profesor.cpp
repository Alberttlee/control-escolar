#include <iostream>
#include "Profesor.h"
using namespace std;


void Profesor::registrarProfesor(int _idProfesor, Sexo _sexo, int _edad, const string _profesion, int _numeroCedula) {
	setIdProfesor(_idProfesor);
	sexo = _sexo;
	edad = _edad;
	profesion = _profesion;
	numeroCedula = _numeroCedula;
}

void Profesor::mostrarDatos() {
	cout << "ID Profesor: " << getIdProfesor() << endl;
	cout << "Nombre: " << nombre << endl;
	cout << "Apellido: " << apellido << endl;

	switch (sexo) {
		case MASCULINO: cout << "Sexo: Masculino" << endl; break;
		case FEMENINO: cout << "Sexo: Femenino" << endl; break;
		case OTRO: cout << "Sexo: Otro" << endl;; break;
		default: cout << "Sexo: Desconocido" << endl; break;
	}

	cout << "Edad: " << edad << endl;
	cout << "Profesion: " << profesion << endl;
	cout << "No. de Cedula profesional: " << numeroCedula << endl;
}

void Profesor::eliminarProfesor() {
	id = 0;
	nombre.clear();
	apellido.clear();
	edad = 0;
	profesion.clear();
	numeroCedula = 0;
	sexo = DESCONOCIDO;
	cout << "Profesor eliminado" << endl;
}
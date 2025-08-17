#include <iostream>
#include "Profesor.h"
using namespace std;

Profesor::Profesor() : idProfesor(0), nombre(""), apellido(""), edad(0), profesion(""), numeroCedula(0), sexo(DESCONOCIDO) {}

Profesor::~Profesor() {}

Profesor::Profesor(const std::string _nombre, const std::string _apellido) : Profesor() {
	this -> nombre = _nombre;
	this -> apellido = _apellido; ///agrege
}

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
	idProfesor = 0;
	nombre.clear();
	apellido.clear();
	edad = 0;
	profesion.clear();
	numeroCedula = 0;
	sexo = DESCONOCIDO;
	cout << "Profesor eliminado" << endl;
}
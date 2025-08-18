#include <iostream>
#include "Profesor.h"
using namespace std;


Profesor::Profesor() : Persona(), profesion(""), numeroCedula(0) {}

Profesor::Profesor(int _id, const string& _nombre, const string& _apellido,
                   Sexo _sexo, int _edad, const string& _profesion, int _numeroCedula)
    : Persona(_id, _nombre, _apellido, _sexo, _edad),
      profesion(_profesion), numeroCedula(_numeroCedula) {}

void Profesor::setProfesion(const string& _profesion) { 
	profesion = _profesion; 
}

const string& Profesor::getProfesion() const { 
	return profesion; 
}

void Profesor::setNumeroCedula(int _numeroCedula) { 
	numeroCedula = _numeroCedula; 
}

int Profesor::getNumeroCedula() const { 
	return numeroCedula; 
}


void Profesor::registrarProfesor(int _id, const string& _nombre, const string& _apellido,
								Sexo _sexo, int _edad, const string& _profesion, int _numeroCedula) {
	setId(_id);
	setNombre(_nombre);
	setApellido(_apellido);
	setSexo(_sexo);
	setEdad(_edad);
	profesion = _profesion;
	numeroCedula = _numeroCedula;
}

void Profesor::mostrarDatos(ostream& out) const {
	cout << "\n=== Profesor ===" << endl;
	Persona::mostrarDatos(); // Llama al método de la clase base
	cout << "Profesion: " << profesion << endl;
	cout << "No. de Cedula profesional: " << numeroCedula << endl;
}

void Profesor::eliminarProfesor() {
	setId(0);
	setNombre("");
	setApellido("");
	setEdad(0);
	setSexo(Sexo::OTRO);
	profesion.clear();
	numeroCedula = 0;
	cout << "Profesor eliminado" << endl;
}
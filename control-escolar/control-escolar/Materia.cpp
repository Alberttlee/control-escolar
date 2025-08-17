#include <iostream>
#include "Materia.h"

using namespace std;

Materia::Materia() : idMateria(0), nombre(""), numeroCreditos(0), profesor() {}

Materia::Materia(const string& _nombre) : idMateria(0), numeroCreditos(0), nombre(_nombre) {}

Materia::~Materia() {}

void Materia::registrarMateria(int _idMateria, float _numeroCreditos, const Profesor& _profesor) {
	this -> idMateria = _idMateria;
	this -> numeroCreditos = _numeroCreditos;
	this -> profesor = _profesor;
}

void Materia::mostrarDatos() {
	cout << "ID Materia: " << getIdMateria() << endl;
	cout << "Nombre de materia: " << nombre << endl;
	cout << "Numero de creditos: " << numeroCreditos << endl;
	cout << "Profesor: " << profesor.getNombre() << endl;
}

void Materia::eliminarMateria() {
	idMateria = 0;
	nombre = "";
	numeroCreditos = 0;
	profesor = Profesor(); // Resetea el profesor a un objeto por defecto
}
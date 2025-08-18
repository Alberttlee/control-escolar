#include <iostream>
#include "Materia.h"

using namespace std;

Materia::Materia() : idMateria(0), nombre(""), numeroCreditos(0.0f), profesor() {}

Materia::Materia(const string& _nombre) : idMateria(0), nombre(_nombre), numeroCreditos(0.0f), profesor() {}

int Materia::getIdMateria() const {
	return idMateria;
}

std::string Materia::getNombreMateria() const {
	return nombre;
}

void Materia::registrarMateria(int _idMateria, float _numeroCreditos, const Profesor& _profesor) {
	idMateria = _idMateria;
	numeroCreditos = _numeroCreditos;
	profesor = _profesor;
}

void Materia::mostrarDatos(ostream& out) const {
	out << "\n=== Materia ===" << endl;
	out << "ID: " << idMateria << endl;
	out << "Nombre: " << nombre << endl;
	out << "Creditos: " << numeroCreditos << endl;
	out << "Profesor: " << profesor.getNombreCompleto() << endl;
}


void Materia::eliminarMateria() {
	idMateria = 0;
	nombre = "";
	numeroCreditos = 0;
	profesor = Profesor(); // Resetea el profesor a un objeto por defecto
}
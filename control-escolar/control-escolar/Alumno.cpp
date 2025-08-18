#include <iostream>
#include "Alumno.h"
using namespace std;

Alumno::Alumno() : Persona(), numeroDeControlEscolar(0), semestre(0), materias() {}

Alumno::Alumno(int _id, const string& _nombre, const string& _apellido,
				Sexo _sexo, int _edad, int _numeroDeControlEscolar, int _semestre,
				const list<Materia>& _materias)
	: Persona(_id, _nombre, _apellido, _sexo, _edad),
	numeroDeControlEscolar(_numeroDeControlEscolar), semestre(_semestre), materias(_materias) {
}

int Alumno::getNumeroDeControlEscolar() const { 
	return numeroDeControlEscolar; 
}

int Alumno::getSemestre() const { 
	return semestre; 
}

const list<Materia>& Alumno::getMaterias() const { 
	return materias; 
}

void Alumno::registrarInformacion(int _id, const string& _nombre, const string& _apellido,
									Sexo _sexo, int _edad, int _numeroDeControlEscolar,
									int _semestre, const list<Materia>& _materias) {
	setId(_id);
	setNombre(_nombre);
	setApellido(_apellido);
	setSexo(_sexo);
	setEdad(_edad);
	numeroDeControlEscolar = _numeroDeControlEscolar;
	semestre = _semestre;
	materias = _materias;
}

void Alumno::mostrarDatos(ostream& out) const {
	out << "\n=== Alumno ===" << endl;
	Persona::mostrarDatos(out);
	out << "Numero de control escolar: " << numeroDeControlEscolar << endl;
	out << "Semestre: " << semestre << endl;
	out << "Materias inscritas: " << materias.size() << endl;
}

void Alumno::eliminarInformacion() {
	setId(0);
	setNombre("");
	setApellido("");
	setEdad(0);
	setSexo(Sexo::OTRO);
	numeroDeControlEscolar = 0;
	semestre = 0;
	materias.clear();
	cout << "Informacion del alumno eliminada" << endl;
}
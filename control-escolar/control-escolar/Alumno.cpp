#include <iostream>
#include "Alumno.h"
using namespace std;

Alumno::Alumno() :idAlumno(0), numeroDeControlEscolar(0), edad(0), semestre(0), materias({}), sexo(OTRO) {}

Alumno::~Alumno() {}

Alumno::Alumno(const string& _nombre, const string& _apellido) :Alumno() {
	this -> nombre = _nombre;
	this -> apellido = _apellido; ///agrege
}

void Alumno::registrarInformacion(int _idAlumno, int _numeroDeControlEscolar, int _edad, Sexo _sexo, int _semestre, std::vector<Materia>& _materias) {
	setIdAlumno(_idAlumno);
	numeroDeControlEscolar = _numeroDeControlEscolar;
	edad = _edad;
	sexo = _sexo;
	semestre = _semestre;
	materias = _materias;
}

void Alumno::mostrarDatosAlumno() {
	cout << "ID Alumno : " << getIdAlumno() << endl;
	cout << "Nombre: " << getNombre() << endl;
	cout << "Apellido: " << getApellido() << endl;
	cout << "Edad: " << getEdad() << endl;
	switch (sexo) {
	case MASCULINO: cout << "Sexo: Masculino" << endl; break;
	case FEMENINO: cout << "Sexo: Femenino" << endl; break;
	case OTRO: cout << "Sexo: Otro" << endl; break;
	default: cout << "Sexo: Desconocido" << endl; break;
	}
	cout << "Semestre: " << getSemestre() << std::endl;
	cout << "Materias inscritas: " << materias.size() << std::endl;
}

void Alumno::eliminarInformacion() {
	nombre.clear();
	apellido.clear();
	edad = 0;
	sexo = OTRO;
	semestre = 0;
	materias.clear();
	cout << "Informacion del alumno eliminada" << endl;
}
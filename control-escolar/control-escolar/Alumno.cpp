#include <iostream>
#include "Alumno.h"
using namespace std;


void Alumno::registrarInformacion(int _idAlumno, int _numeroDeControlEscolar, int _edad, Sexo _sexo, int _semestre, std::list<Materia>& _materias) {
	setIdAlumno(_idAlumno);
	numeroDeControlEscolar = _numeroDeControlEscolar;
	this -> edad = _edad; // edad es un atributo de Persona
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
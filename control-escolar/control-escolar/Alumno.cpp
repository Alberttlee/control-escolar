#include <iostream>
#include "Alumno.h"
using namespace std;

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
	cout << "Nombre: " << nombre << endl;
	cout << "Apellido: " << apellido << endl;
	cout << "Edad: " << edad << endl;
	switch (sexo) {
	case MASCULINO: cout << "Sexo: Masculino" << endl; break;
	case FEMENINO: cout << "Sexo: Femenino"; break;
	case OTRO: cout << "Sexo: Otro"; break;
	default: cout << "Sexo: Desconocido"; break;
	}
	cout << endl;
	cout << "Semestre: " << semestre << std::endl;
	cout << "Materias inscritas: " << materias.size() << std::endl;
}

void Alumno::eliminarInformacion() {
	nombre = "";
	apellido = "";
	edad = 0;
	sexo = OTRO;
	semestre = 0;
	materias.clear();
}
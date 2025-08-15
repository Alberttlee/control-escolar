#pragma once
#include <vector>
#include <string>
#include "Materia.h" 


class Alumno {

	//Atributos
public:
	enum Sexo { MASCULINO, FEMENINO, OTRO };
private:
	int idAlumno; //aqui podria hacerce outoincremento, sea introducido manualmente, etc
	std::string nombre;
	std::string apellido;
	int numeroDeControlEscolar;
	int edad;
	int semestre;
	std::vector<Materia> materias;
	Sexo sexo = OTRO;


	//Constructores

public:
	Alumno() {
		idAlumno = 0;
		numeroDeControlEscolar = 0;
		edad = 0;
		semestre = 0;
		materias = {};
	}
	~Alumno() { //Destructor

	}

	Alumno(std::string _nombre, std::string _apellido) : Alumno() {  // Delegacion de constructores

		this->nombre = _nombre;
		this->apellido = _apellido;
	}

	//Metodos 
	void registrarInformacion(int _idAlumno, int _numeroDeControlEscolar, int _edad, Sexo _sexo, int _semestre, std::vector<Materia>& _materias);

	void mostrarDatosAlumno();

	void eliminarInformacion();

	void setIdAlumno(int _idAlumno) {
		idAlumno = _idAlumno;
	}

	int getIdAlumno() {
		return idAlumno;
	}

	std::string getNombre() const {
		return nombre;
	}

};

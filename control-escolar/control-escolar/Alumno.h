#ifndef ALUMNO_H
#define ALUMNO_H

#include <list>
#include <string>
#include "Materia.h" 
#include "Persona.h"


class Alumno : public Persona {

	//Atributos
public:
	enum Sexo { MASCULINO, FEMENINO, OTRO };

private:
	int numeroDeControlEscolar;
	int semestre;
	std::list<Materia> materias;
	Sexo sexo = OTRO;


	//Constructores
public:
	Alumno() : Persona(), numeroDeControlEscolar(0), semestre(0), materias({}), sexo(OTRO) {}

	~Alumno() {}; //Destructor

	Alumno(const std::string& _nombre, const std::string& _apellido) : Alumno() {
		this -> nombre = _nombre;
		this -> apellido = _apellido;
	}

	//Metodos 
	void registrarInformacion(int _idAlumno, int _numeroDeControlEscolar, int _edad, Sexo _sexo, int _semestre, std::list<Materia>& _materias);

	void mostrarDatosAlumno();

	void eliminarInformacion();

	void setIdAlumno(int _idAlumno) {
		this->id = _idAlumno;
	}

	int getIdAlumno() const {
		return id;
	}

	std::string getNombre() const {
		return nombre;
	}
	std::string getApellido() const {
		return apellido;
	}
	int getNumeroDeControlEscolar() const {
		return numeroDeControlEscolar;
	}
	int getEdad() const {
		return edad;
	}
	int getSemestre() const {
		return semestre;
	}
	std::list<Materia> getMaterias() const {
		return materias;
	}

	Sexo getSexo() const {
		return sexo;
	}
};

#endif // ALUMNO_H
#ifndef ALUMNO_H
#define ALUMNO_H

#include <vector>
#include <string>
#include "Materia.h" 


class Alumno {

	//Atributos
public:
	enum Sexo { MASCULINO, FEMENINO, OTRO };

private:
	int idAlumno; //aqui podria hacerce autoincremento, sea introducido manualmente, etc
	std::string nombre;
	std::string apellido;
	int numeroDeControlEscolar;
	int edad;
	int semestre;
	std::vector<Materia> materias;
	Sexo sexo = OTRO;


	//Constructores

public:
	Alumno();

	~Alumno(); //Destructor

	Alumno(const std::string& _nombre, const std::string& _apellido);

	//Metodos 
	void registrarInformacion(int _idAlumno, int _numeroDeControlEscolar, int _edad, Sexo _sexo, int _semestre, std::vector<Materia>& _materias);

	void mostrarDatosAlumno();

	void eliminarInformacion();

	void setIdAlumno(int _idAlumno) {
		this->idAlumno = _idAlumno;
	}

	int getIdAlumno() const {
		return idAlumno;
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
	std::vector<Materia> getMaterias() const {
		return materias;
	}
	Sexo getSexo() const {
		return sexo;
	}
};

#endif // ALUMNO_H
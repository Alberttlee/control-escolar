#pragma once

#include <string>
#include "Profesor.h"

class Materia {
	//Atributos
private:
	int idMateria;
	std::string nombre;
	float numeroCreditos;
	Profesor profesor;


public:


	Materia() : idMateria(0), nombre(""), numeroCreditos(0), profesor() {}

	Materia(const Materia& other) = default;
	Materia& operator=(const Materia& other) = default;

	Materia(std::string _nombre) : idMateria(0), numeroCreditos(0), nombre(_nombre) {}

	~Materia() {

	}

	//Metodos
	void registrarMateria(int _idMateria, float _numeroCreditos, const Profesor& _profesor);

	void mostrarDatos();

	void eliminarMateria();

	void setIdMateria(int _idMateria) {
		idMateria = _idMateria;
	}

	int getIdMateria() const {
		return idMateria;
	}

	std::string getNombreMateria() const {
		return nombre;
	}
};

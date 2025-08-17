#ifndef MATERIA_H
#define MATERIA_H

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

	Materia();

	Materia(const Materia& otro) = default;

	Materia& operator=(const Materia& otro) = default;

	Materia(const std::string& _nombre);

	~Materia();

	//Metodos
	void registrarMateria(int _idMateria, float _numeroCreditos, const Profesor& _profesor);

	void mostrarDatos();

	void eliminarMateria();

	void setIdMateria(int _idMateria) {
		this -> idMateria = _idMateria;
	}

	int getIdMateria() const {
		return this -> idMateria;
	}

	std::string getNombreMateria() const {
		return this -> nombre;
	}
};

#endif // MATERIA_H
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

	Materia(const std::string& _nombre);

	//Metodos
	void registrarMateria(int _idMateria, float _numeroCreditos, const Profesor& _profesor);

	void mostrarDatos(std::ostream& out = std::cout) const;

	void eliminarMateria();

	void setIdMateria(int _idMateria);

	int getIdMateria() const;

	std::string getNombreMateria() const;
};

#endif // MATERIA_H
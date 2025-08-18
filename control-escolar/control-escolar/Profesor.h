#ifndef PROFESOR_H
#define PROFESOR_H

#include "Persona.h" 

class Profesor : public Persona {

private:
	std::string profesion;
	int numeroCedula;

public:

	Profesor();

	Profesor(int _id, const std::string& _nombre, const std::string& _apellido,
		Sexo _sexo, int _edad, const std::string& _profesion, int _numeroCedula);

	//Getters and Setters
	void setProfesion(const std::string& _profesion);
	const std::string& getProfesion() const;

	void setNumeroCedula(int _numeroCedula);
	int getNumeroCedula() const;

	//Metodos
	void registrarProfesor(int _id, const std::string& _nombre, const std::string& _apellido,
		Sexo _sexo, int _edad, const std::string& _profesion, int _numeroCedula);

	void mostrarDatos(std::ostream& out = std::cout) const override;

	void eliminarProfesor();

};

#endif // PROFESOR_H

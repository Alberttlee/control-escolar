#ifndef PROFESOR_H
#define PROFESOR_H

#include <string>
#include "Persona.h" // Assuming Profesor inherits from Persona

class Profesor : public Persona {
//Atributos
public:
	enum Sexo { MASCULINO, FEMENINO, OTRO, DESCONOCIDO };

private:
	std::string profesion;
	int numeroCedula;
	Sexo sexo;

public:
	//Constructores
	Profesor() : Persona(), profesion(""), numeroCedula(0), sexo(DESCONOCIDO) {}

	Profesor(const Profesor& otro) = default;

	Profesor& operator=(const Profesor& otro) = default;

	Profesor(const std::string _nombre, const std::string _apellido) : Profesor(){
		this->nombre = _nombre;
		this->apellido = _apellido; // Agregado para inicializar apellido
	}

	~Profesor(){}

	//Metodos
	void registrarProfesor(int _idProfesor, Sexo _sexo, int _edad,const std::string _profesion, int _numeroCedula);

	void mostrarDatos();

	void eliminarProfesor();

	void setIdProfesor(int _idProfesor) {
		this -> id = _idProfesor;
	}

	int getIdProfesor()const{
		return this->id;
	}

	std::string getNombre() const {
		return this->nombre;
	}

	std::string getApellido() const {
		return this->apellido;
	}

	std::string getNombreCompleto() const {
		return nombre + " " + apellido;
	}

};

#endif // PROFESOR_H

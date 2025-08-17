#ifndef PROFESOR_H
#define PROFESOR_H

#include <string>

class Profesor {
//Atributos
public:
	enum Sexo { MASCULINO, FEMENINO, OTRO, DESCONOCIDO };

private:
	int idProfesor;
	std::string nombre;
	std::string apellido;
	int edad;
	std::string profesion;
	int numeroCedula;
	Sexo sexo;

public:
	//Constructores
	Profesor();

	Profesor(const Profesor& otro) = default;

	Profesor& operator=(const Profesor& otro) = default;

	Profesor(const std::string _nombre, const std::string _apellido);

	~Profesor(); // Destructor

	//Metodos
	void registrarProfesor(int _idProfesor, Sexo _sexo, int _edad,const std::string _profesion, int _numeroCedula);

	void mostrarDatos();

	void eliminarProfesor();

	void setIdProfesor(int _idProfesor) {
		idProfesor = _idProfesor;
	}

	int getIdProfesor() {
		return this->idProfesor;
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

#pragma once
#include <string>

class Profesor {
	//Atributos
public:
	enum Sexo { MASCULINO, FEMENINO, OTRO, DESCONOCIDO };
private:
	int idProfesor;  //aqui podria hacerce outoincremento, sea introducido manualmente, etc
	std::string nombre;
	std::string apellido;
	int edad;
	std::string profesion;
	int numeroCedula;
	Sexo sexo;

public:
	//Constructores
	Profesor() {
		idProfesor = 0;
		edad = 0;
		profesion = "";
		numeroCedula = 0;
		sexo = DESCONOCIDO;
	}

	Profesor(const Profesor& other) = default;
	Profesor& operator=(const Profesor& other) = default;

	Profesor(std::string _nombre, std::string _apellido) : Profesor() {
		this->nombre = _nombre;
		this->apellido = _apellido;
	}

	~Profesor() { //Destructor

	}

	//Metodos
	void registrarProfesor(int _idProfesor, Sexo _sexo, int _edad, std::string _profesion, int _numeroCedula);

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

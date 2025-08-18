#ifndef ALUMNO_H
#define ALUMNO_H

#include <list>
#include "Materia.h" 
#include "Persona.h"


class Alumno : public Persona {

	//Atributos
private:
	int numeroDeControlEscolar;
	int semestre;
	std::list<Materia> materias;

	//Constructores
public:
	Alumno();

	Alumno(int _id, const std::string& _nombre, const std::string& _apellido,
		Sexo _sexo, int _edad, int _numeroDeControlEscolar, int _semestre,
		const std::list<Materia>& _materias);

	int getNumeroDeControlEscolar() const;
	int getSemestre() const;
	const std::list<Materia>& getMaterias() const;

	//Metodos 
	void registrarInformacion(int _id, const std::string& _nombre, const std::string& _apellido,
		Sexo _sexo, int _edad, int _numeroDeControlEscolar,
		int _semestre, const std::list<Materia>& _materias);

	void mostrarDatos(std::ostream& out = std::cout) const override;

	void eliminarInformacion();
};

#endif // ALUMNO_H
#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>

enum Sexo { MASCULINO, FEMENINO, OTRO };

class Persona {
protected:
    int id;
    std::string nombre;
    std::string apellido;
    Sexo sexo;
    int edad;

public:
    Persona();

    Persona(int _id, const std::string& _nombre, const std::string& _apellido, Sexo sexo, int _edad);
    
	//Getters and Setters
    void setId(int _id);
    int getId() const;

    void setNombre(const std::string& _nombre);
    const std::string& getNombre() const;

    void setApellido(const std::string& _apellido);
    const std::string& getApellido() const;

    void setSexo(Sexo _sexo);
    Sexo getSexo() const;

    void setEdad(int _edad);
    int getEdad() const;

    std::string getNombreCompleto() const;

	virtual void mostrarDatos(std::ostream& out = std::cout) const;
};

#endif // PERSONA_H
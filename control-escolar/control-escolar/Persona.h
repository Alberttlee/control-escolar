#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona {
protected:
    int id;
    std::string nombre;
    std::string apellido;
    int edad;

public:
    Persona() : id(0), nombre(""), apellido(""), edad(0) {}

    Persona(int _id, const std::string& _nombre, const std::string& _apellido, int _edad)
        : id(_id), nombre(_nombre), apellido(_apellido), edad(_edad) {
    }
    virtual ~Persona() = default;


    int getId() const { return id; }

    const std::string& getNombre() const { return nombre; }

    const std::string& getApellido() const { return apellido; }

    int getEdad() const { return edad; }
};

#endif // PERSONA_H
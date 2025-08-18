#include "Persona.h"
#include <iostream>
using namespace std;

Persona::Persona() : id(0), nombre(""), apellido(""), sexo(Sexo::OTRO), edad(0) {}

Persona::Persona(int _id, const string& _nombre, const string& _apellido, Sexo _sexo, int _edad)
    : id(_id), nombre(_nombre), apellido(_apellido), sexo(_sexo), edad(_edad) {
}

void Persona::setId(int _id) { id = _id; }
int Persona::getId() const { return id; }

void Persona::setNombre(const string& _nombre) { nombre = _nombre; }
const string& Persona::getNombre() const { return nombre; }

void Persona::setApellido(const string& _apellido) { apellido = _apellido; }
const string& Persona::getApellido() const { return apellido; }

void Persona::setSexo(Sexo _sexo) { sexo = _sexo; }
Sexo Persona::getSexo() const { return sexo; }

void Persona::setEdad(int _edad) { edad = _edad; }
int Persona::getEdad() const { return edad; }

string Persona::getNombreCompleto() const {
    return nombre + " " + apellido;
}

void Persona::mostrarDatos(ostream& aut) const {
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << " " << apellido << endl;
    cout << "Edad: " << edad << endl;
    switch (sexo) {
        case MASCULINO: cout << "Sexo: Masculino" << endl; break;
        case FEMENINO: cout << "Sexo: Femenino" << endl; break;
        case OTRO: cout << "Sexo: Otro" << endl; break;
    default: cout << "Sexo: Desconocido" << endl; break;
    }
}

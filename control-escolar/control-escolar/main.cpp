#include <iostream>
#include <vector>
#include "Alumno.h"
#include "Profesor.h"
#include "Materia.h"
using namespace std;



int main() {
    vector<Profesor> profesores;
    vector<Materia> materias;
    vector<Alumno> alumnos;


    // 1. Captura de Profesores
    cout << "Captura de 2 profesores:" << endl;
    for (int i = 0; i < 2; ++i) {
        string nombre, apellido, profesion;
        int id, edad, cedula, sexoInt;
        Profesor::Sexo sexo;

        cout << "Profesor #" << (i + 1) << endl;
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Apellido: ";
        cin >> apellido;
        cout << "ID: ";
        cin >> id;
        cout << "Sexo (0: MASCULINO, 1: FEMENINO, 2: OTRO, 3: DESCONOCIDO): ";
        cin >> sexoInt;
        sexo = static_cast<Profesor::Sexo>(sexoInt);
        cout << "Edad: ";
        cin >> edad;
        cout << "Profesion: ";
        cin.ignore();
        getline(cin, profesion);
        cout << "Numero de cedula: ";
        cin >> cedula;

        Profesor prof(nombre, apellido);
        prof.registrarProfesor(id, sexo, edad, profesion, cedula);
        profesores.push_back(prof);
        cout << endl;
    }
    system("cls"); // Limpiar pantalla para mejor visualización

    // 2. Captura de Materias
    cout << "\nCaptura de 3 materias:" << endl;
    for (int i = 0; i < 3; ++i) {
        string nombreMateria;
        int idMateria, idProfesor;
        float creditos;

        cout << "Materia #" << (i + 1) << endl;
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, nombreMateria);
        cout << "ID de la materia: ";
        cin >> idMateria;
        cout << "Creditos: ";
        cin >> creditos;

        // Mostrar profesores disponibles
        cout << "  Profesores disponibles:" << endl;
        for (size_t j = 0; j < profesores.size(); ++j) {
            cout << " Profesor: " << profesores[j].getNombreCompleto() << "  ID: " << profesores[j].getIdProfesor() << endl;
        }
        cout << "\nInserte el ID del profesor responsable que sera asignado: ";
        cin >> idProfesor;

        // Buscar profesor por ID
        Profesor* profPtr = nullptr;
        for (auto& prof : profesores) {
            if (prof.getIdProfesor() == idProfesor) {
                profPtr = &prof;
                break;
            }
        }
        if (!profPtr) {
            cout << "Profesor no encontrado. Se asigna el primero por defecto." << endl;
            profPtr = &profesores[0];
        }

        Materia mat(nombreMateria);
        mat.registrarMateria(idMateria, creditos, *profPtr);
        materias.push_back(mat);
        cout << endl;

    }

    system("cls"); // Limpiar pantalla para mejor visualización

    // 3. Captura de Alumnos
    cout << "Captura de 2 alumnos:" << endl;
    for (int i = 0; i < 2; ++i) {
        string nombre, apellido;
        int idAlumno, numControl, edad, sexoInt, semestre, numMaterias;
        Alumno::Sexo sexo;

        cout << "Alumno #" << (i + 1) << endl;
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Apellido: ";
        cin >> apellido;
        cout << "ID: ";
        cin >> idAlumno;
        cout << "Numero de control escolar: ";
        cin >> numControl;
        cout << "Edad: ";
        cin >> edad;
        cout << "Sexo (0: MASCULINO, 1: FEMENINO, 2: OTRO): ";
        cin >> sexoInt;
        sexo = static_cast<Alumno::Sexo>(sexoInt);
        cout << "Semestre: ";
        cin >> semestre;

        // Selección de materias
        cout << "Materias disponibles:" << endl;
        for (size_t j = 0; j < materias.size(); ++j) {
            cout << "ID: " << materias[j].getIdMateria() << ": " << materias[j].getNombreMateria() << endl;
        }
        cout << "¿Cuantas materias cursa este alumno? ";
        cin >> numMaterias;
        vector<Materia> materiasAlumno;
        for (int m = 0; m < numMaterias; ++m) {
            int idMat;
            cout << "ID de la materia #" << (m + 1) << ": ";
            cin >> idMat;
            bool found = false;
            for (auto& mat : materias) {
                if (mat.getIdMateria() == idMat) {
                    materiasAlumno.push_back(mat);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Materia no encontrada, se omite." << endl;
            }
        }

        Alumno alum(nombre, apellido);
        alum.registrarInformacion(idAlumno, numControl, edad, sexo, semestre, materiasAlumno);
        alumnos.push_back(alum);
        cout << endl;
    }

    system("cls"); // Limpiar pantalla para mejor visualización

    //					INTERFAZ DE USUARIO	

    int opcion;

    cout << "\nDesea Visualizar:" << endl;
    cout << "\n1. Profesor" << endl;
    cout << "2. Materia" << endl;
    cout << "3. Alumno" << endl;

    cin >> opcion;

    int id;

    bool encontrado = false;

    switch (opcion) {
    case 1: // Profesor
        cout << "Ingrese el ID del profesor: ";
        cin >> id;
        for (auto& prof : profesores) {
            if (prof.getIdProfesor() == id) {
                prof.mostrarDatos();
                encontrado = true;
                break;
            }
        }
        if (!encontrado) cout << "Profesor no encontrado.\n";
        break;
    case 2: // Materia
        cout << "Ingrese el ID de la materia: ";
        cin >> id;
        for (auto& mat : materias) {
            if (mat.getIdMateria() == id) {
                mat.mostrarDatos();
                encontrado = true;
                break;
            }
        }
        if (!encontrado) cout << "Materia no encontrada.\n";
        break;
    case 3: // Alumno
        cout << "Ingrese el ID del Alumno: ";
        cin >> id;
        for (Alumno& alum : alumnos) {
            if (alum.getIdAlumno() == id) {
                alum.mostrarDatosAlumno();
                encontrado = true;
                break;
            }
        }
        if (!encontrado) cout << "Profesor no encontrado.\n";
        break;
    default:
        cout << "Opcion invalida.\n";
        break;
    }

    if (!encontrado) {
        cout << "No se encontro el registro con ese ID.\n";

    }

    system("pause");

    return 0;
}
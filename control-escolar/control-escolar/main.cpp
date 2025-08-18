#include <iostream>
#include <list>

#include "Alumno.h"
#include "Profesor.h"
#include "Materia.h"

using namespace std;

#ifdef _WIN32
void limpiarPantalla() { system("cls"); }
void pausarPantalla() { system("pause"); }
#else
void limpiarPantalla() { system("clear"); }
void pausarPantalla() { cin.get(); }
#endif

int main() {

    list<Profesor> profesores;
    list<Materia> materias;
    list<Alumno> alumnos;


    //Captura de 3 Profesores
    cout << "Captura de 3 profesores:\n" << endl;
    for (int i = 0; i < 3; ++i) {
        string nombre, apellido, profesion;
        int id, edad, cedula, sexoInt;
        Sexo sexo;

        cout << "Profesor #" << (i + 1) << endl;
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Apellido: ";
        cin >> apellido;
        cout << "ID: ";
        cin >> id;
        cout << "Sexo (0: MASCULINO, 1: FEMENINO, 2: OTRO, 3: DESCONOCIDO): ";
        cin >> sexoInt;
        sexo = static_cast<Sexo>(sexoInt);
        cout << "Edad: ";
        cin >> edad;
        cout << "Profesion: ";
        cin.ignore();
        getline(cin, profesion);
        cout << "Numero de cedula: ";
        cin >> cedula;

        Profesor prof;
        prof.registrarProfesor(id, nombre, apellido, sexo, edad, profesion, cedula);
        profesores.push_back(prof);
        cout << endl;
    }
    limpiarPantalla();

    //Captura de 4 Materias
    cout << "\nCaptura de 4 materias:\n" << endl;
    for (int i = 0; i < 4; ++i) {
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
        cout << "\n  Profesores disponibles:" << endl;
        for (const auto& p : profesores) {
            cout << "  ID: " << p.getId() << "  Profesor: " << p.getNombreCompleto() << endl;
        }
        cout << "\nInserte el ID del profesor responsable que sera asignado: ";
        cin >> idProfesor;

        // Buscar profesor por ID
        const Profesor* profPtr = nullptr;
        for (const auto& p : profesores) {
            if (p.getId() == idProfesor) {
                profPtr = &p;
                break;
            }
        }
        if (!profPtr) {
            cout << "Profesor no encontrado. Se asignara el primero por defecto." << endl;
            profPtr = &(*profesores.begin());
        }

        Materia mat(nombreMateria);
        mat.registrarMateria(idMateria, creditos, *profPtr);
        materias.push_back(mat);
        cout << endl;

    }

    limpiarPantalla();

    // Captura de 3 Alumnos
    cout << "Captura de 3 alumnos:\n" << endl;
    for (int i = 0; i < 3; ++i) {
        string nombre, apellido;
        int idAlumno, numControl, edad, sexoInt, semestre, numMaterias;
        Sexo sexo;

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
        sexo = static_cast<Sexo>(sexoInt);
        cout << "Semestre: ";
        cin >> semestre;

        // Selección de materias
        cout << "\nMaterias disponibles:" << endl;
        for (const auto& m : materias) {
            cout << "ID: " << m.getIdMateria() << ": " << m.getNombreMateria() << endl;
        }
        cout << "\nCuantas materias cursa este alumno? ";
        cin >> numMaterias;

        list<Materia> materiasAlumno;
        for (int m = 0; m < numMaterias; ++m) {
            int idMat;
            cout << "ID de la materia #" << (m + 1) << ": ";
            cin >> idMat;
            bool encontrado = false;
            for (const auto& mat : materias) {
                if (mat.getIdMateria() == idMat) {
                    materiasAlumno.push_back(mat);
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Materia no encontrada, se omite." << endl;
            }
        }

        Alumno alum;
        alum.registrarInformacion(idAlumno, nombre, apellido, sexo, edad, numControl, semestre, materiasAlumno);
        alumnos.push_back(alum);
        cout << endl;
    }


    //  INTERFAZ DE USUARIO	
    int opcion;
	bool salir = false;

    while (!salir) {
        limpiarPantalla();

        cout << "\nDesea Visualizar:" << endl;
        cout << "\n1. Profesor" << endl;
        cout << "2. Materia" << endl;
        cout << "3. Alumno" << endl;
		cout << "4. Salir" << endl;
        cout << "\nElige una opcion [1-4]: ";

        cin >> opcion;

        int id;

        bool encontrado = false;

        switch (opcion) {
        case 1: // Profesor
            cout << "Ingrese el ID del profesor: ";
            cin >> id;
            for (const auto& prof : profesores) {
                if (prof.getId() == id) {
                    prof.mostrarDatos();
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) cout << "Profesor no encontrado\n";
            break;
        case 2: // Materia
            cout << "Ingrese el ID de la materia: ";
            cin >> id;
            for (const auto& mat : materias) {
                if (mat.getIdMateria() == id) {
                    mat.mostrarDatos();
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) cout << "Materia no encontrada\n";
            break;
        case 3: // Alumno
            cout << "Ingrese el ID del Alumno: ";
            cin >> id;
            for (const auto& alum : alumnos) {
                if (alum.getId() == id) {
                    alum.mostrarDatos();
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) cout << "Alumno no encontrado\n";
            break;
        case 4: // Salir
            cout << "\nSaliendo del programa...\n";
            salir = true;
            break;
        default:
            cout << "Opcion invalida.\n";
            break;
        }

        if (!salir) {
            pausarPantalla();
        }
    }

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

const int MAX_ALUMNOS = 100;

struct Alumno {
    int    id;        // antes: ID
    string nom;       // antes: nombre
    int    edad;      // igual
    float  prom;      // antes: promedio
};

struct Materia {
    string nomMat;                 // antes: nombre
    Alumno lista[MAX_ALUMNOS];     // antes: alumnos
    int    cantidad;               // antes: numAlumnos
};

void insertarAlumno(Materia& mater, Alumno nuevo){
    if (mater.cantidad < MAX_ALUMNOS){
        mater.lista[mater.cantidad] = nuevo;
        mater.cantidad++;
        cout << "Alumno insertado exitosamente." << endl;
    } else {
        cout << "No se puede insertar: arreglo lleno." << endl;
    }
}

void eliminarAlumno(Materia& mater, int idBuscado) {
    bool hallado = false;
    for (int k = 0; k < mater.cantidad; k++) {
        if (mater.lista[k].id == idBuscado) {
            hallado = true;
            for (int m = k; m < mater.cantidad - 1; m++) {
                mater.lista[m] = mater.lista[m + 1];
            }
            mater.cantidad--;
            cout << "Alumno eliminado exitosamente." << endl;
            break;
        }
    }
    if (!hallado) {
        cout << "Alumno con ID " << idBuscado << " no encontrado." << endl;
    }
}

void mostrarAlumnos(Alumno lista[], int pos, int cant) {
    if (pos >= cant) {
        return;
    }
    cout << "ID: " << lista[pos].id;
    cout << ", Nombre: " << lista[pos].nom;
    cout << ", Edad: " << lista[pos].edad;
    cout << ", Promedio: " << lista[pos].prom << endl;
    mostrarAlumnos(lista, pos + 1, cant); // siguiente alumno
}

int main() {
    Materia curso;
    curso.nomMat = "Matemáticas";
    curso.cantidad = 0;

    Alumno e1 = {1, "Juan Perez", 20, 8.5f};
    Alumno e2 = {2, "Maria Lopez", 22, 9.0f};
    Alumno e3 = {3, "Carlos Ruiz", 21, 7.8f};

    insertarAlumno(curso, e1);
    insertarAlumno(curso, e2);
    insertarAlumno(curso, e3);

    cout << "Alumnos en " << curso.nomMat << ":" << endl;
    mostrarAlumnos(curso.lista, 0, curso.cantidad);

    eliminarAlumno(curso, 2);

    cout << "Alumnos después de eliminar:" << endl;
    mostrarAlumnos(curso.lista, 0, curso.cantidad);

    return 0;
}

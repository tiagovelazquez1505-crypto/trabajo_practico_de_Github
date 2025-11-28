#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

struct Alumno {
    int    id;
    string nombre;
    int    edad;
    float  nota;
};

void insertarAlumno(Alumno lista[], int &cant, const Alumno &nuevo){
    if (cant >= MAX){
        cout << "Arreglo lleno. No se puede insertar.\n";
        return;
    }
    lista[cant] = nuevo;
    cant++;
}


void eliminarAlumno(Alumno lista[], int &cant, int idBuscado){
    int pos = -1;
    for (int i = 0; i < cant; i++){
        if (lista[i].id == idBuscado){
            pos = i;
            break;
        }
    }
    if (pos == -1){
        cout << "No existe un alumno con id " << idBuscado << ".\n";
        return;
    }
    for (int i = pos; i < cant - 1; i++){
        lista[i] = lista[i + 1];
    }
    cant--;
    cout << "Alumno con id " << idBuscado << " eliminado.\n";
}


void mostrar(const Alumno lista[], int cant){
    if (cant == 0){
        cout << "No hay alumnos.\n";
        return;
    }
    for (int i = 0; i < cant; i++){
        cout << "ID: " << lista[i].id
             << " | Nombre: " << lista[i].nombre
             << " | Edad: " << lista[i].edad
             << " | Nota: " << lista[i].nota << "\n";
    }
}

int main(){
    Alumno alumnos[MAX];
    int cant = 0;


    Alumno a1{1, "Ana", 18, 8.5f};
    Alumno a2{2, "Luis", 19, 7.0f};
    Alumno a3{3, "Marta", 20, 9.2f};

    insertarAlumno(alumnos, cant, a1);
    insertarAlumno(alumnos, cant, a2);
    insertarAlumno(alumnos, cant, a3);

    cout << "Lista inicial:\n";
    mostrar(alumnos, cant);

    eliminarAlumno(alumnos, cant, 2);

    cout << "\nLuego de borrar id=2:\n";
    mostrar(alumnos, cant);

    return 0;
}

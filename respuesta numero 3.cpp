#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

struct Alumno {
    int    id;
    string nombre;
    int    edad;
    float  nota;
};


void mostrarRec(const Alumno lista[], int cant, int pos = 0){
    if (pos >= cant) return;
    cout << "ID: " << lista[pos].id
         << " | Nombre: " << lista[pos].nombre
         << " | Edad: " << lista[pos].edad
         << " | Nota: " << lista[pos].nota << "\n";
    mostrarRec(lista, cant, pos + 1);


void insertarAlumno(Alumno arr[], int &cant, const Alumno &nuevo){
    if (cant >= MAX) return;
    arr[cant++] = nuevo;
}

int main(){
    Alumno alumnos[MAX];
    int cant = 0;


    insertarAlumno(alumnos, cant, {1, "Ana",   18, 8.5f});
    insertarAlumno(alumnos, cant, {2, "Luis",  19, 7.0f});
    insertarAlumno(alumnos, cant, {3, "Marta", 20, 9.2f});

    cout << "Listado (recursivo):\n";
    mostrarRec(alumnos, cant);

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <alumno.h>

using namespace std;

void Alumno::modificarDatos(string dni, string apellido, string nombres, string carrera, string correo, int e) {
        DNI = dni;
        Apellido = apellido;
        Nombres = nombres;
        Carrera = carrera;
        mail = correo;
        edad = e;
    }
    void Alumno::inscribirMateria(string codigo, string nombre) {
        materiasInscriptas.push_back(make_pair(nombre, -1));
    }
    bool Alumno::cargarNota(string nombreMateria, int nota) {
        for (int i = 0; i < materiasInscriptas.size(); i++) {
            if (materiasInscriptas[i].first == nombreMateria) {
                materiasInscriptas[i].second = nota;
            }
        }
    }
    string Alumno::getDNI() {
        return DNI;
    }
    void Alumno::setDNI(string dni) {
    DNI = dni;
    }
    void Alumno::setApellido(string apellido) {
        Apellido = apellido;
    }
    void Alumno::setNombres(string nombres) {
        Nombres = nombres;
    }
    void Alumno::setCarrera(string carrera) {
        Carrera = carrera;
    }
    void Alumno::setCorreo(string correo) {
        mail = correo;
    }
    void Alumno::setEdad(int edad) {
        this->edad = edad;
    }
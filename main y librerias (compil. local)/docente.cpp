#include <iostream>
#include <vector>
#include <string>
#include <docente.h>

using namespace std;

class Docente {
private:
    string DNI;
    string Apellido;
    string Nombres;
    string mail;
    string titulo;
    vector<string> materiasEnseña;
public:
    Docente(string dni, string apellido, string nombres, string correo, string tit) {
        DNI = dni;
        Apellido = apellido;
        Nombres = nombres;
        mail = correo;
        titulo = tit;
    }
    void anotarMateria(string materia) {
        materiasEnseña.push_back(materia);
    }
    vector<string> getMateriasEnseña() {
        return materiasEnseña;
    }
    void modificarDatos(string dni, string apellido, string nombres, string correo, string tit) {
        DNI = dni;
        Apellido = apellido;
        Nombres = nombres;
        mail = correo;
        titulo = tit;
    }
        string getDNI() {
        return DNI;
    }
    void setApellido(string apellido) {
    Apellido = apellido;
    }
    void setNombres(string nombres) {
        Nombres = nombres;
    }
    void setCorreo(string correo) {
        mail = correo;
    }
    void setTitulo(string tit) {
        titulo = tit;
    }
};
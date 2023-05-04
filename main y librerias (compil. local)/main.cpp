#include <iostream>
#include <vector> /*Hago uso de <vector> para evitar usar arreglos. Prefiero la funcionalidad dinamica del vector y las herramientas que trae*/
#include <string> /*Hago uso de <string> para acceder a las herramientas de manipulacion de cadenas. Veo apropiado usar cadenas de caracteres para este problema*/
#include <alumno.h>
#include <docente.h>

using namespace std;

int main() {
    vector<Docente> docentes;
    vector<Alumno> alumnos;
    int opcion = 0;
    while (opcion != 6) {
        cout << "Sistema de Gestión de Universidad" << endl;
        cout << "1. Alta (Alumnos y Docentes)" << endl;
        cout << "2. Inscribir a materia (Alumnos)" << endl;
        cout << "3. Anotar titular (Docente)" << endl;
        cout << "4. Cargar Nota (Alumnos)" << endl;
        cout << "5. Modificar Datos (Alumnos y Docentes)" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese opción: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Ingrese tipo de usuario (1: Alumno, 2: Docente): ";
                int tipoUsuario;
                cin >> tipoUsuario;
                if (tipoUsuario == 1) {
                    string dni, apellido, nombres, carrera, correo;
                    int edad;
                    cout << "Ingrese DNI: ";
                    cin >> dni;
                    cout << "Ingrese Apellido: ";
                    cin >> apellido;
                    cout << "Ingrese Nombres: ";
                    cin >> nombres;
                    cout << "Ingrese Carrera: ";
                    cin >> carrera;
                    cout << "Ingrese Correo: ";
                    cin >> correo;
                    cout << "Ingrese Edad: ";
                    cin >> edad;
                    Alumno alumno(dni, apellido, nombres, carrera, correo, edad);
                    alumnos.push_back(alumno);
                    cout << "Alumno registrado exitosamente." << endl;
                } else if (tipoUsuario == 2) {
                    string dni, apellido, nombres, correo, titulo;
                    cout << "Ingrese DNI: ";
                    cin >> dni;
                    cout << "Ingrese Apellido: ";
                    cin >> apellido;
                    cout << "Ingrese Nombres: ";
                    cin >> nombres;
                    cout << "Ingrese Correo: ";
                    cin >> correo;
                    cout << "Ingrese Título: ";
                    cin >> titulo;
                    Docente docente(dni, apellido, nombres, correo, titulo);
                    docentes.push_back(docente);
                    cout << "Docente registrado exitosamente." << endl;
                } else {
                    cout << "Opción inválida." << endl;
                }
                break;
            case 2:
                if (alumnos.empty()) {
                    cout << "No hay alumnos registrados." << endl;
                } else {
                    string dniAlumno, codigoMateria, nombreMateria;
                    cout << "Ingrese DNI del alumno: ";
                    cin >> dniAlumno;
                    for (int i = 0; i < alumnos.size(); i++) {
                        if (alumnos[i].getDNI() == dniAlumno) {
                            cout << "Ingrese Código de Materia: ";
                            cin >> codigoMateria;
                            cout << "Ingrese Nombre de Materia: ";
                            cin >> nombreMateria;
                            alumnos[i].inscribirMateria(codigoMateria, nombreMateria);
                            cout << "Materia inscripta exitosamente." << endl;
                            break;
                        }
                        if (i == alumnos.size() - 1) {
                            cout << "No se encontró el alumno." << endl;
                        }
                    }
                }
                break;
            case 3:
                if (docentes.empty()) {
                    cout << "No hay docentes registrados." << endl;
                } else {
                    string dniDocente, nombreMateria;
                    cout << "Ingrese DNI del docente: ";
                    cin >> dniDocente;
                    for (int i = 0; i < docentes.size(); i++) {
                        if (docentes[i].getDNI() == dniDocente) {
                            cout << "Ingrese Nombre de Materia: ";
                            cin >> nombreMateria;
                            docentes[i].anotarMateria(nombreMateria);
                            cout << "Materia anotada exitosamente." << endl;
                            break;
                        }
                        if (i == docentes.size() - 1) {
                            cout << "No se encontró el docente." << endl;
                        }
                    }
                }
                break;
            case 4:
                if (alumnos.empty()) {
                    cout << "No hay alumnos registrados." << endl;
                } else {
                    string dniAlumno, nombreMateria;
                    int nota;
                    cout << "Ingrese DNI del alumno: ";
                    cin >> dniAlumno;
                    for (int i = 0; i < alumnos.size(); i++) {
                        if (alumnos[i].getDNI() == dniAlumno) {
                            cout << "Ingrese Nombre de Materia: ";
                            cin >> nombreMateria;
                            cout << "Ingrese nota: ";
                            cin >> nota;
                            if (alumnos[i].cargarNota(nombreMateria, nota)) {
                                cout << "Nota cargada exitosamente." << endl;
                            } else {
                                cout << "La materia no fue encontrada o no está inscripto en ella." << endl;
                            }
                            break;
                        }
                        if (i == alumnos.size() - 1) {
                            cout << "No se encontró el alumno." << endl;
                        }
                    }
                }
                break;
            case 5:
                if (alumnos.empty() && docentes.empty()) {
                    cout << "No hay usuarios registrados." << endl;
                } else {
                    int tipoUsuarioModificar;
                    cout << "Seleccione el tipo de usuario a modificar (1: Alumno, 2: Docente): ";
                    cin >> tipoUsuarioModificar;
                    if (tipoUsuarioModificar == 1) {
                        string dni, apellido, nombres, carrera, correo;
                        int edad;
                        cout << "Ingrese DNI del alumno a modificar: ";
                        cin >> dni;
                        for (int i = 0; i < alumnos.size(); i++) {
                            if (alumnos[i].getDNI() == dni) {
                                cout << "Ingrese Apellido: ";
                                cin >> apellido;
                                cout << "Ingrese Nombres: ";
                                cin >> nombres;
                                cout << "Ingrese Carrera: ";
                                cin >> carrera;
                                cout << "Ingrese Correo: ";
                                cin >> correo;
                                cout << "Ingrese Edad: ";
                                cin >> edad;
                                alumnos[i].setApellido(apellido);
                                alumnos[i].setNombres(nombres);
                                alumnos[i].setCarrera(carrera);
                                alumnos[i].setCorreo(correo);
                                alumnos[i].setEdad(edad);
                                cout << "Alumno modificado exitosamente." << endl;
                                break;
                            }
                            if (i == alumnos.size() - 1) {
                                cout << "No se encontró el alumno." << endl;
                            }
                        }
                    } else if (tipoUsuarioModificar == 2) {
                        string dni, apellido, nombres, correo, titulo;
                        cout << "Ingrese DNI del docente a modificar: ";
                        cin >> dni;
                        for (int i = 0; i < docentes.size(); i++) {
                            if (docentes[i].getDNI() == dni) {
                                cout << "Ingrese Apellido: ";
                                cin >> apellido;
                                cout << "Ingrese Nombres: ";
                                cin >> nombres;
                                cout << "Ingrese Correo: ";
                                cin >> correo;
                                cout << "Ingrese Título: ";
                                cin >> titulo;
                                docentes[i].setApellido(apellido);
                                docentes[i].setNombres(nombres);
                                docentes[i].setCorreo(correo);
                                docentes[i].setTitulo(titulo);
                                cout << "Docente modificado exitosamente." << endl;
                                break;
                            }
                            if (i == docentes.size() - 1) {
                                cout << "No se encontró el docente." << endl;
                            }
                        }
                    } else {
                        cout << "Opción inválida." << endl;
                    }
                }
                break;
            case 6:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
                break;
        }
    } while (opcion != 6);
    return 0;
}
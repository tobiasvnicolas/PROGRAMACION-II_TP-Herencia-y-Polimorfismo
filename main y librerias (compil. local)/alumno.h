using namespace std;

class Alumno {
private:
    string DNI;
    string Apellido;
    string Nombres;
    string Carrera;
    string mail;
    int edad;
    vector<pair<string, int>> materiasInscriptas;
public:
    Alumno(string dni, string apellido, string nombres, string carrera, string correo, int e);
    void modificarDatos(string dni, string apellido, string nombres, string carrera, string correo, int e);
    void inscribirMateria(string codigo, string nombre);
    bool cargarNota(string nombreMateria, int nota);
    string getDNI();
    void setDNI(string dni);
    void setApellido(string apellido);
    void setNombres(string nombres);
    void setCarrera(string carrera);
    void setCorreo(string correo);
    void setEdad(int edad);
};
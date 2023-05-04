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
    Docente(string dni, string apellido, string nombres, string correo, string tit);
    void anotarMateria(string materia);
    vector<string> getMateriasEnseña();
    void modificarDatos(string dni, string apellido, string nombres, string correo, string tit);
        string getDNI();
    void setApellido(string apellido);
    void setNombres(string nombres);
    void setCorreo(string correo);
    void setTitulo(string tit);
};
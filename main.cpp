#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// Clase Pelicula
class Pelicula {
private:
    string titulo;
    int duracion; // minutos
    string genero;

public:
    Pelicula(string t, int d, string g) : titulo(t), duracion(d), genero(g) {}
    
    string getTitulo() const { return titulo; }
    int getDuracion() const { return duracion; }
    string getGenero() const { return genero; }
    
    void mostrar() const {
        cout << "Titulo: " << titulo
             << " | Duracion: " << duracion << " min"
             << " | Genero: " << genero << endl;
    }
};

// Clase Usuario
class Usuario {
private:
    int id;
    string documento; // identificador único
    string nombre;
    vector<Pelicula> peliculas;

    int tiempoTotalRecursivo(int indice) {
        if (indice == peliculas.size()) return 0;
        return peliculas[indice].getDuracion() + tiempoTotalRecursivo(indice + 1);
    }

public:
    Usuario(int i, string doc, string n) : id(i), documento(doc), nombre(n) {}

    int getId() const { return id; }
    string getDocumento() const { return documento; }
    string getNombre() const { return nombre; }

    void agregarPelicula(const Pelicula &p) { peliculas.push_back(p); }

    void mostrarPeliculasOrdenadas() {
        sort(peliculas.begin(), peliculas.end(),
             [](const Pelicula &a, const Pelicula &b) {
                 return a.getDuracion() > b.getDuracion(); // mayor a menor
             });
        cout << "\nPeliculas de " << nombre << ":\n";
        for (const auto &p : peliculas) p.mostrar();
    }

    int calcularTiempoTotal() { return tiempoTotalRecursivo(0); }
};

// Función para elegir usuario
Usuario* seleccionarUsuario(vector<Usuario> &usuarios) {
    if (usuarios.empty()) {
        cout << "No hay usuarios registrados.\n";
        return nullptr;
    }

    cout << "\nLista de usuarios:\n";
    for (const auto &u : usuarios) {
        cout << "ID: " << u.getId()
             << " | Documento: " << u.getDocumento()
             << " | Nombre: " << u.getNombre() << endl;
    }

    cout << "Ingrese el ID del usuario: ";
    int id;
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (auto &u : usuarios) {
        if (u.getId() == id) return &u;
    }

    cout << "Usuario no encontrado.\n";
    return nullptr;
}

// Función para ingresar películas para un usuario
void ingresarPeliculasParaUsuario(Usuario &usuario) {
    int n;
    cout << "¿Cuántas peliculas quieres registrar para " << usuario.getNombre() << "? ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < n; i++) {
        string titulo, genero;
        int duracion;

        cout << "\nPelícula #" << i + 1 << ":\n";
        cout << "Titulo: ";
        getline(cin, titulo);

        cout << "Duracion (minutos): ";
        cin >> duracion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Genero: ";
        getline(cin, genero);

        usuario.agregarPelicula(Pelicula(titulo, duracion, genero));
    }
}

int main() {
    vector<Usuario> usuarios;
    int opcion;
    int contadorId = 1;

    do {
        cout << "\n=== SISTEMA DE REGISTRO DE PELICULAS MULTIUSUARIO ===\n";
        cout << "1 - Ingresar usuario\n";
        cout << "2 - Ingresar peliculas vistas por un usuario\n";
        cout << "3 - Lista de peliculas de un usuario (ordenadas por duracion)\n";
        cout << "4 - Tiempo total dedicado al cine por un usuario\n";
        cout << "0 - Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1: {
                string nombre, documento;
                cout << "Ingrese el nombre del usuario: ";
                getline(cin, nombre);
                cout << "Ingrese el documento del usuario (identificador único): ";
                getline(cin, documento);

                // Verificar si ya existe el documento
                bool existe = false;
                for (const auto &u : usuarios) {
                    if (u.getDocumento() == documento) {
                        existe = true;
                        break;
                    }
                }
                if (existe) {
                    cout << "Error: Ya existe un usuario con ese documento.\n";
                } else {
                    usuarios.push_back(Usuario(contadorId++, documento, nombre));
                    cout << "Usuario " << nombre << " registrado exitosamente.\n";
                }
                break;
            }
            case 2: {
                Usuario* u = seleccionarUsuario(usuarios);
                if (u) ingresarPeliculasParaUsuario(*u);
                break;
            }
            case 3: {
                Usuario* u = seleccionarUsuario(usuarios);
                if (u) u->mostrarPeliculasOrdenadas();
                break;
            }
            case 4: {
                Usuario* u = seleccionarUsuario(usuarios);
                if (u)
                    cout << "Tiempo total dedicado al cine por "
                         << u->getNombre() << ": "
                         << u->calcularTiempoTotal() << " minutos.\n";
                break;
            }
            case 0:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }

    } while (opcion != 0);

    return 0;
}
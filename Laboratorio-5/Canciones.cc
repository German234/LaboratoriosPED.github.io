#include <iostream>
#include <string>

using namespace std;

// Estructura para almacenar los datos de una canción
struct Cancion {
    string nombre;
    string artista;
    int anioLanzamiento;
    string genero;
    Cancion* siguiente;
};

// Función para agregar una nueva canción a la lista enlazada
void agregarCancion(Cancion*& listaCanciones) {
    Cancion* nuevaCancion = new Cancion;

    //Pidiendo los datos de la canción
    cout << "Ingrese el nombre de la canción: ";
    cin.ignore(); // Para limpiar el buffer del teclado
    getline(cin, nuevaCancion->nombre);
    cout << "Ingrese el artista: ";
    getline(cin, nuevaCancion->artista);
    cout << "Ingrese el año de lanzamiento: ";
    cin >> nuevaCancion->anioLanzamiento;
    cout << "Ingrese el género musical: ";
    cin.ignore();
    getline(cin, nuevaCancion->genero);

    // Asignando el puntero siguiente a nullptr

    nuevaCancion->siguiente = nullptr;

    if (listaCanciones == nullptr) {
        listaCanciones = nuevaCancion;
    } else {
        Cancion* temp = listaCanciones;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevaCancion;
    }

    cout << "Canción agregada exitosamente.\n";
}

// Función para mostrar todas las canciones
void mostrarCanciones(Cancion* listaCanciones) {
    if (listaCanciones == nullptr) {
        cout << "No hay canciones en la lista.\n";
        return;
    }

    Cancion* temp = listaCanciones;
    while (temp != nullptr) {
        cout << "Nombre: " << temp->nombre << endl;
        cout << "Artista: " << temp->artista << endl;
        cout << "Año de lanzamiento: " << temp->anioLanzamiento << endl;
        cout << "Género: " << temp->genero << endl;
        cout << "----------------------------\n";
        temp = temp->siguiente;
    }
}

// Función para mostrar canciones lanzadas antes del 2000
void mostrarCancionesAntiguas(Cancion* listaCanciones) {
    if (listaCanciones == nullptr) {
        cout << "No hay canciones en la lista.\n";
        return;
    }

    Cancion* temp = listaCanciones;
    bool encontradas = false;

    while (temp != nullptr) {
        if (temp->anioLanzamiento < 2000) {
            cout << "Nombre: " << temp->nombre << endl;
            cout << "Artista: " << temp->artista << endl;
            cout << "Año de lanzamiento: " << temp->anioLanzamiento << endl;
            cout << "Género: " << temp->genero << endl;
            cout << "----------------------------\n";
            encontradas = true;
        }
        temp = temp->siguiente;
    }

    if (!encontradas) {
        cout << "No hay canciones lanzadas antes del 2000.\n";
    }
}

// Función para mostrar la canción más antigua
void mostrarCancionMasAntigua(Cancion* listaCanciones) {
    if (listaCanciones == nullptr) {
        cout << "No hay canciones en la lista.\n";
        return;
    }

    Cancion* temp = listaCanciones;
    Cancion* masAntigua = listaCanciones;

    while (temp != nullptr) {
        if (temp->anioLanzamiento < masAntigua->anioLanzamiento) {
            masAntigua = temp;
        }
        temp = temp->siguiente;
    }

    cout << "La canción más antigua es:\n";
    cout << "Nombre: " << masAntigua->nombre << endl;
    cout << "Artista: " << masAntigua->artista << endl;
    cout << "Año de lanzamiento: " << masAntigua->anioLanzamiento << endl;
    cout << "Género: " << masAntigua->genero << endl;
}


int main() {
    Cancion* listaCanciones = nullptr;
    int opcion;

    do {
        cout << "\nMenú de opciones:\n";
        cout << "1. Agregar una nueva canción\n";
        cout << "2. Mostrar la lista de canciones completa\n";
        cout << "3. Mostrar canciones lanzadas antes del 2000\n";
        cout << "4. Mostrar la canción más antigua\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarCancion(listaCanciones);
                break;
            case 2:
                mostrarCanciones(listaCanciones);
                break;
            case 3:
                mostrarCancionesAntiguas(listaCanciones);
                break;
            case 4:
                mostrarCancionMasAntigua(listaCanciones);
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}

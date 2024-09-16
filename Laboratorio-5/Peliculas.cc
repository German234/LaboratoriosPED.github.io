#include <iostream>
#include <string>

struct Nodo {
    std::string pelicula;   // Nombre de la película almacenado en el nodo
    Nodo* siguiente;        // Puntero al siguiente nodo
};

// Funciones para la lista simplemente enlazada
void AgregarPeliculaAlInicio(Nodo*& cabeza, const std::string& pelicula);
void AgregarPeliculaAlFinal(Nodo*& cabeza, const std::string& pelicula);
void EliminarPelicula(Nodo*& cabeza, const std::string& pelicula);
void MostrarPlaylist(Nodo* cabeza);
bool BuscarPelicula(Nodo* cabeza, const std::string& pelicula);
void LimpiarPlaylist(Nodo*& cabeza);

// Función principal
int main(int argc, char* argv[]) {
    Nodo* playlist = nullptr;

    // Agregar películas al inicio de la playlist
    AgregarPeliculaAlInicio(playlist, "Interstellar");
    AgregarPeliculaAlInicio(playlist, "Inception");
    AgregarPeliculaAlInicio(playlist, "The Dark Knight");

    // Agregar películas al final de la playlist
    AgregarPeliculaAlFinal(playlist, "Tenet");
    AgregarPeliculaAlFinal(playlist, "Dunkirk");

    // Mostrar la playlist completa
    std::cout << "Playlist de películas: " << std::endl;
    MostrarPlaylist(playlist);

    // Buscar una película en la playlist
    std::string pelicula_buscada = "Inception";
    std::cout << "Buscando la película \"" << pelicula_buscada << "\": " 
              << (BuscarPelicula(playlist, pelicula_buscada) ? "Encontrada" : "No encontrada") << std::endl;

    // Eliminar una película de la playlist
    EliminarPelicula(playlist, "The Dark Knight");
    std::cout << "Playlist después de eliminar \"The Dark Knight\": " << std::endl;
    MostrarPlaylist(playlist);

    // Limpiar toda la playlist
    LimpiarPlaylist(playlist);
    std::cout << "Playlist después de limpiarla: " << std::endl;
    MostrarPlaylist(playlist);

    return 0;
}

// Agregar una película al inicio de la playlist
void AgregarPeliculaAlInicio(Nodo*& cabeza, const std::string& pelicula) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->pelicula = pelicula;
    nuevo_nodo->siguiente = cabeza;
    cabeza = nuevo_nodo;
    std::cout << "Película \"" << pelicula << "\" agregada al inicio de la playlist." << std::endl;
}

// Agregar una película al final de la playlist
void AgregarPeliculaAlFinal(Nodo*& cabeza, const std::string& pelicula) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->pelicula = pelicula;
    nuevo_nodo->siguiente = nullptr;

    if (cabeza == nullptr) {
        cabeza = nuevo_nodo;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo_nodo;
    }
    std::cout << "Película \"" << pelicula << "\" agregada al final de la playlist." << std::endl;
}

// Eliminar una película específica de la playlist
void EliminarPelicula(Nodo*& cabeza, const std::string& pelicula) {
    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;

    while (actual != nullptr && actual->pelicula != pelicula) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == nullptr) return; // Película no encontrada

    if (anterior == nullptr) {
        cabeza = actual->siguiente; // Eliminar la primera película
    } else {
        anterior->siguiente = actual->siguiente;
    }

    delete actual; // Liberar la memoria del nodo eliminado
    std::cout << "Película \"" << pelicula << "\" eliminada de la playlist." << std::endl;
}

// Mostrar la playlist completa
void MostrarPlaylist(Nodo* cabeza) {
    Nodo* actual = cabeza;
    if (actual == nullptr) {
        std::cout << "La playlist está vacía." << std::endl;
        return;
    }
    while (actual != nullptr) {
        std::cout << actual->pelicula << " -> ";
        actual = actual->siguiente;
    }
    std::cout << "nullptr" << std::endl;
}

// Buscar una película en la playlist
bool BuscarPelicula(Nodo* cabeza, const std::string& pelicula) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        if (actual->pelicula == pelicula) {
            return true;  // Película encontrada
        }
        actual = actual->siguiente;
    }
    return false;  // Película no encontrada
}

// Limpiar toda la playlist (eliminar todas las películas)
void LimpiarPlaylist(Nodo*& cabeza) {
    while (cabeza != nullptr) {
        Nodo* actual = cabeza;
        cabeza = cabeza->siguiente;
        delete actual;
    }
    std::cout << "La playlist ha sido limpiada." << std::endl;
}

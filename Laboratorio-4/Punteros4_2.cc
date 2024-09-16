#include <iostream>
#include <string>


struct Persona {
    string nombre;
    int edad;
};

// Función para mostrar los detalles de las personas
void MostrarPersona(Persona *persona, int *cantidadPersonas) {
    for (int i = 0; i < *cantidadPersonas; i++) {
        cout << "Nombre: " << persona[i].nombre << endl;
        cout << "Edad: " << persona[i].edad << endl;
    }
}

// Versión alternativa para mostrar los detalles de las personas usando punteros
void MostrarPersonaVersion2(Persona *persona, int *cantidadPersonas) {
    for (int i = 0; i < *cantidadPersonas; i++) {
        cout << "Nombre: " << (persona + i)->nombre << endl;
        cout << "Edad: " << (persona + i)->edad << endl;
    }
}

// Función para agregar personas
void AgregarPersona(Persona *persona, int *cantidadPersonas) {
    for (int i = 0; i < *cantidadPersonas; i++) {
        std::cout << "Ingrese el nombre de la persona: ";
        std::cin >> persona[i].nombre;
        cout << "Ingrese la edad de la persona: ";
        cin >> persona[i].edad;
        cin.getline(character->name, 50);
    }
}

// Versión alternativa para agregar personas usando punteros
void AgregarPersonaVersion2(Persona *persona, int *cantidadPersonas) {
    for (int i = 0; i < *cantidadPersonas; i++) {
        cout << "Ingrese el nombre de la persona: ";
        cin >> (persona + i)->nombre;
        cout << "Ingrese la edad de la persona: ";
        cin >> (persona + i)->edad;
    }
}

// Función para actualizar una persona
void ActualizarUnaPersona(Persona *persona, int *cantidadPersonas) {
    string nombre;
    int edad;
    cout << "Ingrese el nombre de la persona a actualizar: ";
    cin >> nombre;

    for (int i = 0; i < *cantidadPersonas; i++) {
        if (persona[i].nombre == nombre) {
            cout << "Ingrese la nueva edad de la persona: ";
            cin >> edad;
            persona[i].edad = edad;
            break;
        }
    }
}

// Versión alternativa para actualizar una persona usando punteros
void ActualizarUnaPersonaVersion2(Persona *persona, int *cantidadPersonas) {
    string nombre;
    int edad;
    cout << "Ingrese el nombre de la persona a actualizar: ";
    cin >> nombre;

    for (int i = 0; i < *cantidadPersonas; i++) {
        if ((persona + i)->nombre == nombre) {
            cout << "Ingrese la nueva edad de la persona: ";
            cin >> edad;
            (persona + i)->edad = edad;
            break;
        }
    }
}

int main() {
    int cantidadPersonas = 3;

    // Declaración de un arreglo de estructuras con asignación dinámica de memoria
    Persona *personas = new Persona[cantidadPersonas];

    // Inicialización de los datos de las personas
    personas[0].nombre = "Juan";
    personas[0].edad = 20;
    personas[1].nombre = "Maria";
    personas[1].edad = 30;
    personas[2].nombre = "Pedro";
    personas[2].edad = 40;

    // Mostrar las personas usando la versión 2
    MostrarPersonaVersion2(personas, &cantidadPersonas);

    // Agregar nuevas personas (si fuera necesario)
    // AgregarPersona(personas, &cantidadPersonas);

    // Actualizar una persona
    ActualizarUnaPersonaVersion2(personas, &cantidadPersonas);

    // Mostrar los detalles de las personas después de la actualización
    MostrarPersona(personas, &cantidadPersonas);

    // Liberar la memoria asignada dinámicamente
    delete[] personas;

    return 0;
}

#include <iostream>
#include <cstring> // Para usar strcpy y strcmp
using namespace std;

struct Character {
    char name[50];
    int characterClass; // 0 = Guerrero, 1 = Mago, 2 = Arquero
    int strength;
    int agility;
    int magic;
};

// Función para crear un nuevo personaje
void createCharacter(Character *character) {
    cout << "Introduce el nombre del personaje: ";
    cin.ignore(); // Limpiar el buffer de entrada
    cin.getline(character->name, 50);

    cout << "Selecciona la clase del personaje (0 = Guerrero, 1 = Mago, 2 = Arquero): ";
    cin >> character->characterClass;

    cout << "Introduce la fuerza del personaje: ";
    cin >> character->strength;

    cout << "Introduce la agilidad del personaje: ";
    cin >> character->agility;

    cout << "Introduce la magia del personaje: ";
    cin >> character->magic;
}

// Función para mostrar los detalles del personaje
void showCharacter(const Character *character) {
    cout << "\nNombre: " << character->name << endl;
    cout << "Clase: ";
    switch (character->characterClass) {
        case 0: cout << "Guerrero"; break;
        case 1: cout << "Mago"; break;
        case 2: cout << "Arquero"; break;
        default: cout << "Desconocida"; break;
    }
    cout << endl;
    cout << "Fuerza: " << character->strength << endl;
    cout << "Agilidad: " << character->agility << endl;
    cout << "Magia: " << character->magic << endl;
}

// Función para modificar el nombre o los atributos del personaje
void modifyCharacter(Character *character) {
    int option;
    cout << "\n¿Qué deseas modificar? (1 = Nombre, 2 = Fuerza, 3 = Agilidad, 4 = Magia): ";
    cin >> option;

    switch (option) {
        case 1:
            cout << "Introduce el nuevo nombre del personaje: ";
            cin.ignore(); // Limpiar el buffer de entrada
            cin.getline(character->name, 50);
            break;
        case 2:
            cout << "Introduce la nueva fuerza del personaje: ";
            cin >> character->strength;
            break;
        case 3:
            cout << "Introduce la nueva agilidad del personaje: ";
            cin >> character->agility;
            break;
        case 4:
            cout << "Introduce la nueva magia del personaje: ";
            cin >> character->magic;
            break;
        default:
            cout << "Opción no válida." << endl;
            break;
    }
}

int main() {
    int numCharacters = 2; // Número de personajes en el arreglo

    // Declaración de un arreglo de estructuras junto con la asignación de memoria dinámica
    Character *characters = new Character[numCharacters];

    // Crear y mostrar personajes
    for (int i = 0; i < numCharacters; i++) {
        cout << "\nCreando personaje " << (i + 1) << ":" << endl;
        createCharacter(&characters[i]);
    }

    for (int i = 0; i < numCharacters; i++) {
        cout << "\nMostrando personaje " << (i + 1) << ":" << endl;
        showCharacter(&characters[i]);
    }

    // Modificar personajes
    char choice;
    cout << "\n¿Deseas modificar algún personaje? (s/n): ";
    cin >> choice;

    if (choice == 's' || choice == 'S') {
        int index;
        cout << "Selecciona el índice del personaje a modificar (1 - " << numCharacters << "): ";
        cin >> index;

        if (index > 0 && index <= numCharacters) {
            modifyCharacter(&characters[index - 1]);
            showCharacter(&characters[index - 1]);
        } else {
            cout << "Índice no válido." << endl;
        }
    }

    // Liberar la memoria asignada dinámicamente
    delete[] characters;

    return 0;
}

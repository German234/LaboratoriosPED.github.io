//Manejar un arreglo de estructuras con punteros
#include <iostream>


struct Persona{
    std::string nombre;
    int edad;
};

void MostrarPersona(Persona *persona, int *cantidadPersonas){

    for (int i = 0; i < *cantidadPersonas; i++)
    {
        std::cout << "Nombre: " << persona[i].nombre << std::endl;
        std::cout << "Edad: " << persona[i].edad << std::endl;    
    }
 
}


void MostrarPersonaVersion2(Persona *persona,int *cantidadPersonas){
    for (int i = 0; i < *cantidadPersonas; i++)
    {
        std::cout << "Nombre: " << (persona + i)->nombre << std::endl;
        std::cout << "Edad: " << (persona + i)->edad << std::endl;    
    }

}

int main(){

    
    
    int cantidadPersonas = 3;

    //declaracion de arreglo de estructuras
    Persona *personas = new Persona[cantidadPersonas];


    // Persona personas[cantidadPersonas];
    personas[0].nombre = "Juan";
    personas[0].edad = 20;
    personas[1].nombre = "Maria";
    personas[1].edad = 30;
    personas[2].nombre = "Pedro";
    personas[2].edad = 40;
    // Persona *puntero_personas = personas;
    MostrarPersonaVersion2(personas, &cantidadPersonas);

    // Liberar la memoria asignada dinámicamente
    delete[] personas;
}





void AgregarPersona(Persona* persona, int *cantidadPersonas){
    for (int i = 0; i < *cantidadPersonas; i++)
    {
        std::cout << "Ingrese el nombre de la persona: ";
        std::cin >> persona[i].nombre;
        std::cout << "Ingrese la edad de la persona: ";
        std::cin >> persona[i].edad;
    }
}

void AgregarPersonaVersion2(Persona* persona, int *cantidadPersonas){
    for (int i = 0; i < *cantidadPersonas; i++)
    {
        std::cout << "Ingrese el nombre de la persona: ";
        std::cin >> (persona + i)->nombre;
        std::cout << "Ingrese la edad de la persona: ";
        std::cin >> (persona + i)->edad;
    }
}

void ActualizarUnaPersona(Persona* persona, int *cantidadPersonas){
    std::string nombre;
    int edad;
    std::cout << "Ingrese el nombre de la persona a actualizar: ";
    std::cin >> nombre;
    
    for (int i = 0; i < *cantidadPersonas; i++)
    {
        if(persona[i].nombre == nombre){
            
            std::cout << "Ingrese la edad a actualizar: ";
            std::cin >> edad;
            persona[i].edad = edad;
        }
    }
}

void ActualizarUnaPersonaVersion2(Persona* persona, int *cantidadPersonas){
    std::string nombre;
    int edad;
    std::cout << "Ingrese el nombre de la persona a actualizar: ";
    std::cin >> nombre;
    
    for (int i = 0; i < *cantidadPersonas; i++)
    {
        if((persona + i)->nombre == nombre){
            std::cout << "Ingrese la edad a actualizar: ";
            std::cin >> edad;
            (persona + i)->edad = edad;
        }
    }
}




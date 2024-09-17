#include <iostream>

struct Nodo {
    int dato;
    Nodo* siguiente;
};

void InsertarLista(Nodo *&lista, int numero){ //Se pasa por referencia para que la lista se modifique
    Nodo *nuevo_nodo = new Nodo(); //Reservar memoria para el nuevo nodo
    Nodo *aux; //Puntero auxiliar para recorrer la lista

    nuevo_nodo->dato = numero; //Asignar el valor al nuevo nodo
    nuevo_nodo->siguiente = nullptr; //Asignar el valor al nuevo nodo

    if(lista == nullptr){ //Si la lista esta vacia
        lista = nuevo_nodo; //Asignar el nuevo nodo a la lista
    }else{
        aux = lista; //Asignar el puntero auxiliar a la lista
        while(aux->siguiente != nullptr){ //Recorrer la lista para que el puntero auxiliar quede en el ultimo nodo
            aux = aux->siguiente; //Avanza al siguiente nodo
        }
        aux->siguiente = nuevo_nodo; //Cuando llega al ultimo nodo, asigna el nuevo nodo
    }

    std::cout << "Elemento " << numero << " insertado a la lista" << std::endl;

    delete nuevo_nodo; //Liberar memoria
}

void MostrarLista(Nodo *lista){
   while(lista != nullptr){ //Mientras no sea el final de la lista
       std::cout << lista->dato << " -> "; //Mostrar el dato del nodo
       lista = lista->siguiente; //Avanzar al siguiente nodo
   }
}

void CalcularMayorMenor(Nodo *lista){ //No se pasa por referencia porque no se modifica la lista
    int mayor = 0;
    int menor = 999999;


    while(lista != nullptr){ //Mientras no sea el final de la lista
        if(lista->dato > mayor){ //Calculando el mayor
            mayor = lista->dato;
        }
        if(lista->dato < menor){ //Calculando el menor
            menor = lista->dato;
        }

        lista = lista->siguiente; //Avanzar al siguiente nodo
    }

    std::cout << "Mayor: " << mayor << std::endl;
    std::cout << "Menor: " << menor << std::endl;
}

int main(){
    Nodo *lista = nullptr;
    int dato;
    char respuesta;

    do{
        std::cout << "Digite un numero: ";
        std::cin >> dato;
        InsertarLista(lista, dato);  


        std::cout << "Desea agregar otro elemento a la lista? (s/n): ";
        std::cin >> respuesta;

    }while(respuesta == 's' || respuesta == 'S');

    std::cout << "Elementos de la lista: ";
    MostrarLista(lista);

    std::cout << "El mayor y menor elemento de la lista son: ";
    std::cout << std::endl;
    CalcularMayorMenor(lista);

}
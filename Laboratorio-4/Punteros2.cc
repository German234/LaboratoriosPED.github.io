//Determinar si el numero es par o impar con punteros  y mostrar la direccion de memoria del numero ingresado
#include <iostream>

void DeterminarPar(int* numero){
    if(*numero % 2 == 0){
        std::cout << "El numero " << *numero<< " es par" << std::endl;
        std::cout << "La direccion de memoria del numero es: " << numero << std::endl;
    }else{
        std::cout << "El numero " << *numero<< " es impar" << std::endl;
        std::cout << "La direccion de memoria del numero es: " << numero << std::endl;
    }
}

int main() {
  int numero = 10;
  int* puntero_numero = &numero;
  DeterminarPar(puntero_numero);
  
  return 0;
}
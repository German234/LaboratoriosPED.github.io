#include <iostream>

void ActualizarValor(int* x){
  *x = 20;
  std::cout << "El valor de x dentro de la funcion es: " << *x << std::endl;
}

int main() {
  int x = 10;
  //A los punteros se les asigna direcciones de memoria
  int *p = &x;

  //Se imprime el valor de x dentro de la funcion
  ActualizarValor(p);

  std::cout << "El valor de x despues de llamar a la funcion es: " << x << std::endl;

  return 0;
}






void ActualizarValorVersion2(int* x){
  *x = 30;
  std::cout << "El valor de x dentro de la funcion es: " << *x << std::endl;
}


    // ActualizarValorVersion2(p);  
    // std::cout << "El valor de x despues de llamar version 2 a la funcion es: " << x << std::endl;
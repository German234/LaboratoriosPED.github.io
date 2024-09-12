#include <iostream>

int main() {
  int x = 10;
  //A los punteros se les asigna direcciones de memoria
  int* p = &x; // Valor y una direccion de memoria
  std::cout << "x = " << x << std::endl; //10 
  std::cout << "&x = " << &x << std::endl; // Direccion de memoria de x
  std::cout << "p = " << p << std::endl;   //Direccion de memoria de x  
  std::cout << "*p = " << *p << std::endl; //Valor de x
  return 0;
}
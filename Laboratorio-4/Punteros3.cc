//De un arreglo de numeros determinar si es par o impar y mostrar la direccion de memoria de cada numero
#include <iostream>

void DeterminarPar(int* arreglo_Numeros, int *tamano){
    for(int i = 0; i < *tamano; i++){
        if(arreglo_Numeros[i] % 2 == 0){
            std::cout << "El numero " << arreglo_Numeros[i]<< " es par" << std::endl;
            std::cout << "La direccion de memoria del numero es: " << &arreglo_Numeros[i] << std::endl;
        }else{
            std::cout << "El numero " << arreglo_Numeros[i]<< " es impar" << std::endl;
            std::cout << "La direccion de memoria del numero es: " << &arreglo_Numeros[i] << std::endl;
        }
    }
}

void DeterminarParVersion2(int* arreglo_Numeros, int *tamano){
    for(int i = 0; i < *tamano; i++){
        if(*(arreglo_Numeros + i) % 2 == 0){
            std::cout << "El numero " << *(arreglo_Numeros + i)<< " es par" << std::endl;
            std::cout << "La direccion de memoria del numero es: " << arreglo_Numeros + i << std::endl;
        }else{
            std::cout << "El numero " << *(arreglo_Numeros + i)<< " es impar" << std::endl;
            std::cout << "La direccion de memoria del numero es: " << arreglo_Numeros + i << std::endl;
        }
    }
}

int main(){
    int arregloNumeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};	
    int tamano = sizeof(arregloNumeros)/sizeof(arregloNumeros[0]);
    int* puntero_arregloNumeros = arregloNumeros;
    DeterminarParVersion2(puntero_arregloNumeros, &tamano);
}


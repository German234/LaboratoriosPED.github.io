#include <iostream>
#include <string>
#include <algorithm>  // Para std::sort y std::binary_search

using namespace std;

// Estructura para definir un producto
struct Producto {
    string nombre;
    string categoria;
    double precio;
    int cantidadStock;
};

// Función para agregar un nuevo producto al arreglo
void AgregarProducto(Producto productos[], int& tamano, const string& nombre, const string& categoria, double precio, int cantidadStock) {
    if (tamano < 100) {  // Límite de tamaño del arreglo
        productos[tamano].nombre = nombre;
        productos[tamano].categoria = categoria;
        productos[tamano].precio = precio;
        productos[tamano].cantidadStock = cantidadStock;
        tamano++;
    } else {
        cout << "No se pueden agregar más productos, el arreglo está lleno." << endl;
    }
}

// Función para mostrar todos los productos
void MostrarProductos(const Producto productos[], int tamano) {
    for (int i = 0; i < tamano; ++i) {
        cout << "Nombre: " << productos[i].nombre 
             << ", Categoría: " << productos[i].categoria 
             << ", Precio: $" << productos[i].precio 
             << ", Stock: " << productos[i].cantidadStock << endl;
    }
}

// Comparador para ordenar los productos por precio
bool CompararPorPrecio(const Producto& a, const Producto& b) {
    return a.precio < b.precio;
}

// Comparador para ordenar los productos por nombre
bool CompararPorNombre(const Producto& a, const Producto& b) {
    return a.nombre < b.nombre;
}

// Función para ordenar los productos por precio usando std::sort
void OrdenarProductosPorPrecio(Producto productos[], int tamano) {
    sort(productos, productos + tamano, CompararPorPrecio);
}

// Función para ordenar los productos por nombre usando std::sort
void OrdenarProductosPorNombre(Producto productos[], int tamano) {
    sort(productos, productos + tamano, CompararPorNombre);
}

// Función para buscar un producto por nombre usando std::binary_search
void BuscarProductoPorNombre(Producto productos[], int tamano, const string& nombreBuscado) {
    // Primero ordenamos los productos por nombre
    OrdenarProductosPorNombre(productos, tamano);
    
    // Aplicamos binary_search
    bool encontrado = binary_search(productos, productos + tamano, Producto{nombreBuscado, "", 0.0, 0}, CompararPorNombre);

    if (encontrado) {
        cout << "El producto '" << nombreBuscado << "' fue encontrado." << endl;
    } else {
        cout << "El producto '" << nombreBuscado << "' no fue encontrado." << endl;
    }
}

int main() {
    // Crear un arreglo de productos y una variable para llevar el tamaño actual
    Producto productos[100];  // Arreglo de tamaño fijo
    int tamano = 0;

    // Agregar algunos productos al sistema
    AgregarProducto(productos, tamano, "Laptop", "Electrónica", 1200.99, 10);
    AgregarProducto(productos, tamano, "Smartphone", "Electrónica", 699.99, 20);
    AgregarProducto(productos, tamano, "Televisor", "Electrónica", 399.99, 15);
    AgregarProducto(productos, tamano, "Cámara", "Fotografía", 549.99, 8);

    // Mostrar los productos antes de ordenar
    cout << "Productos antes de ordenar por precio:" << endl;
    MostrarProductos(productos, tamano);

    // Ordenar los productos por precio
    OrdenarProductosPorPrecio(productos, tamano);

    // Mostrar los productos después de ordenar por precio
    cout << "\nProductos después de ordenar por precio:" << endl;
    MostrarProductos(productos, tamano);

    // Buscar un producto por nombre usando binary_search
    BuscarProductoPorNombre(productos, tamano, "Smartphone");

    return 0;
}

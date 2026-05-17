/*  SISTEMA DE CONTROL DE PRODUCTOS
Mini-proyecto de C++ — Bootcamp "Programación de Cero a POO"
  
Autor: Frederick Lema
Fecha: 17 de mayo del 2026

Enunciado: Desarrolla un programa modular en C++ que permita:
 -Gestionar un inventario de hasta 50 productos utilizando arreglos y que use funciones específicas para: 
    Leer y registrar: Ingresar el nombre, precio y cantidad de nuevos productos, validando que los datos sean lógicos y positivos. 
    Mostrar inventario: Imprimir una tabla detallada con todos los productos registrados actualmente.  
    Buscar información: Localizar productos específicos mediante la coincidencia de texto en sus nombres.  
    Calcular estadísticas: Determinar el valor total del inventario, el promedio de precios y los valores máximos y mínimos.  
    Eliminar registros: Borrar productos seleccionados reorganizando el almacenamiento de los arreglos. 
     Analizar inversión (Mejora Creativa): Generar un reporte especializado que ordene los productos de mayor a menor valor monetario acumulado mediante el algoritmo de ordenamiento burbuja.
*/

#include <iostream>  // Para cin y cout
#include <string>    // Para usar el tipo string
#include <iomanip>   // Para dar formato a la salida (setw, fixed, setprecision)
using namespace std;
 
//Definición de constantes
const int MAX = 50;  // Máximo de productos que el sistema puede manejar
 
//Declaración de funciones para el sistema de control de productos
void mostrarMenu();
void registrarProducto(string nombres[], double precios[], int cantidades[], int &total);
void mostrarProductos(string nombres[], double precios[], int cantidades[], int total);
void buscarProducto(string nombres[], double precios[], int cantidades[], int total);
void calcularEstadisticas(string nombres[], double precios[], int cantidades[], int total);
void eliminarProducto(string nombres[], double precios[], int cantidades[], int &total);
void reporteValorInventario(string nombres[], double precios[], int cantidades[], int total);
bool validarEnteroPositivo(int &numero, string mensaje);
bool validarDecimalPositivo(double &numero, string mensaje);
void separador();

//  FUNCIÓN PRINCIPAL
int main() {
    //Declaración de los arreglos del inventario 
    //Cada posición i de los tres arreglos corresponde
    //al mismo producto: nombres[i], precios[i], cantidades[i]
    string nombres[MAX];
    double precios[MAX];
    int    cantidades[MAX];
    int    total = 0;  // Contador de productos registrados actualmente

    int opcion;  // Variable para leer la opción del menú
 
    // Bucle principal del programa
    // El programa sigue corriendo hasta que el usuario elija salir (opción 7)
    do {
        mostrarMenu();
        cout << "  Ingrese una opcion: ";
        cin  >> opcion;
 
        cout << endl;
 
        // Estructura switch para manejar cada opción del menú
        switch (opcion) {
            case 1:
                registrarProducto(nombres, precios, cantidades, total);
                break;
            case 2:
                mostrarProductos(nombres, precios, cantidades, total);
                break;
            case 3:
                buscarProducto(nombres, precios, cantidades, total);
                break;
            case 4:
                calcularEstadisticas(nombres, precios, cantidades, total);
                break;
            case 5:
                eliminarProducto(nombres, precios, cantidades, total);
                break;
            case 6:
                // ── MEJORA CREATIVA: Reporte de valor por producto ──
                reporteValorInventario(nombres, precios, cantidades, total);
                break;
            case 7:
                cout << "  Gracias por usar el sistema. Hasta luego!" << endl;
                separador();
                break;
            default:
                // Validación: opción fuera del rango 1–7
                cout << "  [ERROR] Opcion invalida. Por favor ingrese un numero entre 1 y 7." << endl;
                break;
        }
 
        cout << endl;
 
    } while (opcion != 7);  // Repite mientras el usuario no elija salir
 
    return 0;
}

// Muestra las opciones disponibles al usuario
void mostrarMenu() {
    cout << "============================================" << endl;
    cout << "      SISTEMA DE CONTROL DE PRODUCTOS" << endl;
    cout << "============================================" << endl;
    cout << "1. Registrar producto" << endl;
    cout << "2. Mostrar inventario" << endl;
    cout << "3. Buscar producto por nombre" << endl;
    cout << "4. Ver estadisticas del inventario" << endl;
    cout << "5. Eliminar producto" << endl;
    cout << "6. Reporte de valor por producto [EXTRA]" << endl;
    cout << "7. Salir" << endl;
    cout << "============================================" << endl;
}

//  Pide los datos del producto y los guarda en los arreglos
void registrarProducto(string nombres[], double precios[], int cantidades[], int &total) {
 
    cout << "---- REGISTRAR PRODUCTO ----" << endl;
 
    // Verificar si el inventario ya esta lleno
    if (total >= MAX) {
        cout << "El inventario esta lleno." << endl;
        return;
    }
 
    string nombre;
    double precio;
    int    cantidad;
    // Lectura del nombre del producto
    cout << "Nombre del producto: ";
    cin  >> nombre;
    // Validacion: el nombre no puede estar vacio
    cout << "Precio unitario: ";
    cin  >> precio;
 
    // Validacion: el precio no puede ser negativo ni cero
    if (precio <= 0) {
        cout << "Error: el precio debe ser mayor a 0." << endl;
        return;
    }
 
    cout << "Cantidad en inventario: ";
    cin  >> cantidad;
 
    // Validacion: la cantidad no puede ser negativa
    if (cantidad < 0) {
        cout << "Error: la cantidad no puede ser negativa." << endl;
        return;
    }

    // Guardar los datos en los arreglos en la posicion actual
    nombres[total]    = nombre;
    precios[total]    = precio;
    cantidades[total] = cantidad;
    total++;  // aumentar el contador de productos
 
    cout << "Producto registrado correctamente." << endl;
    cout << "Total de productos: " << total << endl;
}
 

//  Recorremos los arreglos y muestra todos los productos
void mostrarProductos(string nombres[], double precios[], int cantidades[], int total) {
 
    cout << "---- INVENTARIO COMPLETO ----" << endl;
    // Validar si no hay productos registrados
    if (total == 0) {
        cout << "No hay productos registrados." << endl;
        return;
    }
 
    // Recorrer e imprimir cada producto
    for (int i = 0; i < total; i++) {
        cout << "-----------------------------" << endl;
        cout << "Producto #" << (i + 1) << endl;
        cout << "Nombre  : " << nombres[i] << endl;
        cout << "Precio  : $" << precios[i] << endl;
        cout << "Cantidad: " << cantidades[i] << " unidades" << endl;
    }
 
    cout << "-----------------------------" << endl;
    cout << "Total de productos: " << total << endl;
}

//  Buscar un producto comparando el nombre exacto
void buscarProducto(string nombres[], double precios[], int cantidades[], int total) {
 
    cout << "---- BUSCAR PRODUCTO ----" << endl;
    // Validar si no hay productos registrados
    if (total == 0) {
        cout << "No hay productos registrados para buscar." << endl;
        return;
    }
    // Leer el nombre a buscar
    string busqueda;
    cout << "Ingrese el nombre del producto a buscar: ";
    cin  >> busqueda;
 
    bool encontrado = false;
 
    // Recorrer todos los productos y comparar el nombre
    for (int i = 0; i < total; i++) {
        if (nombres[i] == busqueda) {
            cout << "Producto encontrado:" << endl;
            cout << "Posicion: " << (i + 1) << endl;
            cout << "Nombre  : " << nombres[i] << endl;
            cout << "Precio  : $" << precios[i] << endl;
            cout << "Cantidad: " << cantidades[i] << " unidades" << endl;
            encontrado = true;
        }
    }
    // Si no se encontro ningun producto con ese nombre mostrar mensaje
    if (encontrado == false) {
        cout << "No se encontro ningun producto con ese nombre." << endl;
    }
}

//  Calcular y mostrar estadisticas del inventario: total de unidades, valor total, promedio de precios, producto mas caro y mas barato
void calcularEstadisticas(string nombres[], double precios[], int cantidades[], int total) {
 
    cout << "---- ESTADISTICAS DEL INVENTARIO ----" << endl;
    // Validar si no hay productos registrados
    if (total == 0) {
        cout << "No hay productos registrados." << endl;
        return;
    }
    // Variables para acumular los totales y encontrar maximos y minimos
    int    totalUnidades  = 0;
    double valorTotal     = 0;
    double sumaPrecios    = 0;
 
    // Inicializar maximo y minimo con el primer producto
    int indiceMasCaro   = 0;
    int indiceMasBarato = 0;
 
    // Recorrer todos los productos para calcular
    for (int i = 0; i < total; i++) {
        totalUnidades = totalUnidades + cantidades[i];
        valorTotal    = valorTotal + (precios[i] * cantidades[i]);
        sumaPrecios   = sumaPrecios + precios[i];
 
        // Comparar para encontrar el mas caro
        if (precios[i] > precios[indiceMasCaro]) {
            indiceMasCaro = i;
        }
 
        // Comparar para encontrar el mas barato
        if (precios[i] < precios[indiceMasBarato]) {
            indiceMasBarato = i;
        }
    }
    // Calcular el precio promedio
    double promedio = sumaPrecios / total;
 
    cout << "Productos distintos      : " << total << endl;
    cout << "Total de unidades        : " << totalUnidades << endl;
    cout << "Valor total en inventario: $" << valorTotal << endl;
    cout << "Precio promedio          : $" << promedio << endl;
    cout << "-----------------------------" << endl;
    cout << "Producto mas caro  : " << nombres[indiceMasCaro]  << " ($" << precios[indiceMasCaro]  << ")" << endl;
    cout << "Producto mas barato: " << nombres[indiceMasBarato] << " ($" << precios[indiceMasBarato] << ")" << endl;
}

//  Elimina un producto por numero de posicion y
//  desplaza los siguientes para cerrar el hueco
void eliminarProducto(string nombres[], double precios[], int cantidades[], int &total) {
 
    cout << "---- ELIMINAR PRODUCTO ----" << endl;
 
    // Validar si no hay productos registrados
    if (total == 0) {
        cout << "No hay productos para eliminar." << endl;
        return;
    }
 
    // Mostrar la lista antes de pedir la posicion
    mostrarProductos(nombres, precios, cantidades, total);
 
    int posicion;
    cout << "Ingrese el numero del producto a eliminar: ";
    cin  >> posicion;
 
    // Validar que la posicion este dentro del rango
    if (posicion < 1 || posicion > total) {
        cout << "Error: posicion invalida." << endl;
        return;
    }
 
    int indice = posicion - 1;  // convertir posicion a indice de arreglo
    string nombreEliminado = nombres[indice];
 
    // Desplazar todos los elementos hacia atras para cerrar el hueco
    for (int i = indice; i < total - 1; i++) {
        nombres[i]    = nombres[i + 1];
        precios[i]    = precios[i + 1];
        cantidades[i] = cantidades[i + 1];
    }
 
    total--;  // reducir el contador
 
    // Mostrar mensaje de confirmacion y el total actualizado
    cout << "Producto '" << nombreEliminado << "' eliminado." << endl;
    cout << "Productos restantes: " << total << endl;
}
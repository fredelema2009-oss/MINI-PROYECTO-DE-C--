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

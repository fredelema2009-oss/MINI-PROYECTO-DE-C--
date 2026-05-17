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


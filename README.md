#  Sistema de Control de Productos

# Mini-proyecto de C++ estructurado — Bootcamp "Programación de Cero a POO"

-------------------------

##  Descripción

**Sistema de Control de Productos** es un programa de consola desarrollado en C++ que permite gestionar un inventario básico de productos de forma sencilla e interactiva. El sistema facilita el registro, visualización, búsqueda y análisis de productos, brindando al usuario información clara y ordenada en todo momento.

El programa fue construido aplicando los principios de programación estructurada: uso de funciones, arreglos, estructuras de control y validaciones de entrada.

------------------------------------

##  Funcionalidades principales

- **Registrar productos** — permite ingresar nombre, precio y cantidad de cada producto
- **Mostrar inventario** — lista todos los productos registrados con su información completa
- **Buscar producto por nombre** — localiza un producto específico dentro del inventario
- **Calcular estadísticas** — muestra el total de productos, el valor total del inventario, el producto más caro y el más económico
- **Eliminar producto** — permite eliminar un producto del inventario por su posición
- **Menú principal interactivo** — navegación clara entre todas las opciones del sistema
- **Validaciones de entrada** — el sistema detecta y rechaza datos inválidos (precios negativos, cantidades negativas, nombres vacíos, opciones fuera de rango)

-------------------------------------------------

##  Mejora creativa — Reporte de valor por producto

Como mejora creativa, el sistema incluye una funcionalidad de **reporte de valor por producto**, que calcula el *valor total en inventario* de cada ítem (precio × cantidad) y los muestra ordenados de mayor a menor valor acumulado.

Esto permite identificar rápidamente qué productos representan mayor inversión en bodega, aportando un análisis útil más allá del simple listado.

------------------------------------------------

##  Estructura del proyecto


- **Variables y Tipos de Datos**: Se emplean tipos "string" para descripciones, "float" para valores monetarios y "int" para el control de inventario y menús.
- **Entrada y Salida de Datos**: Uso de "cin" con limpieza de búfer para capturar datos y "cout" para generar una interfaz de usuario clara y legible en consola.  
- **Estructuras Condicionales**: Aplicación de sentencias "if-else" para la validación de rangos y un selector switch para gestionar la navegación del menú principal. 
- **Estructuras Repetitivas**: Implementación de ciclos for para recorrer los arreglos y un bucle "do-while" que mantiene el programa en ejecución hasta que el usuario decida salir.  
- **Arreglos**: Gestión de la información mediante arreglos paralelos que almacenan los datos de hasta 50 productos de forma simultánea.  
- **Funciones**: El código está totalmente modularizado, separando la lógica de registro, visualización y procesamiento en funciones independientes fuera del "main()".  
- **Validaciones**: Se incluyeron filtros de seguridad que impiden el ingreso de números negativos o carácteres inválidos, asegurando la integridad del sistema.  
- **Lógica Clara de Solución**: El programa sigue un flujo lineal lógico: Entrada (Registro) -> Procesamiento (Cálculos y Alertas) -> Salida (Reportes e Inventario). 

---

## Autor

**[Frederick Lema]**  
Bootcamp "Programación de Cero a POO"  
Módulo: Clase 11 - Mini-proyecto de C++

---

# Instrucciones de Ejecución
1. Asegúrate de tener un compilador de C++ instalado (como g++).
2. Clona el repositorio.
3. Compila el archivo: g++ SistemaDeControlDeProductos.cpp -o SistemaDeControlDeProductos
4. Ejecuta el programa: ./SistemaDeControlDeProductos
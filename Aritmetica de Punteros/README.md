# Aritmética de Punteros - Estructura de Datos (UNMSM)

Este proyecto demuestra los conceptos fundamentales de la **Aritmética de Punteros** en C++, siguiendo la guía teórica proporcionada en la Sesión 9.

##  Conceptos Implementados

### 1. Equivalencia Puntero-Arreglo
En C++, el nombre de un arreglo decae en un puntero a su primer elemento. Por lo tanto:
- `p = a;` es idéntico a `p = &a[0];`
- El acceso `a[i]` es equivalente a `*(p + i)`.

### 2. Las Cuatro Notaciones Equivalentes
Para asignar o acceder a un valor en una posición `i`, existen cuatro formas válidas e idénticas:
1. `p[i] = valor;` (Notación de índice sobre puntero)
2. `*(p + i) = valor;` (Suma de puntero + offset, desreferencia)
3. `*(i + p) = valor;` (Suma conmutativa)
4. `i[p] = valor;` (Notación invertida: `a[b] = b[a]`)

### 3. Índices Negativos
Es posible usar índices negativos con punteros si este apunta a una posición intermedia de un arreglo. Ejemplo:
- Si `p = a + 5;`, entonces `p[-2]` accede a la posición `a[3]`.

### 4. Punteros a Cadenas
Se demuestra la manipulación de arreglos de caracteres (`char*`) utilizando aritmética para modificar elementos específicos de la cadena.

### 5. Escalado de Memoria
Las direcciones de memoria avanzan automáticamente según el tamaño del tipo de dato (`sizeof`). 
- Un puntero `int*` avanza **4 bytes** por cada incremento de `+1`.

---

##  Estructura del Proyecto

El código está organizado de forma modular siguiendo estándares de ingeniería:

- `main.cpp`: Punto de entrada del programa.
- `Demos.cpp`: Coordinador de las demostraciones de punteros.
- `pointers.h` / `pointers.cpp`: Implementación de la lógica de aritmética de punteros.
- `util.h` / `util.cpp`: Funciones auxiliares para formateo de consola.
- `Makefile`: Automatización de la compilación.

---


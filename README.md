# TAREA GRUPAL: Implementar en C++ Avanzado

## ESTRUCTURA DE DATOS

**Grupo:** 3  
**Curso:** Estructura de Datos

---

## 👥 Integrantes

|  Rol   | Apellidos y Nombres                  |  Código  |
| :----: | :----------------------------------- | :------: |
| **C3** | Quezada Pairazaman Sebastian Emanuel | 24200030 |
|        | Torreblanca Toledo Richard Anderson  | 24200041 |
|        | Huaman Ibarra Jonathan Oscar         | 24200147 |
|        | Prudencio Vargas Ricardo             | 24200028 |
|        | Zelada Llaxa Junior Clisman          | 24200071 |
|        | Meza Dalguer Anyel Giuliana          | 24200111 |
|        | Tohalino Aroste Fabio Antonio        | 24200175 |

---

## 📘 Descripción del Trabajo

Este trabajo aborda la implementación teórica y práctica de estructuras de datos lineales y jerárquicas avanzadas, así como características modernas del lenguaje C++ para la programación genérica y manipulación de memoria.

A continuación, se detallan los módulos desarrollados en este entregable:

### 1. Pilas (Stack)

Implementación de una estructura **LIFO** (Last In, First Out) utilizando herencia de una clase base `CArray` para la gestión dinámica de memoria.

- **Operaciones:** `push`, `pop`, `top`, `search`.
- **Características:** Redimensionamiento automático y manejo de excepciones (`std::underflow_error`).

### 2. Colas (Queue) [cite: 964]

Implementación de una estructura **FIFO** (First In, First Out) optimizada mediante un **arreglo circular**.

- **Optimización:** Uso de aritmética modular para los índices `front` y `rear` para evitar desplazamientos costosos de memoria.
- **Operaciones:** `enqueue`, `dequeue`, `search`, eliminación por valor e índice.

### 3. Clases en C++ y Punteros a Miembros

Aplicación de punteros que referencian atributos o métodos de una clase de forma genérica, permitiendo aplicar lógica sobre cualquier instancia.

- **Operadores:** Uso de `.*` (objeto directo) y `->*` (puntero a objeto).
- **Aplicación:** Implementación de Tablas de Despacho (Dispatch Tables) para selección dinámica de funciones.

### 4. Aritmética de Punteros

Manipulación directa de direcciones de memoria y equivalencia entre notación de arreglos y punteros.

- **Conceptos:** Desplazamiento basado en `sizeof`, índices negativos (ej. `p[-2]`) y equivalencia de notaciones (`a[i]` vs `*(a+i)`).

### 5. Árboles B (B-Trees)

Estructuras auto-balanceadas de orden _m_, optimizadas para el acceso a grandes bloques de datos.

- **Propiedades:** Nodos con múltiples claves e hijos, minimizando la altura del árbol.
- **Algoritmos:** Manejo de **Overflow** mediante _Split_ (división y ascenso de mediana) y **Underflow** mediante Redistribución o Concatenación.

### 6. Templates Variádicos y ForEach

Uso de características modernas de C++ para definir funciones y clases que aceptan un número variable de argumentos (_Parameter Packs_).

- **Implementación:** Algoritmo `ForEach` genérico capaz de invocar funciones con diferente aridad (cantidad de argumentos) sobre un contenedor `CArray`.

### 7. Árboles Binarios de Búsqueda (BST)

Estructura jerárquica donde cada nodo tiene como máximo dos hijos, manteniendo la propiedad de orden (izquierda < padre < derecha).

- **Genericidad:** Uso de `Traits` para definir tipos y comparadores personalizados.
- **Operaciones:** Inserción recursiva, búsqueda logarítmica O(log n), eliminación (casos de hoja, 1 hijo, 2 hijos) y recorrido Inorden utilizando templates variádicos.

---

## ⚙️ Requisitos

- **Lenguaje:** C++
- **Estándar:** C++17 o superior.

---

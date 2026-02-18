# Árboles Binarios de Búsqueda (BST)

## Autor
Prudencio Vargas Ricardo Nicolas  
Código: 24200028  

---

## ¿Qué es un Árbol Binario de Búsqueda (BST)?

Un Árbol Binario de Búsqueda (Binary Search Tree - BST) es una estructura de datos jerárquica donde cada nodo tiene como máximo dos hijos y cumple la siguiente propiedad:

- Todos los valores del subárbol izquierdo son menores que el nodo.
- Todos los valores del subárbol derecho son mayores que el nodo.

Esta propiedad permite realizar búsquedas eficientes con complejidad promedio O(log n).

---

## Operaciones Implementadas

En esta implementación se desarrollaron las siguientes operaciones:

### 1. Inserción
Permite agregar un nuevo elemento respetando la propiedad del BST.

### 2. Búsqueda
Permite verificar si un elemento existe en el árbol.

### 3. Eliminación
Permite eliminar un nodo considerando los tres casos:
- Nodo hoja
- Nodo con un hijo
- Nodo con dos hijos

### 4. Recorridos
Se implementaron los siguientes recorridos:

- InOrder (Izquierda - Raíz - Derecha)
- PreOrder (Raíz - Izquierda - Derecha)
- PostOrder (Izquierda - Derecha - Raíz)

---

## Complejidad

- Búsqueda: O(log n) promedio
- Inserción: O(log n) promedio
- Eliminación: O(log n) promedio

En el peor caso (árbol desbalanceado), las operaciones pueden degradarse a O(n).

---

## Archivos del Proyecto

- BST.h → Definición de la clase y estructura del nodo.
- BST.cpp → Implementación de los métodos.
- main.cpp → Programa principal de prueba.


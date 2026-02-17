# Colas (Queue)

## Concepto
Una cola es una estructura de datos lineal que sigue el principio **FIFO (First In, First Out)**: el primero en entrar es el primero en salir.

## Operaciones Fundamentales
- **enqueue(x):** Inserta un elemento al final.
- **dequeue():** Elimina y retorna el frente.
- **front():** Retorna el frente sin eliminar.
- **back():** Retorna el último sin eliminar.
- **empty():** Verifica si está vacía.

## Implementación Circular
La cola se implementa con un arreglo circular. Los índices `front` y `rear` avanzan con el operador módulo `%`.

## Ejemplo de Uso
```cpp
CQueue<int> cola;
cola.enqueue(10);
cola.enqueue(20);
cola.enqueue(30);

cout << cola.front(); // 10
cola.dequeue();       // elimina 10

Capacidad = 8, Count = 3
┌───┬───┬───┬───┬───┬───┬───┬───┐
│10 │20 │30 │   │   │   │   │   │
└───┴───┴───┴───┴───┴───┴───┴───┘
 ↑               ↑
front           rear


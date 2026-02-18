# COLA (QUEUE) - Estructura de Datos

## Introducción
Una cola (queue) es una estructura de datos lineal que sigue el principio FIFO (First In, First Out): el primer elemento en entrar es el primero en salir. Se puede visualizar como una fila de personas esperando ser atendidas.

## Clases Implementadas

### CArray.h
Clase base que maneja un arreglo dinámico. Proporciona la gestión de memoria y operaciones básicas:
- `resize()`: Redimensiona el arreglo
- `operator[]`: Acceso por índice
- `size()` y `empty()`: Consultas de estado

template <typename T>
class CArray {
protected:
    T* m_data;      // Puntero al arreglo
    int m_size;      // Elementos actuales
    int m_capacity;  // Capacidad total
};

### CQueue.h
Clase principal que implementa la cola circular heredando de CArray. Contiene TODOS los métodos de la teoría:

| Método | Descripción | Complejidad |
|--------|-------------|-------------|
| enqueue(val) | Inserta al final | O(1) |
| dequeue() | Elimina y retorna el frente | O(1) |
| front() | Retorna el frente sin eliminar | O(1) |
| back() | Retorna el final sin eliminar | O(1) |
| search(val) | Busca un valor (0 = frente) | O(n) |
| removeByValue(val) | Elimina por valor | O(n) |
| removeByIndex(idx) | Elimina por posición | O(n) |
| print() | Muestra la cola completa | O(n) |
| count() | Retorna número de elementos | O(1) |

## Programa Principal

### main.cpp
Contiene un menú interactivo que permite probar cada operación de la cola:
- Insertar elementos (enqueue)
- Eliminar frente (dequeue)
- Consultar frente y final
- Buscar elementos
- Eliminar por valor o posición
- Ver estado actual de la cola
- Demo ejemplar: Muestra una ejecución completa de todos los métodos

### funciones_colas.h / .cpp
Funciones auxiliares que incluyen:
- mostrarCola(): Muestra información de la cola
- demoEjemplar(): Demostración completa con todos los métodos

## Cómo ejecutar

### Compilar:
g++ main.cpp funciones_colas.cpp -o colas.exe

### Ejecutar:
.\colas.exe
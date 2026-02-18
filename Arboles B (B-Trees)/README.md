# Implementación Técnica de Árbol B (C++)

Este repositorio contiene una implementación funcional de un Árbol B, centrada en la eficiencia de búsqueda e inserción mediante el manejo de múltiples claves por nodo.

## Funcionalidad del Código

### 1. Estructura del Nodo (`NodoB`)
El corazón del sistema es la estructura `NodoB`, que gestiona:
- **Claves**: Un arreglo de tamaño `M` para almacenar los datos.
- **Hijos**: Un arreglo de punteros `M + 1` para la navegación.
- **Estado**: Controla el número actual de claves (`numClaves`) y si es un nodo hoja (`esHoja`).

### 2. Lógica de Inserción (`ArbolB::insertar`)
La inserción sigue una estrategia preventiva:
- **División de Nodos (`dividirHijo`)**: Cuando un nodo alcanza el límite `M`, se divide automáticamente, promoviendo la clave media al padre. Esto garantiza que el árbol nunca exceda su capacidad y se mantenga balanceado.
- **Inserción en Hoja**: Las nuevas claves siempre se insertan inicialmente en los nodos hoja, desplazando las existentes para mantener el orden.

### 3. Búsqueda y Navegación
- **`buscar(T k)`**: Realiza una búsqueda recursiva comparando la clave con los elementos del nodo actual para decidir qué rama seguir.
- **`recorrer()`**: Implementa un recorrido in-order que imprime todas las claves en orden ascendente, verificando visualmente la integridad del árbol.

## Cómo Usar el Código

### Compilación Directa
```powershell
g++ -Wall -I. -std=c++11 main.cpp DemoBTree.cpp -o btree_program.exe
```

### Flujo de Ejecución
El programa `main.cpp` utiliza la función `ejecutarDemoArbolB()` para:
1. Instanciar un `ArbolB<int, 5>`.
2. Insertar una secuencia de números.
3. Mostrar el árbol resultante mediante `recorrer()`.
4. Validar la existencia de claves específicas mediante `buscar()`.

---
*Enfoque: Estructuras de Datos Dinámicas y Gestión de Nodos.*

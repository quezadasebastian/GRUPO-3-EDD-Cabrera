# Clases en C++ y Punteros a Miembros

## Concepto

Un **Puntero a Miembro** es una característica avanzada de C++ que permite almacenar la dirección de un atributo o método de una clase de forma genérica, sin estar atado a una instancia específica

A diferencia de un puntero normal, un puntero a miembro no guarda una dirección de memoria absoluta (como `0x7fff...`), sino el **offset (desplazamiento)** del miembro dentro de la estructura de la clase

## Operadores Fundamentales

Para utilizar estos punteros, necesitamos un objeto concreto (la instancia) y operadores especiales de "desreferencia":

- **`.*` (Punto-Asterisco):** Se usa cuando tenemos el objeto directo (`obj`).
  - Ejemplo: `obj.*ptr`
- **`->*` (Flecha-Asterisco):** Se usa cuando tenemos un puntero al objeto (`pObj`).
  - Ejemplo: `pObj->*ptr`

## Sintaxis de Declaración

| Tipo         | Declaración              | Asignación         |
| :----------- | :----------------------- | :----------------- |
| **Atributo** | `int Clase::*ptr`        | `&Clase::atributo` |
| **Método**   | `int (Clase::*ptr)(int)` | `&Clase::metodo`   |

## Tabla de Despacho (Dispatch Table)

Podemos crear arreglos de punteros a métodos para seleccionar dinámicamente qué función ejecutar en tiempo de ejecución. Esto permite cambiar el comportamiento del objeto sin usar `if/else` o `switch`

## Ejemplo de Uso

```cpp
// 1. Definimos el puntero
int (MathCore::*operacion)(int);

// 2. Lo apuntamos a un método (ej. sumar)
operacion = &MathCore::sumarConX;

MathCore obj(10, 20); // x=10, y=20

// 3. Ejecutamos dinámicamente
// (obj.*operacion)(5) -> Equivale a: obj.sumarConX(5)
cout << (obj.*operacion)(5); // Salida: 15
```

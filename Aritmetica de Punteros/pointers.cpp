#include "pointers.h"
#include "util.h"
#include <iostream>

/**
 * 4.1 Equivalencia Puntero-Arreglo
 * Demuestra que el nombre de un arreglo decae en un puntero a su primer
 * elemento.
 */
void demoEquivalenciaArreglo() {
  imprimirLineaSeparadora("4.1 EQUIVALENCIA PUNTERO-ARREGLO");
  int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  int *p = a; // Equivalente a p = &a[0]

  std::cout << "Direccion base p (a[0]): " << p << std::endl;
  std::cout << "Acceso a[7] (tradicional): " << a[7] << std::endl;
  std::cout << "Acceso *(a + 7) (aritmetica): " << *(a + 7) << std::endl;
  std::cout << "Acceso *(p + 7) (sobre puntero): " << *(p + 7) << std::endl;
}

/**
 * 4.2 Cuatro Notaciones Equivalentes
 * Muestra las 4 formas validas e identicas de acceder a un arreglo usando
 * punteros.
 */
void demoCuatroNotaciones() {
  imprimirLineaSeparadora("4.2 CUATRO NOTACIONES EQUIVALENTES");
  int arr[10] = {0};
  int *p = arr;
  int pos = 7;
  int val = 13;

  // 1. Notación de índice sobre puntero
  p[pos] = val;
  std::cout << "1. p[" << pos << "] = " << val << " \t-> arr[7]: " << arr[pos]
            << std::endl;

  // 2. Suma de puntero + offset, desreferencia
  val++;
  *(p + pos) = val;
  std::cout << "2. *(p + " << pos << ") = " << val
            << " \t-> arr[7]: " << arr[pos] << std::endl;

  // 3. Suma conmutativa
  val++;
  *(pos + p) = val;
  std::cout << "3. *(" << pos << " + p) = " << val
            << " \t-> arr[7]: " << arr[pos] << std::endl;

  // 4. Notación invertida (a[b] = b[a])
  val++;
  pos[p] = val;
  std::cout << "4. " << pos << "[p] = " << val << " \t-> arr[7]: " << arr[pos]
            << std::endl;
}

/**
 * 4.3 Indices Negativos
 * Demuestra como retroceder en memoria usando indices negativos sobre un
 * puntero desplazado.
 */
void demoIndicesNegativos() {
  imprimirLineaSeparadora("4.3 INDICES NEGATIVOS");
  int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int *p = a + 5; // p apunta a a[5]

  std::cout << "p apunta a a[5] (valor " << *p << " en direccion " << p << ")"
            << std::endl;
  std::cout << "p[-2] accede a " << p[-2] << " (a[3])" << std::endl;
  std::cout << "*(p - 2) accede a " << *(p - 2) << " (equivalente)"
            << std::endl;

  p[-2] = 99;
  std::cout << "Despues de p[-2] = 99, el arreglo es: " << std::endl;
  imprimirArreglo(a, 10);
}

/**
 * 4.5 Punteros a Cadenas
 * Manipulacion de punteros sobre arreglos de caracteres.
 */
void demoPunterosCadenas() {
  imprimirLineaSeparadora("4.5 PUNTEROS A CADENAS");
  char str[] = "UNXSM"; // Usamos arreglo para que sea modificable
  char *pStr = str;
  char *p2 = pStr + 3; // Apunta a 'S'

  std::cout << "Cadena actual: " << str << std::endl;
  std::cout << "p2 apunta a: '" << *p2 << "' (en pStr+3)" << std::endl;

  // Modificando usando aritmetica
  *(p2 - 1) = 'X';
  std::cout << "*(p2 - 1) = 'X' \t-> " << str << std::endl;

  p2[-1] = 'Z';
  std::cout << "p2[-1] = 'Z' \t\t-> " << str << std::endl;
}

/**
 * 4.4 Esquema de Memoria
 * Muestra como las direcciones avanzan segun el sizeof(tipo).
 */
void demoEscaladoMemoria() {
  imprimirLineaSeparadora("4.4 ESQUEMA DE MEMORIA (ESCALADO)");
  int a[5] = {10, 20, 30, 40, 50};
  int *p = a;

  std::cout << "sizeof(int) = " << sizeof(int) << " bytes" << std::endl;
  std::cout << "Indice\tValor\tDireccion\tDiferencia (bytes)" << std::endl;

  for (int i = 0; i < 5; ++i) {
    long offset = (long)(p + i) - (long)p;
    std::cout << "[" << i << "]\t" << *(p + i) << "\t" << (p + i) << "\t"
              << offset << std::endl;
  }
}

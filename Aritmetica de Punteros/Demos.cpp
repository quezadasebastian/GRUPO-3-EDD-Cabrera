#include "pointers.h"
#include <iostream>

/**
 * @brief Ejecuta todas las demostraciones de aritmetica de punteros.
 * Esta funcion centraliza las llamadas para mantener el main limpio.
 */
void ejecutarTodasLasDemos() {
  std::cout << "Iniciando secuencia de demostraciones...\n" << std::endl;

  demoEquivalenciaArreglo();
  demoCuatroNotaciones();
  demoIndicesNegativos();
  demoPunterosCadenas();
  demoEscaladoMemoria();
}

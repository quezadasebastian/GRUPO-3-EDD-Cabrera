#include "util.h"
#include <iomanip>
#include <iostream>

void imprimirArreglo(int *arr, int size) {
  std::cout << "[ ";
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << (i == size - 1 ? "" : ", ");
  }
  std::cout << " ]" << std::endl;
}

void imprimirLineaSeparadora(const char *titulo) {
  std::cout << "\n" << std::setfill('-') << std::setw(60) << "" << std::endl;
  std::cout << "  " << titulo << std::endl;
  std::cout << std::setfill('-') << std::setw(60) << "" << std::setfill(' ')
            << std::endl;
}

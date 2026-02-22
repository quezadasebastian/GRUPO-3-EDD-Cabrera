#ifndef POINTERS_H
#define POINTERS_H

#include "types.h"

using PtrMetodo = int (Tipos::*)(int);
using PtrAtributo = int Tipos::*;

void demostrarPunterosAtributos();
void demostrarPunterosMetodos();
void demostrarTablaDespacho();

#endif
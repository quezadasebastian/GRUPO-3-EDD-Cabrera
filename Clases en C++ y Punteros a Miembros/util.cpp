#include "util.h"
#include <iostream>
using namespace std;

void imprimirEstado(const Tipos& obj, std::string contexto) {
    cout << "  [Estado " << contexto << "] x=" << obj.x << ", y=" << obj.y << endl;
}
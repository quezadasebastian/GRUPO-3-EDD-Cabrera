#include "containers/BTree.h"
#include "util.h"
#include <iostream>

// Función para ejecutar la demostración del Árbol B
void ejecutarDemoArbolB() {
    std::cout << "Iniciando Demo de Árbol B..." << std::endl;
    util::imprimirSeparador();

    ArbolB<int, 5> t; // Un Árbol B con máximo de claves M = 5
    
    int claves[] = {10, 20, 5, 6, 12, 30, 7, 17};
    int n = sizeof(claves) / sizeof(claves[0]);

    for (int i = 0; i < n; i++) {
        std::cout << "Insertando: " << claves[i] << std::endl;
        t.insertar(claves[i]);
    }

    std::cout << "Recorrido del árbol construido:";
    t.recorrer();
    std::cout << std::endl;

    int k = 6;
    (t.buscar(k) != nullptr) ? std::cout << "\nPresente" : std::cout << "\nNo Presente";

    k = 15;
    (t.buscar(k) != nullptr) ? std::cout << "\nPresente" : std::cout << "\nNo Presente";
    
    std::cout << std::endl;
    util::imprimirSeparador();
}




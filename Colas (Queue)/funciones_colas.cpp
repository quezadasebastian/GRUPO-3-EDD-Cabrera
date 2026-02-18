#include "funciones_colas.h"
#include <iostream>
#include <string>
using namespace std;

void mostrarCola(const CQueue<string>& cola) {
    cout << "[ ";
    cout << "Elementos en cola: " << cola.count() << " ";
    cout << "]\n";
}

void demoEjemplar() {
    cout << "\n___________________________________\n";
    cout << "|   DEMOSTRACION COMPLETA DE COLA    |\n";
    cout << "____________________________________\n";
    
    CQueue<int> colaDemo;
    
    // 1. ENQUEUE - Insertar elementos
    cout << "\n 1. ENQUEUE (Insertar al final)\n";
    cout << "   Insertando: 10, 20, 30, 40, 50\n\n";
    
    cout << "   Estado inicial: ";
    colaDemo.print();
    cout << "\n";
    
    for(int i = 1; i <= 5; i++) {
        cout << "   enqueue(" << i*10 << ") ";
        colaDemo.enqueue(i * 10);
        colaDemo.print();
        cout << "\n";
    }
    
    // 2. FRONT - Ver frente
    cout << "\n 2. FRONT (Ver frente sin eliminar)\n";
    cout << "   Cola actual: ";
    colaDemo.print();
    cout << "\n   Elemento al frente: " << colaDemo.front() << "\n";
    
    // 3. BACK - Ver final
    cout << "\n 3. BACK (Ver final sin eliminar)\n";
    cout << "   Cola actual: ";
    colaDemo.print();
    cout << "\n   Elemento al final: " << colaDemo.back() << "\n";
    
    // 4. SEARCH - Buscar
    cout << "\n 4. SEARCH (Buscar valor)\n";
    cout << "   Cola actual: ";
    colaDemo.print();
    int valorBuscar = 30;
    int pos = colaDemo.search(valorBuscar);
    if(pos != -1)
        cout << "\n   Valor " << valorBuscar << " encontrado en posicion: " << pos << " (desde frente)\n";
    else
        cout << "\n   Valor " << valorBuscar << " no encontrado\n";
    
    // 5. DEQUEUE - Eliminar frente
    cout << "\n 5. DEQUEUE (Eliminar frente)\n";
    cout << "   Cola antes: ";
    colaDemo.print();
    int eliminado = colaDemo.dequeue();
    cout << "\n   Elemento eliminado: " << eliminado;
    cout << "\n   Cola despues: ";
    colaDemo.print();
    cout << "\n";
    
    // 6. REMOVE BY VALUE - Eliminar por valor
    cout << "\n 6. REMOVE BY VALUE (Eliminar por valor)\n";
    cout << "   Cola antes: ";
    colaDemo.print();
    int valorEliminar = 40;
    if(colaDemo.removeByValue(valorEliminar)) {
        cout << "\n   Valor " << valorEliminar << " eliminado";
        cout << "\n   Cola despues: ";
        colaDemo.print();
    } else {
        cout << "\n   Valor " << valorEliminar << " no encontrado";
    }
    cout << "\n";
    
    // 7. REMOVE BY INDEX - Eliminar por indice
    cout << "\n 7. REMOVE BY INDEX (Eliminar por posicion)\n";
    cout << "   Cola antes: ";
    colaDemo.print();
    int indiceEliminar = 0; // El frente actual
    if(colaDemo.removeByIndex(indiceEliminar)) {
        cout << "\n   Elemento en indice " << indiceEliminar << " (frente) eliminado";
        cout << "\n   Cola despues: ";
        colaDemo.print();
    } else {
        cout << "\n   Indice invalido";
    }
    cout << "\n";
    
    cout << "\nDemostracion completada exitosamente.\n\n";
}
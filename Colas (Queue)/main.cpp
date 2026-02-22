#include <iostream>
#include <string>
#include <limits>
#include "CQueue.h"
#include "funciones_colas.h"

using namespace std;

void limpiarPantalla() {
    // Limpiar pantalla (funciona en Windows y Linux)
    system("cls || clear");
}

void pausar() {
    cout << "\nPresiona Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    CQueue<string> cola;
    int opcion;
    string valor;
    
    do {
        limpiarPantalla();
        cout << "______________________________________\n";
        cout << "|     SISTEMA DE COLAS (QUEUE)       |\n";
        cout << "--------------------------------------\n";
        cout << "|  1. ENQUEUE (Insertar)             |\n";
        cout << "|  2. DEQUEUE (Eliminar frente)      |\n";
        cout << "|  3. FRONT (Ver frente)              |\n";
        cout << "|  4. BACK (Ver final)                |\n";
        cout << "|  5. SEARCH (Buscar valor)           |\n";
        cout << "|  6. REMOVE BY VALUE (Eliminar val)  |\n";
        cout << "|  7. REMOVE BY INDEX (Eliminar pos)  |\n";
        cout << "|  8. MOSTRAR COLA                     |\n";
        cout << "|  9. DEMO EJEMPLAR COMPLETA          |\n";
        cout << "|  0. Salir                           |\n";
        cout << "_______________________________________\n";
        cout << "Elementos en cola: " << cola.count() << "\n";
        cout << "\nOpcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1: // ENQUEUE
                cout << "\nENQUEUE - Insertar elemento\n";
                cout << "Valor a insertar: ";
                cin >> valor;
                cola.enqueue(valor);
                cout << "\"" << valor << "\" insertado en la cola.\n";
                pausar();
                break;
                
            case 2: // DEQUEUE
                cout << "\nDEQUEUE - Eliminar frente\n";
                try {
                    valor = cola.dequeue();
                    cout << "Elemento \"" << valor << "\" eliminado del frente.\n";
                } catch(const underflow_error&) {
                    cout << "Error: La cola esta vacia.\n";
                }
                pausar();
                break;
                
            case 3: // FRONT
                cout << "\nFRONT - Ver frente\n";
                try {
                    cout << "Elemento al frente: \"" << cola.front() << "\"\n";
                } catch(const underflow_error&) {
                    cout << "La cola esta vacia.\n";
                }
                pausar();
                break;
                
            case 4: // BACK
                cout << "\nBACK - Ver final\n";
                try {
                    cout << "Elemento al final: \"" << cola.back() << "\"\n";
                } catch(const underflow_error&) {
                    cout << "La cola esta vacia.\n";
                }
                pausar();
                break;
                
            case 5: {// SEARCH
                cout << "\nSEARCH - Buscar valor\n";
                cout << "Valor a buscar: ";
                cin >> valor;
                int pos = cola.search(valor);
                if(pos != -1) {
                    cout << "\"" << valor << "\" encontrado en posición: " << pos 
                         << " (0 = frente)\n";
                } else {
                    cout << "\"" << valor << "\" no encontrado en la cola.\n";
                }
                pausar();
                break;
            }
            case 6: // REMOVE BY VALUE
                cout << "\nREMOVE BY VALUE - Eliminar por valor\n";
                cout << "Valor a eliminar: ";
                cin >> valor;
                if(cola.removeByValue(valor)) {
                    cout << "Primera ocurrencia de \"" << valor << "\" eliminada.\n";
                } else {
                    cout << "\"" << valor << "\" no encontrado en la cola.\n";
                }
                pausar();
                break;
                
            case 7: // REMOVE BY INDEX
                cout << "\nREMOVE BY INDEX - Eliminar por posición\n";
                cout << "Posición a eliminar (0 = frente): ";
                int idx;
                cin >> idx;
                if(cola.removeByIndex(idx)) {
                    cout << "Elemento en posición " << idx << " eliminado.\n";
                } else {
                    cout << "Índice inválido. La cola tiene " << cola.count() << " elementos.\n";
                }
                pausar();
                break;
                
            case 8: // MOSTRAR COLA
                cout << "\nESTADO ACTUAL DE LA COLA\n";
                cout << "   ";
                cola.print();
                cout << "\n";
                mostrarCola(cola);
                pausar();
                break;
                
            case 9: // DEMO EJEMPLAR
                demoEjemplar();
                pausar();
                break;
                
            case 0:
                cout << "\nHasta luego!\n";
                break;
                
            default:
                cout << "\nOpción no válida. Intenta de nuevo.\n";
                pausar();
        }
    } while(opcion != 0);
    
    return 0;
}
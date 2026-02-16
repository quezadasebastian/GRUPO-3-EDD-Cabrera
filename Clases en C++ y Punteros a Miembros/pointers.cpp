#include "pointers.h"
#include "util.h"
#include <iostream>
#include <vector>

using namespace std;

/*
@author Quezada Pairazaman Sebastian Emanuel - [24200030]
*/

/*
Metodo para demostrar:
    Uso de Puntero a Objeto directo
    Uso de Puntero a objeto modificando su valor
*/
void demostrarPunterosAtributos() {
    cout << "\n 1. Demo Punteros a Atributos" << endl;
    PtrAtributo pAtrX = &Tipos::x;
    PtrAtributo pAtrY = &Tipos::y;
    Tipos obj(10, 20);
    Tipos* pObj = &obj;

    imprimirEstado(obj, "Inicial");
    // Uso con Objeto directo
    cout << "  -> Accediendo a obj.*pAtrX: " << obj.*pAtrX << endl;
    // Uso con Puntero a Objeto (Modificando a Y)
    cout << "  -> Modificando pObj->*pAtrY = 999..." << endl;
    pObj->*pAtrY = 999; 
    imprimirEstado(obj, "Final");
}

/*
Metodo para demostrar uso de Punteros a Metodos
*/
void demostrarPunterosMetodos() {
    cout << "\n 2. Demo Punteros a Metodos" << endl;

    PtrMetodo miFuncion = &Tipos::sumarConX; 
    Tipos obj(5, 5); 
    int argumento = 10;

    //Llamada a sumarConX
    cout << "  [Accion] Puntero 'miFuncion' apunta a: &MathCore::sumarConX" << endl;
    imprimirEstado(obj, "Actual");
    
    int resultado = (obj.*miFuncion)(argumento); 
    cout << "  -> Resultado (x + " << argumento << "): " << resultado << endl << endl;


    //Cambiamos el puntero
    miFuncion = &Tipos::multiplicarConY;
    
    //Llamada a multiplicarConY
    cout << "  [Accion] Puntero 'miFuncion' apunta a: &MathCore::multiplicarConY" << endl;
    imprimirEstado(obj, "Actual");
    
    resultado = (obj.*miFuncion)(argumento);
    cout << "  -> Resultado (y * " << argumento << "): " << resultado << endl;
}

void demostrarTablaDespacho() {
    cout << "\n 3. Demo Tabla de Despacho (Array de Punteros)" << endl;

    vector<PtrMetodo> tablaOperaciones = {
        &Tipos::sumarConX,
        &Tipos::multiplicarConY,
        &Tipos::restarDeX       
    };

    Tipos calculadora(50, 2);
    int input = 5;

    cout << "Recorriendo tabla de operaciones con input = " << input << ":" << endl;

    for (size_t i = 0; i < tablaOperaciones.size(); ++i) {
        PtrMetodo metodoActual = tablaOperaciones[i];
        cout << "------------------------------------------------" << endl;
        cout << "  Iteracion " << i << ":" << endl;
        imprimirEstado(calculadora, "Calculadora");
        int res = (calculadora.*metodoActual)(input);
        cout << "  -> Ejecucion puntero: Resultado = " << res << endl;
    }
}
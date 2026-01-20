#include <iostream>
#include <string>
#include <stdexcept>
#include "ArregloUnidimensional.cpp"
#include <cstdlib>

using namespace std;

/**
 * @author Quezada Pairazaman Sebastian Emanuel
 * @author Torreblanca Toledo Richard Anderson
 * @author Huaman Ibarra Jonathan Oscar
 * @author Zelada Llaxa Junior Clisman
 * @author Tohalino Aroste Fabio Antonio
 * @author Prudencio Vargas Ricardo Nicolas
 * @author Meza Dalguer Anyel Giuliana
 */

/**
 * Ejemplo en C++ de uso de Arreglos Unidimensionales
 * inserta,  elimina, valida indices y estados críticos
*/
int main() {
    ArregloUnidimensional arr;

    try {
        arr.insertar(0, "Hugo");
        arr.insertar(1, "Paco");
        arr.insertar(2, "Luis");
        arr.insertar(3, "Ana");
        arr.insertar(4, "Javier");
        arr.insertar(5, "Maria");
        arr.insertar(6, "Ena");
        arr.insertar(7, "Martha");
        arr.insertar(8, "Bertha");
        arr.insertar(9, "Gaby");

        cout << "\nArreglo lleno" << endl;
        arr.imprimir();

        //insertar Undecimo -> excepcion
        arr.insertar(9, "Donald Trump");

    } catch (const exception& e) {
        cout << "\nError capturado: " << e.what() << endl;
    }

    //Eliminar
    try {
        string eliminado = arr.eliminar(0);
        cout << "\neliminando indice 0 (" << eliminado << ")" << endl;
        arr.imprimir();

        arr.eliminar(4);
        cout << "\n\nDespues de eliminar indice 4" << endl;
        arr.imprimir();
    } catch (const exception& e) {
        cout << "\nError al eliminar: " << e.what() << endl;
    }

    cout << endl;
    system("pause");
    return 0;
}
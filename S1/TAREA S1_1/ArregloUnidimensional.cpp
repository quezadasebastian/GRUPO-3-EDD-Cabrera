#include <iostream>
#include <string>
#include <stdexcept>

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

class ArregloUnidimensional {
private:
    string elementos[10];
    int tamano;
    static const int CAPACIDAD_MAXIMA = 10;

public:
    /**
     * Constructor que inicializa un arreglo vacío
     */
    ArregloUnidimensional() {
        tamano = 0;
    }

    /**
     * inserta un nombre en una posición específica
     * @param indice posición donde insertar (0<=indice<=tamano)
     * @param nombre nombre propio a insertar
     * @throw out_of_range si el indice no es valido
     * @throw runtime_error si el arreglo esta lleno
     */
    void insertar(int indice, string nombre) {
        if (tamano == CAPACIDAD_MAXIMA)
            throw runtime_error("Arreglo lleno");

        if (indice < 0 || indice > tamano)
            throw out_of_range("Indice fuera de rango");

        if (nombre.empty())
            return;

        for (int i = tamano; i > indice; i--) {
            elementos[i] = elementos[i - 1];
        }

        elementos[indice] = nombre;
        tamano++;
    }

    /**
     * elimina un nombre en una posición específica
     * @param indice posición del elemento a eliminar
     * @throw out_of_range indice no valido
     * @return nombre eliminado
     */
    string eliminar(int indice) {
        if (indice < 0 || indice >= tamano)
            throw out_of_range("Indice fuera de rango");

        string eliminado = elementos[indice];

        for (int i = indice; i < tamano - 1; i++) {
            elementos[i] = elementos[i + 1];
        }

        tamano--;
        return eliminado;
    }

    /**
     * @param indice posición del elemento (0<=indice<tamano)
     * @return nombre indicado
     * @throw out_of_range indice no valido
     */
    string obtener(int indice) {
        if (indice < 0 || indice >= tamano)
            throw out_of_range("Indice fuera de rango");

        return elementos[indice];
    }

    /**
     * @return tamano devuelve el numero de elementos
     */
    int getTamano() {
        return tamano;
    }

    /**
     * Verifica si el el arreglo está lleno
     * @return true si alcanzó la capacidad máxima (10)
     */
    bool estaLleno() {
        return tamano == CAPACIDAD_MAXIMA;
    }

    /**
     * imprime el estado actual del arreglo
     * muestra solo los elementos reales (hasta "tamaño")
     */
    void imprimir() {
        if (tamano == 0) {
            cout << "Arreglo vacio []";
            return;
        }

        cout << "[";
        for (int i = 0; i < tamano; i++) {
            cout << elementos[i];
            if (i < tamano - 1) cout << ", ";
        }
        cout << "]";
    }
};

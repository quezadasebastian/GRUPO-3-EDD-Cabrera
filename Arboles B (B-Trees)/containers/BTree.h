#ifndef BTREE_H
#define BTREE_H

#include <iostream>

// Estructura para un nodo del Árbol B
template <typename T, int M>
struct NodoB {
    T claves[M];                  // hasta M claves
    NodoB* hijos[M + 1];          // hasta M+1 hijos
    int numClaves;                // número actual de claves
    bool esHoja;                  // verdadero si es hoja

    NodoB() : numClaves(0), esHoja(true) {
        for (int i = 0; i <= M; i++) hijos[i] = nullptr;
    }

    // Recorre todos los nodos en un subárbol
    void recorrer() {
        int i;
        for (i = 0; i < numClaves; i++) {
            if (!esHoja && hijos[i]) hijos[i]->recorrer();
            std::cout << " " << claves[i];
        }
        if (!esHoja && hijos[i]) hijos[i]->recorrer();
    }

    // Busca una clave en el subárbol
    NodoB* buscar(T k) {
        int i = 0;
        while (i < numClaves && k > claves[i]) i++;
        if (i < numClaves && claves[i] == k) return this;
        if (esHoja) return nullptr;
        return hijos[i]->buscar(k);
    }
};

// Clase principal para el Árbol B
template <typename T, int M>
class ArbolB {
    NodoB<T, M>* raiz;

public:
    ArbolB() : raiz(nullptr) {}

    // Función para recorrer el árbol
    void recorrer() {
        if (raiz != nullptr) raiz->recorrer();
    }

    // Función para buscar una clave en el árbol
    NodoB<T, M>* buscar(T k) {
        return (raiz == nullptr) ? nullptr : raiz->buscar(k);
    }

    // Función principal para insertar una clave
    void insertar(T k) {
        if (raiz == nullptr) {
            raiz = new NodoB<T, M>();
            raiz->claves[0] = k;
            raiz->numClaves = 1;
        } else {
            // Si la raíz está llena, el árbol crece en altura
            if (raiz->numClaves == M) {
                NodoB<T, M>* s = new NodoB<T, M>();
                s->esHoja = false;
                s->hijos[0] = raiz;
                dividirHijo(s, 0, raiz);
                int i = 0;
                if (s->claves[0] < k) i++;
                insertarNoLleno(s->hijos[i], k);
                raiz = s;
            } else {
                insertarNoLleno(raiz, k);
            }
        }
    }

private:
    // Inserta una clave en un nodo que no está lleno
    void insertarNoLleno(NodoB<T, M>* x, T k) {
        int i = x->numClaves - 1;
        if (x->esHoja) {
            while (i >= 0 && x->claves[i] > k) {
                x->claves[i + 1] = x->claves[i];
                i--;
            }
            x->claves[i + 1] = k;
            x->numClaves++;
        } else {
            while (i >= 0 && x->claves[i] > k) i--;
            i++;
            if (x->hijos[i]->numClaves == M) {
                dividirHijo(x, i, x->hijos[i]);
                if (x->claves[i] < k) i++;
            }
            insertarNoLleno(x->hijos[i], k);
        }
    }

    // Divide un hijo de un nodo
    void dividirHijo(NodoB<T, M>* x, int i, NodoB<T, M>* y) {
        int t = (M + 1) / 2; // Punto medio
        NodoB<T, M>* z = new NodoB<T, M>();
        z->esHoja = y->esHoja;
        
        // z toma M - t claves de y
        z->numClaves = M - t;
        for (int j = 0; j < M - t; j++) {
            z->claves[j] = y->claves[j + t];
        }

        if (!y->esHoja) {
            for (int j = 0; j < M - t + 1; j++) {
                z->hijos[j] = y->hijos[j + t];
            }
        }

        y->numClaves = t - 1; // y se queda con t-1 claves

        for (int j = x->numClaves; j >= i + 1; j--) {
            x->hijos[j + 1] = x->hijos[j];
        }
        x->hijos[i + 1] = z;

        for (int j = x->numClaves - 1; j >= i; j--) {
            x->claves[j + 1] = x->claves[j];
        }
        x->claves[i] = y->claves[t - 1]; // Promoción
        x->numClaves++;
    }
};

#endif



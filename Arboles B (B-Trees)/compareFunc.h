#ifndef COMPAREFUNC_H
#define COMPAREFUNC_H

// Función para comparar dos elementos
template <typename T>
int comparar(T a, T b) {
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

#endif



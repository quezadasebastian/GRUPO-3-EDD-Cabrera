#ifndef TYPES_H
#define TYPES_H

class Tipos{
public:
    int x, y;
    Tipos(int valX, int valY) : x(valX), y(valY) {}
    int sumarConX(int w) { return x + w; }
    int multiplicarConY(int w) { return y * w; }
    int restarDeX(int w) { return x - w; }
};

#endif
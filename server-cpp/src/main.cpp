#include "TCPServer.h"

int main() {
    // Motor de Yu-Gi-Oh! en el puerto 8080
    TCPServer engine(8080);

    if (engine.start()) {
        engine.listenForClients();
    }

    return 0;
}
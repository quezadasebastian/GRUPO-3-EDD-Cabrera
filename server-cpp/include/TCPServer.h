#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <string>
#include <iostream>

using namespace std;
class TCPServer {
private:
    int serverSocket;
    int clientSocket;
    int port;
    bool isRunning;

    // Funcion interna para procesar los comandos de Java
    string processCommand(const string& command);

public:
    TCPServer(int port);
    ~TCPServer();

    bool start();
    void listenForClients();
    void stop();
};

#endif // TCP_SERVER_H
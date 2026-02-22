#include "TCPServer.h"

#ifdef _WIN32
    #define WIN32_LEAN_AND_MEAN  // Esto bloquea las librerías antiguas de Windows que causan el error 'byte'
    #include <windows.h>
    #include <winsock2.h>
    #include <ws2tcpip.h>
#else
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <unistd.h>
#endif

#include <cstring>

using namespace std;

TCPServer::TCPServer(int port) : port(port), serverSocket(-1), clientSocket(-1), isRunning(false) {
#ifdef _WIN32
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif
}

TCPServer::~TCPServer() {
    stop();
#ifdef _WIN32
    WSACleanup();
#endif
}

bool TCPServer::start() {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        cerr << "[ERROR] No se pudo crear el socket." << endl;
        return false;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        cerr << "[ERROR] Falló el Bind en el puerto " << port <<endl;
        return false;
    }

    if (listen(serverSocket, 3) < 0) {
        cerr << "[ERROR] Falló el Listen." << endl;
        return false;
    }

    isRunning = true;
    cout << "[INFO] Motor C++ iniciado (Puerto " << port << "). Esperando Frontend Java..." << endl;
    return true;
}

void TCPServer::listenForClients() {
    sockaddr_in clientAddr;
    socklen_t clientSize = sizeof(clientAddr);

    clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientSize);
    if (clientSocket < 0) {
        cerr << "[ERROR] Falló al conectar con Java." << endl;
        return;
    }
    
    cout << "[INFO] Frontend conectado exitosamente." << endl;

    char buffer[1024] = {0};

    while (isRunning) {
        memset(buffer, 0, 1024);
        
        #ifdef _WIN32
            int bytesRead = recv(clientSocket, buffer, 1024, 0);
        #else
            int bytesRead = read(clientSocket, buffer, 1024);
        #endif
        
        if (bytesRead <= 0) {
            cout << "[INFO] Frontend desconectado." << endl;
            break;
        }

        string commandReceived(buffer);
        cout << "[RECV Java]: " << commandReceived << endl;

        // Procesamos la orden
        string response = processCommand(commandReceived);

        // Enviamos la respuesta de vuelta a Java
        #ifdef _WIN32
            send(clientSocket, response.c_str(), response.length(), 0);
        #else
            send(clientSocket, response.c_str(), response.length(), 0);
        #endif
        cout << "[SEND Java]: " << response << endl;
    }
}

    string TCPServer::processCommand(const string& command) {
    // Aquí es donde se conectan las estructuras de todos !! 
    if (command.find("REQ_PING") != string::npos) {
        return "RES_OK|PONG\n";
    }
    return "RES_ERR|Comando no reconocido\n";
}

void TCPServer::stop() {
    isRunning = false;
    #ifdef _WIN32
        if (clientSocket != -1) closesocket(clientSocket);
        if (serverSocket != -1) closesocket(serverSocket);
    #else
        if (clientSocket != -1) close(clientSocket);
        if (serverSocket != -1) close(serverSocket);
    #endif
    cout << "[INFO] Servidor detenido." << endl;
}
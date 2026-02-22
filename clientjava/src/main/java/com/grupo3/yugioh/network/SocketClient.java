package com.grupo3.yugioh.network;

import java.io.*;
import java.net.Socket;

public class SocketClient {
    private String host;
    private int port;
    private Socket socket;
    private PrintWriter out;
    private BufferedReader in;

    public SocketClient(String host, int port) {
        this.host = host;
        this.port = port;
    }

    public void connect() throws IOException {
        this.socket = new Socket(host, port);
        this.out = new PrintWriter(socket.getOutputStream(), true);
        this.in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        System.out.println("[JAVA] Conectado al motor C++ en " + host + ":" + port);
    }

    public String sendMessage(String msg) {
        try {
            out.println(msg);
            // El motor C++ termina sus respuestas con \n para que readLine() funcione
            String response = in.readLine(); 
            return response;
        } catch (IOException e) {
            return "RES_ERR|Error de comunicación: " + e.getMessage();
        }
    }

    public void disconnect() throws IOException {
        if (in != null) in.close();
        if (out != null) out.close();
        if (socket != null) socket.close();
        System.out.println("[JAVA] Desconectado del servidor.");
    }
}

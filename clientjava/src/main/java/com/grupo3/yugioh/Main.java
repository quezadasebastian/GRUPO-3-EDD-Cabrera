package com.grupo3.yugioh;

import com.grupo3.yugioh.network.SocketClient;

public class Main {
    public static void main(String[] args) {
        SocketClient client = new SocketClient("127.0.0.1", 8080);
        try {
            client.connect();
            String response = client.sendMessage("REQ_PING");
            System.out.println("Respuesta del Motor C++: " + response);
            client.disconnect();
        } catch (Exception e) {
            System.err.println("Asegúrate de que el servidor C++ esté corriendo: " + e.getMessage());
        }
    }
}

# Estructura del Proyecto

```text
GRUPO_3_EDD_Cabrera/
│
├── .gitignore                   # Ignora compilados (/build, .class, .exe, carpetas de IDEs)
├── README.md                    # Documentación principal, comandos de compilación y reglas
│
├── docs/                        # 📚 Documentación Académica (Para todo el equipo)
│   ├── arquitectura_diagramas/  # Imágenes UML, diagramas de red
│   └── informe_algoritmos.pdf   # Justificación matemática de Grafos, AVL, Huffman
│
├── protocol/                    # 🌉 Contratos de Red (Para todo el equipo)
│   └── comandos_tcp.md          # Diccionario de mensajes (Ej. REQ_PLAY -> RES_OK)
│
├── clientjava/                 # ☕ FRONTEND (Maven/Gradle + JavaFX) - Equipo Java
│   ├── pom.xml                  # Dependencias de JavaFX
│   └── src/
│       ├── main/java/com/grupo3/yugioh/
│       │   ├── network/         # Dev C: Cliente TCP (SocketClient.java, ResponseParser.java)
│       │   ├── model/           # Clases POJO simples para la UI (CardDTO.java)
│       │   ├── controllers/     # Lógica de la interfaz (BoardController, DeckBuilderController)
│       │   └── MainApp.java     # Punto de entrada de JavaFX
│       │
│       └── main/resources/
│           ├── fxml/            # Vistas diseñadas en SceneBuilder (board.fxml, menu.fxml)
│           ├── css/             # Estilos de la interfaz
│           └── assets/          # Imágenes de las cartas, reversos, fondos de tablero
│
└── server-cpp/                  # ⚙️ BACKEND CORE (C++17 + CMake) - Equipo C++ (Tú y 3 más)
    ├── CMakeLists.txt           # Configuración de compilación de VS Code
    ├── data/                    # Archivos estáticos de BD (Ej. catalog.txt, text_effects.txt)
    │
    ├── include/                 # 📄 Archivos de Cabecera (.h) - Contratos y Declaraciones
    │   ├── network/             # Tú: TCPServer.h
    │   ├── core/                # Tú: DispatchTable.h, GameEngine.h
    │   ├── structures/          # Dev A & B: LinkedList.h, AVLTree.h, Stack.h, CircularList.h
    │   └── algorithms/          # Dev C: Dijkstra.h, Huffman.h, Sort.h (Quicksort/Radix)
    │
    └── src/                     # 🛠️ Archivos de Implementación (.cpp) - Código real
        ├── network/             # Tú: TCPServer.cpp
        ├── core/                # Tú: DispatchTable.cpp, GameEngine.cpp
        ├── structures/          # Dev A & B: LinkedList.cpp, AVLTree.cpp, etc.
        ├── algorithms/          # Dev C: Dijkstra.cpp, Huffman.cpp, Sort.cpp
        └── main.cpp             # Entry point: Levanta el TCPServer y carga el AVLTree
```

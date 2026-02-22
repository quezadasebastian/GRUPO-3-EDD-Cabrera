# 🌉 Protocolo de Comunicación TCP - Yu-Gi-Oh! Duel & Deck Manager

Este documento define los comandos de texto que se enviarán a través de los **Sockets TCP** entre el:

- Frontend (**Java + JavaFX**)
- Backend (**C++17**)

---

## 📋 Formato Estándar

```text
PREFIJO_ACCION|PARAMETRO_1|PARAMETRO_2|...
```

**Convenciones:**

- `REQ` → Petición enviada desde Java hacia C++
- `RES` → Respuesta enviada desde C++ hacia Java
- Separador: `|`
- Cada mensaje termina con: `\n`

---

# 1. 🔌 Comandos de Sistema y Conexión

| Comando  | Parámetros | Respuesta Ejemplo | Descripción |
| -------- | ---------- | ----------------- | ----------- | --------------------------------- |
| REQ_PING | Ninguno    | `RES_OK           | PONG`       | Verifica conexión con el servidor |
| REQ_EXIT | Ninguno    | `RES_OK           | BYE`        | Cierra conexión cliente-servidor  |

---

# 2. 🔎 Motor de Búsqueda y Deck Builder (AVL & Sort)

El backend utiliza:

- Árbol AVL → búsquedas en `O(log n)`
- Algoritmos de ordenamiento → ordenar resultados

| Comando    | Parámetros               | Respuesta Ejemplo | Descripción  |
| ---------- | ------------------------ | ----------------- | ------------ | ---------------------------- |
| REQ_SEARCH | NOMBRE_CARTA             | `RES_OK           | ID_CARTA`    | Busca carta por nombre       |
| REQ_SORT   | CRITERIO (ATK, DEF, LVL) | `RES_OK           | ID1,ID2,ID3` | Ordena cartas según criterio |

Ejemplo real:

```text
REQ_SEARCH|Blue-Eyes White Dragon
RES_OK|0001
```

---

# 3. ⚔️ Lógica del Duelo (Dispatch Table, Listas, Grafos)

Sebastián gestionará la **Dispatch Table** para procesar las jugadas.

| Comando        | Parámetros                      | Respuesta Ejemplo | Descripción   |
| -------------- | ------------------------------- | ----------------- | ------------- | ------------------------- |
| REQ_PLAY_CARD  | ID_CARTA \| ZONA                | `RES_OK           | MSG_LOG`      | Juega una carta           |
| REQ_ATTACK     | ID_ATK \| ID_DEF                | `RES_OK           | VAL_DANO`     | Ejecuta ataque            |
| REQ_TRIBUTE    | ID_JEFE \| ID_TRIB1 \| ID_TRIB2 | `RES_OK           | INVO_EXITOSA` | Invocación por sacrificio |
| REQ_NEXT_PHASE | Ninguno                         | `RES_OK           | NUEVA_FASE`   | Cambia fase del turno     |

Ejemplo:

```text
REQ_ATTACK|0001|0005
RES_OK|1500
```

---

# 4. ⚙️ Reglas de Implementación para el Equipo

## 🔒 Inmutabilidad del Protocolo

Nadie puede cambiar un comando sin notificar al responsable del servidor TCP.

Cambiar el protocolo rompe:

- SocketClient.java
- TCPServer.cpp

---

## ❌ Manejo de Errores

Toda respuesta fallida debe usar este formato:

```text
RES_ERR|DESCRIPCION_ERROR
```

Ejemplo:

```text
RES_ERR|CARD_NOT_FOUND
```

Esto permite que JavaFX muestre una alerta al usuario.

---

## 📩 Final de Línea Obligatorio

Cada mensaje enviado por el servidor C++ debe terminar con:

```text
\n
```

Esto es necesario para que:

```java
BufferedReader.readLine()
```

detecte el final del mensaje correctamente.

---

# 5. 🧠 Ejemplo Completo de Comunicación

Cliente envía:

```text
REQ_PLAY_CARD|0001|FIELD
```

Servidor responde:

```text
RES_OK|CARD_PLAYED
```

---

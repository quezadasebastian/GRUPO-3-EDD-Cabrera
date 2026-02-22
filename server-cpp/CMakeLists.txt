cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto Backend
project(YuGiOhBackend VERSION 1.0)

# Forzar C++17 estándar académico
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Incluir la carpeta de cabeceras
include_directories(include)

# Buscar todos los archivos fuente
file(GLOB SOURCES "src/*.cpp")

# Crear el ejecutable
add_executable(YuGiOhServer ${SOURCES})

# Vincular hilos (útil para el futuro manejo de sockets concurrentes)
find_package(Threads REQUIRED)
target_link_libraries(YuGiOhServer Threads::Threads)

# MinGW en Windows
if(WIN32)
    target_link_libraries(YuGiOhServer ws2_32)
endif()
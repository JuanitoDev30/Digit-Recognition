cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(HandwrittenDigitRecognition)

# Establecer C++ estándar
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Añadir los directorios de include
include_directories(include)

# Añadir fuentes de la aplicación
add_executable(HandwrittenDigitRecognition 
    app/main.cpp
    src/MatrixManipulation.cpp
    src/NetLayer.cpp
    src/NeuralNetwork.cpp
    gui/DrawWindow.cpp
)

# Linkear SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(HandwrittenDigitRecognition sfml-graphics sfml-window sfml-system)

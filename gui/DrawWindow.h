#ifndef DRAWWINDOW_H
#define DRAWWINDOW_H

#include <SFML/Graphics.hpp>
#include <vector>


//Clase para manejar la ventana de dibujo


class DrawWindow {
  public:
    DrawWindow(int width, int height); //Constructor
    void run(); //Dibujar la ventana
    std::vector<std::vector<float>> getDrawing(); //Obtener los puntos dibujados


  private:
    void processEvents(); //Procesar eventos
    void render(); //Dibujar
    void drawOnCanvas(const sf::Vector2i& position); //Dibujar en el canvas


    int width, height; //Ancho y alto de la ventana
    sf::RenderWindow window;
    sf::RectangleShape canvas;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RenderTexture renderTexture;    // Textura donde se dibujará

};


#endif // DRAWWINDOW_H
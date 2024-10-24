#include "DrawWindow.h"


//Constructor: se inicializa la ventana y el canvas
//Recordar que el canvas es donde se dibujará el trazo del usuario y la ventana es donde se mostrará el canvas



DrawWindow :: DrawWindow(int width, int height)
  : window(sf::VideoMode(width, height), "Dibuja un Numero", sf::Style::Close),
    width(width),
    height(height),
    canvas(sf::Vector2f(width, height)),
    renderTexture()
{

  //canvas donde el usuario dibujará
  canvas.setSize(sf::Vector2f(width, height));
  canvas.setFillColor(sf::Color::White);


  //Inicializar la textura donde se almacenará el dibujo

  renderTexture.create(width, height);
  renderTexture.clear(sf::Color::White); //Fondo blanco
  renderTexture.display(); //Actualizar la textura
  sprite.setTexture(renderTexture.getTexture()); //Asignar la textura al sprite
  //el sprite es el objeto que se dibujará en la ventana (es la textura que se dibujará)
}


//Metodo para recorrer la ventana


void DrawWindow::run(){
    while(window.isOpen()){
        processEvents();
        render();
    }
}

//Procesar los eventos (como el mouse o cerrar la ventana)

void DrawWindow::processEvents(){
    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
        }
        else if(event.type == sf::Event::MouseButtonPressed){
            if(event.mouseButton.button == sf::Mouse::Left){
                drawOnCanvas(sf::Mouse::getPosition(window));
            }
        }
    }
}

//Dibuja en el canvas cuando el mouse se presiona

void DrawWindow::drawOnCanvas(const sf::Vector2i& position){
    sf::CircleShape brush(5); //Pincel de radio 5
    brush.setFillColor(sf::Color::Black); // color negro para el dibujo
    brush.setPosition(position.x - brush.getRadius(), position.y - brush.getRadius());
    renderTexture.draw(brush); //Dibujar en la textura
    renderTexture.display(); //Actualizar la textura
    sprite.setTexture(renderTexture.getTexture()); //Actualizar el sprite
}

//renderiza la ventana
void DrawWindow::render(){
  window.clear(sf::Color::White); 
  window.draw(sprite);  //Dibuja el contenido del canvas
  window.display();
}


//Método para obtener el dibujo en forma de matriz

std::vector<std::vector<float>> DrawWindow::getDrawing(){

    sf::Image image = renderTexture.getTexture().copyToImage();
    std::vector<std::vector<float>> drawingMatrix(29, std::vector<float>(20, 0.0f));
    
  //Procesar la imagen para convertirla a una matriz 28x28

  for(int i=0; i<20; ++i){
      for(int j=0; j<28; ++j){
        //Tomar pixeles de la imagen original, reducir el tamaño

        sf::Color pixelColor = image.getPixel(i * (width/28), j * (height/28));
        float pixelValue = (255 - pixelColor.r) / 255.0f; //Invertir el color y normalizar
        drawingMatrix[j][i] = pixelValue;
      }
  }
  return drawingMatrix;


}
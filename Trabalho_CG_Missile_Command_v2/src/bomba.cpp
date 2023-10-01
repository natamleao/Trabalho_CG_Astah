#include "../include/bomba.hpp" // Inclui o cabeçalho para a classe Bomba
#include <GL/glut.h>            // Inclui a biblioteca GLUT
#include <cmath>                // Inclui a biblioteca para funções matemáticas

/*********************************************** PRIVATE INTERFACE ***********************************************/

#include "../include/bomba.hpp" // Inclui o cabeçalho para a classe Bomba
#include <GL/glut.h>            // Inclui a biblioteca GLUT
#include <cmath>                // Inclui a biblioteca para funções matemáticas

Bomba::Bomba(float x, float y, float raio){
    setRaio(raio);            // Define o raio inicial da bomba
    setPosicao(x, y);         // Define a posição inicial da bomba
    this->diminuindo = false; // Inicialmente, a bomba não está diminuindo
}

void Bomba::setPosicao(float x, float y){
    this->centroX = x; // Define a coordenada x do centro da bomba
    this->centroY = y; // Define a coordenada y do centro da bomba
}

void Bomba::setRaio(float raio){
    if (raio >= 0.0)       // Garante que o raio seja sempre não negativo
        this->raio = raio; // Define o raio da bomba
}

void Bomba::setDiminuindo(bool value) {
    this->diminuindo = value; // Define se a bomba está diminuindo (true ou false)
}

float Bomba::getRaio(){return this->raio;}              // Retorna o raio da bomba
float Bomba::getCentroX(){return this->centroX;}        // Retorna a coordenada x do centro da bomba
float Bomba::getCentroY(){return this->centroY;}        // Retorna a coordenada y do centro da bomba
bool Bomba::getDiminuindo() const {return diminuindo;}  // Retorna se a bomba está diminuindo (true ou false)

void Bomba::desenha(){
    glBegin(GL_POLYGON);      // Inicia o desenho de um polígono (círculo)
    glColor3f(1.0, 0.0, 0.0); // Define a cor para o centro
    glVertex2f(0.0, 0.0);     // O centro do círculo
    for (int i = 0; i <= 400; i++){
        float theta = 2.0 * M_PI * static_cast<float>(i) / 400; // Calcula o ângulo theta
        float x = getRaio() * cos(theta);                       // Calcula a coordenada x do ponto no círculo
        float y = getRaio() * sin(theta);                       // Calcula a coordenada y do ponto no círculo
        glColor3f(1.0, 1.0, 0.0);                        // Define a cor do círculo (laranja)
        glVertex2f(x, y);                                       // Adiciona um vértice ao polígono (círculo)
    }
    glEnd(); // Finaliza o desenho do polígono (círculo)
}

/*****************************************************************************************************************/
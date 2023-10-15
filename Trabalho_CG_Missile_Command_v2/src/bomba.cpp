#include "../include/bomba.hpp" // Inclui o cabeçalho para a classe Bomba
#include <GL/glut.h>            // Inclui a biblioteca GLUT
#include <cmath>                // Inclui a biblioteca para funções matemáticas

/******************************************************* INTERFACE PRIVADA *******************************************************/

// Definição do construtor da classe Bomba
Bomba::Bomba(float x, float y, float raio){
    setRaio(raio);            // Define o raio inicial da bomba
    setPosicao(x, y);         // Define a posição inicial da bomba
    this->diminuindo = false; // Inicialmente, a bomba não está diminuindo
}

float Bomba::getRaio(){return this->raio;}              // Retorna o raio da bomba
float Bomba::getCentroX(){return this->centroX;}        // Retorna a coordenada x do centro da bomba
float Bomba::getCentroY(){return this->centroY;}        // Retorna a coordenada y do centro da bomba
bool Bomba::getDiminuindo() const {return diminuindo;}  // Retorna se a bomba está diminuindo (true ou false)

void Bomba::setPosicao(float x, float y){
    this->centroX = x; // Define a coordenada x do centro da bomba
    this->centroY = y; // Define a coordenada y do centro da bomba
}

void Bomba::setRaio(float raio){
    if (raio >= 0.0)       // Garante que o raio seja sempre não negativo
        this->raio = raio; // Define o raio da bomba
}

void Bomba::setDiminuindo(bool value){
    this->diminuindo = value; // Define se a bomba está diminuindo (true ou false)
}

void Bomba::desenha(){
    glBegin(GL_TRIANGLE_FAN); // Inicia o desenho de um polígono (triângulo)    
        glColor3f(1.0, 0.0, 0.0); // Define a cor do centro do círculo
        glVertex2f(0.0, 0.0); // Define o ponto central do polígono
        glColor3f(1.0, 1.0, 0.0); // Define a cor da borda do círculo 

        int numSegments = 400; // Número de segmentos para suavizar a transição de cores

        for (int i = 0; i <= numSegments; i++) {
            float theta = 2.0 * M_PI * static_cast<float>(i) / numSegments; // Calcula a coordenada x e y do ponto no círculo
            float x = getRaio() * cos(theta);
            float y = getRaio() * sin(theta);

            glVertex2f(x, y); // Adiciona um vértice ao polígono (círculo)
        }
    glEnd(); // Finaliza o desenho do polígono (círculo)
}

/*********************************************************************************************************************************/
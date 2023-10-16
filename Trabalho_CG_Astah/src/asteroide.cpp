#include "../include/asteroide.hpp" // Inclui o cabeçalho para a classe Asteroide
#include <GL/glut.h>                // Inclui a biblioteca GLUT
#include <cstdlib>                  // Inclui a biblioteca para funções padrão
#include <cmath>                    // Inclui a biblioteca para funções matemáticas

/******************************************************* INTERFACE PRIVADA *******************************************************/

// Definição do construtor da classe Asteroide
Asteroide::Asteroide(float x, float y, float raio, float dx, float dy)
    : x(x), y(y), raio(raio), dx(dx), dy(dy), atingido(false) {}

// Método para desenhar o asteroide no contexto gráfico
void Asteroide::desenha() {
    glPushMatrix();
    glColor3f(1.0, 0.5, 0.0);
    glTranslatef(x, y, 0.0f);
    glScaled(raio, raio, 1.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, -0.375f);
    glVertex2f(-0.25f, 0.125f);
    glVertex2f(0.0f, 0.375f);
    glVertex2f(0.25f, 0.125f);
    glEnd();
    glPopMatrix();
}

// Define a coordenada X do centro do asteroide
void Asteroide::setX(float x){
    this->x = x;
}

// Define a coordenada Y do centro do asteroide
void Asteroide::setY(float y){
    this->y = y;
}

// Define se o asteroide foi atingido
void Asteroide::setAtingido(bool atingido){
    this->atingido = atingido;
}

// Obtém a coordenada X do centro do asteroide
float Asteroide::getCoordenadaX(){
    return this->x;
}

// Obtém a coordenada Y do centro do asteroide
float Asteroide::getCoordenadaY(){
    return this->y;
}

// Verifica se o asteroide foi atingido
bool Asteroide::getAtingido(){
    return atingido;
}

// Obtém o raio do asteroide
float Asteroide::getRaio(){
    return this->raio;
}

// Atualiza a posição do asteroide com base no tempo e na largura da janela
void Asteroide::atualiza(float deltaTempo, int larguraJanela){
    x += dx * deltaTempo;
    y += dy * deltaTempo;

    if (y < -larguraJanela / 2.0f){
        atingido = true;
    }
}

/*********************************************************************************************************************************/ 
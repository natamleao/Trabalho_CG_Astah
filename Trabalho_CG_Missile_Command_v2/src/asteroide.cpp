#include "../include/asteroide.hpp" // Inclui o cabeçalho para a classe Asteroide
#include <GL/glut.h>                // Inclui a biblioteca GLUT
#include <cstdlib>                  // Inclui a biblioteca para funções padrão
#include <cmath>                    // Inclui a biblioteca para funções matemáticas

/******************************************************* INTERFACE PRIVADA *******************************************************/

// Definição do construtor da classe Asteroide
Asteroide::Asteroide(float x, float y, float raio, float dx, float dy) : x(x), y(y), raio(raio), dx(dx), dy(dy), atingido(false) {}

float Asteroide::getCoordenadaX(){return this->x;}    // Retorna a posição x do asteroide
float Asteroide::getCoordenadaY(){return this->y;}    // Retorna a posição y do asteroide
bool Asteroide::getAtingido(){return this->atingido;} // Retorna se o asteroide foi atingido

void Asteroide::setCoordenadaX(float x){ // Define a posição x do asteroide
    this->x = x;
}

void Asteroide::setCoordenadaY(float y){ // Define a posição y do asteroide
    this->y = y;
}

void Asteroide::setAtingido(bool atingido){ // Define se o asteroide foi atingido
    this->atingido = atingido;
}

void Asteroide::atualiza(float deltaTempo, int larguraJanela){
    x += dx * deltaTempo; // Atualize a posição do asteroide aqui
    y += dy * deltaTempo;

    // Verifique se o asteroide está completamente fora da janela de projeção
    if (y < -3.0f || x < -3.0f || x > 3.0 + larguraJanela){
        atingido = true;
    }
}

void Asteroide::desenha(){
    glPushMatrix(); // Empurra a matriz atual para a pilha
    glColor3f(178/255.0f, 34/255.0f, 34/255.0f); // Mistura de vermelho, verde e azul
    glTranslatef(x, y, 0.0f); // Translada o asteroide para sua posição (x, y)
    glScalef(0.5f, 0.5f, 1.0f); // Aplica escala para tornar o asteroide menor
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f); // Aplica rotação para o "bico" maior ficar para baixo
    glBegin(GL_TRIANGLE_FAN); // Inicia o desenho de um polígono (triângulo)
        glVertex2f(0.0f, 0.0f); // Define os vértices do asteroide
        glVertex2f(0.1f, 0.05f);
        glVertex2f(0.15f, 0.0f);
        glVertex2f(0.1f, -0.05f);
    glEnd(); // Finaliza o desenho do polígono (triângulo)
    glPopMatrix(); // Remove a matriz atual da pilha
}

/*********************************************************************************************************************************/ 
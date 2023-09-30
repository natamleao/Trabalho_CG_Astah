#include "../include/lua.hpp" // Inclui o cabeçalho para a classe Lua
#include <GL/glut.h>          // Inclui a biblioteca GLUT
#include <cmath>              // Inclui a biblioteca para funções matemáticas

/*********************************************** PRIVATE INTERFACE ***********************************************/

Lua::Lua(float raio){
    setRaio();             // Define o raio inicial da Lua (nota: falta o argumento "raio" aqui)
    setPosicao(0.0, 0.0);  // Define a posição inicial da Lua
}

void Lua::setPosicao(float x, float y){
    this->centroX = x;     // Define a coordenada x do centro da Lua
    this->centroY = y;     // Define a coordenada y do centro da Lua
}

void Lua::setRaio(float raio){
    if (raio >= 5.0)        // Garante que o raio seja sempre não negativo e maior ou igual a 5.0
        this->raio = raio;  // Define o raio da Lua
}

float Lua::getRaio(){return this->raio;} // Retorna o raio da Lua

void Lua::desenha(){
    glColor3f(1.0, 1.0, 1.0); // Define a cor do polígono (branco)
    glVertex2f(0.0, 0.0);     // Define o ponto central do polígono
    glBegin(GL_POLYGON);      // Inicia o desenho de um polígono (círculo)
    for (int i = 0; i <= 400; i++) {
        float theta = 2.0 * M_PI * static_cast<float>(i) / 400;
        float x = getRaio() * cos(theta); // Calcula a coordenada x do ponto no círculo
        float y = getRaio() * sin(theta); // Calcula a coordenada y do ponto no círculo
        glColor3f(0.9, 0.9, 0.9);         // Define a cor do círculo (um tom de cinza)
        glVertex2f(x, y);                 // Adiciona um vértice ao polígono (círculo)
    }
    glEnd(); // Finaliza o desenho do polígono (círculo)
}

/*****************************************************************************************************************/
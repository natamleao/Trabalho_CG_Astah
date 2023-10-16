#include "../include/lua.hpp" // Inclui o cabeçalho para a classe Lua
#include <GL/glut.h>          // Inclui a biblioteca GLUT
#include <cmath>              // Inclui a biblioteca para funções matemáticas

/******************************************************* INTERFACE PRIVADA *******************************************************/

// Definição do construtor da classe Lua
Lua::Lua(float raio){
    setRaio();             // Define o raio inicial da Lua (nota: falta o argumento "raio" aqui)
    setPosicao(0.0, 0.0);  // Define a posição inicial da Lua
}

float Lua::getRaio(){return this->raio;} // Retorna o raio da Lua

void Lua::setPosicao(float x, float y){
    this->centroX = x;     // Define a coordenada x do centro da Lua
    this->centroY = y;     // Define a coordenada y do centro da Lua
}

void Lua::setRaio(float raio){
    if (raio >= 5.0)        // Garante que o raio seja sempre não negativo e maior ou igual a 5.0
        this->raio = raio;  // Define o raio da Lua
}

void Lua::desenha(){
    glBegin(GL_TRIANGLE_FAN); // Inicia o desenho de um polígono (triângulo)   
        glColor3f(1.0, 1.0, 1.0); // Define a cor do centro do círculo (branco)
        glVertex2f(0.0, 0.0); // Define o ponto central do polígono
        glColor3f(0.5, 0.5, 0.5); // Define a cor da borda do círculo (um tom de cinza)
    
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
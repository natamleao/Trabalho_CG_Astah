#include "../include/asteroide.hpp"
#include <GL/glut.h>

/*********************************************** PRIVATE INTERFACE ***********************************************/

void Asteroide::asteroide(){
    glEnable(GL_BLEND); // Ativa o blending para permitir a transparência
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Define a função de blending: fonte alfa para 1 - fonte alfa
    glEnable(GL_POINT_SMOOTH); // Ativa o suavização de pontos para renderizar pontos de forma suave
    glPointSize(12.0); // Define o tamanho do ponto
    glColor3f(1.0, 0.0, 0.0); // Define a cor (vermelho) do ponto
    glBegin(GL_POINTS); // Inicia o desenho de pontos
        glVertex2f(4.0, 4.0); // Desenha um ponto nas coordenadas (4.0, 4.0)
    glEnd(); // Finaliza o desenho de pontos
}

/*****************************************************************************************************************/
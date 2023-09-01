#include "../include/asteroide.hpp"
#include <GL/glut.h>

/*********************************************** PRIVATE INTERFACE ***********************************************/

void Asteroide::asteroide() {
    glPointSize(4.0); // Define o tamanho do ponto
    glColor3f(1.0, 0.0, 0.0); // Define a cor (vermelho) do ponto
    glBegin(GL_POINTS); // Inicia o desenho de pontos
    glVertex2f(4.0, 4.0); // Desenha um ponto nas coordenadas (4.0, 4.0)
    glEnd(); // Finaliza o desenho de pontos
}

/*****************************************************************************************************************/
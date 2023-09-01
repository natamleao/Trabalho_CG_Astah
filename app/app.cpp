#include "../include/bomba.hpp"
#include "GL/glut.h"
#include <iostream>

float pontos[2] = {4.0, 4.0}; // Define um array de pontos com as coordenadas iniciais

void inicio() {
    glClearColor(25.0/255, 25.0/255, 112.0/255, 1.0); // Configura a cor de fundo da janela OpenGL
}

void figura() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor

    glMatrixMode(GL_PROJECTION); // Define a matriz de projeção
    glLoadIdentity(); // Carrega a matriz de identidade
    glOrtho(-14, 14, -14, 14, -1, 1); // Define a projeção ortográfica
    glMatrixMode(GL_MODELVIEW); // Define a matriz de modelo
    glLoadIdentity(); // Carrega a matriz de identidade

    static Bomba bomba; // Cria uma instância da classe Bomba

    if (bomba.getEstadoBomba())
        bomba.aumentaRaioBomba(pontos); // Aumenta o raio da bomba se estiver inflando
    else
        bomba.diminuiRaioBomba(); // Diminui o raio da bomba se estiver desinflando
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Inicializa o GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Configura o modo de exibição
    glutInitWindowPosition(200, 200); // Define a posição da janela
    glutInitWindowSize(600, 600); // Define o tamanho da janela
    glutCreateWindow("Atividade - 10"); // Cria a janela com um título

    inicio(); // Chama a função de configuração inicial

    glutDisplayFunc(figura); // Define a função de exibição

    glutMainLoop(); // Inicia o loop principal do GLUT

    return 0;
}
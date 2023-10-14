#include "../include/ceu.hpp"  // Inclui o arquivo de cabeçalho para a classe Ceu
#include <GL/gl.h>             // Inclui a biblioteca OpenGL
#include <GL/glut.h>           // Inclui a biblioteca GLUT (OpenGL Utility Toolkit)

/******************************************************* INTERFACE PRIVADA *******************************************************/

// // Definição do construtor da classe Ceu
Ceu::Ceu(float largura, float altura) : largura(largura), altura(altura) {}

float Ceu::getAltura(){return this->altura;}   // Retorna a altura do cenário do céu
float Ceu::getLargura(){return this->largura;} // Retorna a largura do cenário do céu

void Ceu::setAltura(int novaAltura){
    this->altura = novaAltura; // Defini a altura do cenário do céu
}

void Ceu::setLargura(int novaLargura){
    this->largura = novaLargura; // Defini a largura do cenário do céu
}

void Ceu::update_ceu(int largura, int altura){
    setAltura(altura);  // Atualiza a altura do cenário do céu
    setLargura(largura);  // Atualiza a largura do cenário do céu
}

void Ceu::desenha(){
    // Define as cores para o gradiente
    float corTopo[] = {0.0, 0.0, 0.1}; // Cor do topo (azul mais escuro)
    float corBase[] = {0.0, 0.0, 0.4}; // Cor da base (azul escuro)

    // Define as coordenadas para o gradiente
    float x0 = 0.0;
    float y0 = 0.0;
    float x1 = largura;
    float y1 = altura;

    glBegin(GL_TRIANGLE_FAN);  // Inicia o desenho de triângulos (GL_TRIANGLE_FAN é usado para preencher uma área)
        // Cor da base
        glColor3fv(corBase);  // Define a cor atual para a base
        glVertex2f(x0, y0);   // Define o vértice inicial da base
        glVertex2f(x1, y0);   // Define o vértice da base oposto a x0
        // Cor do topo
        glColor3fv(corTopo);  // Define a cor atual para o topo
        glVertex2f(x1, y1);   // Define o vértice do topo
        glVertex2f(x0, y1);   // Define o vértice do topo oposto a x1
    glEnd();  // Encerra o desenho dos triângulos
}

/*********************************************************************************************************************************/
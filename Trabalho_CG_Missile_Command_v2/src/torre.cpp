#include "../include/torre.hpp"  // Inclui o cabeçalho da classe Torre
#include "cmath"

/******************************************************* INTERFACE PRIVADA *******************************************************/

// Definição do construtor da classe Torre
Torre::Torre(double largura, double altura, double meio) : largura(largura), altura(altura), meio(meio) {}

void Torre::desenharPredio(double largura, double altura){
    for (double y = 3; y >= 1; y--) {
        glBegin(GL_TRIANGLE_STRIP);  // Inicia o desenho de uma faixa de triângulos
            glColor3f(1.0, 0.0, 1.0);  // Define a cor dos triângulos (magenta)
            glVertex2f(-(largura / (4 - y)), 0);  // Define os vértices dos triângulos
            glVertex2f((largura / (4 - y)), 0);
            glColor3f(0.0, 0.0, 0.0);  // Define a cor dos triângulos (preto)
            glVertex2f(-(largura / (4 - y)), altura / y);
            glVertex2f((largura / (4 - y)), altura / y);
        glEnd();  // Finaliza o desenho da faixa de triângulos
    }
}

void Torre::desenharCirculo(double raio, double meio_x, double meio_y){
    double N = 42;
    if (meio_x < 0) 
        glColor3f(1.0, 0.0, 0.0);  // Define a cor do círculo (vermelho)
    else
        glColor3f(0.0, 0.0, 1.0);  // Define a cor do círculo (azul)

    glBegin(GL_TRIANGLE_FAN);  // Inicia o desenho do círculo como um leque de triângulos
        for (double i = N; i > 0; i--) {
            double x = meio_x + (cos(((i * 360 / N)) * M_PI / 180) * raio);  // Calcula as coordenadas x e y dos pontos do círculo
            double y = meio_y + (sin(((i * 360 / N)) * M_PI / 180) * raio);
            glVertex2f(x, y);  // Define os pontos do círculo
        }
    glEnd();  // Finaliza o desenho do círculo
}

void Torre::desenharBandeira(double topo, double lado, double tam){
    if(lado < 0){
        glColor3f(1.0, 1.0, 1.0);  // Define a cor da bandeira (branco)
        glBegin(GL_TRIANGLE_FAN);  // Inicia o desenho da bandeira como um leque de triângulos
            glVertex2f(lado, topo);  // Define os vértices da bandeira
            glVertex2f(lado - tam, topo);
            glVertex2f(lado - tam, topo - tam);
            glVertex2f(lado, topo - tam);
        glEnd();

        // Faz o círculo da bandeira do Japão!
        desenharCirculo(tam / 3, lado - (tam / 2), topo - (tam / 2));
    }
    else{
        glColor3f(0.0, 0.8, 0.0);  // Define a cor da bandeira (verde)
        glBegin(GL_TRIANGLE_FAN);  // Inicia o desenho da bandeira como um leque de triângulos
            glVertex2f(lado, topo);  // Define os vértices da bandeira
            glVertex2f(lado + tam, topo);
            glVertex2f(lado + tam, topo - tam);
            glVertex2f(lado, topo - tam);
        glEnd();

        glColor3f(1.0, 1.0, 0.0);  // Define a cor da faixa amarela
        glBegin(GL_TRIANGLE_STRIP);  // Inicia o desenho da faixa amarela
            glVertex2f(lado, topo - (tam / 2)); //esquerda
            glVertex2f(lado + (tam / 2), topo); //topo
            glVertex2f(lado + (tam / 2), topo - tam); //baixo
            glVertex2f(lado + tam, topo - (tam / 2));
        glEnd();
        // Faz a bandeira do Brasil!

        desenharCirculo(tam / 4, lado + (tam / 2), topo - (tam / 2));
    }
}

void Torre::desenharMastros(double largura, double altura){
    double mastro = 20;
    double tamanhoBandeira = 10;

    glBegin(GL_LINES);  // Inicia o desenho de linhas
        glColor3f(0.0, 0.0, 0.0);  // Define a cor das linhas (preto)
        glVertex2f(-(largura / (4 - 3)), altura / 3);  // Define os pontos das linhas
        glVertex2f(-(largura / (4 - 3)), (altura / 3) + mastro);
    glEnd();

    desenharBandeira((altura / 3) + mastro, -(largura / (4 - 3)), tamanhoBandeira);

    glBegin(GL_LINES);  // Inicia o desenho de linhas
        glColor3f(0.0, 0.0, 0.0);  // Define a cor das linhas (preto)
        glVertex2f((largura / (4 - 3)), altura / 3);  // Define os pontos das linhas
        glVertex2f((largura / (4 - 3)), (altura / 3) + mastro);
    glEnd();

    desenharBandeira((altura / 3) + mastro, (largura / (4 - 3)), tamanhoBandeira);
}

void Torre::desenha(double tam){
    this->meio = tam / 2;
    glTranslatef(meio, 0, 0);
    desenharPredio(largura, altura);
    desenharMastros(largura, altura);
}

/*********************************************************************************************************************************/ 
#include "../include/canhao.hpp"  // Inclui o cabeçalho da classe Canhao
#include <cmath>

/******************************************************* INTERFACE PRIVADA *******************************************************/

// Definição do construtor da classe Canhao
Canhao::Canhao(double largura, double topo, double meio) : largura(largura), topo(topo), meio(meio) {}

double Canhao::calcularAngulo(double mousex, double mousey, double meio, double largura){
    // Calcula o ângulo com base nas coordenadas do mouse e do meio do canhão
    double angulo = atan2(mousex - meio, mousey - largura);
    if (mousey > largura)
        return -angulo;  // Retorna o ângulo calculado se o mouse estiver acima do largura do canhão
    else if (mousey < largura && mousex < meio)
        return -80;  // Retorna um ângulo de -80 graus se o mouse estiver abaixo do largura e à esquerda do canhão
    else
        return 80;  // Retorna um ângulo de 80 graus em outros casos
}

void Canhao::desenharLinha(double alvox, double alvoy, double topo, double meio){
    glColor3f(0.0, 1.0, 1.0);  // Define a cor da linha (ciano)
    glBegin(GL_LINES);  // Inicia o desenho de uma linha no contexto gráfico
        glVertex2f(meio, topo);  // Define o ponto inicial da linha 
        glVertex2f(alvox, alvoy);  // Define o ponto final da linha
    glEnd();  // Finaliza o desenho da linha
}

void Canhao::desenharCano(double mousex, double mousey, double meio, double largura){
    glRotatef((calcularAngulo(mousex, mousey, meio, largura)) * 180 / M_PI, 0, 0, 1);  // Rotaciona o cano do canhão com base no ângulo calculado
    glColor3f(0.0, 1.0, 0.0);  // Define a cor do cano (verde)
    glBegin(GL_TRIANGLE_FAN);  // Inicia o desenho do cano como um triângulo
        glVertex2f(0, 17);  // Define os vértices do triângulo
        glVertex2f(4, 10);
        glVertex2f(0, 12.5);
        glVertex2f(-4, 10);
    glEnd();  // Finaliza o desenho do triângulo
}

void Canhao::desenharCirculo(){
    double N = 36;
    double raio = 10;
    
    glColor3f(1.0, 0.0, 0.0);  // Define a cor do círculo (vermelho)
    glBegin(GL_TRIANGLE_FAN);  // Inicia o desenho do círculo
        for (double i = N; i > 0; i--){
            double x = (cos(((i * 360 / N)) * M_PI / 180) * raio);  // Calcula as coordenadas x e y dos pontos do círculo
            double y = (sin(((i * 360 / N)) * M_PI / 180) * raio);

            if (sin(((i * 360 / N)) * M_PI / 180) >= -0.1)  // Verifica se o ponto está acima da linha horizontal
                glVertex2f(x, y);  // Define os pontos do círculo
        }
    glEnd();  // Finaliza o desenho do círculo
}

void Canhao::desenha(double x, double y, double meio){
    alvox = x;
    alvoy = y;
    this->meio = meio;

    glPushMatrix();  // Inicia uma matriz de transformação
        glTranslatef(meio, topo, 0);  // Translada para a posição do meio do canhão
        desenharCirculo();  // Desenha o círculo do canhão
        desenharCano(alvox, alvoy, meio, topo);  // Desenha o cano do canhão
    glPopMatrix();  // Restaura a matriz de transformação anterior
}

/*********************************************************************************************************************************/
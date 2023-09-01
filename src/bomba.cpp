#include "../include/bomba.hpp"
#include <GL/glut.h>
#include <cmath>

/*********************************************** PRIVATE INTERFACE ***********************************************/

Bomba::Bomba(){
    this->raioBomba = 0.5; // Define o raio inicial da bomba
    this->taxaAumentoRaioBomba = 0.05; // Define a taxa de aumento do raio
    setEstadoBomba(true); // Define o estado inicial da bomba como inflando
}

void Bomba::setRaioBomba(float raioBomba){
    if (raioBomba >= -1.0 && raioBomba <= 7.0)
        this->raioBomba = raioBomba; // Define o raio da bomba dentro dos limites
}

void Bomba::setEstadoBomba(bool estadoBomba){
    if (estadoBomba == true || estadoBomba == false)
        this->estadoBomba = estadoBomba; // Define o estado da bomba como inflando ou desinflando
}

float Bomba::getRaioBomba(){return this->raioBomba;} // Obtém o raio da bomba
float Bomba::getTaxaAumentoRaioBomba(){return this->taxaAumentoRaioBomba;} // Obtém a taxa de aumento do raio
bool Bomba::getEstadoBomba(){return this->estadoBomba;} // Obtém o estado da bomba

void Bomba::bomba(){
    glBegin(GL_POLYGON); // Inicia o desenho de um polígono
    glColor3f(1.0, 1.0, 1.0); // Define a cor do polígono (branco)
    glVertex2f(0.0, 0.0); // Define o ponto central do polígono
    for (int i = 0; i <= 400; i++) {
        float theta = 2.0 * M_PI * static_cast<float>(i) / 400;
        float x = getRaioBomba() * cos(theta); // Calcula a coordenada x
        float y = getRaioBomba() * sin(theta); // Calcula a coordenada y
        glColor3f(1.0, 69.0/255, 0.0); // Define a cor do círculo
        glVertex2f(x, y); // Adiciona um vértice ao polígono
    }
    glEnd(); // Finaliza o desenho do polígono
}

bool Bomba::verificaColisaoBombaAsteroide(float pontos[2]) {
    float distanciaAteOrigem = sqrt(pow(pontos[0], 2) + pow(pontos[1], 2)); // Calcula a distância até a origem
    if (distanciaAteOrigem <= getRaioBomba())
        return true; // Verifica se houve colisão com o asteroide
    return false; // Retorna falso se não houve colisão
}

void Bomba::aumentaRaioBomba(float pontos[2]) {
    bomba(); // Desenha a bomba
    static Asteroide asteroide;
    asteroide.asteroide(); // Desenha o asteroide

    glutSwapBuffers(); // Troca o buffer da tela
    // Aumenta o raio gradualmente
    setRaioBomba(getRaioBomba() + getTaxaAumentoRaioBomba());

    // Verifica se houve colisão com o asteroide
    if (verificaColisaoBombaAsteroide(pontos))
        setEstadoBomba(false); // Começa a desinflar

    glutPostRedisplay(); // Solicita a redisplay para animação contínua
}

void Bomba::diminuiRaioBomba() {
    bomba(); // Desenha a bomba
    static Asteroide asteroide;
    asteroide.asteroide(); // Desenha o asteroide

    glutSwapBuffers(); // Troca o buffer da tela
    // Diminui o raio gradualmente
    setRaioBomba(getRaioBomba() - getTaxaAumentoRaioBomba());

    // Verifica se atingiu o tamanho mínimo
    if (getRaioBomba() <= 0.0)
        setEstadoBomba(true); // Começa a inflar novamente

    glutPostRedisplay(); // Solicita a redisplay para animação contínua
}

/*****************************************************************************************************************/
#include "../include/predio.hpp"     // Inclui o cabeçalho da classe Predio
#include "../include/asteroide.hpp"  // Inclui o cabeçalho da classe Asteroide
#include <GL/glut.h>

/******************************************************* INTERFACE PRIVADA *******************************************************/

float corpredio[] = {0.5, 0.5, 0.5}; // Cor cinza para o prédio
float corjanela[] = {1.0, 1.0, 0.0}; // Cor amarela para a janela

// Definição do construtor da classe Asteroide
Predio::Predio(float largura, float altura, float posicaoX, float larguraJanela, float alturaJanela) {
    this->largura = largura;
    this->altura = altura;
    this->posX = posicaoX; // Inicializa a coordenada X
    this->posY = 0.0; // Inicializa a coordenada Y
    this->larguraJanela = larguraJanela;
    this->alturaJanela = alturaJanela;
    this->atingido = false;
    adicionarJanela(10.0, 10.0, 10.0, 20.0); // Adicione as minhas janelas diretamente no meu construtor de predio
    adicionarJanela(-20.0, 10.0, 10.0, 20.0);
    adicionarJanela(10.0, 40.0, 10.0, 20.0);
    adicionarJanela(-20.0, 40.0, 10.0, 20.0);
    adicionarJanela(10.0, 70.0, 10.0, 20.0);
    adicionarJanela(-20.0, 70.0, 10.0, 20.0);
}

float Predio::getPosicaoX(){return this->posX;} // Retorna a coordenada X
float Predio::getPosicaoY(){return this->posY;} // Retorna a coordenada Y

void Predio::setAlturaJanela(float AlturaJanela){
    this->alturaJanela = AlturaJanela; // Define a nova altura da janela
}

void Predio::setLarguraJanela(float larguraJanela){
    this->larguraJanela = larguraJanela; // Define a nova largura da janela
}

void Predio::setAtingido(bool atingido){
    this->atingido = atingido;
}

void Predio::adicionarJanela(float x, float y, float largura, float altura) {
    janelas.push_back(std::make_tuple(x, y, largura, altura));  // Adiciona informações da janela ao vetor de janelas
}

void Predio::redimensionarPredio(float novaLarguraJanela, float novaAlturaJanela) {
    float proporcaoLargura = novaLarguraJanela / larguraJanela; // Calcule a proporção de redimensionamento
    float proporcaoAltura = novaAlturaJanela / alturaJanela;

    largura *= proporcaoLargura; // Atualize a largura e altura do prédio
    altura *= proporcaoAltura;

    posX *= proporcaoLargura; // Atualize a posição horizontal do prédio
    posY *= proporcaoAltura; // Atualize a posição vertical do prédio

    for (auto& janelaInfo : janelas){ // Atualize as coordenadas das janelas com base na nova escala 
        float x = std::get<0>(janelaInfo) * proporcaoLargura;
        float y = std::get<1>(janelaInfo) * proporcaoAltura;
        float largura = std::get<2>(janelaInfo) * proporcaoLargura;
        float altura = std::get<3>(janelaInfo) * proporcaoAltura;

        std::get<0>(janelaInfo) = x; // Atualize as informações da janela
        std::get<1>(janelaInfo) = y;
        std::get<2>(janelaInfo) = largura;
        std::get<3>(janelaInfo) = altura    ;
    }
}

bool Predio::verificaColisaoComAsteroides(std::vector<Asteroide>& asteroides){
    if(!atingido){
        for (Asteroide& asteroide : asteroides) {
            // Verifica se o asteroide está dentro do retângulo do prédio
            if (asteroide.getCoordenadaX() >= posX && asteroide.getCoordenadaX() <= (posX + largura) && 
                asteroide.getCoordenadaY() >= posY && asteroide.getCoordenadaY() <= (posY + altura)) {
                return true;
            }
    }
    }
    return false; // Não houve colisão detectada
}

void Predio::desenha(){
    glBegin(GL_TRIANGLE_FAN);
        if (atingido)
            glColor3f(0.0, 0.0, 0.4); // Cor azul escuro se o prédio foi atingido
        else
            glColor3fv(corpredio);
        
        glVertex2f(-largura / 2, 0.0); // Canto inferior esquerdo
        glVertex2f(largura / 2, 0.0); // Canto inferior direito
        glVertex2f(largura / 2, altura); // Canto superior direito
        glVertex2f(-largura / 2, altura); // Canto superior esquerdo
        glEnd();

        for (const auto& janelaInfo : janelas){ // Janela informações x, y, largura e altura
            float x = std::get<0>(janelaInfo);
            float y = std::get<1>(janelaInfo);
            float largura = std::get<2>(janelaInfo);
            float altura = std::get<3>(janelaInfo);

            glBegin(GL_TRIANGLE_FAN); // Desenha as janelas
            if (atingido)
                glColor3f(0.0, 0.0, 0.4); // Cor azul escuro se o prédio foi atingido
            else 
                glColor3fv(corjanela);

            glVertex2f(x, y);
            glVertex2f(x + largura, y);
            glVertex2f(x + largura, y + altura);
            glVertex2f(x, y + altura);
            glEnd();
        }
}
/*********************************************************************************************************************************/ 
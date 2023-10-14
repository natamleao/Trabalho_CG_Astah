#include "../include/asteroide.hpp" // Inclui o cabeçalho para a classe Asteroide
#include "../include/estrela.hpp"   // Inclui o cabeçalho para a classe Estrela
#include "../include/bomba.hpp"     // Inclui o cabeçalho para a classe Bomba
#include "../include/lua.hpp"       // Inclui o cabeçalho para a classe Lua
#include "../include/canhao.hpp"    // Inclui o cabeçalho para a classe Canhao
#include "../include/torre.hpp"     // Inclui o cabeçalho para a classe Torre
#include "../include/ceu.hpp"       // Inclui o cabeçalho para a classe Ceu
#include "../include/predio.hpp"    // Inclui o cabeçalho para a classe Predio
#include <GL/glut.h>                // Inclui a biblioteca GLUT para gráficos
#include <iostream>                 // Inclui a biblioteca para entrada/saída
#include <vector>                   // Inclui a biblioteca para usar vetores
#include <cstdlib>                  // Inclui a biblioteca para gerar números aleatórios
#include <ctime>                    // Inclui a biblioteca para obter o tempo atual
#include <cmath>                    // Inclui a biblioteca para funções matemáticas

int larguraJanela = 600;             // Largura inicial da janela
int alturaJanela = 600;              // Altura inicial da janela
float raioInicialBomba = 0.0;        // Raio inicial das bombas
double mouseX = larguraJanela / 2;   // Posição inicial do mouse X
double mouseY;                       // Posição inicial do mouse Y
float centroX = larguraJanela / 2;   // Posição X do centro para os predios
float larguraEntrePredios = 100.0;   // Largura entre prédios

float atrasoAsteroides = 2.0f;          // Atraso inicial (em segundos)
float tempoAtual = 0.0f;                // Tempo atual
float tempoDesdeUltimoAsteroide = 0.0f; // Tempo desde o último asteroide

std::vector<Asteroide> asteroides;         // Vetor para armazenar asteroides
std::vector<Estrela> estrelas;             // Vetor para armazenar objetos da classe Estrela
std::vector<Bomba> bombas;                 // Objetos da classe Bomba
std::vector<Predio> predios;               // Vetor para armazenar objetos da classe Predio
Torre torre(30, 175, 0);                   // Objeto da classe Torre com largura, altura e coordenada X do meio
Canhao canhao(30, 175, larguraJanela / 2); // Objeto da classe Canhao com largura, altura e coordenada X do meio
Ceu ceu(larguraJanela, alturaJanela);      // Objeto da classe Ceu, fundo da minha tela
Lua lua;                                   // Objeto da classe Lua

// Função de inicialização
void inicializacao();
// Função de redimensionamento da janela
void redimensionarJanela(int novaLargura, int novaAltura);
// Função para aumentar o raio das bombas
void aumentarRaioBombas();
// Função para capturar a posição do mouse
void mousePos(int x, int y);
// Função para tratar o clique do mouse
void cliqueMouse(int botao, int estado, int x, int y);
// Função para desenhar
void desenhar();
// Função de atualização
void atualizar(int valor);

int main(int argc, char** argv){
    glutInit(&argc, argv);                           // Inicializa o GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);     // Define o modo de exibição
    glutInitWindowPosition(0, 0);                    // Define a posição inicial da janela
    glutInitWindowSize(larguraJanela, alturaJanela); // Define o tamanho da janela
    glutCreateWindow("Missile Command");             // Cria a janela com o título especificado

    // Criando as estrelas
    for (int i = 0; i < 100; i++){
        estrelas.push_back(Estrela(5.0, larguraJanela, alturaJanela)); // Adiciona estrelas ao vetor
    }

    // Criando os prédios à esquerda do mundo
    for (int i = 0; i < 4; i++) {
        float posX = centroX - (i + 1) * larguraEntrePredios; // Ajuste a largura entre prédios conforme necessário
        Predio predioEsquerda(70.0, 110.0, posX, larguraJanela, alturaJanela);
        predios.push_back(predioEsquerda);
    }

    // Criando os prédios à direita do mundo
    for (int i = 0; i < 4; i++) {
        float posX = centroX + (i + 1) * larguraEntrePredios; // Ajuste a largura entre prédios conforme necessário
        Predio predioDireita(70.0, 110.0, posX, larguraJanela, alturaJanela);
        predios.push_back(predioDireita);
    }    

    inicializacao(); // Executa a função de inicialização
    glutDisplayFunc(desenhar); // Define a função de desenho
    glutTimerFunc(10, atualizar, 0);
    glutReshapeFunc(redimensionarJanela); // Define a função de redimensionamento da janela
    glutMouseFunc(cliqueMouse); // Define a função de clique do mouse
    glutPassiveMotionFunc(mousePos);

    srand(time(nullptr)); // Inicializa o gerador de números aleatórios

    glutMainLoop(); // Entra no loop principal do GLUT

    return 0;
}

// Função de inicialização
void inicializacao(){
    glClearColor(1.0, 1.0, 1.0, 1.0); // Define a cor de fundo da janela
    glPointSize(10.0); // Define o tamanho dos pontos
    glLineWidth(3.0);  // Define a largura da linha

    glMatrixMode(GL_PROJECTION);  // Define a matriz de projeção
    glLoadIdentity();
    glOrtho(0, larguraJanela - 1, 0, alturaJanela - 1, -1, 1); // Define a projeção ortográfica
    glMatrixMode(GL_MODELVIEW);   // Define a matriz de modelagem
    glLoadIdentity();
}

// Função de redimensionamento da janela
void redimensionarJanela(int novaLargura, int novaAltura){
    larguraJanela = novaLargura;           // Atualiza a largura da janela
    alturaJanela = novaAltura;             // Atualiza a altura da janela
    glViewport(0, 0, novaLargura, novaAltura); // Define a região de visualização

    ceu.update_ceu(larguraJanela, alturaJanela);
    glMatrixMode(GL_PROJECTION);  // Define a matriz de projeção
    glLoadIdentity();
    glOrtho(0, larguraJanela - 1, 0, alturaJanela - 1, -1, 1); // Redefine a projeção ortográfica

    // Atualize as coordenadas das estrelas para refletir as novas dimensões
    for(Estrela& estrela : estrelas){
        estrela.atualizarCoordenadas(novaLargura, novaAltura);
    }

    // Redimensione os prédios para refletir as novas dimensões
    for (Predio& predio : predios){
        predio.redimensionarPredio(novaLargura, novaAltura);
        predio.setAlturaJanela(alturaJanela);
        predio.setLarguraJanela(larguraJanela);
    }

    glutPostRedisplay();               // Solicita a redisplay da cena
}

// Função para aumentar o raio das bombas
void aumentarRaioBombas(){
    const float incrementoRaio = 1.2;  // Valor de incremento para o raio
    const float limiteRaio = 40.0;     // Valor máximo para o raio

    for (auto it = bombas.begin(); it != bombas.end();) {
        Bomba& bomba = *it; // Obtem uma referência para o objeto Bomba apontado por 'it'

        if (!bomba.getDiminuindo() && bomba.getRaio() < limiteRaio)
            bomba.setRaio(bomba.getRaio() + incrementoRaio); // Aumenta o raio da bomba atual somando o valor de incremento ao raio atual
        else if (!bomba.getDiminuindo() && bomba.getRaio() >= limiteRaio)
            bomba.setDiminuindo(true); // Inicia a diminuição da bomba
        else if (bomba.getDiminuindo()) {
            bomba.setRaio(bomba.getRaio() - incrementoRaio); // Reduza o raio da bomba até que ele seja zero
            if (bomba.getRaio() <= 0.0) {
                it = bombas.erase(it); // Se a bomba atingiu o raio mínimo, remova-a do vetor de bombas
                continue;
            }
        }
        ++it;
    }

    glutPostRedisplay();
}

// Função para capturar a posição do mouse
void mousePos(int x, int y){
    mouseX = x;
    mouseY = glutGet(GLUT_WINDOW_HEIGHT) - y; // Inverta a coordenada y
    glutPostRedisplay(); // Redesenha a janela
}

// Função para tratar o clique do mouse
void cliqueMouse(int botao, int estado, int x, int y){
    float coordenadaX = x;                // Calcula a coordenada X do clique do mouse
    float coordenadaY = alturaJanela - y; // Calcula a coordenada Y do clique do mouse invertendo a posição Y em relação à altura da janela

    if(botao == GLUT_LEFT_BUTTON && estado == GLUT_DOWN){
        Bomba novaBomba(coordenadaX, coordenadaY, raioInicialBomba);
        bombas.push_back(novaBomba);
        raioInicialBomba = 0.0;          // Reseta o raio inicial
        glutIdleFunc(aumentarRaioBombas); // Continua a animação
    }

    glutPostRedisplay(); // Solicita a redisplay da cena
}

// Função para desenhar
void desenhar(){
    glClear(GL_COLOR_BUFFER_BIT);

    ceu.desenha();

    glPushMatrix();
    torre.desenha(larguraJanela - 1);
    glPopMatrix();

    glPushMatrix();
    canhao.desenha(mouseX, mouseY, larguraJanela / 2);
    glPopMatrix();

    for (Estrela& estrela : estrelas) {
        estrela.desenha(); // Desenha as estrelas no cenário
    }

    glPushMatrix();
    glTranslated((larguraJanela / 2), (3 * alturaJanela / 4), 0.0); // Translada a lua
    lua.desenha(); // Desenha a lua
    glPopMatrix();

    for (Bomba& bomba : bombas) {
        glPushMatrix();
        glTranslatef(bomba.getCentroX(), bomba.getCentroY(), 0.0); // Translada a bomba
        bomba.desenha(); // Desenha a bomba
        glPopMatrix();
    }

    for(Predio& predio : predios){
        glPushMatrix();
        glTranslated(predio.getPosicaoX(), predio.getPosicaoY(), 0.0); // Translada o prédio
        predio.desenha(); // Desenha o prédio
        glPopMatrix();
    }

    // Desenhe os asteroides com atraso
    glPushMatrix();
    glTranslated(larguraJanela / 2.0, larguraJanela / 2.0, 0.0);
    glScalef(250.0, 250.0, 1.0);
    for (size_t i = 0; i < asteroides.size(); i++) {
        Asteroide& asteroide = asteroides[i];
        if (!asteroide.getAtingido() && tempoAtual >= atrasoAsteroides * (i + 1)) {
            asteroide.desenha();
        }
    }
    glPopMatrix();

    glutSwapBuffers();
}

// Função de atualização
void atualizar(int valor){
    tempoAtual += 0.01f; // Atualiza o tempo atual
    tempoDesdeUltimoAsteroide += 0.01f; // Atualiza o tempo desde o último asteroide
    // Crie um novo asteroide somente se o tempo desde o último asteroide for maior que o atraso desejado
    if (tempoDesdeUltimoAsteroide >= atrasoAsteroides){
        float randomX = (rand() / (float)RAND_MAX) * 2.0f - 1.0f;
        float randomDx = (rand() / (float)RAND_MAX) * 0.2f - 0.1f; // Defina uma velocidade horizontal aleatória
        float randomDy = -0.6f; // Defina uma velocidade vertical negativa constante
        asteroides.push_back(Asteroide(randomX, 1.2f, 0.02f, randomDx, randomDy));

        // Reinicie o tempo desde o último asteroide
        tempoDesdeUltimoAsteroide = 0.0f;
    }
    // Atualize os asteroides existentes
    for (size_t i = 0; i < asteroides.size(); i++){
        Asteroide& asteroide = asteroides[i];
        asteroide.atualiza(0.01f, larguraJanela);

        // Verifique se o asteroide saiu completamente da tela (abaixo ou fora das laterais)
        if (asteroide.getAtingido()){
            // Remova o asteroide do vetor
            asteroides.erase(asteroides.begin() + i);
            i--; // Atualize o índice após a remoção
        }
    }

    glutPostRedisplay();
    glutTimerFunc(10, atualizar, 0);
}
#include "../include/estrela.hpp" // Inclui o cabeçalho para a classe Estrela
#include <random>                 // Inclui a biblioteca para geração de números aleatórios

/******************************************************* INTERFACE PRIVADA *******************************************************/

// Definição do construtor da classe Estrela
Estrela::Estrela(float tamanho, int largura, float altura) : tamanho(tamanho){
    std::random_device rd;  // Inicializa o gerador de números aleatórios
    std::mt19937 gen(rd()); // Mersenne Twister 19937 como motor
    std::uniform_real_distribution<float> x_dist(2.0, static_cast<float>(largura - 2)); // Gera um número aleatório para x no intervalo [2.0, largura - 2.0]
    float x = x_dist(gen);
    std::uniform_real_distribution<float> y_dist(static_cast<float>(altura / 2 + 1), static_cast<float>(altura - 2)); // Gera um número aleatório para y no intervalo [altura / 2 + 1, altura - 2.0]
    float y = y_dist(gen);
    this->vetorTranslacao = {x, y}; // Define o vetor de translação para a estrela
}

void Estrela::atualizarCoordenadas(int novaLargura, int novaAltura){
    std::random_device rd;  // Inicializa o gerador de números aleatórios
    std::mt19937 gen(rd()); // Mersenne Twister 19937 como motor
    std::uniform_real_distribution<float> x_dist(2.0, static_cast<float>(novaLargura - 2)); // Gera um número aleatório para x no intervalo [2.0, novaLargura - 2.0]
    float x = x_dist(gen);
    std::uniform_real_distribution<float> y_dist(static_cast<float>(novaAltura / 2 + 1), static_cast<float>(novaAltura - 2)); // Gera um número aleatório para y no intervalo [novaAltura / 2 + 1, novaAltura - 2.0]
    float y = y_dist(gen);
    this->vetorTranslacao = {x, y}; // Atualiza o vetor de translação da estrela com as novas coordenadas
}

void Estrela::desenha(){
    glColor3f(1.0, 215/255.0, 1.0); // Define a cor branca para a estrela (RGB)
    glPushMatrix();
    glTranslatef(vetorTranslacao[0], vetorTranslacao[1], 0.0); // Posiciona a estrela no vetor de translação
    glBegin(GL_TRIANGLES); // Inicia o desenho de triângulos (as pontas da estrela)
        for (int i = 0; i < 5; i++) {
            float angle1 = i * 2 * M_PI / 5;       // Calcula o ângulo para uma das pontas
            float x1 = tamanho * sin(angle1);      // Calcula a coordenada x da ponta
            float y1 = tamanho * cos(angle1);      // Calcula a coordenada y da ponta
            float angle2 = (i + 2) * 2 * M_PI / 5; // Deslocamento de 2 ângulos para obter a ponta oposta
            float x2 = tamanho * sin(angle2);      // Calcula a coordenada x da ponta oposta
            float y2 = tamanho * cos(angle2);      // Calcula a coordenada y da ponta oposta
            glVertex2f(0.0, 0.0); // Centro da estrela
            glVertex2f(x1, y1);   // Uma das pontas da estrela
            glVertex2f(x2, y2);   // A ponta oposta da estrela
        }
    glEnd(); // Finaliza o desenho dos triângulos
    glPopMatrix();
}

/*********************************************************************************************************************************/ 
/*********************************************** PUBLIC INTERFACE ***********************************************/
/**
 * @file estrela.hpp
 * 
 * @brief Declaração da classe Estrela, que representa uma estrela gráfica.
 * 
 * Esta classe define uma estrela gráfica que pode ser desenhada em uma janela OpenGL.
 * Ela possui propriedades como tamanho e vetor de translação, e permite desenhar a estrela no contexto gráfico.
 * 
 */

#ifndef ESTRELA_H
#define ESTRELA_H

#include <GL/glut.h>
#include <cmath>
#include <vector>

class Estrela{
    private:
        float tamanho;                 /**< O tamanho da estrela. */
        std::vector<float> vetorTranslacao; /**< O vetor de translação para posicionar a estrela. */
    public:
    
        /**
         * @brief Construtor da classe Estrela.
         * 
         * Cria um objeto Estrela com um tamanho especificado, gerando uma posição aleatória dentro da janela.
         * 
         * @param tamanho O tamanho da estrela.
         * @param largura A largura da janela.
         * @param altura A altura da janela.
         */
        Estrela(float tamanho, int largura, float altura);

        /**
         * @brief Desenha a estrela no contexto gráfico.
         */
        void desenha();
};

#endif

/****************************************************************************************************************/
/******************************************************* INTERFACE PÚBLICA *******************************************************/

#ifndef CEU_H
#define CEU_H

#include <GL/glut.h>

/**
 * @file ceu.hpp
 * 
 * @brief Declaração da classe Ceu, que representa o céu em um jogo.
 * 
 * Esta classe define um cenário de céu que pode ser desenhado em uma janela OpenGL.
 * Ele possui propriedades como largura e altura, e permite desenhar o céu no contexto gráfico.
 * 
 */
class Ceu{
    private:
        float largura;  /**< A largura do cenário do céu. */
        float altura;   /**< A altura do cenário do céu. */

    public:
        /**
         * @brief Construtor da classe Ceu.
         * 
         * Cria um objeto Ceu com dimensões específicas.
         * 
         * @param largura A largura do cenário do céu.
         * @param altura A altura do cenário do céu.
         */
        Ceu(float largura, float altura);

        /**
         * @brief Obtém a altura do cenário do céu.
         * 
         * @return A altura do cenário do céu.
         */
        float getAltura();

        /**
         * @brief Obtém a largura do cenário do céu.
         * 
         * @return A largura do cenário do céu.
         */
        float getLargura();

        /**
         * @brief Define a altura do cenário do céu.
         * 
         * @param novaAltura A nova altura para o cenário do céu.
         */
        void setAltura(int novaAltura);

        /**
         * @brief Define a largura do cenário do céu.
         * 
         * @param novaLargura A nova largura para o cenário do céu.
         */
        void setLargura(int novaLargura);

        /**
         * @brief Atualiza as dimensões do cenário do céu.
         * 
         * Atualiza as dimensões do cenário do céu com novos valores de largura e altura.
         * 
         * @param largura A nova largura do cenário do céu.
         * @param altura A nova altura do cenário do céu.
         */
        void update_ceu(int largura, int altura);

        /**
         * @brief Desenha o cenário do céu.
         * 
         * Desenha o cenário do céu no contexto gráfico.
         */
        void desenha();
};

#endif

/*********************************************************************************************************************************/
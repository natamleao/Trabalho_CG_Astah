/******************************************************* INTERFACE PÚBLICA *******************************************************/

#ifndef CANHAO_H
#define CANHAO_H

#include <GL/glut.h>
#include <cmath>

/**
 * @file canhao.hpp
 * 
 * @brief Declaração da classe Canhao, que representa um canhão em um jogo.
 * 
 * Esta classe define um canhão que pode ser desenhado em uma janela OpenGL.
 * Ele possui propriedades como posição e dimensões, e permite desenhar o canhão no contexto gráfico.
 * 
 */
class Canhao{
    private:
        double alvox;   /**< A coordenada x do canhão. */
        double alvoy;   /**< A coordenada y do canhão. */
        double largura; /**< A largura do canhão. */
        double topo;    /**< A topo do canhão. */
        double meio;    /**< A coordenada x do meio do canhão. */

    public:
        /**
         * @brief Construtor da classe Canhao.
         * 
         * Cria um objeto Canhao com dimensões específicas.
         * 
         * @param largura A largura do canhão.
         * @param topo A topo do canhão.
         * @param meio A coordenada x do meio do canhão.
         */
        Canhao(double largura, double topo, double meio);

        /**
         * @brief Calcula o ângulo.
         * 
         * Calcula o ângulo com base nas coordenadas do mouse e do meio do canhão.
         * 
         * @param mousex A coordenada x do mouse.
         * @param mousey A coordenada y do mouse.
         * @param meio A coordenada x do meio do canhão.
         * @param largura A coordenada y do largura do canhão.
         * 
         * @return O ângulo calculado.
         */
        double calcularAngulo(double mousex, double mousey, double meio, double largura);

        /**
         * @brief Desenha uma linha.
         * 
         * Desenha uma linha no contexto gráfico.
         * 
         * @param alvox A coordenada x inicial da linha.
         * @param alvoy A coordenada y inicial da linha.
         * @param topo A topo da linha.
         * @param meio A coordenada x do meio.
         */
        void desenharLinha(double alvox, double alvoy, double topo, double meio);

        /**
         * @brief Desenha o cano do canhão.
         * 
         * Desenha o cano do canhão com base nas coordenadas do mouse e do meio do canhão.
         * 
         * @param mousex A coordenada x do mouse.
         * @param mousey A coordenada y do mouse.
         * @param meio A coordenada x do meio do canhão.
         * @param largura A coordenada y do largura do canhão.
         */
        void desenharCano(double mousex, double mousey, double meio, double largura);

        /**
         * @brief Desenha um círculo.
         * 
         * Desenha um círculo no contexto gráfico.
         */
        void desenharCirculo();

        /**
         * @brief Função de desenho do canhão.
         * 
         * Desenha o canhão na posição especificada.
         * 
         * @param x A coordenada x onde o canhão deve ser desenhado.
         * @param y A coordenada y onde o canhão deve ser desenhado.
         * @param meio A coordenada x do meio do canhão.
         */
        void desenha(double x, double y, double meio);
};

#endif

/*********************************************************************************************************************************/ 
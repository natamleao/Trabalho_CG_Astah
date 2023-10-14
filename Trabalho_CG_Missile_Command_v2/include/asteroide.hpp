/******************************************************* INTERFACE PÚBLICA *******************************************************/

#ifndef ASTEROIDE_H
#define ASTEROIDE_H

#include <GL/glut.h>
#include <cstdlib>
#include <cmath>

/**
 * @file asteroide.hpp
 * 
 * @brief Declaração da classe Asteroide, que representa um asteroide em um jogo.
 * 
 * Esta classe define um asteroide que pode ser desenhado em uma janela OpenGL.
 * Ele possui propriedades como posição, raio e velocidade, e permite desenhar o asteroide no contexto gráfico.
 * 
 */
class Asteroide {
    private:
        float x;       /**< A coordenada x do asteroide. */
        float y;       /**< A coordenada y do asteroide. */
        float raio;    /**< O raio do asteroide. */
        float dx;      /**< A velocidade horizontal do asteroide. */
        float dy;      /**< A velocidade vertical do asteroide. */
        bool atingido; /**< Indica se o asteroide foi atingido. */
    
    public:
        /**
         * @brief Construtor da classe Asteroide.
         * 
         * Cria um objeto Asteroide com parâmetros específicos.
         * 
         * @param x Posição x inicial do asteroide.
         * @param y Posição y inicial do asteroide.
         * @param raio Raio do asteroide.
         * @param dx Velocidade horizontal do asteroide.
         * @param dy Velocidade vertical do asteroide.
         */
        Asteroide(float x, float y, float raio, float dx, float dy);

        /**
         * @brief Obtém a posição x do asteroide.
         * 
         * @return A posição x do asteroide.
         */
        float getCoordenadaX();
    
        /**
         * @brief Obtém a posição y do asteroide.
         * 
         * @return A posição y do asteroide.
         */
        float getCoordenadaY();
    
        /**
         * @brief Verifica se o asteroide foi atingido.
         * 
         * @return true se o asteroide foi atingido, false caso contrário.
         */
        bool getAtingido();
    
        /**
         * @brief Define a posição x do asteroide.
         * 
         * @param x Nova posição x do asteroide.
         */
        void setCoordenadaX(float x);
    
        /**
         * @brief Define a posição y do asteroide.
         * 
         * @param y Nova posição y do asteroide.
         */
        void setCoordenadaY(float y);
    
        /**
         * @brief Define se o asteroide foi atingido.
         * 
         * @param atingido true se o asteroide foi atingido, false caso contrário.
         */
        void setAtingido(bool atingido);
    
        /**
         * @brief Atualiza a posição do asteroide com base no tempo.
         * 
         * @param deltaTempo Intervalo de tempo desde a última atualização.
         * @param larguraJanela Largura da janela de projeção.
         */
        void atualiza(float deltaTempo, int larguraJanela) ;

        /**
         * @brief Função de desenho do asteroide.
         * 
         * Desenha o asteroide na posição atual.
         */
        void desenha();
    };

#endif

/*********************************************************************************************************************************/ 
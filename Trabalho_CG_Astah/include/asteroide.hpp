/******************************************************* INTERFACE PÚBLICA *******************************************************/

#ifndef ASTEROIDE_H
#define ASTEROIDE_H

#include <GL/glut.h>
#include <cstdlib>
#include <cmath>

/**
 * @file asteroide.h
 * 
 * @brief Declaração da classe Asteroide, que representa um asteroide gráfico.
 * 
 * Esta classe define um asteroide gráfico que pode ser desenhado em uma janela OpenGL.
 * Ela possui propriedades como raio, posição e permite desenhar o asteroide no contexto gráfico.
 */
class Asteroide{
    private:
        float x;        /**< A coordenada X do centro do asteroide. */
        float y;        /**< A coordenada Y do centro do asteroide. */
        float raio;     /**< O raio do asteroide. */
        float dx;       /**< A velocidade horizontal do asteroide. */
        float dy;       /**< A velocidade vertical do asteroide. */
        bool atingido;  /**< Flag que determina se o asteroide foi atingido. */
    
    public:
        /**
         * @brief Construtor da classe Asteroide.
         * 
         * Cria um objeto Asteroide com propriedades iniciais.
         * 
         * @param x A coordenada X do centro do asteroide.
         * @param y A coordenada Y do centro do asteroide.
         * @param raio O raio do asteroide.
         * @param dx A velocidade horizontal do asteroide.
         * @param dy A velocidade vertical do asteroide.
         */
        Asteroide(float x, float y, float raio, float dx, float dy);
    
        /**
         * @brief Desenha o asteroide no contexto gráfico.
         */
        void desenha();
    
        /**
         * @brief Define a coordenada X do centro do asteroide.
         * 
         * @param x A coordenada X do centro do asteroide.
         */
        void setX(float x);
    
        /**
         * @brief Define a coordenada Y do centro do asteroide.
         * 
         * @param y A coordenada Y do centro do asteroide.
         */
        void setY(float y);
    
        /**
         * @brief Define se o asteroide foi atingido.
         * 
         * @param atingido Um valor booleano que indica se o asteroide foi atingido.
         */
        void setAtingido(bool atingido);
    
        /**
         * @brief Obtém a coordenada X do centro do asteroide.
         * 
         * @return A coordenada X do centro do asteroide.
         */
        float getCoordenadaX();
    
        /**
         * @brief Obtém a coordenada Y do centro do asteroide.
         * 
         * @return A coordenada Y do centro do asteroide.
         */
        float getCoordenadaY();
    
        /**
         * @brief Verifica se o asteroide foi atingido.
         * 
         * @return true se o asteroide foi atingido, false caso contrário.
         */
        bool getAtingido();
    
        /**
         * @brief Obtém o raio do asteroide.
         * 
         * @return O raio do asteroide.
         */
        float getRaio();
    
        /**
         * @brief Atualiza a posição do asteroide com base no tempo e na largura da janela.
         * 
         * @param deltaTempo O intervalo de tempo desde a última atualização.
         * @param larguraJanela A largura da janela em que o asteroide está sendo desenhado.
         */
        void atualiza(float deltaTempo, int larguraJanela);
};

#endif

/*********************************************************************************************************************************/ 
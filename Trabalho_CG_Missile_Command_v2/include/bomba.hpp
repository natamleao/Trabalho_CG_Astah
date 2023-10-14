/******************************************************* INTERFACE PÚBLICA *******************************************************/
                                                
#ifndef BOMBA_H
#define BOMBA_H

#include <GL/glut.h>
#include <cmath>

/**
 * @file bomba.hpp
 * 
 * @brief Declaração da classe Bomba, que representa uma bomba gráfica.
 * 
 * Esta classe define uma bomba gráfica que pode ser desenhada em uma janela OpenGL.
 * Ela possui propriedades como raio e posição, e permite desenhar a bomba no contexto gráfico.
 * 
 */
class Bomba{
    private:
        float raio;      /**< O raio da bomba. */
        float centroX;   /**< A coordenada X do centro da bomba. */
        float centroY;   /**< A coordenada Y do centro da bomba. */
        bool diminuindo; /**< Flag que determinna o estado da bomba*/
        
    public:
    
        /**
         * @brief Construtor da classe Bomba.
         * 
         * Cria um objeto Bomba com raio zero e posição inicial (0.0, 0.0).
         */
        Bomba(float x=0.0, float y=0.0, float raio=0.0);

        /**
         * @brief Obtém o raio da bomba.
         * 
         * @return O raio da bomba.
         */
        float getRaio();

        /**
         * @brief Obtém a coordenada X do centro da bomba.
         * 
         * @return A coordenada X do centro da bomba.
         */
        float getCentroX();

        /**
         * @brief Obtém a coordenada Y do centro da bomba.
         * 
         * @return A coordenada Y do centro da bomba.
         */
        float getCentroY();

        /**
         * @brief Verifica se a bomba está diminuindo.
         * 
         * @return true se a bomba está diminuindo, false caso contrário.
         */
        bool getDiminuindo() const;

        /**
         * @brief Define a posição da bomba.
         * 
         * @param x A coordenada X da posição.
         * @param y A coordenada Y da posição.
         */
        void setPosicao(float x, float y);

        /**
         * @brief Define o raio da bomba.
         * 
         * @param raio O raio da bomba.
         */
        void setRaio(float raio = 0.0);

        /**
         * @brief Define se a bomba está diminuindo.
         * 
         * @param value Um valor booleano que indica se a bomba está diminuindo.
         */
        void setDiminuindo(bool value);

        /**
         * @brief Desenha a bomba no contexto gráfico.
         */
        void desenha();
};

#endif

/*********************************************************************************************************************************/ 
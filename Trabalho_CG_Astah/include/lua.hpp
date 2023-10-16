/******************************************************* INTERFACE PÚBLICA *******************************************************/

#ifndef LUA_H
#define LUA_H

#include <GL/glut.h>
#include <cmath>

/**
 * @file lua.hpp
 * 
 * @brief Declaração da classe Lua, que representa uma lua gráfica.
 * 
 * Esta classe define uma lua gráfica que pode ser desenhada em uma janela OpenGL.
 * Ela possui propriedades como raio e posição, e permite desenhar a lua no contexto gráfico.
 * 
 */
class Lua{
    private:
        float raio;      /**< O raio da lua. */
        float centroX;   /**< A coordenada X do centro da lua. */
        float centroY;   /**< A coordenada Y do centro da lua. */

    public:
    
        /**
         * @brief Construtor da classe Lua.
         * 
         * Cria um objeto Lua com um raio especificado (padrão de 50.0) e posição inicial (0.0, 0.0).
         * 
         * @param raio O raio da lua.
         */
        Lua(float raio=50.0);

        /**
         * @brief Obtém o raio da lua.
         * 
         * @return O raio da lua.
         */
        float getRaio();

        /**
         * @brief Define a posição da lua.
         * 
         * @param x A coordenada X da posição.
         * @param y A coordenada Y da posição.
         */
        void setPosicao(float x, float y);

        /**
         * @brief Define o raio da lua.
         * 
         * @param raio O raio da lua.
         */
        void setRaio(float raio = 50.0);

        /**
         * @brief Desenha a lua no contexto gráfico.
         */
        void desenha();
};

#endif

/*********************************************************************************************************************************/ 
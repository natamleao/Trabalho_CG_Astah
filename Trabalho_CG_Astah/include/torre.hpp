/******************************************************* INTERFACE PÚBLICA *******************************************************/

#ifndef TORRE_H
#define TORRE_H

#include <GL/glut.h>
#include <cmath>

/**
 * @file torre.hpp
 * 
 * @brief Declaração da classe Torre, que representa uma torre em um jogo.
 * 
 * Esta classe define uma torre que pode ser desenhada em uma janela OpenGL.
 * Ela possui propriedades como largura e altura, e permite desenhar a torre no contexto gráfico.
 * 
 */
class Torre{
    private:
        double largura; /**< A largura da torre. */
        double altura;  /**< A altura da torre. */
        double meio;    /**< A coordenada x do meio da torre. */

    public:
        /**
         * @brief Construtor da classe Torre.
         * 
         * Cria um objeto Torre com dimensões específicas.
         * 
         * @param largura A largura da torre.
         * @param altura A altura da torre.
         * @param meio A coordenada x do meio da torre.
         */
        Torre(double largura, double altura, double meio);

        /**
         * @brief Função de desenho do prédio da torre.
         * 
         * Desenha o prédio da torre com as dimensões especificadas.
         * 
         * @param largura A largura do prédio.
         * @param altura A altura do prédio.
         */
        void desenharPredio(double largura, double altura);
        
        /**
         * @brief Função de desenho de um círculo.
         * 
         * Desenha um círculo com o raio especificado e coordenadas de centro.
         * 
         * @param raio O raio do círculo.
         * @param meio_x A coordenada x do centro do círculo.
         * @param meio_y A coordenada y do centro do círculo.
         */
        void desenharCirculo(double raio, double meio_x, double meio_y);
        
        /**
         * @brief Função de desenho da bandeira.
         * 
         * Desenha uma bandeira com as dimensões especificadas.
         * 
         * @param topo A coordenada y do topo da bandeira.
         * @param lado A coordenada x do lado da bandeira.
         * @param tam O tamanho da bandeira.
         */
        void desenharBandeira(double topo, double lado, double tam);
        
        /**
         * @brief Função de desenho dos mastros.
         * 
         * Desenha os mastros das bandeiras.
         * 
         * @param largura A largura dos mastros.
         * @param altura A altura dos mastros.
         */
        void desenharMastros(double largura, double altura);

        /**
         * @brief Função de desenho da torre.
         * 
         * Desenha a torre com o tamanho especificado.
         * 
         * @param tamanho O tamanho da torre a ser desenhada.
         */
        void desenha(double tamanho);
};

#endif

/*********************************************************************************************************************************/ 
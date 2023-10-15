/******************************************************* INTERFACE PÚBLICA *******************************************************/

#ifndef PREDIO_H
#define PREDIO_H

#include "../include/asteroide.hpp"
#include <GL/glut.h>
#include <vector>
#include <tuple>

/**
 * @file predio.hpp
 * 
 * @brief Declaração da classe Predio, que representa um prédio em um jogo.
 * 
 * Esta classe define um prédio que pode ser desenhado em uma janela OpenGL.
 * Ele possui propriedades como largura, altura, posição e janelas, e permite desenhar o prédio no contexto gráfico.
 * 
 */
class Predio{
    private:
        float largura;       /**< Largura do prédio. */
        float altura;        /**< Altura do prédio. */
        float posX;          /**< Posição x do prédio. */
        float posY;          /**< Posição y do prédio. */
        float alturaJanela;  /**< Altura original da janela de projeção. */
        float larguraJanela; /**< Largura original da janela de projeção. */
        bool atingido;       /**< Marcação para ver se um prédio foi atingido*/
        std::vector<std::tuple<float, float, float, float>> janelas; /**< Vetor de janelas no prédio. */

    public:
        /**
         * @brief Construtor da classe Predio.
         * 
         * Cria um objeto Predio com parâmetros específicos.
         * 
         * @param largura Largura do prédio.
         * @param altura Altura do prédio.
         * @param posicaoX Posição x do prédio.
         * @param larguraJanela Largura original da janela de projeção.
         * @param alturaJanela Altura original da janela de projeção.
         */
        Predio(float largura, float altura, float posicaoX, float larguraJanela, float alturaJanela);

        /**
         * @brief Obtém a posição x do prédio.
         * 
         * @return A posição x do prédio.
         */
        float getPosicaoX();

        /**
         * @brief Obtém a posição y do prédio.
         * 
         * @return A posição y do prédio.
         */
        float getPosicaoY(); 

        /**
         * @brief Define a altura da janela de projeção.
         * 
         * @param alturaJanela Nova altura da janela de projeção.
         */
        void setAlturaJanela(float alturaJanela);

        /**
         * @brief Define a largura da janela de projeção.
         * 
         * @param larguraJanela Nova largura da janela de projeção.
         */
        void setLarguraJanela(float larguraJanela);

        /**
         * @brief Adiciona uma janela ao prédio.
         * 
         * @param x Posição x da janela.
         * @param y Posição y da janela.
         * @param largura Largura da janela.
         * @param altura Altura da janela.
         */
        void adicionarJanela(float x, float y, float largura, float altura);

        /**
         * @brief Redimensiona o prédio para corresponder à nova largura e altura da janela.
         * 
         * @param novaLarguraJanela Nova largura da janela de projeção.
         * @param novaAlturaJanela Nova altura da janela de projeção.
         */
        void redimensionarPredio(float novaLarguraJanela, float novaAlturaJanela);

        // Adicione esta função para verificar colisões com asteroides
        bool verificaColisaoComAsteroides(std::vector<Asteroide>& asteroides);

        void setAtingido(bool atingido);

        float getLargura(); 

        float getAltura(); 

        bool getAtingido();

        /**
         * @brief Função de desenho do prédio.
         * 
         * Desenha o prédio na posição atual.
         */
        void desenha();
};

#endif

/*********************************************************************************************************************************/
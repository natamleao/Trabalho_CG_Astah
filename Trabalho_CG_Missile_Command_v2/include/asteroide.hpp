/*********************************************** INTERFACE PRIVADA ***********************************************/
/**
 * @file asteroide.hpp
 * 
 * @brief Declaração da classe Asteroide, que representa um asteroide em um jogo.
 * 
 * Esta classe define um asteroide que pode ser desenhado em uma janela OpenGL.
 * Ele possui propriedades como posição, raio e velocidade, e permite desenhar o asteroide no contexto gráfico.
 * 
 */

#ifndef ASTEROIDE_H
#define ASTEROIDE_H

#include <GL/glut.h>
#include <cstdlib>
#include <cmath>

class Asteroide{
private:
    float x;                 /**< A coordenada x do asteroide. */
    float y;                 /**< A coordenada y do asteroide. */
    float raio;              /**< O raio do asteroide. */
    float dx;                /**< A velocidade horizontal do asteroide. */
    float dy;                /**< A velocidade vertical do asteroide. */
    bool atingido;           /**< Indica se o asteroide foi atingido. */
    float* centroCirculoX;   /**< Ponteiro para a coordenada x do centro do círculo. */
    float* centroCirculoY;   /**< Ponteiro para a coordenada y do centro do círculo. */
    float* raioCirculo;      /**< Ponteiro para o raio do círculo. */

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
     * @param centroCirculoX Ponteiro para a coordenada x do centro do círculo.
     * @param centroCirculoY Ponteiro para a coordenada y do centro do círculo.
     * @param raioCirculo Ponteiro para o raio do círculo.
     */
    Asteroide(float x, float y, float raio, float dx, float dy, float* centroCirculoX, float* centroCirculoY, float* raioCirculo);

    /**
     * @brief Função de desenho do asteroide.
     * 
     * Desenha o asteroide na posição atual.
     */
    void desenha();

    /**
     * @brief Define a posição x do asteroide.
     * 
     * @param x Nova posição x do asteroide.
     */
    void setX(float x);

    /**
     * @brief Define a posição y do asteroide.
     * 
     * @param y Nova posição y do asteroide.
     */
    void setY(float y);

    /**
     * @brief Define se o asteroide foi atingido.
     * 
     * @param atingido true se o asteroide foi atingido, false caso contrário.
     */
    void setAtingido(bool atingido);

    /**
     * @brief Obtém a posição x do asteroide.
     * 
     * @return A posição x do asteroide.
     */
    float getX();

    /**
     * @brief Obtém a posição y do asteroide.
     * 
     * @return A posição y do asteroide.
     */
    float getY();

    /**
     * @brief Verifica se o asteroide foi atingido.
     * 
     * @return true se o asteroide foi atingido, false caso contrário.
     */
    bool foiAtingido();

    /**
     * @brief Atualiza a posição do asteroide com base no tempo.
     * 
     * @param deltaTempo Intervalo de tempo desde a última atualização.
     */
    void atualiza(float deltaTempo);
};

#endif

/*****************************************************************************************************************/ 
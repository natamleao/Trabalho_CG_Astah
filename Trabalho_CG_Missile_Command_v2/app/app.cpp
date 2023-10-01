#include "../include/bomba.hpp"   // Inclui o cabeçalho para a classe Bomba
#include "../include/estrela.hpp" // Inclui o cabeçalho para a classe Estrela
#include "../include/lua.hpp"     // Inclui o cabeçalho para a classe Lua
#include <GL/glut.h>              // Inclui a biblioteca GLUT
#include <GL/gl.h>                // Inclui a biblioteca OpenGL
#include <vector>                 // Inclui a biblioteca para uso de vetores

int janelaLargura = 600;       // Largura inicial da janela
int janelaAltura = 600;        // Altura inicial da janela
float raioInicial = 0.0;       // Raio inicial das bombas

std::vector<Estrela> estrelas; // Vetor para armazenar objetos da classe Estrela
std::vector<Bomba> bombas;     // Objetos da classe Bomba
Lua lua;                       // Objeto da classe Lua

void inicio(){
    glClearColor(25.0 / 255, 25.0 / 255, 112.0 / 255, 1.0); // Define a cor de fundo da janela
    glPointSize(10.0); // Define o tamanho dos pontos
    glLineWidth(3.0);  // Define a largura da linha
}

void redimensionaJanela(int largura, int altura){
    janelaLargura = largura;           // Atualiza a largura da janela
    janelaAltura = altura;             // Atualiza a altura da janela
    glViewport(0, 0, largura, altura); // Define a região de visualização
    glutPostRedisplay();               // Solicita a redisplay da cena
}

void aumentarRaio(){
    const float incremento = 0.0101; // Valor de incremento para o raio
    const float limiteRaio = 50.0;   // Valor máximo para o raio

    for (Bomba& bomba : bombas) {
        if (bomba.getRaio() < limiteRaio) {
            bomba.setRaio(bomba.getRaio() + incremento);
        }
    }

    glutPostRedisplay();
}

void mouseClique(int button, int state, int x, int y){
    float coord_x = x;
    float coord_y = janelaAltura - y;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        Bomba novaBomba(coord_x, coord_y, raioInicial);
        bombas.push_back(novaBomba);
        raioInicial = 0.0; // Reseta o raio inicial
        glutIdleFunc(aumentarRaio); // Continua a animação
    }

    glutPostRedisplay(); // Solicita a redisplay da cena
}

void desenha(){
    glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor

    glMatrixMode(GL_PROJECTION);  // Define a matriz de projeção
    glLoadIdentity();
    glOrtho(0, janelaLargura - 1, 0, janelaAltura - 1, -1, 1); // Define a projeção ortográfica
    glMatrixMode(GL_MODELVIEW);   // Define a matriz de modelagem
    glLoadIdentity();

    for (Estrela& estrela : estrelas){
        estrela.desenha(); // Desenha as estrelas no cenário
    }

    for (Bomba& bomba : bombas) {
        glPushMatrix();
        glTranslatef(bomba.getCentroX(), bomba.getCentroY(), 0.0); // Translada a bomba
        bomba.desenha(); // Desenha a bomba
        glPopMatrix();
    }

    glPushMatrix();
        glTranslated((janelaLargura/2), (3*janelaAltura/4), 0.0); // Translada a lua
        lua.desenha(); // Desenha a lua
    glPopMatrix();

    glutSwapBuffers(); // Troca os buffers (double buffering)
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);                           // Inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);     // Define o modo de exibição
    glutInitWindowPosition(0, 0);                    // Define a posição inicial da janela
    glutInitWindowSize(janelaLargura, janelaAltura); // Define o tamanho da janela
    glutCreateWindow("Missile Command");             // Cria a janela com o título especificado

    inicio(); // Executa a função de inicialização

    for (int i = 0; i < 50; i++){
        estrelas.push_back(Estrela(5.0, janelaLargura, janelaAltura)); // Adiciona estrelas ao vetor
    }

    glutDisplayFunc(desenha);            // Define a função de desenho
    glutReshapeFunc(redimensionaJanela); // Define a função de redimensionamento da janela
    glutMouseFunc(mouseClique);          // Define a função de clique do mouse

    glutMainLoop(); // Entra no loop principal do GLUT

    return 0;
}
/*********************************************** PUBLIC INTERFACE ***********************************************/

#ifndef BOMBA_H
#define BOMBA_H

#include "../include/asteroide.hpp"

class Bomba{
    private:
        float raioBomba; // Raio inicial do círculo
        float taxaAumentoRaioBomba; // Taxa de aumento do raio
        bool estadoBomba; // Indica se o círculo está inflando ou desinflando
    public:
        Bomba();
        void setRaioBomba(float raioBomba);
        void setEstadoBomba(bool estadoBomba);
        float getRaioBomba();
        float getTaxaAumentoRaioBomba();
        bool getEstadoBomba();
        void bomba();
        bool verificaColisaoBombaAsteroide(float pontos[2]);
        void aumentaRaioBomba(float pontos[2]);
        void diminuiRaioBomba();
};

#endif

/****************************************************************************************************************/
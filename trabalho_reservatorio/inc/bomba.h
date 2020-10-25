#ifndef BOMBA_H
#define BOMBA_H


#include "sensoreletrico.h"

class Bomba
{
    public:
        SensorEletrico& corrente;
        SensorEletrico& tensao;
        Bomba(SensorEletrico& corrente, SensorEletrico& tensao);
        double calcEnergia(const int& indice1, const int& indice2);
        double calcPot( const int &indice2);
        double calcPotAparente(const int &indice2);
        double CalculaFP(int indice2); //fator de potencia
        double getRMS(Sensor& s,const int&);
};

#endif

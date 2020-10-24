#ifndef BOMBA_H
#define BOMBA_H


#include "sensoreletrico.h"

class Bomba : public Sensor
{
    private:
        
        SensorEletrico& corrente;
        SensorEletrico& tensao;
        

    public:
        Bomba(SensorEletrico& corrente, SensorEletrico& tensao);
        double calcEnergia(Bomba& bomba,const int &indice2);
        double calcPot( Bomba& bomba,const int &indice2);
        double calcPotAparente(Bomba& bomba,const int &indice2);
        double CalculaFP(); //fator de potencia
        double getRMS(Sensor& s,const int&);
};

#endif

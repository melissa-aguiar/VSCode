#ifndef BOMBA_H
#define BOMBA_H

#include <vector>
#include "medicao.h"
#include <fstream>
#include <iostream>
#include <string.h>
#include<math.h>
#include <cstring>
#include "sensor.h"

class Bomba : public Sensor
{
    private:
        vector<Medicao> dadosRMS;
        double rms;


    public:
        Bomba(const string&, vector<string> &);
        ~Bomba();
        double CalculaPotencia();
        double CalculaPotenciaAparente();
        double CalculaFP(); //fator de potencia
        double CalculaEnergiaConsumida();
        double getRMS(const int&);
};

#endif

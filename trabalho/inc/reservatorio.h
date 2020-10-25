#ifndef RESERVATORIO_H
#define RESERVATORIO_H
#include "sensorvazao.h"

class Reservatorio
{
private : 
    double volume;

public:
    SensorVazao &v1 , &v2;
    Reservatorio(SensorVazao& v1 , SensorVazao& v2);
    double getVolume(const int &indice);

};



#endif
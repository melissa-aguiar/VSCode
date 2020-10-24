#include "reservatorio.h"

Reservatorio::Reservatorio(SensorVazao& vazao1 , SensorVazao& vazao2): volume(0), v1(vazao1),v2(vazao2)
{
}

double Reservatorio::getVolume(const int &indice)
{
    double vaz1 = 0;
    double vaz2 = 0;
    for (int i = 0; i <= indice; i++)
    {

        vaz1 += v1.getDado(i);
        vaz2 += 1000*v2.getDado(i);

    }
    
    this->volume = (vaz1-vaz2);
    if (volume > 30000) // volume maximo do reservatorio
    {
        volume = 30000;
    }
    if(volume<0)
    {
        volume = 0;
    }
    return this->volume;
}
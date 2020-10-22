#include "sensorvazao.h"
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

SensorVazao::SensorVazao(const string &path, vector<string> &h) //caminho do arquivo e header
{

    this->volume = 0;
    this->headers.assign(h.begin(), h.end());
    abrirArquivo(path);
    
}

double SensorVazao::getVolume(const int &indice)
{
    for (int i = 0; i <= indice; i++)
    {
        this->volume = this->volume + dados[i].valor;
    }
    return this->volume;
}

#ifndef SENSOR_VAZAO_H
#define SENSOR_VAZAO_H

#include "sensor.h"


using namespace std;

class SensorVazao: public Sensor
{
private:
    string unidade;
   
public:

    SensorVazao(const string& path, vector<string>& h);
    bool lerDados();
    string getUnidade();

};

#endif
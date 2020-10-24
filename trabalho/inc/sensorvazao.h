#ifndef SENSOR_VAZAO_H
#define SENSOR_VAZAO_H

#include "sensor.h"


using namespace std;

class SensorVazao: public Sensor
{
private:
    double volume;
   
public:

    SensorVazao(const string& path, vector<string>& h);
    double getVolume(const int&);
    bool lerDados();

};

#endif
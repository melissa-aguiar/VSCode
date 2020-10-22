#ifndef SENSOR_VAZAO_H
#define SENSOR_VAZAO_H
#include <vector>
#include <fstream>
#include "medicao.h"
#include "sensor.h"


using namespace std;

class SensorVazao: public Sensor
{
private:
    double volume;
   
public:
    SensorVazao(const string&, vector<string>&);
    double getVolume(const int&);

};

#endif
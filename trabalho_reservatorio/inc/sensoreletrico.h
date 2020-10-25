#ifndef SENSORELETRICO_H
#define SENSORELETRICO_H

#include "sensor.h"

class SensorEletrico : public Sensor
{
private:
    double f;
    double rms;

vector<Medicao> dadosRMS;
public:
    SensorEletrico(const string& path, vector<string>& h );
    double getFreq();
    double getRMS( const int &indice2);
    bool lerDados();
};


#endif

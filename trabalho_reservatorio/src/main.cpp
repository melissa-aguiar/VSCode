//##### GRUPO: Breno Matsuse, Isabella Pires, Melissa Aguiar, Renan Faria.

#include <iostream>
#include <string.h>
#include "PlantaIndustrial.hpp"
#include "reservatorio.h"

using namespace std;

int main()
{
    //################################## VAZAO ####################################
    vector<string> headersVazao = {"Nome do Sensor", "ID do sensor", "Unidade das medicoes", "Numero de amostras por segundo", "Horario inicio da coleta", "Total de Amostras"};
    SensorVazao vazao1("C:\\Users\\melis\\Desktop\\VSCode\\trabalho_reservatorio\\dados\\SensorVazao1.dat", headersVazao);
    SensorVazao vazao2("C:\\Users\\melis\\Desktop\\VSCode\\trabalho_reservatorio\\dados\\SensorVazao2.dat", headersVazao);
    Reservatorio r1(vazao1,vazao2);

    //################################ CORRENTE E TENSAO ##################################
    vector<string> headersSensores = {"Nome do Sensor", "ID do sensor", "Frequencia da rede", "Numero de amostras por segundo", "Horario inicio da coleta", "Total de Amostras"};
    
    SensorEletrico corrente1("C:\\Users\\melis\\Desktop\\VSCode\\trabalho_reservatorio\\dados\\SensorCorrente1.dat", headersSensores);
    SensorEletrico tensao1("C:\\Users\\melis\\Desktop\\VSCode\\trabalho_reservatorio\\dados\\SensorTensao1.dat", headersSensores);
    Bomba bomba1(corrente1,tensao1);
    SensorEletrico corrente2("C:\\Users\\melis\\Desktop\\VSCode\\trabalho_reservatorio\\dados\\SensorCorrente2.dat", headersSensores);
    SensorEletrico tensao2("C:\\Users\\melis\\Desktop\\VSCode\\trabalho_reservatorio\\dados\\SensorTensao2.dat", headersSensores);
    Bomba bomba2(corrente2,tensao2);

    //################################### INTERFACE ######################################
    PlantaIndustrial(bomba1,bomba2,r1);

    return 0;
}

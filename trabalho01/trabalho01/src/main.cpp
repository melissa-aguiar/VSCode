#include <iostream>
#include "sensorcorrente.h"
#include "sensorvazao.h" // entre aspas duplas pois está dentro de uma pasta do projeto

using namespace std;

void fooVazao(SensorVazao &s)
{
    s.confirmaLeitura();
    //s.imprimeHeaders();
}

void fooCorrente(SensorCorrente &s)
{
    s.confirmaLeitura();
    //s.imprimeHeaders();
}

int main()
{
    
    //################################## VAZAO ####################################
    vector<string> headersVazao = {"Nome do Sensor", "ID do sensor", "Unidade das medicoes", "Numero de amostras por segundo", "Horario inicio da coleta", "Total de Amostras"};
    
    SensorVazao vazao1("C:\\Users\\melis\\Desktop\\GitDesk\\_trabalho01\\trabalho01\\dados\\SensorVazao1.dat", headersVazao);
    vazao1.lerDados();

    SensorVazao vazao2("C:\\Users\\melis\\Desktop\\GitDesk\\_trabalho01\\trabalho01\\dados\\SensorVazao2.dat", headersVazao);
    vazao2.lerDados();

    fooVazao(vazao1);
    fooVazao(vazao2);

    //###################################### CORRENTE E TENSAO ##################################
    vector<string> headersSensores = {"Nome do Sensor", "ID do sensor", "Frequencia da rede", "Numero de amostras por segundo", "Horario inicio da coleta", "Total de Amostras"};
    
    SensorCorrente corrente1("C:\\Users\\melis\\Desktop\\GitDesk\\_trabalho01\\trabalho01\\dados\\SensorCorrente1.dat", headersSensores);
    corrente1.lerDados();

    SensorCorrente corrente2("C:\\Users\\melis\\Desktop\\GitDesk\\_trabalho01\\trabalho01\\dados\\SensorCorrente2.dat", headersSensores);
    corrente2.lerDados();
    
    fooCorrente(corrente1);
    fooCorrente(corrente2);
    
    SensorCorrente tensao1("C:\\Users\\melis\\Desktop\\GitDesk\\_trabalho01\\trabalho01\\dados\\SensorTensao1.dat", headersSensores);
    tensao1.lerDados();

    SensorCorrente tensao2("C:\\Users\\melis\\Desktop\\GitDesk\\_trabalho01\\trabalho01\\dados\\SensorTensao2.dat", headersSensores);
    tensao2.lerDados();
    
    fooCorrente(tensao1);
    fooCorrente(tensao2);

    //################################ INTERFACE RESERVATORIO ###############################

    //int hora, min, seg, indice, op;

    //cout << "Opcao RESERVATORIO selecionada. Menu: " << endl;
    //cout << "1 - Vazao de entrada em um determinado instante" << endl;
    //cout << "2 - Vazao de saida em um determinado instante" << endl;
    //cout << "3 - Volume em um determinado instante" << endl;
    //cout << "Opcao Escolhida: " << endl;
    //cin >> op; fazer switch case

    //cout << "Digite a hora: ";
    //cin >> hora;
    //cout << "Digite o minuto: ";
    //cin >> min;
    //cout << "Digite o segundo: ";
    //cin >> seg;

    //indice = hora * 3600 + min * 60 + seg;
    //indice = indice - 65335; //65335 eh a hora inicial em segundos, quando subtrai isso da hora desejada obtem o indice

    //cout << indice<< endl;

    //double volumeIn = vazao1.getVolume(indice);
    //double volumeOut = 1000 * vazao2.getVolume(indice);

    //cout << "Vazao de entrada neste horario: " << vazao1.getDado(indice) << vazao1.getUnidade() << endl;
    //cout << "Vazao de saida neste horario: " << vazao2.getDado(indice) << vazao2.getUnidade() << endl;
    //cout << "Volume no reservatorio neste horario: " << volumeIn - volumeOut << " litros." << endl;
    

    return 0;
}

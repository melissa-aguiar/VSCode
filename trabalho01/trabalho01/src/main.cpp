#include <iostream>
#include <string.h>
#include "sensorcorrente.h"
#include "sensorvazao.h" // entre aspas duplas pois está dentro de uma pasta do projeto

using namespace std;

void fooVazao(SensorVazao &s)
{
    s.lerDados();
    s.confirmaLeitura();
    //s.imprimeHeaders();
}

void fooCorrente(SensorCorrente &s, int &i1, int &i2)
{
    s.lerDados(i1, i2);
    s.confirmaLeitura();
    //s.imprimeHeaders();
}

int main()
{
    
    //################################## VAZAO ####################################
    vector<string> headersVazao = {"Nome do Sensor", "ID do sensor", "Unidade das medicoes", "Numero de amostras por segundo", "Horario inicio da coleta", "Total de Amostras"};
    
    SensorVazao vazao1("C:\\Users\\melis\\Desktop\\GitDesk\\_trabalho01\\trabalho01\\dados\\SensorVazao1.dat", headersVazao);
    SensorVazao vazao2("C:\\Users\\melis\\Desktop\\GitDesk\\_trabalho01\\trabalho01\\dados\\SensorVazao2.dat", headersVazao);

    fooVazao(vazao1);
    fooVazao(vazao2);

    //###################################### CORRENTE E TENSAO ##################################
    // Sempre que for ler dados de corrente ou tensao, é preciso enviar dois indices.
    //Por padrao inicializei os indices com 0 e 1, mas o usuario que escolhe.
    // Estes indices representam o intervalo dos dados a serem utilizados nas funçoes de RMS, potencia, energia, etc
    // A função de ler dados sempre vai gerar um vetor com todos os dados do .dat e um vetor com o intervalo desejado
    //funçao de calculo RMS deve ser adicionada no sensorcorrente .cpp e .h

    int indice1 = 0;
    int indice2 = 1;

    vector<string> headersSensores = {"Nome do Sensor", "ID do sensor", "Frequencia da rede", "Numero de amostras por segundo", "Horario inicio da coleta", "Total de Amostras"};
    
    SensorCorrente corrente1("C:\\Users\\melis\\Desktop\\GitDesk\\_trabalho01\\trabalho01\\dados\\SensorCorrente1.dat", headersSensores);
    SensorCorrente corrente2("C:\\Users\\melis\\Desktop\\GitDesk\\_trabalho01\\trabalho01\\dados\\SensorCorrente2.dat", headersSensores);
    
    fooCorrente(corrente1, indice1, indice2);
    fooCorrente(corrente2, indice1, indice2);
    //corrente1.imprimeDadosSalvos();
    
    SensorCorrente tensao1("C:\\Users\\melis\\Desktop\\GitDesk\\_trabalho01\\trabalho01\\dados\\SensorTensao1.dat", headersSensores);
    SensorCorrente tensao2("C:\\Users\\melis\\Desktop\\GitDesk\\_trabalho01\\trabalho01\\dados\\SensorTensao2.dat", headersSensores);
    
    fooCorrente(tensao1, indice1, indice2);
    fooCorrente(tensao2, indice1, indice2);


    //################################ INTERFACE RESERVATORIO ###############################
    // se nao puder deixar a interface no main, mover ela pro plantaindustrial .cpp e .h

    //string time;
    //int hora, min, seg, indice, op;

    //cout << "Opcao RESERVATORIO selecionada. Menu: " << endl;
    //cout << "1 - Vazao de entrada em um determinado instante" << endl;
    //cout << "2 - Vazao de saida em um determinado instante" << endl;
    //cout << "3 - Volume em um determinado instante" << endl;
    //cout << "Opcao Escolhida: " << endl;
    //cin >> op; //fazer switch case

    //cout << "Digite a hora no formato hh:mm:ss: ";
    //cin >> time;
    //hora = (int)stod(time.substr(0,2));
    //min = (int)stod(time.substr(3,5));
    //seg = (int)stod(time.substr(6,8));

    //indice = hora * 3600 + min * 60 + seg;
    //indice = indice - 65335; //65335 é a hora inicial em segundos, quando subtrai isso da hora desejada obtem o indice
    // indice 2 = indice; //fazer isso quando o usuario digita um horario só, pq aí o indice 1 ja esta como zero
    // quando o usuario digitar dois horarios, cada um é um dos indices, pra gerar o arquivo com os dados nesse intervalo 
    //cout << indice<< endl;

    //double volumeIn = vazao1.getVolume(indice);
    //double volumeOut = 1000 * vazao2.getVolume(indice);

    //cout << "Vazao de entrada neste horario: " << vazao1.getDado(indice) << vazao1.getUnidade() << endl;
    //cout << "Vazao de saida neste horario: " << vazao2.getDado(indice) << vazao2.getUnidade() << endl;
    //cout << "Volume no reservatorio neste horario: " << volumeIn - volumeOut << " litros." << endl;
    

    return 0;
}

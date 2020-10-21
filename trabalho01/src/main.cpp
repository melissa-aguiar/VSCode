#include <iostream>
#include <string.h>
#include "sensorvazao.h" // entre aspas duplas pois está dentro de uma pasta do projeto
#include "bomba.h"

using namespace std;

/*void fooVazao(Sensor &s)
{
    s.lerDados();
    s.confirmaLeitura();
    //s.imprimeHeaders();
}

void fooCorrente(Sensor &s)
{
    s.lerDados();
    s.confirmaLeitura();
    //s.imprimeHeaders();
}

void fooTensao(Sensor &s)
{
    s.lerDados();
    s.confirmaLeitura();
}*/

void fooSensor(Sensor &s)
{
    s.lerDados();
    s.confirmaLeitura();
}

int main()
{
    
    //################################## VAZAO ####################################
    vector<string> headersVazao = {"Nome do Sensor", "ID do sensor", "Unidade das medicoes", "Numero de amostras por segundo", "Horario inicio da coleta", "Total de Amostras"};
    
    SensorVazao vazao1("C:\\Users\\pires\\OneDrive\\Documentos\\UFJF\\InformaticaIndustrial\\trabalho1\\VSCode-Novo\\trabalho01\\dados\\SensorVazao1.dat", headersVazao);
    SensorVazao vazao2("C:\\Users\\pires\\OneDrive\\Documentos\\UFJF\\InformaticaIndustrial\\trabalho1\\VSCode-Novo\\trabalho01\\dados\\SensorVazao2.dat", headersVazao);

    fooSensor(vazao1);
    fooSensor(vazao2);

    //###################################### CORRENTE E TENSAO ##################################

    int indice1 = 0;
    int indice2 = 385;

    vector<string> headersSensores = {"Nome do Sensor", "ID do sensor", "Frequencia da rede", "Numero de amostras por segundo", "Horario inicio da coleta", "Total de Amostras"};
    
    Bomba corrente1("C:\\Users\\pires\\OneDrive\\Documentos\\UFJF\\InformaticaIndustrial\\trabalho1\\VSCode-Novo\\trabalho01\\dados\\SensorCorrente1.dat", headersSensores);
    Bomba corrente2("C:\\Users\\pires\\OneDrive\\Documentos\\UFJF\\InformaticaIndustrial\\trabalho1\\VSCode-Novo\\trabalho01\\dados\\SensorCorrente2.dat", headersSensores);
    
    fooSensor(corrente1);
    fooSensor(corrente2);
    
    Bomba tensao1("C:\\Users\\pires\\OneDrive\\Documentos\\UFJF\\InformaticaIndustrial\\trabalho1\\VSCode-Novo\\trabalho01\\dados\\SensorTensao1.dat", headersSensores);
    Bomba tensao2("C:\\Users\\pires\\OneDrive\\Documentos\\UFJF\\InformaticaIndustrial\\trabalho1\\VSCode-Novo\\trabalho01\\dados\\SensorTensao2.dat", headersSensores);
    
    fooSensor(tensao1);
    fooSensor(tensao2);

    // #################################### CALCULO DE RMS E POTENCIA APARENTE (FUNCIONANDO) #########################
    double iRMS1 = corrente1.getRMS(indice2);
    double vRMS1 = tensao1.getRMS(indice2);
    double potAparente = iRMS1*vRMS1;

    cout << "valor de corrente RMS no sensor " << corrente1.getNome() << " no horario desejado: " << iRMS1 << endl;
    cout << "valor de tensao RMS no sensor " << tensao1.getNome() << "  no horario desejado: " << vRMS1 << endl;
    cout << "valor de potencia aparente no horario desejado: " << potAparente << endl;


    //################################ VAZAO E VOLUME (FUNCIONANDO) #############################################
    double volume1 = vazao1.getVolume(indice2);
    double volume2 = 1000 * vazao2.getVolume(indice2);
    double volumeTotal = volume1 - volume2; //confirmar se é pra somar as duas bombas mesmo ou se é pra subtrair a 1 da 2
     if (volumeTotal>30000) // volume maximo do reservatorio
        {
            volumeTotal = 30000;
        }

    cout << "Vazao na bomba " << vazao1.getNome() << " (entrada) neste horario: " << vazao1.getDado(indice2) << vazao1.getUnidade() << endl;
    cout << "Vazao na bomba " << vazao2.getNome() << " (saida) neste horario: " << vazao2.getDado(indice2) << vazao2.getUnidade() << endl;
    cout << "Volume no reservatorio neste horario: " << volumeTotal << " litros." << endl;
    
    //################################ INTERFACE RESERVATORIO (CONVERTE A HORA NO INDICE DO DADO DESEJADO) ###############################
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

    return 0;
}

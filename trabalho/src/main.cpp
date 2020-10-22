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
    int indice1=0;
    int indice2 = 385;
    
    //################################## VAZAO ####################################
    vector<string> headersVazao = {"Nome do Sensor", "ID do sensor", "Unidade das medicoes", "Numero de amostras por segundo", "Horario inicio da coleta", "Total de Amostras"};
    
    SensorVazao vazao1("C:\\Users\\pires\\OneDrive\\Documentos\\UFJF\\InformaticaIndustrial\\trabalho1\\VSCode\\trabalho01\\trabalho\\dados\\SensorVazao1.dat", headersVazao);
    SensorVazao vazao2("C:\\Users\\pires\\OneDrive\\Documentos\\UFJF\\InformaticaIndustrial\\trabalho1\\VSCode\\trabalho01\\trabalho\\dados\\SensorVazao2.dat", headersVazao);

   //fooSensor(vazao1);
   //fooSensor(vazao2);
  
    //###################################### CORRENTE E TENSAO ##################################


    vector<string> headersSensores = {"Nome do Sensor", "ID do sensor", "Frequencia da rede", "Numero de amostras por segundo", "Horario inicio da coleta", "Total de Amostras"};
    
    Bomba corrente1("C:\\Users\\pires\\OneDrive\\Documentos\\UFJF\\InformaticaIndustrial\\trabalho1\\VSCode\\trabalho01\\trabalho\\dados\\SensorCorrente1.dat", headersSensores);
    Bomba corrente2("C:\\Users\\pires\\OneDrive\\Documentos\\UFJF\\InformaticaIndustrial\\trabalho1\\VSCode\\trabalho01\\trabalho\\dados\\SensorCorrente2.dat", headersSensores);
    
   // fooSensor(corrente1);
   // fooSensor(corrente2);
    
    Bomba tensao1("C:\\Users\\pires\\OneDrive\\Documentos\\UFJF\\InformaticaIndustrial\\trabalho1\\VSCode\\trabalho01\\trabalho\\dados\\SensorTensao1.dat", headersSensores);
    Bomba tensao2("C:\\Users\\pires\\OneDrive\\Documentos\\UFJF\\InformaticaIndustrial\\trabalho1\\VSCode\\trabalho01\\trabalho\\dados\\SensorTensao2.dat", headersSensores);
    
    //fooSensor(tensao1);
    //fooSensor(tensao2);

    // #################################### CALCULO DE RMS E POTENCIA APARENTE (FUNCIONANDO) #########################
  //  double iRMS1 = corrente1.getRMS(indice2);
   // double vRMS1 = tensao1.getRMS(indice2);
   // double potAparente = iRMS1*vRMS1;

   // cout << "valor de corrente RMS no sensor " << corrente1.getNome() << " no horario desejado: " << iRMS1 << endl;
   // cout << "valor de tensao RMS no sensor " << tensao1.getNome() << "  no horario desejado: " << vRMS1 << endl;
    //cout << "valor de potencia aparente no horario desejado: " << potAparente << endl;

    
vazao1.interface(corrente1,corrente2, vazao1, vazao2, tensao1, tensao2);


    return 0;
}

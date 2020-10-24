#include <iostream>
#include <string.h>
#include "sensorvazao.h" // entre aspas duplas pois está dentro de uma pasta do projeto
#include "bomba.h"

using namespace std;


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


    //###################################### CORRENTE E TENSAO ##################################


    vector<string> headersSensores = {"Nome do Sensor", "ID do sensor", "Frequencia da rede", "Numero de amostras por segundo", "Horario inicio da coleta", "Total de Amostras"};
    
    SensorEletrico corrente1("C:\\Users\\pires\\OneDrive\\Documentos\\UFJF\\InformaticaIndustrial\\trabalho1\\VSCode\\trabalho01\\trabalho\\dados\\SensorCorrente1.dat", headersSensores);
    SensorEletrico tensao1("C:\\Users\\pires\\OneDrive\\Documentos\\UFJF\\InformaticaIndustrial\\trabalho1\\VSCode\\trabalho01\\trabalho\\dados\\SensorTensao1.dat", headersSensores);
    Bomba bomba1(corrente1,tensao1);
    SensorEletrico corrente2("C:\\Users\\pires\\OneDrive\\Documentos\\UFJF\\InformaticaIndustrial\\trabalho1\\VSCode\\trabalho01\\trabalho\\dados\\SensorCorrente2.dat", headersSensores);
    SensorEletrico tensao2("C:\\Users\\pires\\OneDrive\\Documentos\\UFJF\\InformaticaIndustrial\\trabalho1\\VSCode\\trabalho01\\trabalho\\dados\\SensorTensao2.dat", headersSensores);
    Bomba bomba2(corrente2,tensao2);
    corrente1.lerDados();
    corrente2.lerDados();
    tensao1.lerDados();
    tensao2.lerDados();
    vazao1.lerDados();
    vazao2.lerDados();

    
    
    // #################################### CALCULO DE RMS E POTENCIA APARENTE (FUNCIONANDO) #########################
      //double iRMS1 = corrente1.getRMS(indice2);
    //double vRMS1 = tensao1.getRMS(indice2);
    //double potAparente = iRMS1*vRMS1;

   // cout << "valor de corrente RMS no sensor " << corrente1.getNome() << " no horario desejado: " << iRMS1 << endl;
   // cout << "valor de tensao RMS no sensor " << tensao1.getNome() << "  no horario desejado: " << vRMS1 << endl;
    //cout << "valor de potencia aparente no horario desejado: " << potAparente << endl;

    
//vazao1.interface(corrente1,corrente2, vazao1, vazao2, tensao1, tensao2);


//cout<<"Energia : "<< corrente1.calcEnergia(corrente1.getNumAmostrasCiclo(),indice2, corrente1.getPeriodoAmostragem(),corrente1,tensao1);
  
  cout<<"Potencia: "<<bomba1.calcPot(bomba1,indice2)<<endl;
  cout<<"Energia : "<<bomba1.calcEnergia(bomba1,indice2)<<endl;
  //cout<<"Potencia aparente : "<<bomba1.calcPotAparente(bomba1,indice2)<<endl;
    cout<<"Valor RMS : "<<corrente1.getRMS(indice2);
    return 0;
}

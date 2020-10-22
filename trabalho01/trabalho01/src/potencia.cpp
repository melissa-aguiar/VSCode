#include<iostream>
#include<math.h>
#include <cstring>
#include"potencia.h"
#include"sensorcorrente.h"

#include"calculorms.h"


double calcPot( int N , int numAmostras,int T) //dados da corrente//dados da tensao//numero de amostras por ciclo//numero total de amostras
{  
   vector<string> headersSensores = {"Nome do Sensor", "ID do sensor", "Frequencia da rede", "Numero de amostras por segundo", "Horario inicio da coleta", "Total de Amostras"};
   SensorCorrente corrente1("C:\\Users\\User\\Documents\\programas\\dados\\SensorCorrente1.dat", headersSensores);
   SensorCorrente corrente2("C:\\Users\\User\\Documents\\programas\\dados\\SensorCorrente2.dat", headersSensores);
   SensorCorrente tensao1("C:\\Users\\User\\Documents\\programas\\dados\\SensorTensao1.dat", headersSensores);
   SensorCorrente tensao2("C:\\Users\\User\\Documents\\programas\\dados\\SensorTensao2.dat", headersSensores);
   corrente1.lerDados();
   corrente2.lerDados();
   tensao1.lerDados();
   tensao2.lerDados();
   double pot1=0;    //variavel que armazena a potencia
   double pot0;      //variavel que armazena a potencia a ser descartada
   
   int cont=T*numAmostras;
   double i,v;
   double *const calcPot = new double[N]; //vetor que vai armazenar os dados de 1 ciclo
   double *ptr_calcPot=calcPot;   //ponteiro para varrer os dados
   memset(calcPot, 0 , N*sizeof(double));
   
   for(int t=0;t<=cont;t++)
   
   {
       pot0=*ptr_calcPot;   //inserindo e retirando uma amostra
       i=corrente1.getDado(t);
       v=tensao1.getDado(t);
       *ptr_calcPot=(i)*(v);  //armazena a nova potencia
       pot1+=(*ptr_calcPot-pot0)/N;
       if(ptr_calcPot<calcPot+N-1) //enquanto o ponteiro aponta para um endereco do bloco
       {
           ptr_calcPot++;    //atualiza a potencia
                  
       }
       else
       {
           ptr_calcPot=calcPot;   //atribui a ptr_calcPot o endereco de memoria inicial
       }
   }

   
   delete[] calcPot;
   
   return pot1;

}




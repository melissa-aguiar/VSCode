#include "bomba.h"


Bomba::Bomba(SensorEletrico& c,SensorEletrico& t ) : corrente(c),tensao(t)
{
}

double Bomba:: calcPotAparente(Bomba& bomba,const int &indice2 )
   {
    double iRMS1 = this->corrente.getRMS(indice2);
    double vRMS1 = this->tensao.getRMS(indice2);
    double potAparente = iRMS1*vRMS1;
    return potAparente;
   }

   double Bomba:: calcPot( Bomba& bomba,const int& indice2) //dados da corrente//dados da tensao//numero de amostras por ciclo//numero total de amostras
{  
   double Energia = 0;
   
   double pot1=0;    //variavel que armazena a potencia
   double pot0;      //variavel que armazena a potencia a ser descartada
   int Ts = corrente.getPeriodoAmostragem();
   int N = corrente.getNumAmostrasCiclo();

   int cont=Ts*indice2;
   double i,v;
   double *const calcPot = new double[N]; //vetor que vai armazenar os dados de 1 ciclo
   double *ptr_calcPot=calcPot;   //ponteiro para varrer os dados
   memset(calcPot, 0 , N*sizeof(double));
   
   for(int t=cont-2*N;t<=cont;t++)
   
   {
       pot0=*ptr_calcPot;   //inserindo e retirando uma amostra
       i=this->corrente.getDado(t);
       v=this->tensao.getDado(t);
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

double Bomba::calcEnergia(Bomba& bomba,const int& indice2)
{
    double Energia = 0;
    for (int i=1; i <= indice2; i++){    //Calcula a energia de 0 ao indice 2 fazendo o somatório das potencias
            Energia += calcPot(bomba,i)/3600000;
    }

    return Energia;
}
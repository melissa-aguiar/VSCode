#include<iostream>
#include<math.h>
#include <cstring>
#include"potencia.h"
#include"sensorcorrente.h"

#include"calculorms.h"

double calcPotencia(double *pi,double *pt, int N , int numAmostras) //dados da corrente//dados da tensao//numero de amostras por ciclo//numero total de amostras
{
   double pot1=0;    //variavel que armazena a potencia
   double pot0;      //variavel que armazena a potencia a ser descartada
   double *const calcPot = new double[N]; //vetor que vai armazenar os dados de 1 ciclo
   double *ptr_calcPot=calcPot;   //ponteiro para varrer os dados
   memset(calcPot, 0 , N*sizeof(double));
   for(int i=0;i<numAmostras;i++)
   {
       pot0=*ptr_calcPot;   //inserindo e retirando uma amostra
       *ptr_calcPot=(*pi)*(*pt);  //armazena a nova potencia
       pot1+=(*ptr_calcPot-pot0)/N;
       if(ptr_calcPot<ptr_calcPot+N-1) //enquanto o ponteiro aponta para um endereco do bloco
       {
           ptr_calcPot++;    //atualiza a potencia
           pi++;             //atualiza a corrente
           pt++;             //atualiza a tensao
       }
       else
       {
           ptr_calcPot=calcPot;   //atribui a ptr_calcPot o endereco de memoria inicial
       }
       

   }
   delete[] calcPot;
   return pot1;

}

double calcPotAparente(double* pi,double* pt,int N,int numAmostras)//dados corrente//dados tensao//numero de amostras por ciclo//numero total de amostras
{
    double pot1=0;    //variavel que armazena a potencia
    double pot0;      //variavel que armazena a potencia a ser descartada
    double pirms;
    double ptrms;
    pirms=calcRMS(pi,N,numAmostras); //ponteiro com o valor de corrente rms
    ptrms=calcRMS(pt,N,numAmostras); //ponteiro com o valor de tensao rms
    double *const potAp = new double[N]; //vetor que vai armazenar os dados de 1 ciclo
    double *ptr_potAp=potAp; //ponteiro para varrer os dados
    memset(potAp, 0 , N*sizeof(double));
    for(int i=0;i<numAmostras;i++)
    {
       pot0=*ptr_potAp;    //inserimdo e retirando uma amostra
       *ptr_potAp=(pirms)*(ptrms);//armazena a nova potencia
       pot1=*ptr_potAp;              //atualiza a potencia
       if (ptr_potAp<ptr_potAp+N-1)
       {
           ptr_potAp++;  //atualiza o ponteiro da potencia
           pirms++;      //atualiza o ponteiro da corrente rms
           ptrms++;     //atualiza o ponteiro da tensao rms
       }
       else
       {
           ptr_potAp=potAp; //atribui a ptr_potAp p endereco de memoria original
       }
       
       
    }
    delete [] potAp;
    return pot1;
}

double fatorPotencia(double *pi,double *pt,int N,int numAmostras)//potencia aparente//potencia ativa//numero de amostras por ciclo//numero total de amostras

{
   double fatp1=0; //variavel que armazena o fator de potencia
   double fatp0;  //variavel que armazena o fator de potencia a ser descartado
   double potAp;
   double potAv;
   potAv=calcPotencia(pi,pt,N,numAmostras);//ponteiro com a potencia ativa
   potAp=calcPotAparente(pi,pt,N,numAmostras);//ponteiro com a potencia aparente
    double *const fatPot = new double[N]; //vetor que vai armazenar os dados de 1 ciclo
    double *ptr_fatPot=fatPot; //ponteiro para varrer os dados
    memset(fatPot, 0 , N*sizeof(double));
    for(int i=0;i<numAmostras;i++)
    {
        fatp0 =*ptr_fatPot; //inserindo e retirando uma amostra
        *ptr_fatPot=(potAv)/(potAp);//calculando o novo fator de potencia
        fatp1=*ptr_fatPot;            //atualizando o valor de fatp1
        if(ptr_fatPot<ptr_fatPot+N-1)
        {
           ptr_fatPot++;     //atualiza o ponteiro do fator de potencia
           potAv++;          //atualiza o ponteiro da potencia ativa
           potAp++;          //atualiza o ponteiro da potencia aparente
        }
        else
        {
            ptr_fatPot=fatPot;
        }
        
    }
    delete[] fatPot;
    return fatp1;

}

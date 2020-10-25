#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include "medicao.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <fstream>
#include<math.h>
#include <cstring>

using namespace std;

class Sensor 
{
    protected: 
        vector<Medicao> dados;
        vector<Medicao> dadosSalvos;
        vector<string> headers;
        string nome;
        string id;
        
        string horarioInicial;
        int numMed;
        int Ts;
        int N;
        int totAmostras;
        ifstream file;
       
    
    public:
        Sensor();
        ~Sensor();
        virtual bool abrirArquivo(const string&);
        virtual bool lerDados();
        virtual void imprimeDados();
        virtual void confirmaLeitura();
        virtual void imprimeHeaders();
        virtual string getNome();
        virtual string getId();
        virtual string getHorarioInicial();
        virtual int getNumMed();
        virtual int getTotAmostras();
        virtual int getTaxaAmostragem();
        virtual int getNumAmostrasCiclo();
        virtual double getDado(const int&);

        
};

#endif
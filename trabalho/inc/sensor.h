#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include "medicao.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class Sensor
{
    protected: 
        vector<Medicao> dados;
        vector<Medicao> dadosSalvos;
        vector<string> headers;
        string nome;
        string id;
        string unidade;
        string horarioInicial;
        int numMed;
        int Ts;
        string f;
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
        virtual string getUnidade();
        virtual string getHorarioInicial();
        virtual int getNumMed();
        virtual int getTotAmostras();
        virtual int getPeriodoAmostragem();
        virtual string getFreq();
        virtual int getNumAmostrasCiclo();
        virtual double getDado(const int&);
        virtual double getVolume(const int&);
        virtual double getRMS(const int&);
        virtual void interface(Sensor &c1,Sensor &c2,Sensor &v1, Sensor &v2, Sensor &t1, Sensor &t2);
};

#endif
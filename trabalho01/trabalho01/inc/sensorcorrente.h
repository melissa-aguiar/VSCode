#ifndef SENSORCORRENTE_H
#define SENSORCORRENTE_H
#include <vector>
#include <fstream>
#include "medicao.h"


using namespace std;

class SensorCorrente
{
private:
    vector<Medicao> dados;
    vector<Medicao> dadosSalvos;
    vector<string> headers;
    vector<double> dadosRMS;
    string nome;
    string id;
    string horarioInicial;
    int numMed;
    int Ts;
    string f;
    int N;
    int totAmostras;
    double volume;
    double rms;
    ifstream file;
public:
    SensorCorrente(const string&, vector<string>&);
    ~SensorCorrente();
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
    virtual int getPeriodoAmostragem();
    virtual string getFreq();
    virtual int getNumAmostrasCiclo();
    virtual double getDado(const int&);
    virtual double getValorRMSeDadosSalvos(const int&, const int&);
};

#endif
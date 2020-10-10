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
    string nome;
    string id;
    string horarioInicial;
    int numMed;
    int Ts;
    string f;
    int N;
    int totAmostras;
    double volume;
    ifstream file;
public:
    SensorCorrente(const string&, vector<string>&);
    ~SensorCorrente();
    virtual bool abrirArquivo(const string&);
    virtual bool lerDados(const int&, const int&);
    virtual void imprimeDados();
    virtual void imprimeDadosSalvos();
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
};

#endif
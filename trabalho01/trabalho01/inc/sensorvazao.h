#ifndef SENSOR_VAZAO_H
#define SENSOR_VAZAO_H
#include <vector>
#include <fstream>
#include "medicao.h"


using namespace std;

class SensorVazao
{
private:
    vector<Medicao> dados;
    vector<string> headers;
    string nome;
    string id;
    string unidade;
    string horarioInicial;
    int numMed;
    int Ts;
    int f;
    int N;
    int totAmostras;
    double volume;
    ifstream file;
public:
    SensorVazao(const string&, vector<string>&);
    ~SensorVazao();
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
    virtual int getFreq();
    virtual int getNumAmostrasCiclo();
    virtual double getDado(const int&);
    virtual double getVolume(const int&);
    //virtual int salvarDados(const string&, const string&, const string&);
};

#endif
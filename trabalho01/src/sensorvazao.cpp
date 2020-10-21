#include "sensorvazao.h"
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

SensorVazao::SensorVazao(const string &path, vector<string> &h) //caminho do arquivo e header
{
    /*this->nome = "desconhecido";
    this->id = "desconhecido";
    this->unidade = "desconhecida";
    this->horarioInicial = "desconhecido";
    this->numMed = 0;
    this->Ts = 0;
    this->f = 60;
    this->N = 600 / 60;
    this->totAmostras = 0;*/
    this->volume = 0;
    this->headers.assign(h.begin(), h.end());
    //assign copia os dados de um vetor pro outro no intervalo desejado, neste caso copia h todo
    abrirArquivo(path);
}

SensorVazao::~SensorVazao()
{
    //this->file.close(); //alocamos os recursos no construtor e no destrutor fechamos o arquivo
}

/*bool SensorVazao::abrirArquivo(const string &path)
{ //usamos try e catch pois nao sabemos se o arquivo existe, entao podemos lidar com posiveis erros/exceções.
    try
    {
        this->file.open(path); //tenta abrir o arquivo, se der, retorna true
        return true;
    }
    catch (const std::exception &e) //se nao abrir, retorna false. essa função é invocada no construtor
    {
        std::cout << e.what() << '\n';
    }
    return false;
}*/

bool SensorVazao::lerDados()
{
    try
    {
        if (this->file.is_open()) //testa se o arquivo foi aberto
        {
            string d;
            getline(this->file, d); //toda vez que damos um getline, lemos uma linha e saltamos para a proxima
            int n = 0;
            int idx;
            vector<string> dadosHeader(this->headers.size()); //vetor pra armazenar os dados contidos no header
            while (n < this->headers.size())                  //tamanho do vetor de headers
            {
                getline(this->file, d);
                idx = d.find(":"); //a separação entre o nome da informação e a informação é ":"
                //cout << d.substr(1, idx);
                if (d.substr(1, idx - 1) == this->headers[n]) //substr retorna um pedaço da string
                {
                    dadosHeader[n] = d.substr(idx + 1, d.length() - idx);
                    n++; //esta pegando o tamanho total da substring menos a parte do começo ate o ":"
                }
                else
                {
                    return false;
                }
            }
            //apos coletados os dados, preenchemos os atributos da classe
            this->nome = dadosHeader[0];
            this->id = dadosHeader[1];
            this->unidade = dadosHeader[2];
            this->numMed = stod(dadosHeader[5]); //stod converte string em double
            this->horarioInicial = dadosHeader[4];
            this->Ts = (int)stod(dadosHeader[3]);

            Medicao m;
            getline(file, d);

            for (int i = 0; i < this->numMed; i++)
            {
                getline(file, d, ',');
                m.valor = stod(d);
                this->dados.push_back(m);
            }
        }
        else
        {
            return false;
        }
    }
    catch (const std::exception &e) //Classe exception lança informaçoes das nossas exceçoes
    {                               //tem o metodo e.what pra retornar a mensagem de erro caso ocorra algum problema
        std::cout << "Arquivo corrompido. Erro: " << e.what() << '\n';
        return false;
    }
    return true;
}
/*

void SensorVazao::confirmaLeitura()
{
    cout << "Sensor " << this->getNome() << " lido com sucesso!" << endl;
}

void SensorVazao::imprimeHeaders()
{
    cout << "###############################" << endl;
    cout << "Sensor de vazao" << endl;
    cout << "Nome do Sensor: " << this->getNome() << endl;
    cout << "ID do sensor: " << this->getId() << endl;
    cout << "Unidade das medicoes: " << this->getUnidade() << endl;
    cout << "Total de amostras: " << this->getNumMed() << endl;
    cout << "Horario inicio da coleta: " << this->getHorarioInicial() << endl;
    cout << "Periodo de amostragem (s): " << this->getPeriodoAmostragem() << endl;
}

void SensorVazao::imprimeDados()
{
    cout << "Sensor de vazao" << endl;
    cout << "Nome do Sensor: " << this->getNome() << endl;
    cout << "ID do sensor: " << this->getId() << endl;
    cout << "Unidade das medicoes: " << this->getUnidade() << endl;
    cout << "Total de amostras: " << this->getNumMed() << endl;
    cout << "Horario inicio da coleta: " << this->getHorarioInicial() << endl;
    cout << "Periodo de amostragem (s): " << this->getPeriodoAmostragem() << endl;

    for (auto it = this->dados.begin(); it != this->dados.end(); ++it)
    { //iterador it funciona como um ponteiro, ele é um numero qualquer que armazena um endereço de memoria
        //podendo ser somado ou subtraido, neste caso ele vai ir do primeiro endereço de memoria ao ultimo
        //a vantagem é que podemos usar o it  como uma referencia para cada um dos dados
        //quando definimos uma variavel como o retorno de um metodo, o proprio operador "auto" vai definir o tipo da variavel
        cout << " Valor: " << it->valor << " " << this->getUnidade() << endl;
    }
}

string SensorVazao::getNome()
{
    return this->nome;
}

string SensorVazao::getId()
{
    return this->id;
}

string SensorVazao::getUnidade()
{
    return this->unidade;
}

string SensorVazao::getHorarioInicial()
{
    return this->horarioInicial;
}

int SensorVazao::getNumMed()
{
    return this->numMed;
}

int SensorVazao::getTotAmostras()
{
    return this->totAmostras;
}

int SensorVazao::getFreq()
{
    return this->f;
}

int SensorVazao::getNumAmostrasCiclo()
{
    return this->N;
}

int SensorVazao::getPeriodoAmostragem()
{
    return this->Ts;
}

double SensorVazao::getDado(const int &indice)
{
    for (int i = 0; i <= indice; i++)
    {
        if (i == indice)
        {
            return dados[i].valor;
        }
    }
    return false;
}
*/
double SensorVazao::getVolume(const int &indice)
{
    for (int i = 0; i <= indice; i++)
    {
        this->volume = this->volume + dados[i].valor;
    }
    return this->volume;
}

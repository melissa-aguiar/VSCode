
#include "sensor.h"

Sensor::Sensor()
{
    this->nome = "desconhecido";
    this->id = "desconhecido";
    this->f = "desconhecida";
    this->horarioInicial = "desconhecido";
    this->numMed = 0;
    this->Ts = 0;
    this->N = 600 / 60;
    this->totAmostras = 0;
    this->unidade = "un";
    //this->headers.assign(h.begin(), h.end());
    //assign copia os dados de um vetor pro outro no intervalo desejado, neste caso copia h todo
 
}

Sensor::~Sensor()
{
    this->file.close();
}

bool Sensor::abrirArquivo(const string &path)
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
}

bool Sensor::lerDados()
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
            this->f = dadosHeader[2];
            this->numMed = stod(dadosHeader[5]); //stod converte string em double
            this->horarioInicial = dadosHeader[4];
            this->Ts = (int)stod(dadosHeader[3]);

            Medicao m, ms;
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

void Sensor::confirmaLeitura()
{
    if(this->lerDados()==1)
    {
    cout << "Sensor " << this->getNome() << " lido com sucesso!" << endl;
    }
}

void Sensor::imprimeHeaders()
{
    cout << "###############################" << endl;
    cout << "Nome do Sensor: " << this->getNome() << endl;
    cout << "ID do sensor: " << this->getId() << endl;
    cout << "Frequencia da rede: " << this->getFreq() << endl;
    cout << "Total de amostras: " << this->getNumMed() << endl;
    cout << "Horario inicio da coleta: " << this->getHorarioInicial() << endl;
    cout << "Periodo de amostragem (s): " << this->getPeriodoAmostragem() << endl;
}

void Sensor::imprimeDados()
{
    for (auto it = this->dados.begin(); it != this->dados.end(); ++it)
    { //iterador it funciona como um ponteiro, ele é um numero qualquer que armazena um endereço de memoria
        //podendo ser somado ou subtraido, neste caso ele vai ir do primeiro endereço de memoria ao ultimo
        //a vantagem é que podemos usar o it  como uma referencia para cada um dos dados
        //quando definimos uma variavel como o retorno de um metodo, o proprio operador "auto" vai definir o tipo da variavel
        cout << " Valor: " << it->valor << endl;
    }
}

string Sensor::getNome()
{
    return this->nome;
}

string Sensor::getId()
{
    return this->id;
}

string Sensor::getUnidade()
{
    return this->unidade;
}

string Sensor::getHorarioInicial()
{
    return this->horarioInicial;
}

int Sensor::getNumMed()
{
    return this->numMed;
}

int Sensor::getTotAmostras()
{
    return this->totAmostras;
}

string Sensor::getFreq()
{
    return this->f;
}

int Sensor::getNumAmostrasCiclo()
{
    return this->N;
}

int Sensor::getPeriodoAmostragem()
{
    return this->Ts;
}

double Sensor::getDado(const int &indice)
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

void Sensor::interface(Sensor &c1,Sensor &c2,Sensor &v1, Sensor &v2, Sensor &t1, Sensor &t2)
{
    int x,v,op,hora, min, seg,indice,indice2;
    int indice1 = 0;
    double volume1, volume2, vTotal;
    string h;
    std::cout<< "Bem vindo(a)!" <<endl;
    std::cout<< "Selecione a operacao desejada : \n 1 - Vazao de entrada e/ou de saida do tanque.\n 2-Volume do reservatorio \n 3: Nome de um sensor \n 4- ID de um sensor \n 5- Valor RMS de um sensor (corrente ou tensao) \n 6-Potencia de determinada bomba \n 7-Potencia aparente de determinada bomba \n 8-Fator de potencia de uma determinada bomba \n 9-Energia consumida por uma determinada bomba" <<endl;
    cin>>x;
    v1.lerDados();
    v2.lerDados();
    c1.lerDados();
    c2.lerDados();
    t1.lerDados();
    t2.lerDados();

    switch(x)
    {
        case 1 :
            
            
            cout<<" Escolha uma opcao : \n 1 - Vazao de entrada\n 2- Vazao de saida "<<endl;
            cin>>v;
            if(v==1)
            {
                cout<<"Digite o horario desejado no formato hh:mm:ss:: ";
                cin>>h;
                hora = (int)stod(h.substr(0,2));
                min = (int)stod(h.substr(3,2));
                seg = (int)stod(h.substr(6,2));

                indice = hora * 3600 + min * 60 + seg;            
                indice = indice- 65335; //65335 é a hora inicial em segundos, quando subtrai isso da hora desejada obtem o indice
                indice2 = indice;    
                
                cout<<"Vazao de entrada neste horario : " <<v1.getDado(indice2)<<v1.getUnidade()<<endl;
                cout<<"1 - Voltar para o menu      2- Sair"<<endl;
                cin>>op;
            }
            else if (v==2)
            {
                cout<<"Digite o horario desejado no formato hh:mm:ss:: ";
                cin>>h;
                hora = (int)stod(h.substr(0,2));
                min = (int)stod(h.substr(3,2));
                seg = (int)stod(h.substr(6,2));

                indice = hora * 3600 + min * 60 + seg;            
                indice = indice- 65335; //65335 é a hora inicial em segundos, quando subtrai isso da hora desejada obtem o indice
                indice2 = indice;    
                v2.lerDados();
                cout<<"Vazao de saida neste horario : " <<v2.getDado(indice2)<<v2.getUnidade()<<endl;;
                cout<<"1 - Voltar para o menu      2- Sair"<<endl;
                cin>>op;
            }
            else
            {
                cout<<"Digite uma opcao valida" <<endl;
            }
            
        break;

        case 2 :
            cout<<"Digite o horario em que deseja saber o volume do reservatorio no formato hh:mm:ss : ";
            cin>>h;
            hora = (int)stod(h.substr(0,2));
            min = (int)stod(h.substr(3,2));
            seg = (int)stod(h.substr(6,2));

            indice = hora * 3600 + min * 60 + seg;            
            indice = indice- 65335; //65335 é a hora inicial em segundos, quando subtrai isso da hora desejada obtem o indice
            indice2 = indice;    


            volume1 = v1.getVolume(indice2);
            volume2 = 1000 * v2.getVolume(indice2);
            vTotal = volume1 - volume2;

            if (vTotal>30000) // volume maximo do reservatorio
            {
                vTotal = 30000;
            }
            cout << "Volume no reservatorio neste horario: " << vTotal << " litros." << endl;

        break;

        case 3 :

            cout<< "Escolha a opcao correspondente ao sensor desejado :  "<<endl;
            cout<< "1 - Reservatorio \n 2- Eletrico "<<endl ;
            cin>>op;
            if(op==1)
            {
                cout<< "Escolha a opcao correspondente ao sensor desejado : \n 1- Vazao de entrada \n 2- Vazao de saida "<<endl;
                cin>>op;
                if(op==1)
                {
                    cout<<"Nome do sensor escolhido: "<<v1.getNome()<<endl;
                    cout<<"1- Voltar para o menu     2- Sair"<<endl;
                }
                else if(op==2)
                {
                    cout<<"Nome do sensor escolhido: "<<v2.getNome()<<endl;
                    cout<<"1- Voltar para o menu     2- Sair"<<endl;
                }

            }
            else if(op == 2)
            {
                cout<< "Escolha o numero correspondente a bomba desejada : \n Bomba 1    Bomba 2"<<endl;
                cin>>op;
                if(op==1)
                {
                    cout<< "Escolha a opcao correspondente ao sensor desejado : \n 1- Sensor de Corrente \n 2- Sensor de tensao"<<endl;
                    cin>>op;
                    if(op==1)
                    {
                        cout<<"Nome do sensor escolhido : "<<c1.getNome()<<endl;
                        cout<< " 1- Voltar para o menu   2- Sair";
                    }
                    else if(op==2)
                    {
                        cout<<"Nome do sensor escolhido : "<< t1.getNome()<<endl;
                        cout<< " 1- Voltar para o menu   2- Sair";
                    }
                }
                else if(op==2)
                {
                     cout<< "Escolha a opcao correspondente ao sensor desejado : \n 1- Sensor de Corrente \n 2- Sensor de tensao"<<endl;
                    cin>>op;
                    if(op==1)
                    {
                        cout<<"Nome do sensor escolhido : "<<c2.getNome()<<endl;
                        cout<< " 1- Voltar para o menu   2- Sair";
                    }
                    else if(op==2)
                    {
                        cout<<"Nome do sensor escolhido : "<< t2.getNome()<<endl;
                        cout<< " 1- Voltar para o menu   2- Sair";
                    }
                }
            }
        break;

        case 4 : 
                        cout<< "Escolha a opcao correspondente ao sensor desejado :  "<<endl;
            cout<< "1 - Reservatorio \n 2- Eletrico "<<endl ;
            cin>>op;
            if(op==1)
            {
                cout<< "Escolha a opcao correspondente ao sensor desejado : \n 1- Vazao de entrada \n 2- Vazao de saida "<<endl;
                cin>>op;
                if(op==1)
                {
                    cout<<"ID do sensor escolhido: "<<v1.getId()<<endl;
                    cout<<"1- Voltar para o menu     2- Sair"<<endl;
                }
                else if(op==2)
                {
                    cout<<"ID do sensor escolhido: "<<v2.getId()<<endl;
                    cout<<"1- Voltar para o menu     2- Sair"<<endl;
                }

            }
            else if(op == 2)
            {
                cout<< "Escolha o numero correspondente a bomba desejada : \n Bomba 1    Bomba 2"<<endl;
                cin>>op;
                if(op==1)
                {
                    cout<< "Escolha a opcao correspondente ao sensor desejado : \n 1- Sensor de Corrente \n 2- Sensor de tensao"<<endl;
                    cin>>op;
                    if(op==1)
                    {
                        cout<<"ID do sensor escolhido : "<<c1.getId()<<endl;
                        cout<< " 1- Voltar para o menu   2- Sair";
                    }
                    else if(op==2)
                    {
                        cout<<"ID do sensor escolhido : "<< t1.getId()<<endl;
                        cout<< " 1- Voltar para o menu   2- Sair";
                    }
                }
                else if(op==2)
                {
                     cout<< "Escolha a opcao correspondente ao sensor desejado : \n 1- Sensor de Corrente \n 2- Sensor de tensao"<<endl;
                    cin>>op;
                    if(op==1)
                    {
                        cout<<"ID do sensor escolhido : "<<c2.getId()<<endl;
                        cout<< " 1- Voltar para o menu   2- Sair";
                    }
                    else if(op==2)
                    {
                        cout<<"ID do sensor escolhido : "<< t2.getId()<<endl;
                        cout<< " 1- Voltar para o menu   2- Sair";
                    }
                }
            }
        break;

        case 5 : 
            cout<<"Escolha a bomba correspondente ao sensor desejado : \n 1- Bomba 1      2- Bomba 2"<<endl;
            cin>>op;
            cout<<"Digite o horario desejado no formato hh:mm:ss:: ";
            cin>>h;
            hora = (int)stod(h.substr(0,2));
            min = (int)stod(h.substr(3,2));
            seg = (int)stod(h.substr(6,2));

                indice = hora * 3600 + min * 60 + seg;            
                indice = indice- 65335; //65335 é a hora inicial em segundos, quando subtrai isso da hora desejada obtem o indice
                indice2 = indice;    
            if(op==1)
            {
                cout<<"1- Corrente    2- Tensao"<<endl;
                cin>>op;

                if(op==1)
                {
                    cout<<"Valor RMS : "<<c1.getRMS(indice2) << " A"<<"\n 1- Voltar ao menu     2- Sair"<<endl; 
                }
                else if(op==2)
                {
                    cout<<"Valor RMS : "<<t1.getRMS(indice2) << " V" <<"\n 1- Voltar ao menu     2- Sair"<<endl;
                }
            }
            else if(op==2)
            {
                cout<<"1- Corrente    2- Tensao"<<endl;
                cin>>op;

                if(op==1)
                {
                    cout<<"Valor RMS : "<<c2.getRMS(indice2) << " A"<<"\n 1- Voltar ao menu     2- Sair"<<endl; 
                }
                else if(op==2)
                {
                    cout<<"Valor RMS : "<<t2.getRMS(indice2) << " V "<<"\n 1- Voltar ao menu     2- Sair"<<endl;
                }
            }






        }

    }
double Sensor::getVolume(const int&)
{};
double Sensor:: getRMS(const int&)
{}
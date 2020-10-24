#include "sensoreletrico.h"

SensorEletrico::SensorEletrico(const string& path, vector<string>& h)
{
    this->rms=0;
    this->f = 0;
    this->headers.assign(h.begin(), h.end());
    abrirArquivo(path);
    
}
double SensorEletrico::getFreq()
{
    return this->f;
}

double SensorEletrico::getRMS(const int &indice2)
{
    int cont = indice2 * this->Ts;
    double x2=0;									// Vari?vel que armazena o valor RMS e que armazena o valor RMS� (x2 = RMS�)
	double rms, xo;											// Vari?vel que armazena a amostra a ser descartada
	double *const bufferCalculo = new double [this->N];		// Vetor que ir? armazenar os dados de 1 ciclo da onda (Aloca��o din�mica)
	double *ptr_bufferCalculo = bufferCalculo;			// ponteiro que ser? utilizado para varrer os dados
	memset(bufferCalculo, 0 , this->N*sizeof(double));		// Limpa os valores do vetor
	
	for (int i = 0; i < cont; ++i)
	{
		xo = *ptr_bufferCalculo;						//Ao inserir uma nova amostra no vetor, retira a amostra mais antiga e armazena-a em xo
		*ptr_bufferCalculo = (this->dados[i].valor)*(this->dados[i].valor);		//Armazena o novo valor no vetor (x�)
		x2 += (*ptr_bufferCalculo - xo)/this->N;				//Soma a contribui??o
        
        if(ptr_bufferCalculo < (bufferCalculo+this->N-1))  //Enquanto o ponteiro apontar para um endere�o que esteja contido no bloco de mem?ria apontado por bufferCalculo
		{
			ptr_bufferCalculo++;	//Incremente o ponteiro do buffer;
		}
		else
		{
			ptr_bufferCalculo = bufferCalculo;// caso contrario, atribua para ptr_bufferCalculo o endereço do inicial do bloco de mem?ria apontado por bufferCalculo
		}
    }

	delete[] bufferCalculo;	     //Desalocando bloco de mem?ria alocado
	rms = sqrt(x2);				// Calcula a raiz quadrada
    //cout << " Valor RMS: " << this->rms << endl;

    return rms;
}

bool SensorEletrico::lerDados()
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
            this->numMed = stod(dadosHeader[5]); //stod converte string em double
            this->f = stod(dadosHeader[2]);
            this->horarioInicial = dadosHeader[4];
            this->Ts = (int)stod(dadosHeader[3]);
            this->N = (this->Ts) / (this->f);
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

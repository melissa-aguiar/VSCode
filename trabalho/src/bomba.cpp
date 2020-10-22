#include "bomba.h"

Bomba::Bomba(const string& path, vector<string> &h)
{

this->rms = 0;
this->headers.assign(h.begin(), h.end());
abrirArquivo(path);
}


double Bomba::getRMS(const int &indice2)
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
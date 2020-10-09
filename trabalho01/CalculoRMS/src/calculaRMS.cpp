#include<iostream>
#include<math.h>
#include <cstring>

using namespace std;


double calcRMS(double *p, int N, int NumAmost)			//p ? o ponteiro que aponta para os dados, N ? o n?mero de amostras por ciclo e NumAmost ? o n?mero total de amostras a serem processadas.
{
	double RMS=0,x2=0;									// Vari?vel que armazena o valor RMS e que armazena o valor RMS² (x2 = RMS²)
	double xo;											// Vari?vel que armazena a amostra a ser descartada
	double *const bufferCalculo = new double [N];		// Vetor que ir? armazenar os dados de 1 ciclo da onda (Alocação dinâmica)
	double *ptr_bufferCalculo = bufferCalculo;			// ponteiro que ser? utilizado para varrer os dados
	memset(bufferCalculo, 0 , N*sizeof(double));		// Limpa os valores do vetor
	
	for (int i = 0; i < NumAmost;++i)
	{
		xo = *ptr_bufferCalculo;						//Ao inserir uma nova amostra no vetor, retira a amostra mais antiga e armazena-a em xo
		*ptr_bufferCalculo = (*p)*(*p);					//Armazena o novo valor no vetor (x²)
		x2 += (*ptr_bufferCalculo - xo)/N;				//Soma a contribui??o
		

		if(ptr_bufferCalculo < (bufferCalculo+N-1))    //Enquanto o ponteiro apontar para um endereço que esteja contido no bloco de mem?ria apontado por bufferCalculo
		{
			ptr_bufferCalculo++;					   //Incremente o ponteiro do buffer;
			p++;									   //Incremente o ponteiro que aponta para os dados
			
		}
		else
		{
			ptr_bufferCalculo = bufferCalculo;		  // caso contrario, atribua para ptr_bufferCalculo o endereço do inicial do bloco de mem?ria apontado por bufferCalculo
			
		}
	}

	delete[] bufferCalculo;							  //Desalocando bloco de mem?ria alocado
	RMS = sqrt(x2);									  // Calcula a raiz quadrada de RMS² = RMS
	return RMS;

}

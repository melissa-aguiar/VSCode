#include <iostream>
#include <fstream>
#include "geraDados.h"
#include "calculaRMS.h"



using namespace std;


int main()
{
	double freq = 60;			//Frequ?ncia da onda
	double txAmost = 600;		//N?mero de amostras por segundo
	int N = txAmost/freq;		//N?mero de amostras por ciclo da onda
	int numCiclos = 10;			//N?mero de ciclos a serem gerados


	double *dados = new double[numCiclos*N];				//Cria um bloco de mem?ria com endere?o inicial armazenado no ponteiro dados

	geradados(220*1.41, 60 , dados, txAmost, numCiclos*N);  //Fun??o para gera??o dos dados

	cout<<"Resultado do Calculo do valor RMS = "<< calcRMS(dados, N , numCiclos*N) << endl; //C?lculo e exibi??o do valor RMS

		
	delete[] dados;

	system("pause");
	return 0;


}
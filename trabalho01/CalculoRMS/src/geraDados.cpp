#include<math.h>

void geradados(double ampl, double freq, double *p, double txAmost, int totalAmostras)
{

	double ts = 1/txAmost;				// C?lculo do per?odo de amostragem
	double t=0;				

	while(t<ts*totalAmostras)			// Enquanto o tempo for menor que o tempo total 
	{
		*p = ampl*sin(2*3.14*freq*t);	// Armazena na posi??o apontada pelo ponteiro p o valor da senoide no instante t
		 t +=ts;						// Incrementa o tempo em um período de amostragem
		 p++;							// Incrementa o ponteiro para que ele aponte para o pr?ximo endere?o de mem?ria
	}

	return;

}
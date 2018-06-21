#pragma once

// Canevas Test2 
// SL121_LOGA SLO1 2014-2015  C. HUBER 

#pragma once
#include <stdio.h>
#include <time.h>


// Fonction RandomCustomEntier

int RandomCustomEntier(int Sec, unsigned int *Max, unsigned int *Min)
{
	unsigned int Nombre = 0;
	unsigned int Variable = 0;

	while (Variable <= 1)
	{
		while (Sec >= *Max)
		{
			Sec = Sec % 10;
		}
		while (Sec <= *Min)
		{
			Sec = Sec * 2;
		}
		while (Sec >= *Max)
		{
			Sec = Sec - 3;
		}
		if ((Sec <= *Max) && (Sec >= *Min))
		{
			Nombre = Sec;
			Variable = Variable + 1;


		}
	}	

		return (Nombre);
}

float RandomCustomFloat(float Sec, unsigned int *Max, unsigned int *Min)
{
	float Nombre = 0;
	unsigned int Variable = 0;


	while (Variable <= 1)
	{
		while (Sec >= *Max)
		{
			Sec = (int)Sec % 1000;
			Sec = Sec / 10;
		}
		while (Sec <= *Min)
		{
			Sec = Sec * 2;
		}
		while (Sec >= *Max)
		{
			Sec = Sec - 3;
		}
		if ((Sec <= *Max) && (Sec >= *Min))
		{
			Nombre = Sec;
			Variable = Variable + 1;


		}
	}

	return (Nombre);

}





time_t time(time_t* timer);

int main()
{
	time_t timer;
	struct tm y2k = { 0 };
	double seconds;

	unsigned int NbMax;
	unsigned int NbMin;
	unsigned int Nbalea;
	float NbaleaFloat;


	printf("Entrer un nombre Maximum\n");
	scanf_s("%d", &NbMax);
	printf("Entrer un nombre Minimum\n");
	scanf_s("%d", &NbMin);

	y2k.tm_hour = 1;   y2k.tm_min = 0; y2k.tm_sec = 0;
	y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;

	time(&timer);  /* get current time; same as: timer = time(NULL)  */

	seconds = difftime(timer, mktime(&y2k));

	Nbalea = RandomCustomEntier(seconds, &NbMax, &NbMin);
	printf("Nombre entier = %d \n", Nbalea);

	NbaleaFloat = RandomCustomFloat(seconds, &NbMax, &NbMin);
		printf("Nombre float = %.3f ", NbaleaFloat);


	return 0;
}



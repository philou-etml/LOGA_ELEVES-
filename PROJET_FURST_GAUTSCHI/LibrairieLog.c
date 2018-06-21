// Projet
// Auteur :  S.Gautschi

// Suppression avertissement C4996
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>	// pour fopen, fprintf

void EnregistrerLog(int ErreurCode);
void VisualiserLog(char *FileName);

int main(void)
{

}
void VisualiserLog(char *FileName)	//passer en paramètre le nom du fichier
{
	FILE *fp1;
	char ligne[80];
	 
	if (fopen(FileName, "r") == NULL)
	{
		printf("Nom de fichier invalide\n");
		return (0);
	}

	fp1 = fopen(FileName, "r");			// Ouverture pour lecture
	while (!feof(fp1)) {
		if (fgets(ligne, 80, fp1) == NULL) {
			return 0;
		}
		else
		{
			{printf("%s", ligne); }
		}
	}
	fclose(fp1);
}


void EnregistrerLog(int ErreurCode)		//passer en paramètre le numéro de l'erreur
{
	unsigned static  int NumeroErreur = 1;
	char ChoixUtilisateur = 0;
	FILE *fp1;								 // descripteur de fichier

	char ligne[80];
	ligne[0] = 1;

	char *FileName1 = "test1.txt";

	if (NumeroErreur == 1)
	{
		fp1 = fopen("test1.txt", "w");	//ouvre en w la première fois pour supprimer le contenus du fichier

		fprintf(fp1, "ErreurCode %d = %d\n", NumeroErreur, ErreurCode);

		fclose(fp1);
		NumeroErreur = NumeroErreur + 1;
	}
	else
	{
		fp1 = fopen("test1.txt", "a");

		fprintf(fp1, "ErreurCode %d = %d\n", NumeroErreur, ErreurCode);

		NumeroErreur = NumeroErreur + 1;
		fclose(fp1);
	}
}
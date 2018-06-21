// Compiler le programme avec: g++ testCPP.cpp -o testCPP -lgmpxx -lgmp -std=c++0x

// Executer avec: ./testCPP

#include <iostream>
#include <string>
#include <gmpxx.h>

using namespace std;

#define MAX 10


// _______________________________ Prototypes des fonctions _________________________________
// Fonctions pour l'utilisateur
void Crypto(int chaineChiffree[]);
void Decrypto(int chaineChiffree[]);

// Fonctions secondaires
void Chiffrage(char motPourChiffrage[], int motChiffre[]);
void Dechiffrage(int motChiffre[], char motDechiffre[]);
int puissanceMod(int entree, int pow, int mod);
void Grouper3to4(char groupeDe3[], int groupeDe4[]);
void Grouper4to3(int groupeDe4[], char groupeDe3[]);


// ________________________________ Exemple d'utilisation ___________________________________
// !!! -> A mettre en commentaire pour utiliser le fichier comme une librairie 

int main(int argc, char **argv)
{	
	int chaine[15] = {0};
	
	Crypto(chaine);
	Decrypto(chaine);	

	return 0;
}


// _______________________________ Fonctions pour l'utilisateur _____________________________

// *** Fonction Crypto ***
// Cette fonction prend comme paramètre la chaine qui sera retournée

void Crypto(int chaineChiffree[])
{
	char chaineNonChiffree[20];

	cout << "Veuillez entrer un mot de 20 caractères maximum \n";
	
	cin >> chaineNonChiffree;
	
	Chiffrage(chaineNonChiffree, chaineChiffree);	
}

// *** Fonction Decrypto ***
// Cette fonction prend en paramètre la chaine à décrypter et la modifie directement
  
void Decrypto(int chaineChiffree[])
{	
	char chaineDechiffree[20] = {0};

	Dechiffrage(chaineChiffree, chaineDechiffree);
	
	cout << chaineDechiffree << "\n";
}

//********************************************************
// Choix des valeurs de cryptages et de decryptage
//********************************************************
//	p = 53 ou 503 
//	q = 97 ou 563
//
//	n = p * q = 5141 ou 283189
//	M ou fi-n = (p - 1)*(q - 1) = 4992 ou 282124
//	e:		p,q < e < fi-n		&&		PGDC(fi-n, e) = 1
//	-> e = 7 ou 565
//      d: 4279 ou 140313
//      fi-n: 5141 ou 282124
//
// Cle publique: (e, n) - > (565, 283189)
// Cle privee: (d, n) -> (140313, 283189)
//
//********************************************************

// _______________________________ Fonctions secondaires _______________________________________

// *** Fonction Chiffrage ***
// Cette fonction prend comme premier paramètre la chaine de caractère à chiffrer et comme
// deuxième paramètre la chaine chiffree

void Chiffrage(char motPourChiffrage[], int motChiffre[])
{
	cout << "DebutChiffrage";
	
	Grouper3to4(motPourChiffrage, motChiffre);	
	
        // Elever chaque caractere a la puissance e            
        // Faire le modulo de cette valeur
	for(int i = 0; i < 15; i ++)
	{
		// Le principe du chiffrage RSA est de faire:  (<caractere> à la puissance e ) modulo n
		// 'e' et 'n' sont des valeurs précise choisie pour la clé publique
		motChiffre[i] = puissanceMod(motChiffre[i], 565, 283189);	
	}
	cout << "Fin Chiffrage";
}


// *** Fonction Dechiffrage ***
// Cette fonction prend comme parametre la chaine a dechiffrer et la chaie une fois dechiffree

void Dechiffrage(int motChiffre[], char motDechiffre[])
{
	cout << "Debut dechiffrage";
	for(int i = 0; i < 15; i ++)
	{
		// Une fois un caractere chiffre, on ne peut pas le dechiffre avec une cle publique.
		// On est donc oblige de refaire l'operation suivante, mais avec la cle privee
		// (<caractere> à la puissance d) modulo n
		motChiffre[i] = puissanceMod(motChiffre[i], 140313, 283189);
	}

	// On remet les caractere par groupe normaux pour pouvoir les afficher
	Grouper4to3(motChiffre, motDechiffre);
	cout << "Fin dechiffrage\n";
}

// *** Fonction Groupe3to4 ***
// Cette fonction prend en paramètre une chaine avec chaque caractère groupé par groupe de 3 et renvoie un tableau groupé par 4 
// Cette methode permet d'ameliorer le niveau de chiffrage et de le rendre encore plus difficile a dechiffrer

void Grouper3to4(char groupeDe3[], int groupeDe4[])
{
	int i = 0;
	int j = 0;
	
	cout << "Decoupe de 3 en 4\n";

	for (j = 0; j < 15; j ++)
	{
                // Systeme qui transforme les valeurs de groupe de 3 décimale en groupe de 4 (123 456 789 123... -> 1234 5678 9123...)
                if(j % 3 == 0)
                {	
			// Pour le premier genre 123 4xx -> 1234
          	        groupeDe4[j] = groupeDe3[i] * 10 + (groupeDe3[i + 1] - (groupeDe3[i + 1] % 100)) / 100;		
                }
                else if(j % 3 == 1)
                {
			// Le second genre x56 78x -> 5678
                        groupeDe4[j] = (groupeDe3[i] % 100) * 100 + (groupeDe3[i + 1] - (groupeDe3[i + 1] % 10)) / 10; 
                }
                else
                {
			// Le troisième genre xx9 123 -> 9123
                        groupeDe4[j] = (groupeDe3[i] % 10) * 1000 + groupeDe3[i + 1];
                	i ++;
                }
                i ++;
	}	// Et on recomence
	
	for(i = 0; i < 15; i ++)
	{	
		// On affiche de résultat pour le debug
		cout << groupeDe4[i] << " "; 
	}	
	cout << "\nFin decoupe 3 en 4\n";
}

// *** Fonction Groupe4to3 ***
// Cette fonction fait l'action inverse de Groupe3to4. Elle prend en paramètre la chaine groupee par 4 et la chaine une fois groupee par 3

void Grouper4to3(int groupeDe4[], char groupeDe3[])
{
	int i = 0;
	int j = 0;

	cout << "Decoupe de 4 en 3\n";
	
	// Systeme qui transforme les valeurs de groupe de 4 décimale en groupe de 3 (1234 5678 9123... -> 123 456 789 123...)
	for(i = 0; i < 20; i ++)
	{	
		if(i % 4 == 0)
		{
			// Pour le premier genre 123x -> 123
			groupeDe3[i] = groupeDe4[j] / 10;
			j ++;
		} 
		else if (i % 4 == 1)
		{
			// Pour le second genre xxx4 56xx -> 456
			groupeDe3[i] = groupeDe4[j - 1] % 10 * 100 + groupeDe4[j] / 100;
			j ++;
		}
		else if (i % 4 == 2)
		{	
			// Pour le troisième genre xx78 9xxx -> 789
			groupeDe3[i] = groupeDe4[j - 1] % 100 * 10 + groupeDe4[j] / 1000; 
		}
		else
		{
			// Pour le quatrième genre x123 -> 123
			groupeDe3[i] = groupeDe4[j] % 1000;
			j ++;	
		}
	}
	
	
	for(i = 0; i < 15; i ++)
	{
		cout << groupeDe4[i] << " "; 
	}	
	
	cout << "\nFin découpe 4 en 3\n";
}

// *** Fonction puissanceMode ***
// Cette fonction utilise la librairie RSA. Elle s'occupe de preparer les variable pour le chiffrage et 
// le dechiffrage avec les bons types de classes.

int puissanceMod(int entree, int pow, int mod)
{
	int sortie;
	// Initialisation des type.
	mpz_t entree_t, pow_t, mod_t, sortie_t;

	// Pour utiliser les fonction mpz_pow_ui -> (puissance) et mpz_mod -> (modulo), il faut utiliser des types speciaux
	// car nous manipulons des chiffres très très très grand et que ce n'est pas possible de le faire avec des types standard 
	mpz_init(entree_t);
	mpz_init(sortie_t);
	mpz_init(pow_t);
	mpz_init(mod_t);
	
	mpz_set_str(entree_t, to_string(entree).c_str(), 10);
	mpz_set_str(pow_t, to_string(pow).c_str(), 10);
	mpz_set_str(mod_t, to_string(mod).c_str(), 10);

	mpz_pow_ui(sortie_t, entree_t, pow);
	mpz_mod(sortie_t, sortie_t, mod_t);

	// On reconverti la valeur calculée de type mpz_get_ui en un type standard "int"
	sortie = mpz_get_ui(sortie_t);
	return sortie;
}

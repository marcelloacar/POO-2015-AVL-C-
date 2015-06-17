/* ========================================================================== *
**	Trablaho Integrado - ED & POO -
**	- Corretor de texto -
**
** Criado por:
**	Bruno Bittar
**  Hugo Mori
**	Isabela Salmeron
**	Marcello Acar
**	Murilo	Moron
**
**
**	Definicao da classe Dicionario
**
**
**
* ========================================================================== */

#ifndef DICIONARIO_H
#define DICIONARIO_H

// declaracao das bibliotecas utilizadas
#include <iostream>
#include <string>
#include <list>
#include <fstream>


#include "PalavraClass.h"
#include "AVLClass.h"

using namespace std;


// Classe Dicionario

class DicionarioClass{

	private:
		AVLClass avl;
		PalavraClass palavra;
		string vetor[30000];
		int j;

	public:
		bool carregaDicionario();
		void consultaDicionario();
		void inserirDicionario();
		void inserirDicionario2(string palavra);
		int consultaDicionario2(string word);
		void quickSort(string arr[], int left, int right);
		void semelhante();
		void semelhante2(string word);
};

#endif // DICIONARIO_H
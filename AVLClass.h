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
**	Definicao da classe AVL
**
**
**
* ========================================================================== */

#ifndef AVLClass_H
#define AVLClass_H

#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include <fstream>

#include "PalavraClass.h"



#define TRUE 1
#define FALSE 0

using std::string;

// Definicao do nó
struct Node {
	string word;
	Node *esq, *dir;
	short int bal;
};

// Definicao da Arvore
typedef Node *Arvore;

class AVLClass {
	
	private:
		string w;
		Arvore t;
		PalavraClass word;
		

	public:
		AVLClass();
		~AVLClass();
		void inicArvore(Arvore *t);
		void liberaArvore(Arvore *t);
		int verificaAVL(Arvore t, int *alt);
		void imprimeArvoreAux(int nivel);
		void imprimeArvore(Arvore t, int nivel);
		int alturaArvore(Arvore t);
		int numeroNosArvore(Arvore t);
		void percorreArvoreAux();
		string percorreArvoreAux2();
		void percorreArvore(Arvore t);
		string percorreArvore2(Arvore t);
		void arvoreArquivoAUX(string * lista);
		void arvoreArquivo(Arvore t, string * lista, int i);
		void RR(Arvore *t);
		void LL(Arvore *t);
		void RL(Arvore *t);
		void LR(Arvore *t);
		Arvore novoNo(string wordReplace);
		void SubArvoreEsquerdaCresceu(Arvore *t, int *cresceu);
		void SubArvoreDireitaCresceu(Arvore *t, int *cresceu);
		int consultaPalavraAux(string word);
		int consultaPalavra(Arvore t, string word);
		int inserePalavraAVLAux(string wordReplace, int *cresceu);
		int inserePalavraAVL(Arvore *t, string wordReplace, int *cresceu);

};

#endif //AVLClass_H
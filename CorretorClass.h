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
**	Definicao da classe Corretor
**
**
**
* ========================================================================== */

#ifndef CORRETOR_H
#define CORRETOR_H


#define tam 1000

// declaracao das bibliotecas utilizadas
#include <iostream>
#include <string>
#include <list>
#include <fstream>

#include "DicionarioClass.h"
#include "TextoClass.h"
#include "AVLClass.h"
#include "PalavraClass.h"


using namespace std;


class CorretorClass{
	private:
		DicionarioClass dic;
		TextoClass texto;
		string palavraErrada[10000];
		int count;
		int tamanhoArquivo;

	public:
		CorretorClass();
		void pesquisaPalavraDicionario();
		void listarPalavrasErradas();
};

#endif //CORRETOR_H
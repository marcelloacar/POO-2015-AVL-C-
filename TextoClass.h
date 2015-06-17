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
**	Definicao da classe Texto
**
**
**
* ========================================================================== */

#ifndef TEXTO_H
#define TEXTO_H

// declaracao das bibliotecas utilizadas
#include <iostream>
#include <string>
#include <list>
#include <fstream>

#include "PalavraClass.h"


using namespace std;
// Classe Texto

class TextoClass{
	private:
		list<PalavraClass> lista;
		string nomeArquivo;
		
	public:
		//TextoClass();
		bool carregaTexto();
		int carregaTexto2();
		void alterarPalavra();
		void alterarPalavra2(string palavra);
		string retornaPalavras(int i);
		void imprimeLista();
		void salvarNovoTexto();
		void salvarNovoTexto2();

};

#endif // TEXTO_H
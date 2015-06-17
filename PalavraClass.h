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
**	Definicao da classe Palavra
**
**
**
* ========================================================================== */

#ifndef PALAVRA_H
#define PALAVRA_H
#define TRUE 1
#define FALSE 0

// declaracao das bibliotecas utilizadas
#include <iostream>
#include <string>


using std::string;

// Classe Palavra

class PalavraClass{

	private:		
		string word; 

	public:

		void lerPalavra(string pal);
		int semelhancaPalavra(string pal);
		string verPalavra();
		void imprimePalavra();
		int operator==( const string &pal );
		int operator==( const PalavraClass & ); // comparacao de igualdade;
		
};

#endif // PALAVRA_H
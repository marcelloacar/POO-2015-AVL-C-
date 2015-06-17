#include "PalavraClass.h"

using namespace std;

// metodo set
void PalavraClass::lerPalavra(string pal){
	word = pal;
}

/*
**	Metodo para comparar as 2 primeira letras de cada palavra
**	o metodo copia as 2 primeiras letras de cada palavra para uma variavel auxiliar
**	e depois compara letra a letra as duas string auxiliares
*/
int PalavraClass::semelhancaPalavra(string pal){

	// strings auxilares
	char auxPalavra1[2], auxPalavra2[2];

	// copia das strings originais para as auxiliares( metodo copy copia para a cadeia de caracters passada como parametro)
	word.copy( auxPalavra1, 2, 0 );
	pal.copy( auxPalavra2, 2, 0 );

	// \0 eh colocado a mao para evitar copia de lixo nas strings auxiliares
	auxPalavra1[2] = '\0';
	auxPalavra2[2] = '\0';

	// caso qualquer uma das letras sejam diferentes o metodo encerra retornando FALSE( 0 )
	for( int i = 0; i < 3; i++ ){

		if( auxPalavra2[i] != auxPalavra1[i] )
			return( FALSE );
		
	}

	// so retorna TRUE quando as letras das strings sao iguais
	return( TRUE );
}

// metodo para imprimir o atributo da classe
void PalavraClass::imprimePalavra(){
	cout << word << endl;
}

// metodo get, para retornar o atributo da classe
string PalavraClass::verPalavra(){
	return word;
}

/*
** sobrecarga do operado == para comparaçao entre duas string
**	sendo PalavraClass == string
**	desse modo podemos comparar o objeto da classe com uma string
** qualquer desde que o objeto esteja do lado equerdo do operador
*/
int PalavraClass::operator==( const string &pal ){

	if( word == pal ){
		return( TRUE );
	}else{
		return( FALSE );
	}
}


/*
** sobrecarga do operado == para comparaçao entre duas string
**	sendo PalavraClass == PalavraClass
**	desse modo podemos comparar dois objetos da classe PalavraClass
**
*/
int PalavraClass::operator==( const PalavraClass &operand2 ){

	if( word == operand2.word || operand2.word == word ){
		return( TRUE );
	}else{
		return( FALSE );
	}
}
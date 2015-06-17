 /*	- A classe Texto deverá conter uma lista de palavras(feito)
	- O nome do arquivo original do tegxto (feito)
	- Permitir carregar um texto a partir de um arquivo (feito)
	- Percorrer o texto, palavra por palavra(feito)
	- Alterar uma palavra
	- Gravar o texto em um arquivo (não necessariamente o original).
*/


#include "TextoClass.h"


bool TextoClass::carregaTexto(){
	ifstream leitura;
	string test;
	PalavraClass palavra;
	list<PalavraClass>::iterator it;
	cout << endl << "Informe o nome do arquivo e sua extensao (nomearquivo.extensao):" << endl;
	cin >> nomeArquivo;

	leitura.open(nomeArquivo.c_str());

	if(!leitura){
		cout << "NAO CARREGOU" << endl;
		return false;
	}
	else{
		cout << "TEXTO CARREGADO COM SUCESSO" << endl;
	}

	while(!leitura.eof()){
		leitura >> test;
		palavra.lerPalavra(test);
		lista.push_back(palavra);	
	}	

	leitura.close();
	
	return true;
}

int TextoClass::carregaTexto2(){
	ifstream leitura;
	string test;
	string nomeArquivo;
	PalavraClass palavra;
	list<PalavraClass>::iterator it;
	int count = 0;

	cout << endl << "Informe o nome do arquivo e sua extensao (nomearquivo.extensao):" << endl;
	cin >> nomeArquivo;
	leitura.open(nomeArquivo.c_str());

	while(!leitura.eof()){
		leitura >> test;
		palavra.lerPalavra(test);
		lista.push_back(palavra);
		count++;	
	}	

	leitura.close();
	return count;
}

void TextoClass::imprimeLista(){	
	list<PalavraClass>::iterator it;
	for(it = lista.begin(); it != lista.end(); it++){
			it->imprimePalavra();
	}
}

string  TextoClass::retornaPalavras(int i){	
	list<PalavraClass>::iterator it;
	int j = 0;
	for(it = lista.begin(); it != lista.end(); it++){
		if(j == i){
			return it->verPalavra();
		}
		j++;
	}
}


void TextoClass::alterarPalavra(){
	string palavra;
	string palavraNova;
	PalavraClass palavra2;
	list<PalavraClass>::iterator it;
	cout << "Informe a palavra que deseja alterar: " << endl;
	cin >> palavra;	

	for(it = lista.begin(); it != lista.end(); it++){
		if(palavra == it->verPalavra()){
			cout << "Informe a nova palavra: "<< endl;
			cin >> palavraNova;
			palavra2.lerPalavra(palavraNova);
			lista.insert(it, palavra2);
			lista.erase(it);			
			return;
		}
	}
	
	cout << "NAO ACHEI" << endl;			
	
}

void TextoClass::alterarPalavra2(string palavra){
	string palavraNova;
	PalavraClass palavra2;
	list<PalavraClass>::iterator it;

	for(it = lista.begin(); it != lista.end(); it++){
		if(palavra == it->verPalavra()){
			cout << "Informe a nova palavra: "<< endl;
			cin >> palavraNova;
			palavra2.lerPalavra(palavraNova);
			lista.insert(it, palavra2);
			lista.erase(it);			
			return;
		}
	}		
	
}


void TextoClass::salvarNovoTexto(){
	ofstream escrita;
	int opcao;
	string palavra, nomedoArquivo2;
	list<PalavraClass>::iterator it;
	cout << "Gravar no mesmo arquivo? 1 - S    2 - N" << endl;
	cin >> opcao;
	if(opcao == 1){
		escrita.open(nomeArquivo.c_str());
		for(it = lista.begin(); it != lista.end(); it++){
			
			escrita << it->verPalavra() << " ";
		}
		escrita.close();
		lista.clear();
	}
	else{
		cout << "Qual novo nome do arquivo e sua extensao?" << endl;
		cin >> nomedoArquivo2;
		escrita.open(nomedoArquivo2.c_str());
		lista.pop_back();
		for(it = lista.begin(); it != lista.end(); it++){
			
			escrita << it->verPalavra() << " ";
		}
		escrita.close();
		lista.clear();
	}

}

void TextoClass::salvarNovoTexto2(){
	ofstream escrita;
	string palavra, nomedoArquivo;
	list<PalavraClass>::iterator it;

	nomeArquivo = "texto.txt";
	escrita.open(nomeArquivo.c_str());
	for(it = lista.begin(); it != lista.end(); it++){
			
		escrita << it->verPalavra() << " ";
	}
	escrita.close();
	lista.clear();
	
}
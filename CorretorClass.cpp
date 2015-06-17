#include "CorretorClass.h"

CorretorClass::CorretorClass(){
	dic.carregaDicionario();
	count = 0;
}

void CorretorClass::pesquisaPalavraDicionario(){
	string palavras[1000];
	int i;
	int flag=0;
	int opcao=0;

	tamanhoArquivo = texto.carregaTexto2();

	for(i=0; i < tamanhoArquivo; i++){
	 	palavras[i] = texto.retornaPalavras(i);
	}
	for (i=0; i < tamanhoArquivo; i++){
	 	flag = dic.consultaDicionario2(palavras[i]);

	 	if(flag == 0){
	 		palavraErrada[count] = palavras[i];
	 		count++;
	 		while(opcao == 3 || flag == 0){
		 		cout << "A palavra '" << palavras[i] << "' não existe no dicionário!" << endl;
		 		if (i != 0 && i < tamanhoArquivo - 1)
		 			cout << "o erro ocorreu nesse ponto: '" << palavras[i-1] << " " << palavras[i] << " " << palavras[i+1] << "'" << endl; 
		 		cout << "" << endl;
		 		cout << "o que você deseja fazer?" << endl;
		 		cout << "1 - Para corrigir a palavra" << endl;
		 		cout << "2 - Para adicionar palavra ao dicionario" << endl;
		 		cout << "3 - Listar palavras semelhantes" << endl;
		 		cout << "4 - Ignorar o erro" << endl;
		 		cin >> opcao;

		 		switch (opcao){
						case 1:{
							texto.alterarPalavra2(palavras[i]);
							texto.salvarNovoTexto2();
							flag = 1;
							break;
						}
						case 2:{
							dic.inserirDicionario2(palavras[i]);
							flag = 1;					   	
						   	break;
						}
						case 3:{
							dic.semelhante2(palavras[i]);	   		  
						    break;
						}
						case 4:{
							flag = 1;
							break;	
						}
						default: {
							cout << "Digite um numero valido" << endl;
							break;
						}
				}
			}
	 	}
	}

}

void CorretorClass::listarPalavrasErradas(){
	int i;

	cout << " " << endl;
	cout << "Historico de palavras erradas:" << endl;
	for(i=0; i < count; i++){
		cout << palavraErrada[i] << endl;
	}
}
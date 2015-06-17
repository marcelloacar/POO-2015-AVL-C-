#include "DicionarioClass.h"

bool DicionarioClass::carregaDicionario(){
	ifstream leitura;
	string test, nome;
	PalavraClass palavra;
		
	int tamanhoAVL = 0;
	int AVL = 0;
	nome = "dic.txt";
	leitura.open(nome.c_str());

	j=0;

	if(!leitura){
		cout << "Impossivel carregar dicionario, nome do arquivo esta incorreto." << endl;
		exit(1);
		return false;
	}
	else{
		cout << "" << endl;
		cout << "Dicionario carregado com sucesso" << endl;
	}

	while(!leitura.eof()){
		leitura >> test;
		palavra.lerPalavra(test);
		AVL = avl.inserePalavraAVLAux(test, &tamanhoAVL);
		vetor[j] = test;
		j++;
	}

	leitura.close();	
	return true;
}

void DicionarioClass::consultaDicionario(){
	string palavra;
	int AVL = 0;

	cout << "Qual palavra deseja consultar?" << endl;
	cin >> palavra;

	AVL = avl.consultaPalavraAux(palavra);

	if(AVL == 1){
		cout << "Palavra existente no dicionario" << endl;
	}
	else{
		cout << "Palavra inexistente no dicionario" << endl;
	}
}

int DicionarioClass::consultaDicionario2(string word){
	int AVL = 0;

	AVL = avl.consultaPalavraAux(word);

	if(AVL == 1){
		return 1;
	}

	return 0;
}


void DicionarioClass::inserirDicionario(){
	string palavra, nomeArquivo, word;
	ofstream escrita;
	ifstream leitura;
	int AVL = 0;
	int tamanhoAVL = 0;
	string vetor2[30000];

	nomeArquivo = "dic.txt";

	cout << "Qual palavra deseja inserir?" << endl;
	cin >> palavra;

	AVL = avl.consultaPalavraAux(palavra);

	if(AVL == 1){
		cout << "Palavra existente no dicionario" << endl;
	}
	else{
		AVL = avl.inserePalavraAVLAux(palavra, &tamanhoAVL);
		escrita.open(nomeArquivo.c_str());
		for (int i = 0; i < j; i++){
				word = vetor[i];
				escrita << word;
				escrita << "\n";
		}		

		escrita << palavra;
		escrita.close();

		 leitura.open(nomeArquivo.c_str());
		 j = 0;
		 while(!leitura.eof()){
		 	leitura >> word;
		 	vetor2[j] = word;
		 	j++;
		 }

		leitura.close();

		quickSort(vetor2, 0, j);

		escrita.open(nomeArquivo.c_str());
		for (int i = 0; i <= j; i++){
			if(i != 0){
				word = vetor2[i];
				escrita << word;
				escrita << "\n";
			}			
		}		
		escrita.close();

	}
}

void DicionarioClass::inserirDicionario2(string palavra){
	string nomeArquivo, word;
	ofstream escrita;
	ifstream leitura;
	int AVL = 0;
	int tamanhoAVL = 0;
	string vetor2[30000];

	nomeArquivo = "dic.txt";

	AVL = avl.inserePalavraAVLAux(palavra, &tamanhoAVL);
	escrita.open(nomeArquivo.c_str());
	for (int i = 0; i < j; i++){
		word = vetor[i];
		escrita << word;
		escrita << "\n";
	}		

	escrita << palavra;
	escrita.close();

	leitura.open(nomeArquivo.c_str());
	j = 0;
	while(!leitura.eof()){
		leitura >> word;
	 	vetor2[j] = word;
	 	j++;
	}

	leitura.close();

	quickSort(vetor2, 0, j);

	escrita.open(nomeArquivo.c_str());
	for (int i = 0; i <= j; i++){
		if(i != 0){
			word = vetor2[i];
			escrita << word;
			escrita << "\n";
		}			
	}		
	escrita.close();
}

void DicionarioClass::quickSort(string arr[], int left, int right) {

      int i = left, j = right;
      string tmp;
      string pivot = arr[(left + right) / 2];

      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      }

      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}


void DicionarioClass::semelhante(){
	string word;
	string vetorS[10];
	int i;
	int flag;
	int count = 0;

	cout << "Qual palavra deseja procurar semelhantes"<< endl;
	cin >> word;

	for (i = 0; i < j; ++i){
		palavra.lerPalavra(vetor[i]);
		flag = palavra.semelhancaPalavra(word);

		if(flag == 1 && count < 10){
			vetorS[count] = vetor[i];
			count++;
		}
	}

	cout << "" << endl;
	cout << "Lista de Palavras semelhantes: " << endl;
	for (i = 0; i < count; ++i){
		cout << vetorS[i] << endl;
	}
		
}

void DicionarioClass::semelhante2(string word){
	string vetorS[10];
	int i;
	int flag;
	int count = 0;

	for (i = 0; i < j; ++i){
		palavra.lerPalavra(vetor[i]);
		flag = palavra.semelhancaPalavra(word);

		if(flag == 1 && count < 10){
			vetorS[count] = vetor[i];
			count++;
		}
	}

	cout << "" << endl;
	cout << "Lista de Palavras semelhantes: " << endl;
	for (i = 0; i < count; ++i){
		cout << vetorS[i] << endl;
	}
		
}
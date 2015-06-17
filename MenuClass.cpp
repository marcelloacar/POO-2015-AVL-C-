#include "MenuClass.h"


void MenuClass::menuTexto(TextoClass t){
	int menu = 0;
	int opcao;
	while (menu != 5){
				cout << "Menu Texto:" << endl;
				cout << "1 - Carregar um texto a partir de um arquivo." << endl;
				cout << "2 - Alterar palavra do texto." << endl;
				cout << "3 - Para listar todo texto." << endl;
				cout << "4 - Salvar arquivo texto." << endl;
				cout << "5 - Para voltar ao menu principal." << endl;
				cin >> menu;

				switch (menu){
					case 1:{
							   
							   	t.carregaTexto();
							    break;
					}
					case 2:{
							   	t.alterarPalavra();					   	
							   	break;
					}
					case 3:{
							    t.imprimeLista();				  
							    break;
					}
					case 4:{
								t.salvarNovoTexto();
								break;
					}
					case 5:{
							   cout << "Voltar menu principal" << endl;
							   break;
					}
					default: {
								 cout << "Digite um numero valido" << endl;
								 break;
					}
				}
			}
}


void MenuClass::menuDicionario(DicionarioClass dic){

	int menu = 0;
	int opcao;
	dic.carregaDicionario();

	while (menu != 4){
				cout << "Menu Dicionario:" << endl;
				cout << "1 - Consultar dicionario." << endl;
				cout << "2 - Incluir palavra dicionario." << endl;
				cout << "3 - Procurar palavras semelhantes." << endl;
				cout << "4 - Para voltar ao menu principal." << endl;
				cin >> menu;

				switch (menu){
					case 1:{							   
					  	dic.consultaDicionario();
					    break;
					}
					case 2:{
					   	dic.inserirDicionario();					   	
					   	break;
					}
					case 3:{
					    dic.semelhante();				  
					    break;
					}
					case 4:{
					   cout << "Voltar menu principal" << endl;
					   break;
					}					
					default: {
					    cout << "Digite um numero valido" << endl;
					    break;
					}
				}
			}
	
}

void MenuClass::menuCorretor(CorretorClass corretor){
	int menu = 0;
	int opcao;

	while (menu != 3){
				cout << "Menu Corretor:" << endl;
				cout << "1 - Iniciar Corretor." << endl;
				cout << "2 - Consultar historico de palavras erradas." << endl;
				cout << "3 - Para voltar ao menu principal." << endl;
				cin >> menu;

				switch (menu){
					case 1:{							   
					  	corretor.pesquisaPalavraDicionario();
					    break;
					}
					case 2:{
					   	corretor.listarPalavrasErradas();					   	
					   	break;
					}

					case 3:{
					   cout << "Voltar menu principal" << endl;
					   break;
					}			
					default: {
					    cout << "Digite um numero valido" << endl;
					    break;
					}
				}
			}

	system("clear");
}
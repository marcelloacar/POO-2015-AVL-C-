/*----------------------------------------------------------
# Trabalho Integrado: ED1/POO
#
# Integrantes:
# Bruno Bittar Trevizan 	 		RA 380407
# Hugo de Oliveira Mori 	 		RA 552607
# Isabela Salmeron Boschi 	 		RA 552593
# Marcello da Costa Marques Acar 	RA 552550
# Murilo Moron Marques 				RA 511390 
----------------------------------------------------------*/

#include <iostream>
#include <string>
#include <list>
#include <fstream>


#include "MenuClass.h"

using namespace std;

int main(){

	MenuClass menu;
	DicionarioClass dic;
	TextoClass t;
	CorretorClass corretor;
	int opcao = 0;

	system("clear");
	cout << "Escolha uma das opcoes abaixo:" << endl;
	cout << "1 - Para Texto." << endl;
	cout << "2 - Para o Dicionario." << endl;
	cout << "3 - Para o Corretor" << endl;
	cout << "4 - Para sair" << endl;
	cin >> opcao;	

	while (opcao != 4){		
		switch (opcao){
					case 1:{
						system("clear");
						menu.menuTexto(t);						   
						break;
					}
					case 2:{
						system("clear");
						menu.menuDicionario(dic); 						   	
					   	break;
					}
					case 3:{
						system("clear");
						menu.menuCorretor(corretor);	   		  
					    break;
					}
					case 4:{
								
					}
					default: {
						cout << "Digite um numero valido" << endl;
						break;
					}
		}
		system("clear");
		cout << "Escolha uma das opcoes abaixo:" << endl;
		cout << "1 - Para Texto." << endl;
		cout << "2 - Para o Dicionario." << endl;
		cout << "3 - Para o Corretor" << endl;
		cout << "4 - Para sair" << endl;
		cin >> opcao;
	}
	return 0;
}
# Makefile

# Trabalho Integrado: ED1/POO/SI
#
# Integrantes:
# Bruno Bittar Trevizan 	 		RA 380407
# Hugo de Oliveira Mori 	 		RA 552607
# Isabela Salmeron Boschi 	 		RA 552593
# Marcello da Costa Marques Acar 	RA 552550
# Murilo Moron Marques 				RA 511390 

projeto:
	g++ main.cpp AVLClass.cpp CorretorClass.cpp DicionarioClass.cpp MenuClass.cpp PalavraClass.cpp TextoClass.cpp -o trabalho
rm:
	rm trabalho 

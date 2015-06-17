#include <iostream>
#include <string>
#include <list>
#include <fstream>

#include "PalavraClass.h"
#include "AVLClass.h"
#include "DicionarioClass.h"
#include "TextoClass.h"
#include "CorretorClass.h"


using namespace std;



class MenuClass{

	private:
		

	public:
		void menuTexto(TextoClass t);
		void menuCorretor(CorretorClass corretor);
		void menuDicionario(DicionarioClass dic);
};
#include "AVLClass.h"

using namespace std;

/* Construtor padrao */
AVLClass::AVLClass(){
	inicArvore(&t);
}

/* Inicializa a arvore a partir do construtor */
void AVLClass::inicArvore(Arvore *t) {
	try{
		*t = NULL;
	}catch (exception& e){
		cout << "Impossivel alocar Arvore!" << endl;
		exit(0);
	}
}

/*Destrutor padrao */
AVLClass::~AVLClass(){
	liberaArvore(&t);
}

/* Libera todos os nós da arvore apontada por 't', bem 
como todas as cadeias que guardam os nomes. */
void AVLClass::liberaArvore(Arvore *t){
	if (*t != NULL){
		liberaArvore(&(*t)->esq);
		liberaArvore(&(*t)->dir);
		delete *t;
	}
	*t = NULL;
}

/* Verifica se a árvore informada tem a estrutura de uma árvore AVL.*/
int AVLClass::verificaAVL(Arvore t, int *alt) {
	int altEsq, altDir, bal, resEsq, resDir;
	
	if (t == NULL) {
		*alt = 0;
		return TRUE;
	}

	resEsq = verificaAVL(t->esq, &altEsq);
	resDir = verificaAVL(t->dir, &altDir);
	bal = t->bal;

	*alt = ((altEsq<altDir) ? altDir : altEsq) + 1;

	return ((bal >= -1) && (bal <= +1)
		&& (bal == (altDir-altEsq))
		&& resEsq && resDir);
}

void AVLClass::imprimeArvoreAux(int nivel){
	imprimeArvore(t, nivel);
}

/* Imprime a arvore sob a forma de uma árvore 'deitada'. */
void AVLClass::imprimeArvore(Arvore t, int nivel){
	if (t != NULL){
		if (nivel != 0){
			int i;
			for (i = 0; i < nivel; i++){
				cout << "\t";			}
		}
		cout << t->word;
		imprimeArvore(t->esq, nivel + 1);
		if (t == NULL){
			nivel--;
		}
		imprimeArvore(t->dir, nivel + 1);
		if (t == NULL){
			nivel--;
		}
	}
	cout << endl;
}

/* Devolve a altura da arvore 't'. */
int AVLClass::alturaArvore(Arvore t){
	if (t == NULL){
		return 0;
	} else {
		int esquerda = alturaArvore(t->esq);
		int direita = alturaArvore(t->dir);
		return ((esquerda > direita) ? esquerda : direita) + 1;
	}
}

/* Devolve o número de nós da arvore 't' (apenas como teste!) */
int AVLClass::numeroNosArvore(Arvore t){
	if (t == NULL){
		return 0;
	} else{
		int esquerda = numeroNosArvore(t->esq);
		int direita = numeroNosArvore(t->dir);
		return (esquerda + direita) + 1;
	}
}

void AVLClass::percorreArvoreAux(){
	percorreArvore(t);
}

string AVLClass::percorreArvoreAux2(){
	percorreArvore2(t);
}

/* Executa um percurso inordem na arvore, imprimindo todos os elementos (apenas como teste!) */
void AVLClass::percorreArvore(Arvore t){
	if (t != NULL){
		percorreArvore(t->esq);
		percorreArvore(t->dir);
	}
}

string AVLClass::percorreArvore2(Arvore t){
	if (t != NULL){
		percorreArvore(t->esq);
		return t->word;
		percorreArvore(t->dir);
	}
}

void AVLClass::arvoreArquivoAUX(string * lista){
	arvoreArquivo(t, lista, 0);
}

void AVLClass::arvoreArquivo(Arvore t, string * lista, int i){
	if (t != NULL){
		lista[i] = t->word;
		i++;
		arvoreArquivo(t->esq, lista, i++);
		i++;
		arvoreArquivo(t->dir, lista, i++);
	}
}

/** Rotinas para rotação na árvore **/

/* Rotação simples RR - Rotação Direira */
void AVLClass::RR(Arvore *t) {
	Node *aux = *t;
	Node *temp = aux->esq;
	*t = temp;
	aux->esq = temp->dir;
	temp->dir = aux;
}

/* Rotação simples LL - Rotação Esquerda */
void AVLClass::LL(Arvore *t) {
	Node *aux = *t;
	Node *temp = aux->dir;
	*t = temp;
	aux->dir = temp->esq;
	temp->esq = aux;
}

/* Rotação dupla RL - Rotação Direita-Esquerda*/
void AVLClass::RL(Arvore *t) {
	RR(&(*t)->dir);
	LL(&(*t));
}

/* Rotação dupla LR - Rotação Esquerda-Direita*/
void AVLClass::LR(Arvore *t) {
	LL(&(*t)->esq);
	RR(&(*t));
}

/** Rotinas auxiliares para inserção. */

/* Cria um novo nó, com a nova palavra a ser inserida */
Arvore AVLClass::novoNo(string wordReplace) {
	try{
		Node *novo = new Node;
		
		if (novo == NULL){
			return novo;
		}

		novo->esq = NULL;
		novo->dir = NULL;
		novo->bal = 0;
		novo->word = wordReplace;

		return novo;
	} catch (bad_alloc& ba){
		cout << "Impossível alocar espaço para o novo nó!" << endl;
		exit(0);
	}
}

/* Faz os ajustes quando a sub-árvore esquerda cresceu. */
void AVLClass::SubArvoreEsquerdaCresceu(Arvore *t, int *cresceu) {
	switch ((*t)->bal){

		case 1:
			(*t)->bal = 0;
			*cresceu = FALSE;
		break;

		case 0:
			(*t)->bal = -1;
			*cresceu = TRUE;
		break;

		//Desbalanceado
		case -1:
			switch ((*t)->esq->bal){
				//Rotação dupla
				case 1:
					LR(&(*t));
					switch ((*t)->bal){
						case 1:
							(*t)->esq->bal = -1;
							(*t)->dir->bal = 0;
						break;

						case -1:
							(*t)->esq->bal = 0;
							(*t)->dir->bal = 1;
						break;

						case 0:
							(*t)->esq->bal = 0;
							(*t)->dir->bal = 0;
						break;
					}
					(*t)->bal = 0;
				break;

				//Rotação simples
				case -1:
					RR(&(*t));
					(*t)->bal = 0;
					(*t)->dir->bal = 0;
				break;
			}
			*cresceu = FALSE;
		break;
	}
}

/* Faz os ajustes quando a sub-árvore direita cresceu. */
void AVLClass::SubArvoreDireitaCresceu(Arvore *t, int *cresceu) {
	switch ((*t)->bal){
		case -1:
			(*t)->bal = 0;
			*cresceu = FALSE;
		break;

		case 0:
			(*t)->bal = 1;
			*cresceu = TRUE;
		break;

		//Desbalanceado
		case 1:
			switch ((*t)->dir->bal){
				//Rotação dupla
				case -1:
					RL(&(*t));
					switch ((*t)->bal){
						case 1:
							(*t)->esq->bal = -1;
							(*t)->dir->bal = 0;
						break;

						case -1:
							(*t)->esq->bal = 0;
							(*t)->dir->bal = 1;
						break;

						case 0:
							(*t)->esq->bal = 0;
							(*t)->dir->bal = 0;
						break;
					}
					(*t)->bal = 0;
				break;

				//Rotação simples
				case 1:
					LL(&(*t));
					(*t)->bal = 0;
					(*t)->esq->bal = 0;
				break;
			}
			*cresceu = FALSE;
		break;
	}
}

int AVLClass::consultaPalavraAux(string word){
	return consultaPalavra(t, word);
}

/* Caso exista uma palavra igual a informada, returne TRUE, caso contrário retorne FALSE. */
int AVLClass::consultaPalavra(Arvore t, string word) {
	if (t == NULL){
		// caso nao seja encontrada a palavra.
		return FALSE;
	} else {
		if (t->word > word ){
			return consultaPalavra(t->esq, word);
		} else {
			if (t->word < word){
				return consultaPalavra(t->dir, word);
			} else {
				if (t->word == word){
					return TRUE;
				}
			}
		}
	}
}

int AVLClass::inserePalavraAVLAux(string wordReplace, int *cresceu){
	return inserePalavraAVL(&t, wordReplace, cresceu);
}

/* Insere a palavra informada como parâmetro caso não exista
 * a mesma e devolve TRUE. Caso contrário devolve FALSE.
 * A variável 'cresceu' recebe TRUE se a há aumento da altura da
 * árvore e FALSE, caso contrário. */
int AVLClass::inserePalavraAVL(Arvore *t, string wordReplace, int *cresceu) {
	if (*t == NULL){
		*t = novoNo(wordReplace);
		*cresceu = (*t == NULL) ? FALSE : TRUE;
		return (*t == NULL) ? -1 : TRUE;
	} else {
		if ((*t)->word > wordReplace){
			if (!inserePalavraAVL(&(*t)->esq, wordReplace, cresceu)){
				return FALSE;
			}
			if (*cresceu){
				SubArvoreEsquerdaCresceu(&(*t), cresceu);
			}
			return TRUE;
		} else {
			if ((*t)->word < wordReplace){
				if (!inserePalavraAVL(&(*t)->dir, wordReplace, cresceu)){
					return FALSE;
				}
				if (*cresceu){
					SubArvoreDireitaCresceu(&(*t), cresceu);
				}
				return TRUE;
			}
		}
	}
	//Ocorre quando já existe ra.
	*cresceu = FALSE;
	return FALSE;
}
/*
|----------------------------------------------|
||--------------------------------------------||	
|||			   PROJETO - PEDAGIO	     	 |||
|||		ALGORITMOS E ESTRUTURA DE DADOS I	 |||
|||		  KEMUEL ROCHA / PAULO LUCAS		 |||
||--------------------------------------------||
|----------------------------------------------|
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct nodo{
	int inf;
	struct nodo *next;
}NODO; /*NODO DA FILA*/
typedef struct{
	NODO *INICIO;
	NODO *FIM;
}FILA_PEDAGIO; /*DESCRITOR DA FILA*/
typedef FILA_PEDAGIO *FILA;
void cria_fila (FILA *);
int eh_vazia (FILA);
void ins (FILA, int);
int cons(FILA);
int cons_ret (FILA);

typedef struct node{
	int info;
	FILA_PEDAGIO *fila_portao;
	struct node *left;
	struct node *right;
}NODE; /*ARVORE*/
typedef NODE *ARVORE;
void ins_ele (ARVORE *, int);
void maketree(ARVORE *, int, FILA_PEDAGIO *);
void percursoPreOrdem(ARVORE );
void cancelas(ARVORE *);
FILA retornar_fila_da_arvore(ARVORE );
void entrar_na_fila(ARVORE *, int, int);
void remover_da_fila (ARVORE *, int);
void mostrar_primeiro_da_fila (ARVORE *, int);
int info(ARVORE);
ARVORE left(ARVORE);
ARVORE right(ARVORE);

/* (FILA DOS CARROS NAS CANCELAS) */
void cria_fila (FILA *pf){
	*pf=(FILA_PEDAGIO *)malloc(sizeof(FILA_PEDAGIO));
	if (!*pf){
		printf ("\nERRO! Memoria insuficiente!\n");
		exit (1);
	}
	(*pf)->INICIO=(*pf)->FIM=NULL;
}
int eh_vazia (FILA f){
	return (f->INICIO == NULL);
}
void ins (FILA f, int v) {
	NODO *novo;
	novo = (NODO *) malloc (sizeof(NODO));
	
	if (!novo){
		printf ("\n Memoria insuficiente!\n");
		exit (2);
	}

	novo->inf = v;
	novo->next = NULL;
	
	if (eh_vazia(f)){
		f->INICIO=novo;
	}
	else{
		f->FIM->next=novo;
	}
	
	f->FIM=novo;
}

int cons(FILA f){
	if (eh_vazia(f)){
		printf ("\nConsulta em cancela vazia!\n");
	}
	else{
		return f->INICIO->inf;
	}
}
int cons_ret (FILA f) {
	if (eh_vazia(f)){
		printf ("\nConsulta e retirada em cancela vazia!\n");
	}
	else{
		int v=f->INICIO->inf;
		NODO *aux=f->INICIO;
		f->INICIO=f->INICIO->next;
		if (!f->INICIO){
			f->FIM=NULL;
		}
		free (aux);
	return (v);
	}
}

/*________________ARVORE________________*/
void maketree(ARVORE *t, int x, FILA_PEDAGIO *pf){
	*t = (ARVORE)malloc(sizeof(NODE));
	if (!(*t)){
		printf("ERRO DE ALOCACAO DE MEMORIA\n");
		exit(6);
	}
	(*t)->fila_portao = pf;
	(*t)->info = x;
	(*t)->left = NULL;
	(*t)->right = NULL;
}
void ins_ele (ARVORE *t, int x){ /* Função que cria os NOS da arvore: x É TIPOS DE CARROS*/
	if (!(*t)){
      	FILA_PEDAGIO *pf;
		cria_fila(&pf);
		maketree(t, x, pf); /*Quando chamar a maketree vai criar uma fila vazia, pois todos nos tem uma fila*/
	}else{
		if (x<(*t)->info){
			ins_ele(&((*t)->left), x);
		}else
		if (x>(*t)->info){
			ins_ele(&((*t)->right), x);
		}else{/* QUANDO DETECTAR UM TIPO DE VEICULO REPETIDO */
			printf ("NO JA CRIADO!\n");
		}
	}
}
void entrar_na_fila(ARVORE *t, int x, int veic){
	if ((*t)==NULL){
        printf("ARVORE VAZIA\n");
    }else{
	    if (x<(*t)->info){
			entrar_na_fila(&((*t)->left), x, veic);
		}else
		if (x>(*t)->info){
			entrar_na_fila(&((*t)->right), x, veic);
		}else{
		    FILA aux = retornar_fila_da_arvore(*t);
				/* AQUI OS VEICULOS ENTRAM EM SUAS FILAS DETERMINADAS  */
				if(((*t)->left==NULL) && ((*t)->right==NULL)){
					ins(aux, veic);
					printf("O veiculo [%d] entrou na fila [%d]\n\n", veic, x);
				}
				else{/* As filas que não são cancelas inserem e ao mesmo tempo removem, só servem como passagem*/
					int cancela;
					ins(aux, veic);
					printf("NAO EH CANCELA! O veiculo [%d] apenas passou pela fila [%d]\n", cons_ret(aux), x);
					printf("Escolha a Cancela para esse veiculo: [%d] ou [%d]\n", (*t)->left->info, (*t)->right->info);			
					scanf("%d", &cancela);
					entrar_na_fila(t, cancela, veic);
				}	
		}
	}
}
void remover_da_fila (ARVORE *t, int x){
	if ((*t)==NULL){
        printf("NAO EXISTE ESSE NO NA ARVORE\n");
    }else{
		if (x<(*t)->info){
			remover_da_fila(&((*t)->left), x);
		}else
		if (x>(*t)->info){
			remover_da_fila(&((*t)->right), x);
		}else{
		    if((((*t)->left==NULL) && ((*t)->right==NULL))){
    	    	FILA aux = retornar_fila_da_arvore(*t);
        		int aux2 = cons_ret(aux);
        	
        		if (aux2!=0)
    	    		printf("O veiculo [%d] passou pela cancela [%d]\n\n", aux2, x);
  		  	}
    		else{/*NAO EH CANCELA, JÁ FOI RETIRADO DA FILA NA FUNCAO ENTRAR NA FILA*/
        		printf("NAO EH UMA CANCELA\n\n");
			}
		}
	}
}
void mostrar_primeiro_da_fila (ARVORE *t, int x){
	if ((*t)==NULL){
        printf("NAO EXISTE ESSE NO NA ARVORE\n");
    }else{
		if (x<(*t)->info){
			mostrar_primeiro_da_fila(&((*t)->left), x);
		}else
		if (x>(*t)->info){
			mostrar_primeiro_da_fila(&((*t)->right), x);
		}else{
	    	if((((*t)->left==NULL) && ((*t)->right==NULL))){
        		FILA aux = retornar_fila_da_arvore(*t);
        		int aux2 = cons(aux);
        		if (aux2!=0)
    	    		printf("O primeiro veiculo da cancela [%d] eh [%d]\n\n", x,aux2);
    		}
    		else{/*NAO EH CANCELA, JÁ FOI RETIRADO DA FILA NA FUNCAO ENTRAR NA FILA*/
        		printf("NAO EH UMA CANCELA\n\n");
			}
		}
	}
}
void percursoPreOrdem(ARVORE t){
	if (t){
		printf("%d ", info(t)); /*X*/
		percursoPreOrdem(left(t)); /*L*/
		percursoPreOrdem(right(t)); /*R*/
	}
}
void cancelas(ARVORE *t){ /* AS CANCELAS SAO AS FOLHAS DA ARVORE */
    if ((*t)==NULL){
        printf("ARVORE VAZIA");
        exit(12);
    }

    if(((*t)->left==NULL) && ((*t)->right==NULL)){
        printf("%d ",(*t)->info);
    }
    else{
        if((*t)->left!=NULL){
            cancelas(&((*t)->left));
        }
        if((*t)->right!=NULL) {
            cancelas(&((*t)->right));
        }
    }
}
int info(ARVORE t){
	return t->info;
}
FILA retornar_fila_da_arvore(ARVORE t){
	return t->fila_portao;
}
ARVORE left(ARVORE t){
	return t->left;
}
ARVORE right(ARVORE t){
	return t->right;
}




main(){
	ARVORE t=NULL;
	FILA pf=NULL;
	int veiculo = 1, temp1 = 1, temp2 = 1, esc1, esc2, esc3, esc4;
	/*
		ENTRANDO COM OS NOS DA ARVORE PARA CRIAR AS CANCELAS E FILAS
	
		Aqui fizemos uma arvore usando os conceitos de arvore binaria de busca
		Chamamos a funcção ins_ele colocando o numeros de cada nó, a ordem abaixo
		é a mesma que mostraremos no slide, seguindo a ordem escrevendo as linhas da
		arvore de cima ate em baixo:
		4 -> NO
		2 -> NO
		6 -> NO
		1 -> FOLHA
		3 -> FOLHA
		5 -> FOLHA
		7 -> FOLHA
	
		O codigo do nosso projeto, funciona para o numero de cancelas q quiser, entretanto, optamos
		apenas por mostrar utilizando 4 cancelas em um pedagio.	
	*/
		
		
	ins_ele(&t, 4);
	ins_ele(&t, 2);
	ins_ele(&t, 6);
	ins_ele(&t, 1);
	ins_ele(&t, 3);
	ins_ele(&t, 5);
	ins_ele(&t, 7);
	/* ------------------------ ATE AQUI ------------------------------*/
	
	
	
	/* -----PARA MOSTRAR QUE A ARVORE ESTA CRIADA COMO PLANEJADA ------*/
	percursoPreOrdem(t);
	/* ------------------------ ATE AQUI ------------------------------*/
	
	
	
	/* --------------CONSULTANDO AS CANCELAS DO PEDAGIO----------------*/
	printf("\nCANCELAS DO PEDAGIO: ");
	cancelas(&t);
	printf("\n\n");
	/* ------------------------ ATE AQUI ------------------------------*/
	
	
	
	while (temp1!=0){
		printf("Escolha a opccao: \n1 -> ENTRAR VEICULOS\n2 -> CONSULTAR O PRIMEIRO DE CADA CANCELA\n3 -> PASSAR OS VEICULOS NA CANCELA\n0 -> ENCERRAR\n");
		scanf("%d", &esc1);
		temp1=esc1;
		printf("\n");
		switch(esc1){
			case 1: /*---------------------ENTRANDO OS CARROS NAS FILAS---------------------*/
				while(temp2!=0){
					printf("TIPO DE CARRO PARA DETERMINAR A CANCELA: \n1 -> VEICULO DE EMERGENCIA\n3 -> VEICULO DE PASSEIO\n5 -> VEICULO DE PASSAGEIROS\n7 -> VEICULO DE CARGAS\n0 -> PARAR DE ENTRAR COM VEICULOS\n       (CAMINHO MAIS LONGO): \n2 -> VEICULOS DE EMERGENCIA OU PASSEIO\n6 -> CARGAS OU PASSAGEIROS\n4 -> TODOS TIPOS DE CARROS\n");
					scanf("%d", &esc2);
					printf("\n");
					temp2 = esc2;
					if(esc2!=0){
						entrar_na_fila(&t, esc2, veiculo);
						veiculo++;
					}
					printf("=============================================================\n\n\n");
				}
				temp2 = 1;
				break; /*-----------------------------ATE AQUI----------------------------*/
			case 2: 
				while(temp2!=0){/*-------------MOSTRANDO O PRIMEIRO DE CADA CANCELA----------------*/
					printf("CONSULTAR PRIMEIRO ELEMENTO DE QUAL CANCELA\n1 -> VEICULO DE EMERGENCIA\n3 -> VEICULO DE PASSEIO\n5 -> VEICULO DE PASSAGEIROS\n7 -> VEICULO DE CARGAS\n0 -> PARAR CONSULTA\n");
					scanf("%d", &esc3);
					temp2 = esc3;
					if (esc3!=0)
					mostrar_primeiro_da_fila(&t, esc3);
					printf("=============================================================\n\n\n");
				}
				temp2=1;	/*-----------------------------ATE AQUI----------------------------*/
				break;
			case 3:
				while(temp2!=0){/*----------- PASSANDO OS CARROS PELA CANCELA---------------------*/
					printf("LIBERAR PASSAGEM DE QUAL CANCELA\n1 -> VEICULO DE EMERGECIA\n3 -> VEICULO DE PASSEIO\n5 -> VEICULO DE PASSAGEIROS\n7 -> VEICULO DE CARGAS\n0 -> PARAR LIBERACAO\n");
					scanf("%d", &esc4);
					temp2 = esc4;
					if (esc4!=0)
					remover_da_fila(&t, esc4);
					printf("=============================================================\n\n\n");
				}
				temp2=1;	/*-----------------------------ATE AQUI----------------------------*/
				break;
		}
	}
}

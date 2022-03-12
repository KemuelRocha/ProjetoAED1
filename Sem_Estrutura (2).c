#include <stdio.h>
#define MAX 3

main(){
	int fila1[MAX],fila2[MAX],fila3[MAX],fila4[MAX];
	int op, contf1=0, contf2=0, contf3=0, contf4=0, tipo; 
	int f1=0,f2=0,f3=0,f4=0, aux, i1=0, i2=0, i3=0, i4=0, i=0;
	int carro=1;
	int esc;
	fila1[0]=0; /*INICIALIZADO PARA AS FILAS APARECEREM VAZIAS CASO O USUARIO DIGITE PRA CONSULTAR ANTES DE INSERIR*/
	fila2[0]=0;
	fila3[0]=0;
	fila4[0]=0;
	
	do{
	printf("\n 1-INSERIR VEICULOS PEQUENOS\n 2-INSERIR VEICULOS GRANDES\n 3-LIBERAR PASSAGEM\n 4-VERIFICAR O PRIMEIRO VEICULO NA CANCELA\n 0-ENCERRAR\n");
	scanf("%d", &op);
	
		switch(op){
		case 1 :
			printf("\nTIPO DO VEICULO:\n 3-CARRO DE PASSEIO\n 4-EMERGENCIAL\n");
			scanf("%d", &tipo);
			
				if(tipo==3){
					if(f1==MAX){
						printf("\nFILA LOTADA\n");
					}else{
						printf("\nO VEICULO %d ENTROU NA CANCELA 3 (PASSEIO)\n\n", carro);
						fila1[f1] = carro;
						f1++;
						carro++;
					}
				}else{
					if(tipo==4){
						if(f2==MAX){
							printf("\nFILA LOTADA\n");
						}else{
							printf("\nO VEICULO %d ENTROU NA CANCELA 4 (EMERGENCIAL)\n\n", carro);
							fila2[f2] = carro;
							f2++;
							carro++;
						}
					}
				}
		break;
		case 2:
			if(op==2){
				printf("\nTIPO DE VEICULO: \n 5-VEICULO DE PASSAGEIROS\n 6-VEICULO DE CARGA\n");
				scanf("%d", &tipo);
					if(tipo==5){
						if(f3==MAX){
							printf("\nFILA LOTADA\n");
						}else{
							printf("\nO VEICULO %d ENTROU NA CANCELA 5 (PASSAGEIROS)\n\n", carro);
							fila3[f3] = carro;
							f3++;
							carro++;
						}
					}else{
						if(tipo==6){
							if(f4==MAX){
								printf("\nFILA LOTADA\n");
							}else{
								printf("\nOPCAO ESCOLHIDA: VEICULO DE CARGA!\n");
								printf("\nO VEICULO %d ENTROU NA CANCELA 6\n\n", carro);
								fila4[f4] = carro;
								f4++;
								carro++;
							}
						}
					}
			}
		break;
		
		case 3:
			printf("\nREMOVER DE QUAL CANCELA? \n3-VEICULO DE PASSEIO \n4-VEICULO EMERGENCIAL\n5-VEICULO DE PASSAGEIROS\n6-VEICULO DE CARGA\n \n");
			scanf("%d", &tipo);
			if(tipo==3){
				if(i1==MAX){
					printf("NUMERO MAXIMO DE REMOCOES ATINGIDO\n");
				}else{
					int aux1 = fila1[i1];
					fila1[i1] = 0;
					printf("%d FOI REMOVIDO, VIRA %d",aux1, fila1[i1]);
					i1++;
				}
			}else
			if(tipo==4){
				if(i2==MAX){
					printf("NUMERO MAXIMO DE REMOCOES ATINGIDO\n");
				}else{
					int aux2 = fila2[i2];
					fila1[i2] = 0;
					printf("%d FOI REMOVIDO, VIRA %d",aux2, fila2[i2]);
					i2++;
				}
			}else
			if(tipo==5){
				if(i3==MAX){
					printf("NUMERO MAXIMO DE REMOCOES ATINGIDO\n");
				}else{
					int aux3 = fila3[i3];
					fila3[i3] = 0;
					printf("%d FOI REMOVIDO, VIRA %d",aux3, fila3[i3]);
					i3++;
				}
			}else
			if(tipo==6){
				if(i4==MAX){
					printf("NUMERO MAXIMO DE REMOCOES ATINGIDO\n");
				}
				else{
					int aux4 = fila4[i4];
					fila4[i4] = 0;
					printf("%d FOI REMOVIDO, VIRA %d\n",aux4, fila4[i4]);
					i4++;
				}
			}
		break;
		
		case 4: 
			printf("\nESCOLHA A CANCELA:\n\n3-VEICULO DE PASSEIO \n4-VEICULO EMERGENCIAL\n5-VEICULO DE PASSAGEIROS\n6-VEICULO DE CARGA\n");
			scanf("%d", &esc);
				
				switch(esc){
					case 3:
						if (i1==MAX){
							break;
						}
						if(fila1[i1]==0)
							printf("\nFILA VAZIA\n");
						else
							printf("\nPRIMEIRO DA FILA (VEICULO DE PASSEIO) -> %d\n", fila1[i1]);
					break;
					
					case 4:
						if(i2==MAX){
							break;
						}
						if(fila2[i2]==0)
							printf("\nFILA VAZIA\n");
						else 
							printf("\nPRIMEIRO DA FILA (VEICULO EMERGENCIAL) -> %d\n", fila2[i2]);
					break;
					
					case 5:
						if(i3==MAX){
							break;
						}
						if(fila3[i3]==0)
							printf("\nFILA VAZIA\n");
						else
							printf("\nPRIMEIRO DA FILA (VEICULO DE PASSAGEIROS) -> %d\n", fila3[i3]);
					break;
					
					case 6:
						if(i4==MAX){
							break;
						}
						if(fila4[i4]==0)
							printf("\nFILA VAZIA\n");
						else
							printf("\nPRIMEIRO DA FILA (VEICULO DE CARGA) -> %d\n", fila4[i4]);
					break;
				}
		break;
		}
	}while(op!=0);
}


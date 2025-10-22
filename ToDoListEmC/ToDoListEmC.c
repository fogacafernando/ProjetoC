#include <stdio.h>
#include <string.h>
#define MaxTexto 50
#define MaxTarefas 50

typedef struct {
    char texto[MaxTexto];
    int concluida;
} tarefa;

int main(){
	
	tarefa tarefas[MaxTarefas];
	int TotalTarefas = 0;
	int funcoes, i, aux;
	
	
	do{
		printf ("\nPressione 1 para adicionar uma tarefa\n");
		printf ("Pressione 2 para visualizar as tarefas\n");
		printf ("Pressione 3 para marcar uma tarefa como concluida\n");
		printf ("Pressione 4 para remover uma tarefa\n");
		printf ("Pressione 5 para sair\n\n");
		scanf("%d", &funcoes);
		getchar();
	switch (funcoes){
		
		case 1: 
			if (TotalTarefas < MaxTarefas){
			printf("\nAdicione uma tarefa:\n");
			fgets(tarefas[TotalTarefas].texto, MaxTexto, stdin);
			tarefas[TotalTarefas].texto[strcspn(tarefas[TotalTarefas].texto, "\n")] = '\0';
			TotalTarefas++;
			printf("Tarefa Adicionada!!\n\n");
		}	else {
			printf("\nLimite de tarefas atingido\n\n");
		} 
			break;
		case 2:
			if (TotalTarefas == 0){
				printf("\nNenhuma tarefa foi adicionada!\n\n");
			}else{
				for (int i = 0; i < TotalTarefas; i++){
					if (tarefas[i].concluida == 1){
					printf("\n( X ) %d - %s\n\n", i + 1, tarefas[i].texto);
				}else{
					printf("\n(   ) %d - %s\n\n", i + 1, tarefas[i].texto);
				}
				}
			}
			break;
		case 3:
			if (TotalTarefas == 0){
				printf("\nNenhuma tarefa foi adicionada!\n\n");
			}else{
				for (int i = 0; i < TotalTarefas; i++){
					printf("\n%d - %s\n", i + 1, tarefas[i].texto);
				}
				printf("\nDigite o numero da tarefa que concluiu (ou 0 para voltarao menu):\n\n");
				scanf("%d", &aux);
				if (aux == 0) break;
				if (aux >= 1 && aux <= TotalTarefas){
					tarefas[aux - 1].concluida = 1;
				}
			}
			break;
		case 4:
			if(TotalTarefas == 0){
			printf("Nenhuma tarefa para ser removida\n ");
			}else{
			for (int i = 0; i < TotalTarefas; i++){
					printf("\n%d - %s\n", i + 1, tarefas[i].texto);
				}
			}
			printf("\nQual tarefa deseja remover ? (ou 0 para voltar ao menu)\n");
			scanf ("%d", &aux);
			if(aux == 0) {
			break;
		} else if (aux >= 1 && aux <= TotalTarefas) {
			for (i = aux - 1; i < TotalTarefas - 1; i++) {
                tarefas[i] = tarefas[i + 1];
            }
			TotalTarefas--;
			printf("Tarefa %d removida com sucesso!\n\n", aux);
			}else {
            printf("Tarefa Inexistente!\n\n");
        }
			break;
		case 5:
			printf("\nEncerrando o programa\n");
			break;
		default:
			printf("opção invalida\n");
		}
		
	}while (funcoes != 5);
	
	return 0;
}

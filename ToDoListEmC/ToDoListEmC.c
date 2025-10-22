#include <stdio.h>
#include <string.h>
#define MaxTexto 100
#define MaxTarefas 100

typedef struct {
    char texto[MaxTexto];
    int concluida;
} tarefa;

int main(){
	
	tarefa tarefas[MaxTarefas];
	int TotalTarefas = 0;
	int funcoes, i, aux;
	
	
	do{
		printf ("Pressione 1 para adicionar uma tarefa\n");
		printf ("Pressione 2 para visualizar as tarefas\n");
		printf ("Pressione 3 para marcar uma tarefa como concluida\n");
		printf ("Pressione 4 para remover uma tarefa\n");
		printf ("Pressione 5 para sair\n");
		scanf("%d", &funcoes);
		getchar();
	switch (funcoes){
		
		case 1: 
			if (TotalTarefas < MaxTarefas){
			printf("Adicione uma tarefa:\n");
			fgets(tarefas[TotalTarefas].texto, MaxTexto, stdin);
			tarefas[TotalTarefas].texto[strcspn(tarefas[TotalTarefas].texto, "\n")] = '\0';
			TotalTarefas++;
			printf("Tarefa Adicionada!!\n\n");
		}	else {
			printf("Limite de tarefas atingido\n\n");
		} 
			break;
		case 2:
			if (TotalTarefas == 0){
				printf("Nenhuma tarefa foi adicionada!\n\n");
			}else{
				for (int i = 0; i < TotalTarefas; i++){
					printf("%d - %s\n", i + 1, tarefas[i].texto);
				}
			}
			break;
		case 3:
			if (TotalTarefas == 0){
				printf("Nenhuma tarefa foi adicionada!\n\n");
			}else{
				for (int i = 0; i < TotalTarefas; i++){
					printf("%d - %s\n", i + 1, tarefas[i].texto);
				}
				printf("Digite o numero correspondente a tarefa que concluiu\n\n");
				scanf("%d", &aux);
				if (aux >= 1 && aux <= TotalTarefas){
					tarefas[aux - 1].concluida = 1;
				}
			}
			break;
		case 4:
			printf("incompleto");
			break;
		case 5:
			printf("Encerrando o programa\n");
			break;
		default:
			printf("opção invalida\n");
		}
		
	}while (funcoes != 5);
	
	return 0;
}

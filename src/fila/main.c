
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define ERROR 0
#define SUCCESS 1

void limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear"); 
#endif    
}

int main()
{ 
    Fila *f= criarFila();
    if (f==NULL)
      printf("Não foi possível alocar memória");
    
    int opcao, valor, resultado;  
    do{
        limparTela();
        printf("\n1 - Enfileirar");
        printf("\n2 - Desenfileirar");
        printf("\n3 - Mostrar primeiro");
        printf("\n4 - Mostrar fila");
        printf("\n5 - Liberar fila");
        printf("\n6 - Sair");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\nDigite o valor a ser enfileirado: ");
            scanf("%d", &valor);
            resultado = enfileirar(f, valor);
            if (resultado==ERROR)
              printf("\nFila cheia, não foi possível inserir");
             else
              printf("\n%d inserido com sucesso", valor); 
            break;
        
        case 2:
            resultado=desenfileirar(f, &valor);
            if (resultado==ERROR)
              printf("\nFila vazia");
            else
              printf("\nItem %d removido", valor);
            
            break;
          
        case 3:
            resultado=obterPrimeiro(f, &valor);
            if (resultado==ERROR)
                printf("\nFila vazia");
            else
                printf("\nItem no início:  %d", valor);
        
            break;   
        
        case 4:
            mostrarFila(f);
            break;
        
        case 5:
             liberarFila(f);
             printf("\nFila liberada e recriada");
             f=criarFila();
             break;   
        case 6:
           printf("\nSaindo...");
           liberarFila(f);
           break;    
        default:
            printf("\nOpção inválida");
            break;
        }

        getchar();
        getchar();
    }while (opcao!=6);  


    return 0;
}

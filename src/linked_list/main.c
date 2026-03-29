#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif    
}

int main()
{
    List *list = create_list();
    if (list == NULL)
    {
        printf("Não foi possível alocar memória");
        exit(1);
    }

    int option, value, searched_value;
    bool result;
    do {
        clearScreen();
        printf("\n1 - Inserir no início");
        printf("\n2 - Inserir no final");
        printf("\n3 - Inserir após um elemento");
        printf("\n4 - Remover");
        printf("\n5 - Mostrar lista");
        printf("\n6 - Liberar lista");
        printf("\n7 - Sair");
        printf("\nEscolha uma opção: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nDigite o valor a ser inserido no início: ");
            scanf("%d", &value);
            result = insert_beginning(list, value);
            if (result == false)
                printf("\nErro ao inserir");
            else
                printf("\n%d inserido com sucesso no início", value);
            break;

        case 2:
            printf("\nDigite o valor a ser inserido no final: ");
            scanf("%d", &value);
            result = insert_end(list, value);
            if (result == false)
                printf("\nErro ao inserir");
            else
                printf("\n%d inserido com sucesso no final", value);
            break;

        case 3:
            printf("\nDigite o valor a ser inserido: ");
            scanf("%d", &value);
            printf("\nDigite o valor existente na lista: ");
            scanf("%d", &searched_value);
            result = insert_after(list, value, searched_value);
            if (result == false)
                printf("\nErro ao inserir. Elemento não encontrado.");
            else
                printf("\n%d inserido com sucesso após %d", value, searched_value);
            break;

        case 4:
            printf("\nDigite o valor a ser removido: ");
            scanf("%d", &value);
            result = remove_item(list, value);
            if (result == false)
                printf("\nErro ao remover. Elemento não encontrado.");
            else
                printf("\n%d removido com sucesso", value);
            break;

        case 5:
            print_list(list);
            break;

        case 6:
            free_list(list);
            printf("\nLista liberada e recriada");
            list = create_list();
            break;

        case 7:
            printf("\nSaindo...");
            free_list(list);
            break;

        default:
            printf("\nOpção inválida");
            break;
        }
        getchar();
        getchar();
    } while (option != 7);

    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char *lista = (char *) malloc(sizeof(char)*30);
    int contador=1;
    int opcao;
    lista[0] = '\0';
    while(1)
    {
        printf("Digite a opcao desejada\n");
        printf("1 - Para adicionar nome\n");
        printf("2 - Para remover nome\n");
        printf("3 - Para listar nome(s)\n");
        printf("4 - Para sair\n");
        scanf("%d",&opcao);
        switch (opcao)
        {
        case 1:
            printf("Adicionar nome\n");
            adicionar(lista, &contador);
            break;
        case 2:
            printf("Remover nome\n");
            //remover(lista, &contador);
            break;
        case 3:
            listar(lista);
            break;
        case 4:
            printf("Sair\n");
            printf("Limpando memoria\n");
            free(lista);
            return 0;
            break;
        default:
            printf("erro\n");
            break;
        }
    }
    return 0;
}
void adicionar(char *lista, int *contador)
{
    char *aux;
    printf("Digite o nome para adicionar: ");
    getchar();
    fgets(aux,30,stdin);
    strcat(lista,aux);
    contador++;
    lista = realloc(lista,(*contador+1)*sizeof(char)*30);
    if(!lista)
    {
        printf("ERRO MEMORIA\n");
        return ;
    }
    printf("Nome salvo\n");
}
/*void remover(char *lista, int *contador)
{
    int i,j,contador,posicao;
    printf("Digite o numero correspondente ao nome:")
    scanf("%d",&posicao);
    while(lista[i]!='\0')
    {
        for(j=0;j<strlen(lista);j++)
        {
            if(lista[j]=='\n') contador++;
            if(contador==posicao)
            {
                
            }
        }
    }

}*/
void listar(char *lista)
{
    printf("%s",lista);
}

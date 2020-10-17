#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int padrao = 3;
void escolha(void *pBuffer);
int escolhido(void *pBuffer);
void criaLista(void *pBuffer);
void adicionar(void *pBuffer);
int lugarVago(void *pBuffer);
void remover(void *pBuffer);
void listar(void *pBuffer);
void buscar(void *pBuffer);
void controlaTamanho(void *pBuffer);

typedef struct{
    char *nome;
    char *aux;
    int opcao,i;
    int quantidade;
} pessoa;
int main()
{
    void *pBuffer = (pessoa *) malloc(sizeof(pessoa)*padrao);
    if(!pBuffer) 
    {
        printf("ERRO MEMORIA pBUFFER\n");
        return -1;
    }
    criaLista(pBuffer);
    
    while (1)
    {
        controlaTamanho(pBuffer); 
        printf("1 - Incluir pessoa\n");
        printf("2 - Apagar pessoa\n");
        printf("3 - Buscar pessoa\n");
        printf("4 - Listar pessoas\n");
        printf("5 - Sair\n");
        escolha(pBuffer);
        switch (escolhido(pBuffer))
        {
        case 1:
            printf("Adicionar\n");
            adicionar(pBuffer);
            //if(!pBuffer) 
            //{
            //    printf("ERRO MEMORIA pBUFFER\n");
            //    return -1;
            //}
            break;
        case 2:
            printf("Apagar\n");
            //remover(pBuffer);
            break;
        case 3:
            printf("Buscar\n");
            buscar(pBuffer);
            break;
        case 4:
            printf("Listar\n");
            listar(pBuffer);
            break;
        case 5:
            printf("Sair\n");
            printf("Limpando memoria\n");
            free(pBuffer);
            return 0;
            break;
        default:
            printf("ERRO");
            break;
        }
    }
    return 0;   
}
void controlaTamanho(void *pBuffer)
{
    pessoa *p;
    p = pBuffer;
    printf("*Novo tamanho %d*\n",(p->quantidade+1));
    if(p->quantidade==padrao) 
    pBuffer=(pessoa *) realloc(pBuffer,sizeof(pessoa)*((p->quantidade)+1));
    else return;
    return;
}
void escolha(void *pBuffer)
{
    pessoa *p;
    p = pBuffer;
    scanf("%d",&p->opcao);
}
int escolhido(void *pBuffer)
{
    pessoa *p;
    p = pBuffer;
    return p->opcao;
}
void criaLista(void* pBuffer)
{
	pessoa* p;
	p = pBuffer;
    (*p).quantidade=0;
    for(p->i=0;p->i < padrao; p->i++)
    {
        p[p->i].nome = malloc(sizeof(char));
		p[p->i].nome[0] = '\0';	
    }
	return;
}
void adicionar(void *pBuffer)
{   
    pessoa *p;
    p = pBuffer;
 
    printf("Digite um nome:");
    getchar();
    scanf("%s",p[lugarVago(pBuffer)].nome);
    printf("Nome salvo\n");
    
    p->quantidade+=1;
}
int lugarVago(void *pBuffer)
{
    pessoa *p;
    p = pBuffer;
    for(p->i=0; p->i <= p->quantidade; p->i++)
    {
        if(p[p->i].nome[0]=='\0') return p->i;
    }
    return -1;
}
void listar(void *pBuffer)
{
    pessoa *p;
    p=pBuffer;
    printf("Lista de nomes salvos:\n");
    for(p->i=0;p->i < p->quantidade; p->i++)
    {
        if(p[p->i].nome[0]=='\0') break;
        printf("%d - %s\n",p->i,p[p->i].nome);
    }
}
void buscar(void *pBuffer)
{
    pessoa *p;
    p = pBuffer;
    p->aux = (char *) malloc(sizeof(char));
    printf("Digite o nome para buscar: ");
    getchar();
    scanf("%s",p->aux);
    for(p->i=0; p->i <= p->quantidade; p->i++)
    {
        if(strcmp(p->aux,p[p->i].nome)==0)
        {
            printf("Nome: %s encontrado na lista\n",p->aux);
            free(p->aux);
            return;
        }
        else if(p->i==p->quantidade) printf("Nome: %s nao encontrado na lista\n",p->aux);
    }
    free(p->aux);
}
/*
void remover(void *pBuffer)
{
    printf("Digite o nome para remover: ");
}*/
#include <stdio.h>
#include <stdlib.h>
#define N 10

void troca(int *a,int *b)
{
    int aux;
    aux=*b;
    *a=*b;
    *b=aux;
}

void bubbleSort(int v[],int max)
{
    //max vale N-1
    int i, trocou=1;
    while(trocou)
    {
        trocou=0;
        for(i=0;i<max;i++)
        {
            if(v[i]>v[i+1])
            {
                troca(&v[i],&v[i+1]);
                trocou=1;
            }
        }
        max--;
    }
}

void selectionSort(int v[])
{
    int i, j, menor;
    for(j=0;j<N-1;j++)
    {
        for(i=j+1;i<N;i++)
        {
            if(v[i]<v[menor])
                menor=i;
        }
        troca(&v[i],&v[menor]);
    }
}

void insertionSort(int v[])
{
    int i,j;
    for(j=1;j<N;j++)
    {
        for(i=j;i>0&&v[i-1]>v[i];i--)
            troca(&v[i-1],&v[i]);
    }
}

int buscaSeq(int v[],int chave)
{
    int i;
    for(i=0;i<N&&chave>v[i];i++);
    if((i==N)||(chave!=v[i]))
        return (-1);//nao achou
    else
        return (i);//achou
}

int buscaBinaria(int v[],int chave)
{
    int ini,meio,fim;
    ini=0;
    fim=N-1;
    while(ini<=fim)
    {
        meio=(ini+fim)/2;
        if(chave==v[meio])
            return (meio);//achou
        if(chave<v[meio])
            fim=meio-1;
        else
            ini=meio+1;
    }
    return (-1);//não achou
}

main()
{
    int v[N], i, menuOrd, menuBusca, chave, x;

    for(i=0;i<N;i++)
    {
        printf("\nDigite um numero: \n");
        scanf("%d",&v[i]);
    }

    for(i=0;i<N;i++)
    {
        printf("Entrada %d:\t%d\n",i,v[i]);
    }

    printf("\nSelecione uma ordenacao:\n\n1 - BubbleSort\n2 - Selecao\n3 - Insercao\n\n");
    scanf("%d",&menuOrd);

    switch(menuOrd)
    {
    case 1:
        bubbleSort(v,N-1);
        break;
    case 2:
        selectionSort(v);
        break;
    case 3:
        insertionSort(v);
    }

    for(i=0;i<N;i++)
        printf("%d\n",&v[i]);

    printf("\nInforme uma chave qualquer: ");
    scanf("%d",&chave);

    printf("\nSelecione a Busca:\n\n1 - Busca Sequencial\n2 - Busca Binaria\n");
    scanf("%d",&menuBusca);

    switch(menuBusca)
    {
    case 1:
        buscaSeq(v,chave);
        break;
    case 2:
        buscaBinaria(v,chave);
        break;
    }

    if(menuBusca==1)
    {
        x=buscaSeq(v,chave);
        switch(x)
        {
        case -1:
            printf("\nA chave nao foi encontrada.\n");
            break;
        default :
            printf("\nA chave foi encontrada.\n");
        }
    }
    else
    {
        x=buscaBinaria(v,chave);
        switch(x)
        {
        case -1:
            printf("\nA chave nao foi encontrada.\n");
            break;
        default :
            printf("\nA chave foi encontrada.\n");
        }
    }
}

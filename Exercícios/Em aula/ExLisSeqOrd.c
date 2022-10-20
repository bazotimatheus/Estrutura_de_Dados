#include <stdio.h>
#include <stdlib.h>

#define TAM 10

struct tno{
	char nome[50];
	int cdi;
	char tipo;
	int idade;
	int telefone;
};

struct tlista{
	int qtnos;
	struct tno lista[TAM];
};

void inicializa(struct tlista *pl)
{
	pl->qtnos=0;
}

int lista_vazia(struct tlista *pl)
{
	if(pl->qtnos==0)
		return(1);
	return(0);
}

int lista_cheia(struct tlista *pl)
{
	if(pl->qtnos==TAM)
		return(1);
	return(0);
}

void percurso(struct tlista *pl)
{
	int i;
	for(i=0;i<pl->qtnos;i++)
	{
		printf("%s\t", pl->lista[i].nome);
		printf("%d\t", pl->lista[i].cdi);
		printf("%c\t", pl->lista[i].tipo);
		printf("%d\t", pl->lista[i].idade);
		printf("%d\t", pl->lista[i].telefone);
	}
}

int buscaSeq(struct tlista *pl, int *pos)
{
	int i, x;

	printf("\n Digite o CDI que deseja buscar: ");
	scanf("%d", &x);

	for(i=0;i<pl->qtnos&&x>pl->lista[i].cdi;i++);
	*pos=i;
	if((i==pl->qtnos)||(x!=pl->lista[i].cdi))
		return(0);
	return(1);
}

int buscaBinaria(struct tlista *pl)
{
	int x, ini, fim, meio;
        
	printf("\n Digite o CDI que deseja buscar: ");
        scanf("%d", &x);
	
	ini=0;
	fim=pl->qtnos-1;
	while(ini<=fim)
	{
		meio=(ini+fim)/2;
		if(x==pl->lista[meio].cdi)
			return(meio);
		if(x<pl->lista[meio].cdi)
			fim=meio-1;
		else
			ini=meio+1;
	}
	return(-1);
}

int insereOrd(struct tlista *pl)
{
	int i, posicao;
	
	char nome[50];
	int cdi;
	char tipo;
	int idade;
	int telefone;

	if(lista_cheia(pl))
		return(0);
	
	printf("\n Insira o nome do cliente: ");
	scanf("%s", &nome);
	printf("\n Insira o cdi do cliente: ");
	scanf("%d", &cdi);
	printf("\n Insira o tipo preferido de leitura (C - Ciencia, R - Romance, F - Ficcao, O - Outros) do cliente: ");
	scanf("%c", &tipo);
	printf("\n Insira a idade do cliente: ");
	scanf("%d", &idade);
	printf("\n Insira o telefone do cliente: ");
	scanf("%d", &telefone);
	if(buscaSeq(pl,cdi,&posicao)
		return(-1);
	for(i=pl->qtnos;i>posicao;i--)
	{
		pl->lista[i].nome=pl->lista[i-1].nome;
		pl->lista[i].cdi=pl->lista[i-1].cdi;
		pl->lista[i].tipo=pl->lista[i-1].tipo;
		pl->lista[i].idade=pl->lista[i-1].idade;
		pl->lista[i].telefone=pl->lista[i-1].telefone;
	}
	pl->lista[posicao].nome=nome;
	pl->lista[posicao].cdi=cdi;
	pl->lista[posicao].tipo=tipo;
	pl->lista[posicao].idade=idade;
	pl->lista[posicao].telefone=telefone;
	pl->qtnos++;
	return(1);
}

int removeOrd(struct tlista *pl)
{
	int i, posicao, cdi;

	if(lista_vazia(pl))
		return(0);

	printf("\n Digite o CDI do usuario que deseja remover: ");
	scanf("%d", &cdi);

	if(!buscaSeq(pl,cdi,&posicao))
		return(-1);
	for(i=posicao;i<pl->qtnos-1;i++)
	{
		pl->lista[i].nome=pl->lista[i+1].nome;
		pl->lista[i].cdi=pl->lista[i+1].cdi;
		pl->lista[i].tipo=pl->lista[i+1].tipo;
		pl->lista[i].idade=pl->lista[i+1].idade;
		pl->lista[i].telefone=pl->lista[i+1].telefone;
	}
	pl->qtnos--;
	return(1);
}

int main()
{
    struct tlista pl;
    int menu, pos;

    inicializa(&pl);

    do{
        printf("\n 1 - Lista de dados;\n 2 - Buscar codigo da lista;\n 3 - Remover um cliente da lista;\n 4 - Finalizar.\n");
        scanf("%d", &menu);
        switch(menu)
        {
        case 1:
	    insereOrd(&pl);
	    if(insereOrd(&pl)==0)
		printf("\n Lista cheia.\n");
            break;
        case 2:
            if(buscaBinaria(&pl)==-1)
	    	printf("\n O usuario nao foi encontrado.");
	    else
		pos=buscaBinaria(&pl);
		printf("\n O usuario foi encontrado na posicao %d.", pos);
            break;
        case 3:
            removeOrd(&pl);
	    if(removeOrd(&pl)==0)
		printf("\n Lista vazia.\n");
            break;
        case 4:
            printf("\n Finalizando o programa.\n");
            break;
        }
    }while(menu!=4);
}

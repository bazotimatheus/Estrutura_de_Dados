#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int info;
    struct lista *prox;
};

struct lista *crialsec(int n)
{
	struct lista *p, *ini, *aux;
	int i, valor;
	ini=NULL;
	for(i=0;i<n;i++)
	{
		printf("\n Digite um valor: ");
		scanf("%d", &valor);
		p=(struct lista *)malloc(sizeof(struct lista));
		p->info=valor;
		if(ini==NULL)
		{
			p->prox=p;
			ini=p;
		}
		else{
			p->prox=ini;
			aux->prox=p;
		}
		aux=p;
	}
	return(p);
}

void escreveLsec(struct lista *p)
{
	struct lista *q;
	if(!p)
	{
		printf("\n A lista esta vazia!");
		return;
	}
	else{
		q=p->prox;
		while(q!=p)
		{
			printf("%d\t",q->info);
			q=q->prox;
		}
		if(q==p)
			printf("%d\t",q->info);
	}
}

struct lista *insereFrente(struct lista *p, int valor)
{
	struct lista *q;
	q=(struct lista *)malloc(sizeof(struct lista));
	q->info=valor;
	if(!p)
	{
		q->prox=p;
		return(q);
	}
	if(p->prox==p)
	{
		q->prox=p->prox;
		p->prox=q;
	}
	else{
		q->prox=p->prox;
		p->prox=q;
		return(p);
	}
}

struct lista *removeelemento(struct lista *p, int elem)
{
    struct lista *q;
    if(!p)
    {
        printf("\n A lista esta vazia.\n");
        return(NULL);
    }
    else{
        if(p->info!=elem)
        {
            q=p;
            p=p->prox;
        }
        q->prox=p->prox;
        free(p);
        return(q);
    }
}

struct lista *busca(struct lista *p, int valor)
{
    struct lista *q;
    q=p;
    if(!p)
    {
        printf("\n A lista esta vazia.\n");
        return(NULL);
    }
    while(valor!=q->info)
        q=q->prox;
    return(q);
}

int contaNos(struct lista *p)
{
	struct lista *q;
	int cont;
	if(!p)
		return(0);
	else{
		cont=1;
		q=p->prox;
		while(q!=p)
		{
			cont++;
			q=q->prox;
		}
		return(cont);
	}
}

int main()
{
    struct lista *p;
    int menu, n, x;

    printf("\n Informe a quantidade de nos: ");
    scanf("%d", &n);

    crialsec(n);

    do
    {
        printf("\n 1- Imprimir a lista;\n 2- Inserir um no apos o ultimo no da lista;\n 3- Remover um elemento da lista;\n 4- Buscar um no na lista;\n 5- Contar os nos da lista;\n 6- Sair.\n OPCAO: ");
        scanf("%d", &menu);

        switch(menu)
        {
        case 1:
            escreveLsec(p);
            break;
        case 2:
            printf("\n Insira o valor a ser inserido: ");
            scanf("%d", &x);

            insereFrente(p,x);
            break;
        case 3:
            printf("\n Insira o valor a ser removido: ");
            scanf("%d", &x);

            removeelemento(p,x);
            break;
        case 4:
            printf("\n Insira o valor a ser buscado: ");
            scanf("%d", &x);

            busca(p,x);
            break;
        case 5:
            printf("\n A lista possui %d nos.\n",contaNos(p));
            break;
        case 6:
            printf("\n Finalizando o programa.\n");
            break;
        default:
            printf("\n Opcao invalida. Tente novamente.\n");
            break;
        }
    }while(menu!=6);
}

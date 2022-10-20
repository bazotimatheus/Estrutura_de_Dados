#include<stdio.h>
#include<stdlib.h>

struct lista{
	int info;
	struct lista *prox;
};

struct lista *cria_lista(int n)
{
	struct lista *ini, *ult, *p;
	int i, valor;
	ini=ult=NULL;
	for(i=1;i<=n;i++)
	{
		printf("\nInforme um valor: ");
		scanf("%d", &valor);
		p=(struct lista *)malloc(sizeof(struct lista));
		p->info=valor;
		p->prox=NULL;
		if(ult)
			ult->prox=p;
		else
			ini=p;
		ult=p;
	}
	return(ini);
}

int conta_nos(struct lista *p)
{
	int cont;
	if(!p)
		return(0);
	else{
		cont=0;
		while(p)
		{	cont++;
			p=p->prox
		}
		return(cont);
	}
}

struct lista *busca(struct lista *p, int valor)
{
	struct lista *q;
	q=p;
	while(q!=NULL&&valor!=q->info)
		q=q->prox;
	return(q);
}

struct lista *insere_Ord(struct lista *p, int valor)
{
	struct lista *q, *t, *r;
	q=(struct lista *)malloc(sizeof(struct lista));
	q->info=valor;
	if(!p)
	{
		q->prox=NULL;
		return(q);
	}
	else{
		r=p;
		while(p&&valor>p->info)
		{
			t=p;
			p=p->prox;
		}
		if(!p)
		{
			t->prox=q;
			q->prox=NULL;
			return(r);
		}
		if(valor<p->info)
		{
			q->prox=p;
			if(r!=p)
			{
				t->prox=q;
				return(r);
			}
			return(q);
		}
	}
}

struct lista *remove_Ord(struct lista *p, int valor)
{
	struct lista *q, *t;
	if(!p)
		return(p);
	else{
		if(busca(p,valor)==NULL)
		{	
			printf("\nElemento nao existe na lista.\n");
			return(p);
		}
		else{
			q=p;
			while(q->info<valor)
			{
				t=q;
				q=q->prox;
			}
			if(p!=q)
				t->prox=q->prox;
			else
				p=p->prox;
			free(q);
			return(p);
		}
	}
}

void escreve_lista(struct lista *p)
{
	if(!p)// (p==NULL)
		return;
	else{
		while(p)
		{
			printf("%d\t", p->info);
			p=p->prox;
		}
	}
}

int main()
{
	struct lista *p;
	int menu;
	
	do{
		printf("\n\n 1- Inserir no na lista;\n 2- Buscar no na lista;\n 3- Remover um no da lista;\n 4- Imprimir a lista.\n 5- Sair.\n");
		scanf("%d", &menu);
		switch(menu)
		{
			case 1:
				
				break;
			case 2:
				
				break;
			case 3:
				
				break;
			case 4:
				
				break;
			case 5:
				printf("\nSaindo.\n");
				break;
			default:
				printf("\nOpcao invalida, tente novamente.\n");
				break;
		}
	}while(menu!=5);
}

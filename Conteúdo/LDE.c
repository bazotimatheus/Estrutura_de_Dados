// Listas Duplamente Encadeadas
#include<stdio.h>
#include<stdlib.h>


//Considere:
struct dupla{
	struct dupla *eprox;
	int info;
	struct dupla *dprox;
};

//Fun��o para criar uma LDE com n n�s:
struct dupla *criaLDE(int n)
{
	struct dupla *p, *ini, *ult;
	int i, valor;
	ult=NULL;
	for(i=1;i<=n;i++)
	{
		printf("\nInforme o valor: ");
		scanf("%d", &valor);
		p=(struct dupla *)malloc(sizeof(struct dupla));
		p->info=valor;
		p->eprox=NULL;
		p->dpros=NULL;
		if(ult)
		{
			ult->dprox=p;
			p->eprox=ult;
		}
		else{
			ini=p;
		}
		ult=p;
	}
	return(ini);
}

//Fun��o para escrever a lista:
void escreveLDE(struct dupla *p)
{
	while(p)
	{
		printf("%d\t", p->info);
		p=p->dprox;
	}
	printf("\n\n");
}

//Funcao para contar os nos da LDE:
int contaNos(struct dupla *p)
{
	if(!p)
		return(0);
	else{
		cont=1;
		while(p->dprox)
		{
			p=p->dprox;
			cont++;
		}
	return(cont);
	}
}

//Fun��o para inserir um n� no final da LDE. Retornar ponteiro para a lista resultante:
struct dupla *insereFinal(struct dupla *p, int valor)
{
	struct dupla *q, *t;
	q=(struct dupla *)malloc(sizeof(struct dupla));
	q->eprox=NULL;
	q->info=valor;
	q->dprox=NULL;
	if(!p)
		return(q);
	if(!p->dprox)
	{
		p->dprox=q;
		q->eprox=p;
		return(p);
	}
	else{
		t=p;
		while(t->dprox)
			t=t->dprox;
		t->dprox=q;
		q->eprox=t;
		return(p);
	}
}

//Fun��o para remover o k-�simo n� de uma LDE. Retornar ponteiro para a lista resultante:
struct dupla *removek(struct dupla *p, int k)
{
	struct dupla *q, *t;
	int cont;
	if(k==1)
	{
		if(!p->dprox)
		{
			free(p);
			return(NULL);
		}
		else{
			q=p->dprox;
			q->eprox=NULL;
			free(q);
			return(q);
		}
	}
	else{
		t=p;
		cont=1;
		while(cont!=k)
		{

		}
}

//Fun��o para dividir uma LDE em duas listas
struct dupla *divide(struct dupla *p)
{
	struct dupla *q, *t;
	q=p;
	while(q->dprox);
		q=q->dprox;
	t=q->eprox;
	if(t!=NULL)
	{
		t->dprox=NULL;
		q->eprox=NULL;
	}
	else
		q=NULL;
	return(q);
}

//Fun��o para inserir um n� apontado por p ap�s o n� apontade por x, onde x aponta para algum n� na LDE
void insere(struct dupla *p, struct dupla *x)
{
	if(x->dprox!=NULL)
		x->prox->eprox=p;
	p->dprox=x->dprox;
	p->eprox=x;
	x->dprox=p;
}

//Escreva uma fun��o para remover um n� apontado por x de uma LDE n�o vazia, onde l aponta para o in�cio da lista (n�o usar vari�vel auxiliar). Retornar ponteiro para a lista resultante.
struct dupla *removeNo(struct dupla *l,struct dupla *x)
{
	if(!x->eprox)
	{
		l=l->dprox;
		l->eprox=NULL
	}
	if(!x->dprox)
		x->eprox->dprox=NULL;
	else{
		x->eprox->dprox=x->dprox;
		x->dprox->eprox=x->eprox;
	}
	free(x);
	return(l);
}

//Resolu��o da professora
struct dupla *removeNo(struct dupla *l,struct dupla *x)
{
	if(l==x)
	{	
		if(l->dprox==NULL)
			l=NULL;
		else{
			l=l->dprox;
			l->eprox=NULL;
		}
	}
	else{
		if(!x->dprox)
			x->eprox->dprox=NULL;
		else{
			x->eprox->dprox=x->dprox;
			x->dprox->eprox=x->eprox;
		}
	}
	free(x);
	return(l);
}

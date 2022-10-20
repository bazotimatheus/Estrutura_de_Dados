// Listas Simplesmente Encadeadas

struct lista
{
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

struct lista *inserirFinal(struct lista *p, int valor)
{
	struct lista *q, *t;
	q=(struct lista *)malloc(sizeof(struct lista));
	q->info=valor;
	q->prox=NULL;
	if(!p)
		return(q);
	else{
		t=p;
		while(!t->prox)// (t->prox!=NULL)
			t=t->prox;
		t->prox=q;
		return(p);
	}
}

struct lista *insereApos(struct lista *p, int valor)
{
	struct lista *q, *t;
	q=(struct lista *)malloc(sizeof(struct lista));
	q->info=valor;
	if(p->prox==NULL)
	{
		p->prox=q;
		q->prox=NULL;
		return(p);
	}
	else{
		t=p->prox;
		p->prox=q;
		q->prox=t;
		return(p);
	}
}

struct lista *removeFrente(struct lista *p)
{
	struct lista *q;
	q=p->prox;
	free(p);
	return(q);
}

struct lista *removek(struct lista *p, int k)
{
	struct lista *q, *t;
	int cont;
	if(k==1)
	{
		if(p->prox==NULL)
		{
			free(p);
			return(NULL);
		}
		else{
			q=p;
			p=p->prox;
			free(q);
			return(p);
		}
	}
	else{
		q=p;
		cont=1;
		while(cont!=k)
		{
			t=q;
			q=q->prox;
			cont++;
		}
		t->prox=q->prox;
		free(q);
		return(p);
	}
}

struct lista *concatenalistas(struct lista *x, struct lista *y)
{
	struct lista *q;
	if(x==NULL)
		return(y);
	else{
		q=x;
		while(q->prox)//q->prox!=NULL
			q=q->prox;
		q->prox=y;
		return(x);
	}
}

struct lista *insereAposk(struct lista *p, int k, int valor)
{
	struct lista *q, *t;
	int cont;
	q=(struct lista *)malloc(sizeof(struct lista));
	q->info=valor;
	if(k==1)
	{
		if(!p->prox)//p->prox==NULL
		{
			p->prox=q;
			q->prox=NULL;
			return(p);
		}
		else{
			q->prox=p->prox;
			p->prox=q;
			return(p)
		}
	}
	else{
		cont=1;
		t=p;
		while(cont!=k)
		{
			t=t->prox;
			cont++;
		}
		q->prox=t->prox;
		t->prox=q;
		return(p);
	}
}

struct lista *copia(struct lista *p)
{
	struct lista *nl, *l, *aux, *ant;
	nl=NULL;
	l=p;
	while(l!=NULL)
	{
		aux=(struct lista *)malloc(sizeof(struct lista));
		aux->info=l->info;
		aux->prox=NULL;
		if(nl==NULL)
			nl=aux;
		else
			ant->prox=aux;
		ant=aux;
		l=l->prox;
	}
	return(nl);
}

struct lista *divide_lista(struct lista *p)
{
	struct lista *q, *t;
	q=p;
	while(q->prox)//q->prox!=NULL
	{
		t=q;
		q=q->prox;
	}
	t->prox=NULL;
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

struct lista *busca(struct lista *p, int valor)
{
	struct lista *q;
	q=p;
	while(q!=NULL&&valor!=q->info)
		q=q->prox;
	return(q);
}


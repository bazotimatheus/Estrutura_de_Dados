// Listas Simplesmente Encadeadas Circulares

struct lista *crialsec(int n)
{
	struct lista *p, *ini, *aux;
	int i, valor;
	ini=NULL;
	for(i=0;i<=n;i++)
	{
		printf("\nDigite um valor: ");
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
		printf("\nLista Vazia!");
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
		return(q);
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

struct lista *removeUltimo(struct lista *p)
{
	struct lista *q;
	if(!p)
		return(NULL);
	if(p->prox==p)
	{
		free(p);
		return(NULL);
	}
	else{
		q=p->prox;
		while(q->prox!=p)
			q=q->prox;
		q->prox=p->prox;
		free(p);
		return(q);
	}
}

struct lista *removek(struct lista *p, int k)
{
	struct lista *q, *t;
	int cont;
	if(k==1)
	{
		if(p->prox==p)
		{
			free(p);
			return(NULL);
		}
		else{
			q=p->prox;
			p->prox=q->prox;
			free(q);
			return(p);
		}
	}
	else{
		q=p->prox;
		cont=1;
		while(cont!=k)
		{
			t=q;
			q=q->prox;
			cont++;
		}
		t->prox=q->prox;
		if(q!=p)
		{
			free(q);
			return(p);
		}
		else{
			free(q);
			return(t);
		}
	}
}

struct lista *concatenaLsec(struct lista *l1, struct lista *l2)
{
     struct lista *q;
     if(!l1)
       return(l2);
	if(!l2)
        return(l1);
	else{
		q=l1->prox;
		l1->prox=l2->prox;
		l2->prox=q;
		return(l2);
	}
}


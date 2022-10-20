//Considere:
struct tree{
	struct tree *esq;
	int chave;
	struct tree *dir;
};


//Percurso
void inorder(struct tree *raiz)
{
	if(raiz!=NULL)
	{
		inorder(raiz->esq);
		printf("%d\t",raiz->chave);
		inorder(raiz->dir);
	}
}

void preorder(struct tree *raiz)
{
	if(raiz!=NULL)
	{
		printf("%d\t",raiz->chave);
		preorder(raiz->esq);
		preorder(raiz->dir);
	}
}

void postorder(struct tree *raiz)
{
	if(raiz!=NULL)
	{
		postorder(raiz->esq);
		postorder(raiz->dir);
		printf("%d\t",raiz->chave);
	}	
}


//Conta nós
int contaNos(struct tree *raiz)
{
	if(raiz==NULL)
		return(0);
	return(1+contaNos(raiz->esq)+contaNos(raiz->dir));
}


//Conta folhas
int contaFolha(struct tree *raiz)
{
	if(raiz==NULL)
		return(0);
	if(raiz->esq==NULL&&raiz->dir==NULL)
		return(1);
	return(contaFolha(raiz->esq)+contaFolha(raiz->dir));
}


//Conta pais
int contaPais(struct tree *raiz);
{
	if(raiz==NULL)
		return(0);
	if(raiz->esq==NULL&&raiz->dir==NULL)
		return(0);
	return(1+contaPais(raiz->esq)+contaPais(raiz->dir));
}


//Altura de uma Árvore
int altura(struct tree *raiz)
{
	int e, d;
	if(raiz==NULL)
		return(0);
	
}


//Considere:
#define TRUE 1
#define FALSE 0

//Busca não recursiva
struct tree *busca(struct tree *raiz, int x)
{
	int nao_achei=TRUE;
	while(raiz&&nao_achei)
	{
		if(x==raiz->chave)
			nao_achei=FALSE;
		else{
			if(x<raiz->chave)
				raiz=raiz->esq;
			else
				raiz=raiz->dir;
		}
	}
	if(nao_achei)
		return(NULL);//não achou
	else
		return(raiz);//achou
}

//Busca recursiva
struct tree *buscaRec(struct tree *raiz, int x)
{
	if(raiz)
	{
		if(x==raiz->chave)
			return(raiz);
		if(x<raiz->chave)
			return(buscaRec(raiz->esq,x));
		if(x>raiz->chave)
			return(buscaRec(raiz->dir,x));
	}
}

//Inserção(a chave a ser inserida ficará sempre em uma folha)
struct tree *insereABB(struct tree *raiz, int x)
{
	struct tree *p, *q;
	int achou;
	p=(struct tree *)malloc(sizeof(struct tree));
	p->chave=x;
	p->esq=p->dir=NULL;
	if(!raiz)
		raiz=p;
	else{
		achou=FALSE;
		q=raiz;
		while(!achou)
		{
			if(x<q->chave)
			{
				if(q->esq==NULL)
				{
					q->esq=p;
					achou=TRUE;
				}
				else
					q=q->esq;
			}
			else{
				if(q->dir==NULL)
				{
					q->dir=p;
					achou=TRUE;
				}
				else
					q=q->dir;
			}
		}
	}
	return(raiz);
}

//Inserção Recursiva
struct tree *insereRec(struct tree *raiz, int x)
{
	struct tree *p;
}

//Remoção
struct tree *remover(struct tree *raiz, int x)

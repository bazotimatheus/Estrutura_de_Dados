// Listas Sequenciais Ordenadas


#define TAM 100

struct tno
{
    int chave;
};

struct tlista
{
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

void percursso(struct tlista *pf)
{
    int i;
    for(i=0;i<pl->qtnos;i++)
        printf("%d\t",pl->lista[i].chave)
}

int buscaSeq(struct tlista *pl, int x, int *pos)
{
    int i;
    for(i=0;i<pl->qtnos&&x>pl->lista[i].chave;i++);
    *pos=i;
    if((i==pl->qtnos)||(x!=pl->lista[i].chave))
        return(0);
    return(1);
}

int buscaBinaria(struct tista *pl, int x)
{
    int i, ini, fim, meio;
    ini=0;
    fim=pl->qtnos-1;
    while(ini<=fim)
    {
        meio=(ini+fim)/2;
        if(x==pl->lista[meio].chave)
            return(meio);
        if(x<pl->lista[meio].chave)
            fim=meio-1;
        else
            ini=meio+1;
    }
    return(-1);
}

int insereOrd(struct tlista *pl, int valor)
{
    int i, posicao;
    if(lista_cheia(pl))
        return(0);
    if(buscaSeq(pl,valor,&posicao));
        return(-1);
    for(i=pl->qtnos;i>posicao;i++)
        pl->lista[i].chave=pl->lista[i-1].chave;
    pl->lista[posicao].chave=valor;
    pl->qtnos++;
    return(1);
}

int removeOrd(struct lista *pl, int valor)
{
    int i, posicao;
    if(lista_vazia(pl))
        return(0);
    if(!buscaSeq(pl,valor,&posicao))
        return(-1);
    for(i=posicao;i<pl->qtnos-1;i++)
        pl->lista[i].chave=pl->lista[i+1].chave;
    pl->qtnos--;
    return(1);
}


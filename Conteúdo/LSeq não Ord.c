// Listas Sequenciais não Ordenadas

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

int busca(struct tlista *pl, int x)
{
    int i;
    for(i=0;i<pl->qtnos;i++)
    {
        if(x==pl->lista[i].chave)
            return(i);
    }
    return(-1);
}

int inserecomrepeticao(struct tlista *pl, int valor)
{
    if(lista_cheia(pl))
        return(-1);
    pl->lista[pl->qtnos].chave=valor;
    pl->qtnos++;
    return(1);
}

int inseresemrepeticao(struct tlista *pl, int valor)
{
    int i;
    if(lista_cheia(pl))
        return(-1);
    i=busca(pl,valor);
    if(i>=0)
        return(0);
    pl->lista[pl->qtnos].chave=valor;
    pl->qtnos++;
    return(1);
}

int remove_lista(struct tlista *pl, int valor)
{
    int i, y;
    if(lista_vazia(pl))
        return(-1);
    i=busca(pl,valor);
    if(i<0)
        return(0);
    pl->qtnos--;
    y=pl->lista[pl->qtnos].chave;
    pl->lista[i].chave=pl->lista[pl->qtnos].chave;
    return(y);
}


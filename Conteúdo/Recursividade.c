	Existem duas formas de escrever num programa:
		
		1- Iterativamente
		2- Recursivamente
		
	Uma função é dita recursiva quando é definida em termos de si mesma, isto é, uma função que faz uma chamada a si mesma.
	Recursão é uma técnica matemática.
	
	Ex: 1. Números naturais
	
	-0 é um número natural;
	-O sucessor de um número natural é um número natural;
	
	2. Estruturas de árvores
	
	3. Fatorial	{	
					0!=1
					n!=n*(n-1)!
				}
				
	4. Sequência de Fibonacci
	
	
	*Quando uma função se chama, novos parâmetros e variáveis são alocados em uma *pilha* e o código é executado com novas variáveis;
	
	*Muitas funções recursivas não minimizam a utilização de memória;
	
	*Uma das vantagens da recursão é gerar versões mais claras e simples de algoritmos;
	
	*É importante que o algoritmo recursivo não gere uma sequência infinita de chamadas a si mesmo.
	
	Ex.1: Fatorial
	
	- Iterativo
	
		int fatorial(int n)
		{
			int i, fat=1;
			for(i=n;i>=1;i--)
				fat=fat*i;
			return(fat);
		}
		
	- Recursivo
	Lembrar: 	0! = 1
			n! = n*(n-1)!
			
			int fatorial(int n)
			{
				if(n==0)//condição de parada
					return(1);
				return(n*fatorial(n-1));
			}
			
	Chamada: z=fatorial(6)
		
			6*fatorial(5)
			->	5*fatorial(4)
				->	4*fatorial(3)
					->	3*fatorial(2)
						->	2*fatorial(1)
							->	1*fatorial(0)
							
			1*fatorial(0)=1
			2*fatorial(1)=2*1=2
			3*fatorial(2)=3*2*1=6
			4*fatorial(3)=4*3*2*1=24
			5*fatorial(4)=5*4*3*2*1=120
			6*fatorial(5)=6*5*4*3*2*1=720
			
	Ex.2: Sequência de Fibonacci	(0,1,1,2,3,5,8,13,21,...)
	
	- Iterativo:
		
		int fibo(int n)
		{
			int x,y,z,i;
			i=1;
			x=0;
			y=1;
			while(i<n)
			{	
				z=x+y;
				x=y;
				y=z;
				i++;
			}
			return(x);
		}
		
	- Recursivo:
	Lembrar: 	F1=0
			F2=1
			Fn=F(n-1)+F(n-2),n>2
			
		int fibo(int n)
		{
			if(n==1)
				return(0);
			if(n==2)
				return(1);
			if(n>2)
				return(fibo(n-1)+fibo(n-2));
		}
		
	Chamada(6);
	
	fibo(6)
	->	fibo(5)+fibo(4)
		
	Abre fibo(5)
		->	fibo(4)+fibo(3)
	
	Abre fibo(4)
		->fibo(3)+fibo(2)
		
	Abre fibo(3)
		->fibo(2)+fibo(1)=1+0=1
		
		Agora retorna
			->fibo(4)=fibo(3)+fibo(2)=1+1=2
		
			Agora retorna
				->fibo(5)=fibo(4)+fibo(3)=2+1=3
				
	Retorna tudo e abre fibo(4)
		->	fibo(4)=fibo(3)+fibo(2)=2
			-> fibo(3)=fibo(2)+fibo(1)=1+0=1
			
=========================================================================================================================
	
	1- Função recursiva para calcular o produto entre dois números inteiros a>=0 e b>=0:
		Lembrar:	a*b = 	{
							0, se b=0
							a+soma(a,b-1), se b>0
						}
	
		int produto(int a, int b)
		{
			if(b==0)
				return(0);
			return(a+produto(a,b-1));
		}
		
		Chamada: z=produto(7,3)
		
		produto(7,3)
		->	7+produto(7,2)
			->	7+produto(7,1)
				->	7+produto(7,0)
					->	7+7+7+0=21
					
	
	2- Função recursiva para calcular o valor da potência (b>=0):
		Lembrar:	a^b = 	{
							1, se b=0
							a*produto(a,b-1),b>0
						}
						
		int potencia(int a, int b)
		{
			if(b==0)
				return(1);
			return(a*potencia(a,b-1));
		}
		
		Chamada: z=potencia(3,3)
		
		potencia(3,3)
		->	3*potencia(3,2)
			->	3*potencia(3,1)
				->	3*potencia(3,0)
					->	3*3*3*1 = 27
					
	3- Função recursiva que recebe dois números inteiros (a>=0 e b>=0) e calcula o valor da divisão inteira entre eles:
		
		int divisao(int a, int b)
		{
			if(b>a)
				return(0);
			return(1+divisao(a-b,b);
		}
		
		Chamada: z=divisao(7,3)
		
		divisao(7,3)
		->	1+divisao(4,3)
			->	1+divisao(1,3)
				->	1+1+0 = 2
		
	4- Função recursiva que recebe dois números inteiros (a>=0 e b>=0) e calculo o resto da divisão inteira:
	
		int resto(int a, int b)
		{
			if(b>a)
				return(a);
			return(resto(a-b,b));
		}

	5- Função recursiva que recebe uma string e conta quantos caracteres a string possui:
	
		int contaCar(char str[], int pos)
		{
			if(str[pos]=='\0')
				return(pos);
			return(contaCar(str,pos+1));
		}
		
	6- Função recursiva que recebe uma string e conta quantos caracteres maiúsculos a string possui:
	
		int contaMai(char str[], int pos)
		{
			if(str[pos]=='\0')
				return(0);
			if(str[pos]>='A'&&str[pos]<='Z')
				return(1+contaMai(str,pos+1));
			return(0+contaMai(str,pos+1));
		}
		
	7- Função recursiva para somar os elementos de um vetor de inteiros de tamanho n:
	
		int somaElem(int v[], int n)
		{
			if(n==0)
				return(0);
			return(v[n-1]+somaElem(v,n-1));
		}
		
	8- Escreva uma versão recursiva das funções abaixo:
		
		a-	int busca(int v[], int n, int chave)
			{
				int i;
				for(i=0;i<n;n++)
				{	
					if(chave==v[i])
						return(i);
				}
				return(-1);
			}
			
			
			int buscaRec(int v[], int n, int chave, int i)
			{
				if(i<n)
				{
					if(chave=v[i])
						return(i);
					return(buscaRec(v,n,chave,i+1));
				}
				return(-1);
			}
			
			
			
		b-	int buscaBin(int v[], int ini, int fim, int chave)
			{
				int meio;
				while(ini<=fim)
				{
					meio=(ini+fim)/2;
					if(chave==v[meio])
						return(meio);
					if(chave<v[meio])
						fim=meio-1;
					else
						ini=meio+1;
				}
				return(-1);
			}
			
			
			int buscaBinRec(int v[], int ini, int fim, int chave)
			{
				int meio;
				if(ini>fim)
					return(-1);
				meio=(ini+fim)/2;
				if(chave==v[meio])
					return(meio);
				if(chave<v[meio])
					return(buscaBinRec(v,ini,meio-1,chave));
				else
					return(buscaBinRec(v,meio+1,fim,chave));
			}
			
			
			
			

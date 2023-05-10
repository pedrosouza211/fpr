#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int funcaoCont(char nomeArq[20], int caracter);

void main()
{
	int resposta, cont = 0;
	char nomeArq[20], c;
	
	printf("Digite o nome do arquivo:");
	fflush(stdin);
	gets(nomeArq);
	
	printf("Digite o caracter");
	scanf("%c", &c);
	
	
	cont = funcaoCont(nomeArq, c);
	
	 if (cont==-1)
	 {
		printf("Erro na abertura do arquivo.");
	 }
	else
	{
		printf("Total de vezes q o caracter aparece :%d", cont);
		
	}
	
}

int funcaoCont(char nomeArq[20], int caracter)
{
	
	FILE *arq;
	int cont;
	char c;
	
	
	arq = fopen(nomeArq, "r");
	
	 if(arq==NULL)
	{
		return -1;
	}
	else
	{
		while(fscanf(arq, "%c", &c) != EOF)
	   {
		if (c==caracter)
		{
			cont++;
		}
	   }
		
		
		 fclose(arq);
		
		 return cont;
	}
	
}

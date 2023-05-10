#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int contCaracteresC(char nomeArq[20]);

void main()
{
	int resposta, cont = 0;
	char nomeArq[20];
	
	printf("Digite o nome do arquivo:");
	fflush(stdin);
	gets(nomeArq);
	
	cont = contCaracteresC(nomeArq);
	
	 if (cont==-1)
	 {
		printf("Erro na abertura do arquivo.");
	 }
	else
	{
		printf("Total de caracteres (Letras) do arquivo: %d", cont);
	}
	
	
}

int contCaracteresC(char nomeArq[20])
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
		    if(toupper(c) >= 'A' &&  toupper(c) <= 'Z')
                {
                    cont++;
                }
	   }
		
		 fclose(arq);
		
		 return cont;
	}
	
}



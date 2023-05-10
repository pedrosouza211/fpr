
//exemplo 3: Lendo os elementos de um arquivo, sabendo que os numeros estão dspostos um por linha.

#include <stdio.h>

int LerArquivo(char nomeArq[]);

void main()
{
	
	char nomeArq[20];
	
	printf("Digite o nome do arquivo:");
	gets(nomeArq);
	
	
	//chamando funcao
	if(LerArquivo(nomeArq)==0)
	{
		printf("\nerro na abertura do arquivo");
		
	}
	
	
}

int LerArquivo(char nomeArq[])
{
	FILE *arq;
	int numero;
	
	//abertura do arquivo para leitura!
	
	arq = fopen(nomeArq, "r"); // r = read = leitura
	
	if(arq==NULL)
	{
		return 0;
		
	}
	else
	{
		//lendo os valores do arquivo enquanto existirem
		
		while(	fscanf(arq, "%d\n", &num) != EOF)
		{
			printf("%d\n", numero);
		}
		
		
		fclose(arq);
		
		return 1;
		
		
	}
	
}






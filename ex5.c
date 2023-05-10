#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
int buscarMaiorElemento (char nomeArq[], float limite, float *maior);
int Ex5(char ArqO[], char ArqD[]);
void main()
{
	
	char nomeArq[20], arqDestino[20];
	
	
	printf("Digite o nome do arquivo:");
	gets(nomeArq);
	
	printf("Entre com o nome do novo arquivo : ");
	gets(arqDestino);
	
		if (Ex5(nomeArq, arqDestino)==0)
	{
		printf("\nerro na abertura do arquivo");
	}
	else
	{
		printf("\nArquivo %s  gerado com sucesso!", arqDestino);
	}
	
	
}
int Ex5(char ArqO[], char ArqD[])
{
	
	FILE *arqOrigem, *arqDestino;
	int num;
	float ultimo = FLT_MAX, valor;
	
	//abertura dos arquivos 
	
	arqDestino = fopen(ArqD, "w");    
	
	if((arqOrigem== NULL || arqDestino== NULL))
	{
		return 0;
		
	}
	else
	{
		
	//buscando no arquivo original o maior elemento que seja inferior
		//ao último inserido no novo arquivo
		while (buscarMaiorElemento (ArqO, ultimo, &valor) != -1)
		{
			//inserindo no novo arquivo o elemento encontrado
			fprintf (arqDestino, "%.2f\n", valor);
			
			//atualizando o 'ultimo'
			ultimo = valor;
		}
		
		//fechando o novo arquivo
		fclose (arqDestino);
		
		return 1;
			
		}
	}
	
 int buscarMaiorElemento (char nomeArq[], float limite, float *maior)
{
	//declaração de arquivos
	FILE *arq;
	float ma = FLT_MIN, numero;
	int mudou = 0;
	
	//abrindo o arquivo
	arq = fopen (nomeArq, "r");
	
	//houve erro?
	if (!arq)
	{
		return -1;
	}
	else
	{
		//lendo os valores do arquivo
		while (fscanf (arq, "%f", &numero) != EOF)
		{
			//verificando se o número lido é menor do que o limite
			if ((numero < limite) &&
			    (numero > ma)) //e se é maior do que 'ma'
			{
				ma = numero;  //atualizando o maior número
				mudou = 1;
			}
		}
		
		//fechando o arquivo
		fclose (arq);
		
		//retornando...
		if (mudou == 1)
		{
			*maior = ma;
			return 1;
		}
		else
		{
			return -1;
		}
	}
}
	
	
	
	
	
	
	


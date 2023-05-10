// Exemplo 5: copiando o conteúdo de um arquivo para outro!


#include <stdio.h>

int CopiarArquivo(char origem[], char destino[]);

void main()
{
	
	char arqOrigem[20], arqDestino[20];
	
	printf("Entre com o nome do arquivo a ser copiado: ");
	gets(arqOrigem);
	
	printf("Entre com o nome do novo arquivo a : ");
	gets(arqDestino);
	
	if (CopiarArquivo(arqOrigem, arqDestino)==0)
	{
		printf("\nerro na abertura do arquivo");
	}
	else
	{
		printf("\nArquivo %s gerado com sucesso!", arqDestino);
	}

	
}

int CopiarArquivo(char ArqO[], char ArqD[])
{
	FILE *O, *D;
	char c;
	
	//abertura dos arquivos 
	
	O = fopen(ArqO, "r");  // r = read = leitura || w = write = escrever || o = oppened
	D = fopen(ArqD, "w");    
	
	//testando se teve erro na abertura de um dos arquivos(ou dois)
	if((O== NULL || D== NULL))
	{
		return 0;
		
	}
	else
	{
		//lendo os valores do arquivo origem existirem
		
		while(fscanf(O, "%c", &c) != EOF)
		{
			fprintf(D, "%c", c);
		}
		
		//fechar os arquivos
		fclose(O);
		fclose(D);
		
		return 1;
		
	}
	
}



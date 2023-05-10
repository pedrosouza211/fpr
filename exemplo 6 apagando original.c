//Exemplo 6: Remover todas as ocorrencias de um numero em um arquivo.

// ao final, apagar o arquivo original e renomear o temp para o original.
 
#include <stdio.h>

int removerNumero(char nomeArq[], int numero);

void main()
{
	
	char nomeArq[20];
	int valor;
	
	printf("Entre com o nome do arquivo");
	gets(nomeArq);
	
	printf("Entre com o valor");
	scanf("%d", &valor);
	
	//chamando função
	
	switch (removerNumero(nomeArq, valor))
	{
		case -1: printf("\erro na abertura do arquivo!");
		         break;
		         
	    case 0: printf("Numero não existe no arquivo");
	    break;
	    
	    default: printf("Remocao realizada com sucesso!");
	}
	
	
}

int removerNumero(char nomeArq[], int numero)
{
	
	//declaracao de variaveis
	
	FILE *arq, *temp;
	int num, cont=0;
	
	//abertura dos arquivos 
	
	arq = fopen(nomeArq, "r");  // r = read = leitura || w = write = escrever || o = oppened
	temp= fopen("temp.txt", "w");  
	
	  
	
	//testando se teve erro na abertura de um dos arquivos(ou dois)
	if((arq== NULL || temp== NULL))
	{
		remove ("temp.txt");
		return 0;
		
	}
	else
	{
		//lendo os valores do arquivo origem, enquanto existirem
		//e jogando no temporario apenas os valores diferentes de 'numero'
		
		while(fscanf(arq, "%d\n", &num) != EOF)
		{
			
			if(num!=numero)
			{
				fprintf(temp, "%d\n", num);
			}
			else
			{
				cont++;
			}
			
		}
		
		//fechar os arquivos

		fclose(arq);
		fclose(temp);
		

		//removendo o arquivo original
		remove(nomeArq);
		//renomenado o arquivo temporario para o original
		rename("temp.txt", nomeArq);
		
		return cont;
		
		
	}
	
}

	

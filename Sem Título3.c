

/* Arquivos: fazer um programa que crie um aquivo com os numeros de 1 a N ,
 um por linha.

*/

#include <stdio.h>

//main

void main()
{
	
	//declaracao de variaves
	
	FILE *arq;
	char nomeArq[20];
	int i, N;
	
	//lendo nome do arquivo
	printf("Entre com o nome do arquivo:");
	gets(nomeArq);
	
	//lendo o valor de N
	 printf("Entre com o valor de N:");
	 scanf("%d", &N);
	 
	 //abertura do arquivo(para escrita)
	 
	 arq = fopen (nomeArq, "w");
	
	//testando se o aruivo foi ou não aberto
	
	if(arq==NULL)
	{
		printf("Erro na abertura do arquivo");
	}
	else
	{
		
		//variando os numero de 1 a n para serem armazenados no arquivo
    	for(i=1;i<=N;i++)
	    {
		
		  fprintf(arq, "%d\n", i);
		
	    }
	
	    //fechar o arquivo
	   fclose (arq);
	}
	

}




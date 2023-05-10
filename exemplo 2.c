

/* Arquivos: fazer uma função que crie um aquivo com os numeros de 1 a N ,
 um por linha.

*/

#include <stdio.h>

//declaracao de funçoes

int criarArquivo(char nomeArq[], int N);
//main


void main()
{
	
	//declaracao de variaves
	
	char nomeArq[20];
	int N;
	
	//lendo nome do arquivo
	printf("Entre com o nome do arquivo:");
	gets(nomeArq);
	
	//lendo o valor de N
	 printf("Entre com o valor de N:");
	 scanf("%d", &N);
	 
	 //chamando função
	 if(criarArquivo(nomeArq, N)==0)
	 {
	 		printf("Erro na abertura do arquivo");
	 }
	 else
	 {
	 	printf("Arquivo gerado com sucesso");
	 }
	 

}
int criarArquivo(char nomeArq[], int N)
{
	
	FILE *arq;
	int i;
	
	 //abertura do arquivo(para escrita)
	 
	 arq = fopen (nomeArq, "w");
	
	//testando se o aruivo foi ou não aberto
	
	if(arq==NULL)
	{
		return 0;
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
	   return 1;
	}
	
	
	
}



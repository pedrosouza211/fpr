#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FALSE 0
#define TRUE 1

int funcaoVerificaordenados(char nomeArq[20]);

void main()
{
    int resposta, cont = 0;
    char nomeArq[20];
    
    printf("Digite o nome do arquivo:");
    fflush(stdin);
    gets(nomeArq);
    
     if (funcaoVerificaordenados(nomeArq) == -1)
     {
        printf("Erro na abertura do arquivo.");
     }
     else
     {
         if(funcaoVerificaordenados(nomeArq)==FALSE)
         {
             printf("Arquivo não ordenado");
         }
         else
         {
             if(funcaoVerificaordenados(nomeArq)==TRUE)
             {
                 printf("Arquivo esta ordenado\n");
             }
         }
     }

    
}


int funcaoVerificaordenados(char nomeArq[20])
{
    
    FILE *arq;
    int num, anterior;
    
    
    arq = fopen(nomeArq, "r");
    
     if(arq==NULL)
    {
        return -1;
    }
    else
    {
        fscanf(arq, "%d", &anterior);
        

        while(fscanf(arq, "%d", &num) != EOF)
       {
        
        if (num < anterior)
        {
            return FALSE;
            fclose(arq);
        
        }
        else
        {
            anterior = num;
        }
       }
         fclose(arq);
        
         return TRUE;
    }
    
}

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "Arquivo.h"
#include "Grafo.h"

///###################################################################
///####################### CARREGANDO COM MENU #######################
///###################################################################
void Carrega_Arquivo(){

    char nome_arquivo[100];
    int opcao = -1;

    printf("Escolha uma das opcoes de Grado:");
    printf("\n\n1 - Grafo ponderado");
    printf("\n0 - Grafo nao ponderado\n");

    while(opcao < 0 || opcao > 1)
    {
        scanf("%d",&opcao);
        setbuf(stdin, NULL);
    }

    printf("\n\nDigite o nome do arquivo completo...\n");

    scanf("%s", nome_arquivo);
    setbuf(stdin, NULL);



    printf("\n\nCarregando arquivo %s...\n", nome_arquivo);

    FILE *arquivo = Abre_Arquivo(nome_arquivo);

    if (arquivo == NULL)
     {
         printf("Erro ao carregar o arquivo!");
         return;
     }

    printf("Arquivo aberto...\n");

    Grafo *grafo = Cria_Novo_Grafo(opcao);

    printf("Grafo criado...\n");

    int total_vertice_arquivo = 0;

    fscanf(arquivo, "%d", &total_vertice_arquivo);
    printf("Total de vertices do arquivo: %d\n", total_vertice_arquivo);


    if(grafo->eh_ponderado)
    {
        int id1, id2, peso;
        int retorno;
        while (!feof(arquivo))
        {
            retorno = fscanf(arquivo, "%d %d %d", &id1, &id2,&peso);
            if (retorno != -1)
            {
                printf("Inserindo aresta entre %d e %d = Peso %d\n", id1, id2, peso);
                Popula_Grafo(grafo, id1, id2, peso);
            }
        }

    }
    else
    {
        int id1, id2,peso = 0;
        int retorno;
        while (!feof(arquivo))
        {
            retorno = fscanf(arquivo, "%d %d", &id1, &id2);
            if (retorno != -1)
            {
                printf("Inserindo aresta entre %d e %d = Peso %d\n", id1, id2, peso);
                Popula_Grafo(grafo, id1, id2, peso);
            }
        }



    }



    Fecha_Arquivo(arquivo);

    printf("Grafo populado com sucesso!\n");
    printf("Total de vertices cadastrados: %d\n", grafo->Numero_Vertice);
    printf("Total de arestas cadastradas: %d\n", grafo->Numero_Aresta);
}




///###################################################################
///####################### CARREGANDO SEM MENU #######################
///###################################################################

Grafo *Carrega_Arquivo_Sem_Menu(int opcao, char *nome_arquivo)
{

    printf("\n\nCarregando arquivo %s...\n",nome_arquivo);

    FILE *arquivo = Abre_Arquivo(nome_arquivo);

    if (arquivo == NULL)
     {
         printf("Erro ao carregar o arquivo!");
         return 0;
     }

    printf("Arquivo aberto...\n");

    Grafo *novo_grafo = Cria_Novo_Grafo(opcao);

    printf("Grafo criado...\n");

    int total_vertice_arquivo = 0;

    fscanf(arquivo, "%d", &total_vertice_arquivo);
    printf("Total de vertices do arquivo: %d\n", total_vertice_arquivo);


    if(novo_grafo->eh_ponderado)
    {
        int id1, id2, peso;
        int retorno;
        while (!feof(arquivo))
        {
            retorno = fscanf(arquivo, "%d %d %d", &id1, &id2,&peso);
            if (retorno != -1)
            {
                printf("Inserindo aresta entre %d e %d = Peso %d\n", id1, id2, peso);
                Popula_Grafo(novo_grafo, id1, id2, peso);
            }
        }
    }
    else
    {
        int id1, id2,peso = 0;
        int retorno;
        while (!feof(arquivo))
        {
            retorno = fscanf(arquivo, "%d %d", &id1, &id2);
            if (retorno != -1)
            {
                printf("Inserindo aresta entre %d e %d = Peso %d\n", id1, id2, peso);
                Popula_Grafo(novo_grafo, id1, id2, peso);
            }
        }
    }



    Fecha_Arquivo(arquivo);

    printf("Grafo populado com sucesso!\n");
    printf("Total de vertices cadastrados: %d\n", novo_grafo->Numero_Vertice);
    printf("Total de arestas cadastradas: %d\n\n\n\n", novo_grafo->Numero_Aresta);


    return novo_grafo;

}


int main()
{

        //Carrega_Arquivo();

        char arq_grafo_ponderado[100] = "grafoPonderado.txt";
        char arq_grafo[100] = "grafo.txt";

        Grafo *grafo = Carrega_Arquivo_Sem_Menu(1,arq_grafo_ponderado);
        Grafo *grafoPonderado = Carrega_Arquivo_Sem_Menu(0,arq_grafo);









    return 0;
}

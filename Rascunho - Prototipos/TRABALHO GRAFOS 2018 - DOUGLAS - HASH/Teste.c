#include "Arquivo.h"
#include "Grafo.h"

void teste1()
{
    FILE *arquivo = Abre_Arquivo("instance_1.txt");

    Imprime_Arquivo(arquivo);

    Fecha_Arquivo(arquivo);
}

void teste2()
{
    FILE *arquivo = Cria_Arquivo("teste.txt");

    Escreve_Linha(arquivo, "abc");
    Escreve_Linha(arquivo, "123");

    Fecha_Arquivo(arquivo);
}

void teste3()
{
    Grafo *g = Cria_Novo_Grafo();
    Vertice *v1, *v2, *v3;

    v1 = Cria_Novo_Vertice(1);
    v2 = Cria_Novo_Vertice(2);
    v3 = Cria_Novo_Vertice(3);

    Insere_Vertice(g, v1);
    Insere_Vertice(g, v2);
    Insere_Vertice(g, v3);

    Imprime_Todos_Vertices(g);
}


void teste4(char *nome_arquivo)
{
    FILE *arquivo = Abre_Arquivo(nome_arquivo);

    if (arquivo == NULL)
        return;

    printf("Arquivo aberto...\n");

    Grafo *grafo = Cria_Novo_Grafo();

    printf("Grafo criado... ordem do grafo: %d\n", Retorna_Ordem_Grafo(grafo));

    int total_vertice_arquivo = 0;

    fscanf(arquivo, "%d", &total_vertice_arquivo);

    printf("Total de vertices do arquivo: %d\n", total_vertice_arquivo);

    int id1, id2, peso = 0;
    int retorno;
    while (!feof(arquivo))
    {
        retorno = fscanf(arquivo, "%d %d", &id1, &id2);
        if (retorno != -1)
        {
            printf("Inserindo aresta entre %d e %d\n", id1, id2);
            Popula_Grafo(grafo, id1, id2, peso);
        }
    }

    printf("Grafo populado com sucesso!\n");
    printf("Total de vertices cadastrados: %d\n", grafo->Numero_Vertice);
    printf("Total de arestas cadastradas: %d\n", grafo->Numero_Aresta);
    printf("Imprimindo grafo lido...\n\n");

    Imprime_Todos_Vertices(grafo);

    Imprime_Todas_Arestas(grafo);

    Libera_Grafo(grafo);
}

void teste5(char *nome_arquivo)
{
    FILE *arquivo = Abre_Arquivo(nome_arquivo);

    if (arquivo == NULL)
        return;

    printf("Arquivo aberto...\n");

    Grafo *grafo = Cria_Novo_Grafo();

    printf("Grafo criado\n...");

    int total_vertice_arquivo = 0;

    fscanf(arquivo, "%d", &total_vertice_arquivo);
    printf("Total de vertices do arquivo: %d\n", total_vertice_arquivo);

    printf("\nTrabalhando com hash...\n");

    Aloca_Array_Hash(grafo, total_vertice_arquivo);

    int id1, id2, peso = 0;
    int retorno;
    while (!feof(arquivo))
    {
        retorno = fscanf(arquivo, "%d %d", &id1, &id2);
        if (retorno != -1)
        {
            printf("Inserindo aresta entre %d e %d\n", id1, id2);
            Popula_Grafo(grafo, id1, id2, peso);
        }
    }

    printf("Grafo populado com sucesso!\n");
    printf("Total de vertices cadastrados: %d\n", grafo->Numero_Vertice);
    printf("Total de arestas cadastradas: %d\n", grafo->Numero_Aresta);
    printf("Imprimindo grafo lido...\n\n");

    Imprime_Todos_Vertices(grafo);

    Imprime_Todas_Arestas(grafo);

    printf("\n\nImprimindo hash...\n\n");
    Imprime_Lista_Hash(grafo);

    Libera_Grafo(grafo);

}


























#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"


///#############################
///CRIANDO AS ESTRUTURAS
///#############################
Grafo *Cria_Novo_Grafo(int ehPonderado){

    Grafo *novo_grafo = (Grafo*) malloc(sizeof(Grafo));

    novo_grafo->Numero_Vertice = 0;
    novo_grafo->Numero_Aresta = 0;
    novo_grafo->eh_ponderado = ehPonderado;
    novo_grafo->Primeiro_Vertice = NULL;

    return novo_grafo;
}
Vertice *Cria_Novo_Vertice(int Id){
    Vertice *novo_vertice = (Vertice*) malloc(sizeof(Vertice));

    novo_vertice->Id = Id;
    novo_vertice->Grau_Vertice = 0;

    novo_vertice->Primeira_Aresta = NULL;
    novo_vertice->Proximo_Vertice = NULL;

    return novo_vertice;
}
Aresta *Cria_Nova_Aresta(int Peso, int Id_Vertice){
    Aresta *nova_aresta = (Aresta*) malloc(sizeof(Aresta));

    nova_aresta->Peso = Peso;
    nova_aresta->Id_Vertice = Id_Vertice;

    nova_aresta->Proxima_Aresta = NULL;

    return nova_aresta;
}


GrafoMatriz *Cria_Novo_Grafo_Matriz(int ehPonderado,int ordem){

    GrafoMatriz *novo_grafo = (Grafo*) malloc(sizeof(Grafo));

    novo_grafo->coluna = ordem;
    novo_grafo->linha = ordem;
    novo_grafo->Matriz =(int*) malloc(sizeof col*lin (int))
    novo_grafo->eh_ponderado = ehPonderado;


    return novo_grafo;
}

///#############################
///MANIPULANDO AS ESTRUTURAS
///#############################

void Insere_Vertice(Grafo *grafo, Vertice *vertice){
    if (grafo == NULL)
    {
        printf("\n\nErro ao inserir o vertice\n\n");
        return;
    }


    if (grafo->Primeiro_Vertice == NULL)
    {//se o grafo for vazio, basta inserir no primeiro vertice
        grafo->Primeiro_Vertice = vertice;
    }
    else
    {//se o grafo não for vazio, inserir na primeira posição do grafo
        vertice->Proximo_Vertice = grafo->Primeiro_Vertice;
        grafo->Primeiro_Vertice = vertice;
    }

    grafo->Numero_Vertice++;

}
void Insere_Aresta(Vertice *vertice, int Id_Vertice, int Peso_Aresta){
    Aresta *aresta = Cria_Nova_Aresta(Peso_Aresta, Id_Vertice);

    if (vertice->Primeira_Aresta == NULL)
    {
        vertice->Primeira_Aresta = aresta;
    }
    else
    {
        aresta->Proxima_Aresta = vertice->Primeira_Aresta;
        vertice->Primeira_Aresta = aresta;
    }

    vertice->Grau_Vertice++;
}
void Popula_Grafo(Grafo *grafo, int Id1, int Id2, int Peso){
    Vertice *vertice1, *vertice2;
    Aresta *aresta_Id1_para_Id2, *aresta_Id2_para_Id1;

    vertice1 = Busca_Vertice(grafo, Id1);

    if (vertice1 == NULL)
    {
        vertice1 = Cria_Novo_Vertice(Id1);
        Insere_Vertice(grafo, vertice1);
    }

    vertice2 = Busca_Vertice(grafo, Id2);

    if (vertice2 == NULL)
    {
        vertice2 = Cria_Novo_Vertice(Id2);
        Insere_Vertice(grafo, vertice2);
    }

    aresta_Id1_para_Id2 = Busca_Aresta(vertice1, Id2);

    if (aresta_Id1_para_Id2 == NULL)
        Insere_Aresta(vertice1, Id2, Peso);

    aresta_Id2_para_Id1 = Busca_Aresta(vertice2, Id1);

    if (aresta_Id2_para_Id1 == NULL)
        Insere_Aresta(vertice2, Id1, Peso);

    grafo->Numero_Aresta++;
}


Vertice *Busca_Vertice_Pela_Lista_Adjacencia(Grafo *grafo, int Id){
    Vertice *v = grafo->Primeiro_Vertice;

    if (v->Id == Id)
        return v;

    while (v->Proximo_Vertice != NULL)
    {
        v = v->Proximo_Vertice;

        if (v->Id == Id)
            return v;
    }

    return NULL;
}
Vertice *Busca_Vertice(Grafo *grafo, int Id){
    //verifica se o grafo é NULL ou vazio
    if (grafo == NULL || grafo->Numero_Vertice == 0)
    {
        return NULL;
    }

    return Busca_Vertice_Pela_Lista_Adjacencia(grafo, Id);
}
Aresta *Busca_Aresta(Vertice *vertice, int Id_Vertice){
    if (vertice == NULL || vertice->Primeira_Aresta == NULL)
        return NULL;

    for (Aresta *aresta_auxiliar = vertice->Primeira_Aresta; aresta_auxiliar != NULL; aresta_auxiliar = aresta_auxiliar->Proxima_Aresta)
    {
        if (aresta_auxiliar->Id_Vertice == Id_Vertice)
            return aresta_auxiliar;
    }

    return NULL;
}


void Imprime_Todos_Vertices(Grafo *grafo){
    if (grafo == NULL)
    {
        printf("Gravo nulo");
        return;
    }

    if (grafo->Primeiro_Vertice == NULL)
    {
        printf("Gravo sem vértices");
        return;
    }

    for (Vertice *v = grafo->Primeiro_Vertice; v != NULL; v = v->Proximo_Vertice)
        printf("%d\n", v->Id);
}
void Imprime_Todas_Arestas(Grafo *grafo){
    if (grafo == NULL)
    {
        printf("Grafo nulo\n");
        return;
    }

     if (grafo->Primeiro_Vertice == NULL)
    {
        printf("Gravo sem vértices");
        return;
    }

    for (Vertice *v = grafo->Primeiro_Vertice; v != NULL; v = v->Proximo_Vertice)
    {
        printf("Vertice %d: ", v->Id);

        if (v->Primeira_Aresta == NULL)
        {
            printf("sem vertice");
        }
        else
        {
            for (Aresta *a = v->Primeira_Aresta; a != NULL; a = a->Proxima_Aresta)
                printf("%d ", a->Id_Vertice);
        }

        printf("\n");
    }
}
void Imprime_Grafo(Grafo *grafo)
{
    if (grafo == NULL)
    {
        printf("Grafo nulo\n");
        return;
    }

     if (grafo->Primeiro_Vertice == NULL)
    {
        printf("Gravo sem vértices");
        return;
    }
    printf("\n\n############# IMPRIMINDO GRAFO #############\n\n");
    printf("[V]\t[ARESTA]\n");

    if(grafo->eh_ponderado)
    {
        for (Vertice *v = grafo->Primeiro_Vertice; v != NULL; v = v->Proximo_Vertice)
        {
            printf("[%d] | ", v->Id);

            if (v->Primeira_Aresta == NULL)
            {
                printf("");
            }
            else
            {
                for (Aresta *a = v->Primeira_Aresta; a != NULL; a = a->Proxima_Aresta)
                    printf("[%d (P%d)] -> ", a->Id_Vertice,a->Peso);
            }
            printf("|\n");

        }
    }
    else
    {
        for (Vertice *v = grafo->Primeiro_Vertice; v != NULL; v = v->Proximo_Vertice)
        {
            printf("[%d] | ", v->Id);

            if (v->Primeira_Aresta == NULL)
            {
                printf("");
            }
            else
            {
                for (Aresta *a = v->Primeira_Aresta; a != NULL; a = a->Proxima_Aresta)
                    printf("%d ->", a->Id_Vertice);
            }
            printf("|\n");

        }
    }
}

void Exclui_Aresta(Vertice *vertice, int Id){
    if (vertice->Primeira_Aresta == NULL)
        return;

    Aresta *aux = NULL;

    for (Aresta *aresta = vertice->Primeira_Aresta; aresta != NULL; aresta = aresta->Proxima_Aresta)
    {
        if (aresta->Id_Vertice == Id)
        {
            if (aux == NULL)
                vertice->Primeira_Aresta = aresta->Proxima_Aresta;
            else
                aux->Proxima_Aresta = aresta->Proxima_Aresta;

            free(aresta);
            break;          // Após terminar a exclusão, não é necessário continuar no laço
        }
        else
        {
            aux = aresta;
        }
    }

    vertice->Grau_Vertice--;
}
void Excluir_Todas_Aresta_Vertice(Grafo *grafo, Vertice *vertice){
    if (vertice == NULL || vertice->Primeira_Aresta == NULL)
        return;

    Exclui_Aresta(Busca_Vertice(grafo, vertice->Primeira_Aresta->Id_Vertice), vertice->Id);
    Exclui_Aresta(vertice, vertice->Primeira_Aresta->Id_Vertice);

    Excluir_Todas_Aresta_Vertice(grafo, vertice);
}
void Exclui_Vertice(Grafo *grafo, int Id){
    if (grafo == NULL || grafo->Primeiro_Vertice == NULL)
        return;

    Vertice *aux = NULL;

    for(Vertice *vertice = grafo->Primeiro_Vertice; vertice != NULL; vertice = vertice->Proximo_Vertice)
    {
        if (vertice->Id == Id)
        {

            //Exclui todas as arestas antes de remover o vertice do grafo
            Excluir_Todas_Aresta_Vertice(grafo, vertice);

            if (aux == NULL)
                grafo->Primeiro_Vertice = vertice->Proximo_Vertice;
            else
                aux->Proximo_Vertice = vertice->Proximo_Vertice;

            free(vertice);
            break;          // Após terminar a exclusão, não é necessário continuar no laço
        }
        else
        {
            aux = vertice;
        }
    }
}


void Libera_Grafo(Grafo *grafo){
    if (grafo == NULL)
        return;

    if (grafo->Primeiro_Vertice != NULL)
        Libera_Lista_Verice(grafo->Primeiro_Vertice);



    free(grafo);
}
void Libera_Lista_Arestas(Aresta *aresta){
    if (aresta == NULL)
        return;

    Libera_Lista_Arestas(aresta->Proxima_Aresta);
    free(aresta);
}
void Libera_Lista_Verice(Vertice *vertice){
    if (vertice == NULL)
        return;

    Libera_Lista_Verice(vertice->Proximo_Vertice);
    Libera_Lista_Arestas(vertice->Primeira_Aresta);
    free(vertice);
}

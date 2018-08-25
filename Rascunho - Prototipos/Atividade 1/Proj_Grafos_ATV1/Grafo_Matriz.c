#include <stdio.h>
#include <stdlib.h>
#include "Grafo_Matriz.h"


//#############################
//CRIANDO AS ESTRUTURAS
//#############################

GrafoMatriz *Cria_Novo_Grafo_Matriz(int ehPonderado,int quantidadeVertices){

    GrafoMatriz *novo_grafo = (GrafoMatriz*) malloc(sizeof(GrafoMatriz));



    novo_grafo->Numero_Vertice = 0;
    novo_grafo->Numero_Aresta = 0;
    novo_grafo->eh_ponderado = ehPonderado;

//    CRIANDO UM VETOR DE VERTICES
    novo_grafo->vertice = (int*)malloc(quantidadeVertices*sizeof(int));

    for(int j=0;j<quantidadeVertices;j++)
        novo_grafo->vertice[j] = -1;


//    ALOCANDO ESPAÇO PARA AS LINHAS
    novo_grafo->Matriz = (int**) malloc(quantidadeVertices*sizeof(int*));
//    ALOCANDO ESPAÇO PARA AS COLUNAS
    for(int i = 0; i < quantidadeVertices; i++)
        novo_grafo->Matriz[i] = (int*) malloc(quantidadeVertices*sizeof(int));


    for(int j=0;j<quantidadeVertices;j++)
    {
        for(int k=0;k<quantidadeVertices;k++)
            novo_grafo->Matriz[j][k]=0;
    }

    return novo_grafo;
}

///#############################
///MANIPULANDO AS ESTRUTURAS
///#############################

int busca_Vertice_Matriz(GrafoMatriz *grafo,int id)
{
    for(int i=0;i<grafo->Numero_Vertice;i++)
    {
        if(grafo->vertice[i]==id)
        {
            return i;
        }
    }

    return -1;
}


void Insere_Vertice_Matriz(GrafoMatriz *grafo, int vertice){
    if (grafo == NULL)
    {
        printf("\n\nErro ao inserir o vertice\n\n");
        return;
    }

    if (grafo->Numero_Vertice == 0)
    {//se o grafo for vazio, basta inserir no primeiro vertice
        grafo->vertice[0] = vertice;
        grafo->Numero_Vertice++;
    }
    else
    {
        int pos = busca_Vertice_Matriz(grafo,vertice);

        if(pos == -1)
        {
            grafo->vertice[grafo->Numero_Vertice] = vertice;
            grafo->Numero_Vertice++;
        }
    }



}


void Insere_Aresta_Matriz(GrafoMatriz *grafo, int id1,int id2, int Peso_Aresta){

    int pos_id1 = busca_Vertice_Matriz(grafo,id1);
    int pos_id2 = busca_Vertice_Matriz(grafo,id2);

    if((pos_id1== -1) || (pos_id2 ==-1))
    {
         printf("\nNao foi possivel adicionar esta aresta!");
            return 0;
    }

    if(grafo->eh_ponderado)
    {
        grafo->Matriz[pos_id1][pos_id2] = Peso_Aresta;
        grafo->Matriz[pos_id2][pos_id1] = Peso_Aresta;
    }
    else
    {
        grafo->Matriz[pos_id1][pos_id2] = 1;
        grafo->Matriz[pos_id2][pos_id1] = 1;
    }
    grafo->Numero_Aresta++;


}


void Imprime_Grafo_Matriz(GrafoMatriz *grafo){
    if (grafo == NULL)
    {
        printf("Grafo nulo\n");
        return;
    }

     if (grafo->vertice[0] == -1)
    {
        printf("Gravo sem vértices");
        return;
    }
    printf("\n\n############# IMPRIMINDO GRAFO #############\n\n");
    printf("[Vertice]X[Vertice]\n");

        printf("| X ");
        for(int i = 0;i<grafo->Numero_Vertice;i++)
            printf("| %d  ",grafo->vertice[i]);

            printf("|\n");
        for(int j=0;j<grafo->Numero_Vertice;j++)
        {
            printf("| %d |",grafo->vertice[j]);

            for(int k =0;k<grafo->Numero_Vertice;k++)
            {
                if(grafo->Matriz[j][k]<10)
                printf("  %d |",grafo->Matriz[j][k]);
                else
                printf(" %d |",grafo->Matriz[j][k]);

            }

            printf("\n");
        }



}


//
//void Exclui_Aresta(Vertice *vertice, int Id){
//    if (vertice->Primeira_Aresta == NULL)
//        return;
//
//    Aresta *aux = NULL;
//
//    for (Aresta *aresta = vertice->Primeira_Aresta; aresta != NULL; aresta = aresta->Proxima_Aresta)
//    {
//        if (aresta->Id_Vertice == Id)
//        {
//            if (aux == NULL)
//                vertice->Primeira_Aresta = aresta->Proxima_Aresta;
//            else
//                aux->Proxima_Aresta = aresta->Proxima_Aresta;
//
//            free(aresta);
//            break;          // Após terminar a exclusão, não é necessário continuar no laço
//        }
//        else
//        {
//            aux = aresta;
//        }
//    }
//
//    vertice->Grau_Vertice--;
//}
//void Excluir_Todas_Aresta_Vertice(Grafo *grafo, Vertice *vertice){
//    if (vertice == NULL || vertice->Primeira_Aresta == NULL)
//        return;
//
//    Exclui_Aresta(Busca_Vertice(grafo, vertice->Primeira_Aresta->Id_Vertice), vertice->Id);
//    Exclui_Aresta(vertice, vertice->Primeira_Aresta->Id_Vertice);
//
//    Excluir_Todas_Aresta_Vertice(grafo, vertice);
//}
//void Exclui_Vertice(Grafo *grafo, int Id){
//    if (grafo == NULL || grafo->Primeiro_Vertice == NULL)
//        return;
//
//    Vertice *aux = NULL;
//
//    for(Vertice *vertice = grafo->Primeiro_Vertice; vertice != NULL; vertice = vertice->Proximo_Vertice)
//    {
//        if (vertice->Id == Id)
//        {
//
//            //Exclui todas as arestas antes de remover o vertice do grafo
//            Excluir_Todas_Aresta_Vertice(grafo, vertice);
//
//            if (aux == NULL)
//                grafo->Primeiro_Vertice = vertice->Proximo_Vertice;
//            else
//                aux->Proximo_Vertice = vertice->Proximo_Vertice;
//
//            free(vertice);
//            break;          // Após terminar a exclusão, não é necessário continuar no laço
//        }
//        else
//        {
//            aux = vertice;
//        }
//    }
//}
//
//
//void Libera_Grafo(Grafo *grafo){
//    if (grafo == NULL)
//        return;
//
//    if (grafo->Primeiro_Vertice != NULL)
//        Libera_Lista_Verice(grafo->Primeiro_Vertice);
//
//
//
//    free(grafo);
//}
//void Libera_Lista_Arestas(Aresta *aresta){
//    if (aresta == NULL)
//        return;
//
//    Libera_Lista_Arestas(aresta->Proxima_Aresta);
//    free(aresta);
//}
//void Libera_Lista_Verice(Vertice *vertice){
//    if (vertice == NULL)
//        return;
//
//    Libera_Lista_Verice(vertice->Proximo_Vertice);
//    Libera_Lista_Arestas(vertice->Primeira_Aresta);
//    free(vertice);
//}

#ifndef GRAFO_MATRIZ_H_INCLUDED
#define GRAFO_MATRIZ_H_INCLUDED


///###############################################
///DEFININDO O TIPO GRAFOS
///###############################################

//typedef struct verticeM{
//    int id;
//    int Grau_Vertice;
//
//
//}VerticeMatriz;


typedef struct grafoMatriz{

    int Numero_Vertice;
    int Numero_Aresta;
    int *vertice;
    int **Matriz;
    int eh_ponderado; // [1] VERDADEIRO // [0] FALSO


}GrafoMatriz;


GrafoMatriz *Cria_Novo_Grafo_Matriz(int ehPonderado,int ordem);

void Insere_Vertice_Matriz(GrafoMatriz *grafo, int vertice);


//void Exclui_Aresta(Vertice *vertice, int Id);
//void Excluir_Todas_Aresta_Vertice(Grafo *grafo, Vertice *vertice);
//void Exclui_Vertice(Grafo *grafo, int Id);
//
//
//void Libera_Grafo(Grafo *grafo);
//void Libera_Lista_Arestas(Aresta *aresta);
//void Libera_Lista_Verice(Vertice *vertice);


#endif // GRAFO_MATRIZ_H_INCLUDED

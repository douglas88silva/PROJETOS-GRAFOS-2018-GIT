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




#endif // GRAFO_MATRIZ_H_INCLUDED

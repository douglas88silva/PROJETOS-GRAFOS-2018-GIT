#ifndef GRAFO_MATRIZ_H_INCLUDED
#define GRAFO_MATRIZ_H_INCLUDED


///###############################################
///DEFININDO O TIPO GRAFOS
///###############################################


typedef struct grafoMatriz{

    int Numero_Vertice;
    int Numero_Aresta;
    int *vertice;
    int **Matriz;
    int eh_ponderado; // [1] VERDADEIRO // [0] FALSO


}GrafoMatriz;


GrafoMatriz *Cria_Novo_Grafo_Matriz(int ehPonderado,int ordem);
//Vertice *Cria_Novo_Vertice(int Id);
//Aresta *Cria_Nova_Aresta(int Peso, int Id_Vertice);

void Insere_Vertice_Matriz(GrafoMatriz *grafo, int vertice);
//void Insere_Aresta(Vertice *vertice, int Id_Vertice, int Peso_Aresta);
//void Popula_Grafo(Grafo *grafo, int Id1, int Id2, int Peso);
//
//Vertice *Busca_Vertice_Pela_Lista_Adjacencia(Grafo *grafo, int Id);
//Vertice *Busca_Vertice(Grafo *grafo, int Id);
//Aresta *Busca_Aresta(Vertice *vertice, int Id_Vertice);
//
//void Imprime_Todos_Vertices(Grafo *grafo);
//void Imprime_Todas_Arestas(Grafo *grafo);
//void Imprime_Grafo(Grafo *grafo);
//
//void Exclui_Aresta(Vertice *vertice, int Id);
//void Excluir_Todas_Aresta_Vertice(Grafo *grafo, Vertice *vertice);
//void Exclui_Vertice(Grafo *grafo, int Id);
//
//
//void Libera_Grafo(Grafo *grafo);
//void Libera_Lista_Arestas(Aresta *aresta);
//void Libera_Lista_Verice(Vertice *vertice);


#endif // GRAFO_MATRIZ_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"
#include "Util.h"

Grafo *Cria_Novo_Grafo(){
    Grafo *novo_grafo = (Grafo*) malloc(sizeof(Grafo));

    novo_grafo->Numero_Vertice = 0;
    novo_grafo->Numero_Aresta = 0;
    novo_grafo->Primeiro_Vertice = NULL;
    novo_grafo->PONDERADO = 0;

    return novo_grafo;
}

Grafo *Cria_Novo_Grafo_Ponderado(int PONDERADO){
    Grafo *novo_grafo = (Grafo*) malloc(sizeof(Grafo));

    novo_grafo->Numero_Vertice = 0;
    novo_grafo->Numero_Aresta = 0;
    novo_grafo->Primeiro_Vertice = NULL;
    novo_grafo->PONDERADO = PONDERADO;

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

void Insere_Vertice(Grafo *grafo, Vertice *vertice){

    if (grafo == NULL)
        return;

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

Vertice *Busca_Vertice(Grafo *grafo, int Id){

    //verifica se o grafo é NULL ou vazio
    if (grafo == NULL || grafo->Numero_Vertice == 0)
    {
        return NULL;
    }

    else
        return Busca_Vertice_Pela_Lista_Adjacencia(grafo, Id);
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

int Retorna_Ordem_Grafo(Grafo *grafo){

    if (grafo == NULL)
        return -1;
    else
        return grafo->Numero_Vertice;
}

void Popula_Grafo(Grafo *grafo, int Id1, int Id2, int Peso){

    //COMO O GRAFO NAO E DIRECIONADO SEMPRE CRIO UMA ARESTA 1 PARA 2 E 2 PARA 1
    Vertice *vertice1, *vertice2;
    Aresta *aresta_Id1_para_Id2, *aresta_Id2_para_Id1;

    //VERIFICANDO SE OS VERTICES JÁ EXISTEM NO GRAFO
    vertice1 = Busca_Vertice(grafo, Id1);
    vertice2 = Busca_Vertice(grafo, Id2);

    //CASO NAO EXISTAM CRIA UM NOVO VERTICE E INSERE O MESMO NO GRAFO
    if (vertice1 == NULL)
    {
        vertice1 = Cria_Novo_Vertice(Id1);
        Insere_Vertice(grafo, vertice1);
    }

    if (vertice2 == NULL)
    {
        vertice2 = Cria_Novo_Vertice(Id2);
        Insere_Vertice(grafo, vertice2);
    }

    //VERIFICANDO A EXISTENCIA DE ARESTAS ENTRE OS VERTICES
    aresta_Id1_para_Id2 = Busca_Aresta(vertice1, Id2);
    aresta_Id2_para_Id1 = Busca_Aresta(vertice2, Id1);

    //CASO O GRAFO NÃO SEJA PONDERADO ATRIBUI PESO 0 PARA TODOAS AS ARESTAS
    if(!grafo->PONDERADO)
    {
        Peso=0;
    }

    //CASO NÃO EXISTA CRIA AS ARESTAS ENTRE ELES
    if (aresta_Id1_para_Id2 == NULL)
        Insere_Aresta(vertice1, Id2, Peso);

    if (aresta_Id2_para_Id1 == NULL)
        Insere_Aresta(vertice2, Id1, Peso);

    grafo->Numero_Aresta++;
}


//FALTA IMPLEMENTAR UM METODO DE EXCLUIR VERTICE E ARESTA PASSANDO APENAS OS GRAFOS E OS ID'S
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
            //Exclui todas o vertice do hash
            if (grafo->Trabalha_Com_Hash == 1)
                Exclui_Vertice_Hash(grafo, Id);

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

int Retorna_Grau_Vertice(Vertice *vertice){
    if (vertice == NULL)
        return -1;
    else
        return vertice->Grau_Vertice;
}

int Verificar_K_Regularidade_Grafo(Grafo *grafo, int k){


    //RETORNA "1" SE TODOS OS VERTICES TEM MESMO GRAU E "0" CASO CONTRARIO

    if (grafo == NULL || grafo->Primeiro_Vertice == NULL)
        return 0;

    for (Vertice *vertice = grafo->Primeiro_Vertice; vertice != NULL; vertice = vertice->Proximo_Vertice)
    {
        if (vertice->Grau_Vertice != k)
            return 0;
    }

    return 1;
}

int Verificar_Grafo_Trivial(Grafo *grafo){

    // GRAFO TRIVIAL E UM GRAFO SEM VERTICE
    //RETORNA "0" SE O NAO FOR VAZIO E "1" CASO CONTRARIO
    if (grafo == NULL || grafo->Numero_Vertice != 1)
        return 0;
    else
        return 1;
}

int Verificar_Grafo_Nulo(Grafo *grafo){

    //GRAFO NULO E UM GRAFO SEM ARESTA
    if (grafo == NULL || grafo->Numero_Vertice == 0)
        return 1;
    else
        return 0;
}

void Imprimir_Vizinhanca_Aberta(Vertice *vertice){

    if (vertice == NULL)
        return;

    if (vertice->Primeira_Aresta == NULL)
    {
        printf("Vertice %d sem vizinhanca\n", vertice->Id);
        return;
    }

    printf("Vizinhanca aberta de %d...\n", vertice->Id);

    for (Aresta *aresta = vertice->Primeira_Aresta; aresta != NULL; aresta = aresta->Proxima_Aresta)
        printf("%d\n", aresta->Id_Vertice);

}

void Imprimir_Vizinhanca_Fechada(Vertice *vertice){

    if (vertice == NULL)
        return;

    if (vertice->Primeira_Aresta == NULL)
    {
        printf("Vertice %d sem vizinhanca\n", vertice->Id);
        return;
    }

    Imprimir_Vizinhanca_Aberta(vertice);

    printf("%d\n", vertice->Id);

}

int Verificar_Grafo_Completo(Grafo *grafo){
    if (Verificar_Grafo_Nulo(grafo) == 1 || Verificar_Grafo_Trivial(grafo) == 1)
        return 1;
    else
        return Verificar_K_Regularidade_Grafo(grafo, grafo->Numero_Vertice - 1);
}


void Libera_Grafo(Grafo *grafo){

    if (grafo == NULL)
        return;

    if (grafo->Primeiro_Vertice != NULL)
        Libera_Lista_Verice(grafo->Primeiro_Vertice);

    if (grafo->Hash_Vertice != NULL)
        Libera_Hash_Grafo(grafo);

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

//************** IMPLEMENTANDO***********//

int  Eh_Bipartido(){}
void Caminho_Minimo_Dijkstra(){}
void Caminho_Minimo_Floyd(){}
void Retorna_Grau_Grafo(){}
void Retorna_Fecho_Transitivo_Direto(){}
void Retorna_Fecho_Transitivo_Indireto(){}
void Apresentar_Sequencia_Grau(){}
void Apresentar_SubGrafo_Induzido_por_Vertices(){}
void Apresentar_Complementar_do_Grafo(){}
void Apresentar_Componentes_Fortemente_Conexa(){}
void Verificar_Eh_Euleriano(){}
void Apresentar_Nos_Articulacao(){}
void Apresentar_Arestas_Ponte(){}
void Apresentar_Raio_Centro_Periferia(){}
void Apresentar_AGM_ou_Floresta_Custo_Minimo(){}
void Apresentar_Arvore_de_Busca_Pronfundidade(){}
void Apresentar_Arvore_de_Busca_Largura(){}



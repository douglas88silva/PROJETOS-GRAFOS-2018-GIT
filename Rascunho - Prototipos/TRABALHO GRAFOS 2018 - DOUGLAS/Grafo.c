#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"
#include "Util.h"

Grafo *Cria_Novo_Grafo()
{
    Grafo *novo_grafo = (Grafo*) malloc(sizeof(Grafo));

    novo_grafo->Numero_Vertice = 0;
    novo_grafo->Numero_Aresta = 0;
    novo_grafo->Trabalha_Com_Hash = 0;
    novo_grafo->Tamanho_Hash = 0;

    novo_grafo->Primeiro_Vertice = NULL;
    novo_grafo->Hash_Vertice = NULL;

    return novo_grafo;
}
Vertice *Cria_Novo_Vertice(int Id)
{
    Vertice *novo_vertice = (Vertice*) malloc(sizeof(Vertice));

    novo_vertice->Id = Id;
    novo_vertice->Grau_Vertice = 0;

    novo_vertice->Primeira_Aresta = NULL;

    novo_vertice->Proximo_Vertice = NULL;

    return novo_vertice;
}
Aresta *Cria_Nova_Aresta(int Peso, int Id_Vertice)
{
    Aresta *nova_aresta = (Aresta*) malloc(sizeof(Aresta));

    nova_aresta->Peso = Peso;
    nova_aresta->Id_Vertice = Id_Vertice;

    nova_aresta->Proxima_Aresta = NULL;

    return nova_aresta;
}
HashVertice *Cria_Novo_Hash(Vertice *vertice)
{
    HashVertice *novoHash = (HashVertice*) malloc(sizeof(HashVertice));

    novoHash->Vertice = vertice;
    novoHash->Proximo_Hash_Vertice = NULL;

    return novoHash;
}
void Insere_Vertice(Grafo *grafo, Vertice *vertice)
{
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

    if (grafo->Trabalha_Com_Hash == 1)
        Insere_Vertice_Hash(grafo, vertice);
}
void Insere_Aresta(Vertice *vertice, int Id_Vertice, int Peso_Aresta)
{
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
Vertice *Busca_Vertice(Grafo *grafo, int Id)
{
    //verifica se o grafo é NULL ou vazio
    if (grafo == NULL || grafo->Numero_Vertice == 0)
    {
        return NULL;
    }

    if (grafo->Trabalha_Com_Hash == 1)
        return Busca_Vertice_Pelo_Hash(grafo, Id);
    else
        return Busca_Vertice_Pela_Lista_Adjacencia(grafo, Id);
}
Vertice *Busca_Vertice_Pela_Lista_Adjacencia(Grafo *grafo, int Id)
{
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
Vertice *Busca_Vertice_Pelo_Hash(Grafo *grafo, int Id)
{
    int idx = Id % grafo->Tamanho_Hash;

    if (grafo->Hash_Vertice == NULL || grafo->Hash_Vertice[idx] == NULL)
        return NULL;

    for (HashVertice *aux = grafo->Hash_Vertice[idx]; aux != NULL; aux = aux->Proximo_Hash_Vertice)
    {
        if (aux->Vertice->Id == Id)
            return aux->Vertice;
    }

    return NULL;
}
Aresta *Busca_Aresta(Vertice *vertice, int Id_Vertice)
{
    if (vertice == NULL || vertice->Primeira_Aresta == NULL)
        return NULL;

    for (Aresta *aresta_auxiliar = vertice->Primeira_Aresta; aresta_auxiliar != NULL; aresta_auxiliar = aresta_auxiliar->Proxima_Aresta)
    {
        if (aresta_auxiliar->Id_Vertice == Id_Vertice)
            return aresta_auxiliar;
    }

    return NULL;
}
void Imprime_Todos_Vertices(Grafo *grafo)
{
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
void Imprime_Todas_Arestas(Grafo *grafo)
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
int Retorna_Ordem_Grafo(Grafo *grafo)
{
    if (grafo == NULL)
        return -1;
    else
        return grafo->Numero_Vertice;
}
void Popula_Grafo(Grafo *grafo, int Id1, int Id2, int Peso)
{
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
void Aloca_Array_Hash(Grafo *grafo, int Total_Nos)
{
    int tamanho_hash = Retorna_Numero_Primo(Total_Nos / 3);

    grafo->Hash_Vertice = (HashVertice*) malloc(tamanho_hash * sizeof(HashVertice));

    if (grafo->Hash_Vertice == NULL)
    {
        printf("Memoria insuficiente para alocar o hash");
        return;
    }
    else
    {
        grafo->Trabalha_Com_Hash = 1;
        grafo->Tamanho_Hash = tamanho_hash;

        for (int i = 0; i < tamanho_hash; i++)
        {
            grafo->Hash_Vertice[i] = NULL;
        }
    }
}
void Insere_Vertice_Hash(Grafo *grafo, Vertice *vertice)
{
    int idx = vertice->Id % grafo->Tamanho_Hash;

    HashVertice *hash = Cria_Novo_Hash(vertice);

    if (grafo->Hash_Vertice[idx] == NULL)
    {
        grafo->Hash_Vertice[idx] = hash;
    }
    else
    {
        hash->Proximo_Hash_Vertice = grafo->Hash_Vertice[idx];
        grafo->Hash_Vertice[idx] = hash;
    }
}
void Imprime_Lista_Hash(Grafo *grafo)
{
    if (grafo == NULL)
    {
        printf("Grafo nulo\n");
        return;
    }

    if (grafo->Trabalha_Com_Hash == 0 || grafo->Hash_Vertice == NULL)
    {
        printf("Grafo sem hash\n");
        return;
    }

    printf("Tamanho hash:%d\n", grafo->Tamanho_Hash);

    for (int i = 0; i < grafo->Tamanho_Hash; i++)
    {
        if (grafo->Hash_Vertice[i] == NULL)
        {
            printf("Posicao: %d  -  NULL\n", i);
        }
        else
        {
            printf("Posicao: %d - Lista Id: ", i);

            for(HashVertice *hash = grafo->Hash_Vertice[i]; hash != NULL; hash = hash->Proximo_Hash_Vertice)
            {
                printf("%d ", hash->Vertice->Id);
            }

            printf("\n");

        }
    }

}
void Exclui_Aresta(Vertice *vertice, int Id)
{
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
void Excluir_Todas_Aresta_Vertice(Grafo *grafo, Vertice *vertice)
{
    if (vertice == NULL || vertice->Primeira_Aresta == NULL)
        return;

    Exclui_Aresta(Busca_Vertice(grafo, vertice->Primeira_Aresta->Id_Vertice), vertice->Id);
    Exclui_Aresta(vertice, vertice->Primeira_Aresta->Id_Vertice);

    Excluir_Todas_Aresta_Vertice(grafo, vertice);
}
void Exclui_Vertice_Hash(Grafo *grafo, int Id)
{
    int idx = Id % grafo->Tamanho_Hash;

    if (grafo->Hash_Vertice == NULL || grafo->Hash_Vertice[idx] == NULL)
        return;

    HashVertice *aux = NULL;

    for (HashVertice *hashVertice = grafo->Hash_Vertice[idx]; hashVertice != NULL; hashVertice = hashVertice->Proximo_Hash_Vertice)
    {
        if (hashVertice->Vertice->Id == Id)
        {
            if (aux ==   NULL)
                grafo->Hash_Vertice[idx] = grafo->Hash_Vertice[idx]->Proximo_Hash_Vertice;
            else
                aux->Proximo_Hash_Vertice = hashVertice->Proximo_Hash_Vertice;

            free(hashVertice);
            break;          // Após terminar a exclusão, não é necessário continuar no laço
        }
        else
        {
            aux = hashVertice;
        }
    }
}
void Exclui_Vertice(Grafo *grafo, int Id)
{
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
int Retorna_Grau_Vertice(Vertice *vertice)
{
    if (vertice == NULL)
        return -1;
    else
        return vertice->Grau_Vertice;
}
int Verificar_K_Regularidade_Grafo(Grafo *grafo, int k)
{
    if (grafo == NULL || grafo->Primeiro_Vertice == NULL)
        return 0;

    for (Vertice *vertice = grafo->Primeiro_Vertice; vertice != NULL; vertice = vertice->Proximo_Vertice)
    {
        if (vertice->Grau_Vertice != k)
            return 0;
    }

    return 1;
}
int Verificar_Grafo_Trivial(Grafo *grafo)
{
    if (grafo == NULL || grafo->Numero_Vertice != 1)
        return 0;
    else
        return 1;
}
int Verificar_Grafo_Nulo(Grafo *grafo)
{
    if (grafo == NULL || grafo->Numero_Vertice == 0)
        return 1;
    else
        return 0;
}
void Imprimir_Vizinhanca_Aberta(Vertice *vertice)
{
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
void Imprimir_Vizinhanca_Fechada(Vertice *vertice)
{
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
int Verificar_Grafo_Completo(Grafo *grafo)
{
    if (Verificar_Grafo_Nulo(grafo) == 1 || Verificar_Grafo_Trivial(grafo) == 1)
        return 1;
    else
        return Verificar_K_Regularidade_Grafo(grafo, grafo->Numero_Vertice - 1);
}


void Libera_Grafo(Grafo *grafo)
{
    if (grafo == NULL)
        return;

    if (grafo->Primeiro_Vertice != NULL)
        Libera_Lista_Verice(grafo->Primeiro_Vertice);

    if (grafo->Hash_Vertice != NULL)
        Libera_Hash_Grafo(grafo);

    free(grafo);
}
void Libera_Lista_Arestas(Aresta *aresta)
{
    if (aresta == NULL)
        return;

    Libera_Lista_Arestas(aresta->Proxima_Aresta);
    free(aresta);
}
void Libera_Lista_Verice(Vertice *vertice)
{
    if (vertice == NULL)
        return;

    Libera_Lista_Verice(vertice->Proximo_Vertice);
    Libera_Lista_Arestas(vertice->Primeira_Aresta);
    free(vertice);
}
void Libera_Hash_Grafo(Grafo *grafo)
{
    for (int i = 0; i < grafo->Tamanho_Hash; i++)
    {
        if (grafo->Hash_Vertice[i] != NULL)
            free(grafo->Hash_Vertice[i]);
    }

    free(grafo->Hash_Vertice);
}
void Libera_Lista_Hash(HashVertice *hashVertice)
{
    if (hashVertice == NULL)
        return;

    Libera_Lista_Hash(hashVertice->Proximo_Hash_Vertice);
    free(hashVertice);
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



#include <stdio.h>
//#include <stdlib.h>
#include <time.h>
#include "Grafo.h"
#include "Util.h"
#include "Arquivo.h"

Grafo *grafo = NULL;

void Inicializa_Menu()
{
    Limpa_Tela();
    printf("---------------------------------------------------\n");
    printf("          Trabalha Teoria dos Grafos\n\n");
    printf("Escolha uma das opcoes abaixo:\n");

    if (grafo != NULL)
        printf("(Grafo com %d vertices em memoria)\n", grafo->Numero_Vertice);

    Opcoes_Menu();
}
void Limpa_Tela()
{
    system("cls");
}
void Opcoes_Menu()
{
    printf("  1 - Carregar Arquivo\n");
    printf(" *2 - Salvar Arquivo\n");
    printf("  3 - Criar grafo\n");
    printf("  4 - Inserir Vertice\n");
    printf("  5 - Inserir Aresta\n");
    printf("  6 - Excluir Vertice\n");
    printf("  7 - Excluir Aresta\n");
    printf("  8 - Imprimir grafo\n");
    printf("  9 - Imprimir vertices\n");
    printf(" 10 - Imprimir arestas\n");
    //printf(" 11 - Imprimir hash\n");
    printf(" 12 - Busca vertice\n");
    printf(" 13 - Busca aresta\n");
    //printf(" 14 - Busca sem hash\n");
    printf(" 15 - Retornar grau do no\n");//Caso seja digrafo grau entrada e saida
    printf(" 16 - Verifica a k-regularidade\n");
    printf(" 17 - Informa a ordem do grafo\n");
    printf(" 18 - Informa se o grafo é trivial\n");
    printf(" 19 - Informa se o grafo é nulo\n");
    printf(" 20 - Mostrar vizinhaça aberta de um nó\n");
    printf(" 21 - Mostrar vizinhaça fechada de um nó\n");
    printf("*22 - Verificar se o grafo é um multigrafo\n");
    printf(" 23 - Verificar se o grafo é completo\n");
    printf("*24 - Verificar se o grafo é bipartido\n");
    printf("*25 - Caminho Minimo entre dois vertices Dijkstra\n");
    printf("*26 - Caminho Minimo entre dois vertices Floyd\n");
    printf("*27 - Retorna grau do grafo\n");
    printf("*28 - Retornar fecho transitivo direto de um nó\n");
    printf("*29 - Retornar fecho transitivo indireto de um no\n");
    printf("*30 - Apresentar sequencia de graus\n");
    printf("*31 - Apresenar subgrafo induzido por uma dado conjunto de vertice\n");
    printf("*32 - Apresentar o complementar do grafo\n");
    printf("*33 - Apresentar as componentes fortemente conexas\n");//apenas para digrafos
    printf("*34 - Verificar se o grafo é euleriano\n");
    printf("*35 - Apresentar nos de articulacao\n");
    printf("*36 - Apresentar as arestas ponte\n");
    printf("*37 - Apresentar raio, o diâmetro, o centro e a periferia do grafo\n");
    printf("*38 - Apresentar a AGM do grafo ou as florestas de custo minimo\n");
    printf("*39 - Apresentar as arvores de busca profundidade\n");
    printf("*40 - Apresenatar as arvores de busca largura\n");
    printf(" 41 - Libera grafo\n\n\n");

    printf(" 0 - SAIR\n\n");

    int opcao = 0;

    scanf("%d", &opcao);

    Limpa_Tela();

    switch(opcao)
    {
        case 1:
            Opcao_Carrega_Arquivo();
            break;

        case 2:
            Opcao_Salvar_Arquivo();
            break;

        case 3:
            Opcao_Criar_Grafo();
            break;

        case 4:
            Opcao_Inserir_Vertice();

            break;

        case 5:
            Opcao_Inserir_Aresta();

            break;

        case 6:
            Opcao_Excluir_Vertice();
            break;

        case 7:
            Opcao_Excluir_Aresta();
            break;

        case 8:
            Opcao_Imprimir_Grafo();
            break;

        case 9:

            Opcao_Imprimir_Vertices();
            break;

        case 10:
            Opcao_Imprimir_Arestas();
            break;

        case 11:
            //Opcao_Imprimir_Hash();
            break;


        case 12:
            Opcao_Busca_Vertice();
            break;

        case 13:
            Opcao_Busca_Aresta();

            break;

        case 14:
           // Opcao_Busca_Sem_Hash();
            break;

        case 15:
            Opcao_Retorna_Grau_No();//Caso seja digrafo grau de entrada e saida
            break;

        case 16:
            Opcao_Verifica_K_regularidade();
            break;

        case 17:
            Opcao_Retorna_Ordem_Grafo();
            break;

        case 18:
            Opcao_Informa_Grafo_eh_Trivial();
            break;

        case 19:
            Opcao_Informa_Grafo_eh_nulo();
            break;

        case 20:
            Opcao_Vizinhaca_Aberta_No();
            break;

        case 21:
            Opcao_Vizinhaca_Fechada_No();
            break;

        case 22:
            Opcao_Eh_Multigrafo();
            break;

        case 23:
            Opcao_Eh_Grafo_Completo();
            break;

        case 24:
            Opcao_Eh_Bipartido();
            break;

        case 25:
            Opcao_Caminho_Minimo_Dijkstra();
            break;

        case 26:
            Opcao_Caminho_Minimo_Floyd();
            break;

        case 27:
            Opcao_Retorna_Grau_Grafo();
            break;

        case 28:
            Opcao_Retorna_Fecho_Transitivo_Direto();
            break;

        case 29:
            Opcao_Retorna_Fecho_Transitivo_Indireto();
            break;

        case 30:
            Opcao_Apresentar_Sequencia_Grau();
            break;

        case 31:
            Opcao_Apresentar_SubGrafo_Induzido_por_Vertices();
            break;

        case 32:
            Opcao_Apresentar_Complementar_do_Grafo();
            break;

        case 33:
            Opcao_Apresentar_Componentes_Fortemente_Conexa();
            break;

        case 34:
            Opcao_Verificar_Eh_Euleriano();
            break;

        case 35:
            Opcao_Apresentar_Nos_Articulacao();
            break;

        case 36:
            Opcao_Apresentar_Arestas_Ponte();
            break;

        case 37:
            Opcao_Apresentar_Raio_Centro_Periferia();
            break;

        case 38:
            Opcao_Apresentar_AGM_ou_Floresta_Custo_Minimo();
            break;

        case 39:
            Opcao_Apresentar_Arvore_de_Busca_Pronfundidade();
            break;

        case 40:
            Opcao_Apresentar_Arvore_de_Busca_Largura();
            break;

        case 41:
            Opcao_Libera_Grafo();
            break;

        case 0:
            Opcao_SAIR();
            break;

        default:
            Opcao_SAIR();
            break;
    }

    if (opcao > 0)
        Voltar_Ao_Menu();
}
void Voltar_Ao_Menu()
{
    int resposta;

    printf("\n\nDeseja voltar ao menu inicial? ");
    resposta = Retorna_Sim_Nao();

    if (resposta == 1)
    {
        Inicializa_Menu();
    }
    else
    {
        Opcao_SAIR();
        printf("\nFim do programa!\n");
    }
}
int Retorna_Sim_Nao()
{
    int resposta;

    printf("(1-Sim / 2-Nao)... ");

    scanf("%d", &resposta);

    return resposta;
}

/************* Opções do menu *************/

void Opcao_Carrega_Arquivo()
{
        if (grafo != NULL)
    {
        printf("Grafo em memoria nao esta nulo. Deseja liberar?");
        int resposta = Retorna_Sim_Nao();

        if (resposta == 1)
        {
            Libera_Grafo(grafo);
            grafo = NULL;
            Opcao_Carrega_Arquivo();
        }
        else
        {
            return;
        }
    }


    int opcao = -1;
    printf("Escolha uma das opcoes de Grafo:");
    printf("\n\n1 - Grafo ponderado");
    printf("\n0 - Grafo nao ponderado\n");

    while(opcao < 0 || opcao > 1)
    {
        scanf("%d",&opcao);
        setbuf(stdin, NULL);
    }



    char nome_arquivo[100];

    printf("Digite o nome do arquivo completo...\n");

    scanf("%s", nome_arquivo);
    setbuf(stdin, NULL);

    printf("\n\nCarregando arquivo %s...\n", nome_arquivo);

    FILE *arquivo = Abre_Arquivo(nome_arquivo);

    if (arquivo == NULL)
        return;

    printf("Arquivo aberto...\n");


    //CASO SEJA GRAFO PONDERADO
    if(opcao)
    {
        grafo = Cria_Novo_Grafo_Ponderado(opcao);
    }
    else
    {
        grafo = Cria_Novo_Grafo();
    }


    printf("Grafo criado...\n");

    int total_vertice_arquivo = 0;

    fscanf(arquivo, "%d", &total_vertice_arquivo);
    printf("Total de vertices do arquivo: %d\n", total_vertice_arquivo);


    if(grafo->PONDERADO)
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
void Opcao_Salvar_Arquivo(){}

void Opcao_Criar_Grafo(){
    int resposta;

    if (grafo != NULL)
    {
        printf("Atencao!!! Ja existe um grafo em memória. Dejesa substitui-lo?");
        resposta = Retorna_Sim_Nao();

        if (resposta != 1)
            return;
        else
        {
            Libera_Grafo(grafo);
            printf("Liberado grafo antigo\n");
        }
    }

    grafo = Cria_Novo_Grafo();

    int tamanho_grafo = 0;

    printf("Informar tamanho aproximado do grafo? \n");

    scanf("%d", &tamanho_grafo);

}

void Opcao_Inserir_Vertice(){
    if (grafo == NULL)
    {
        printf("Eh necessario criar um grafo antes de inserir o vertice!\n");
        return;
    }

    int id;

    printf("Digite o Id do vertice\n");

    scanf("%d", &id);

    Vertice *vertice = Busca_Vertice(grafo, id);

    if (vertice == NULL)
    {
        printf("Criando novo vertice...\n");

        vertice = Cria_Novo_Vertice(id);

        printf("Inserindo vertice criado...\n");
        Insere_Vertice(grafo, vertice);

        printf("Vertice %d inserido com sucesso\n", id);
    }
    else
    {
        printf("Ja existe um vertice com o Id %d.\n", id);
        printf("Deseja informar um novo Id?");
        int resposta = Retorna_Sim_Nao();

        if (resposta == 1)
        {
            Limpa_Tela();
            Opcao_Inserir_Vertice();
        }
    }
}

void Opcao_Inserir_Aresta(){
        int id1, id2, peso;
    Vertice *vertice1, *vertice2;

    printf("Informe o id do primeiro vertice...\n");

    scanf("%d", &id1);

    vertice1 = Busca_Vertice(grafo, id1);

    if (vertice1 == NULL)
    {
        printf("Vertice nao encontrado.\n");
        return;
    }

    printf("Informe o id do segundo vertice...\n");

    scanf("%d", &id2);

    vertice2 = Busca_Vertice(grafo, id2);

    if (vertice2 == NULL)
    {
        printf("Vertice nao encontrado.\n");
        return;
    }

    printf("Infome o peso da aresta...\n");

    scanf("%d", &peso);

    Aresta *aresta = Busca_Aresta(vertice1, id2);

    if (aresta != NULL)
    {
        printf("Atencao! Aresta ja inserida no vertice %d.\n", id1);
        return;
    }

    Insere_Aresta(vertice1, id2, peso);

    aresta = Busca_Aresta(vertice2, id1);

    if (aresta != NULL)
    {
        printf("Atenacao! Aresta ja inserida no vertice %d.\n", id2);
        return;
    }

    Insere_Aresta(vertice2, id1, peso);

    grafo->Numero_Aresta++;
}

void Opcao_Excluir_Vertice(){
    int id;
    Vertice *vertice;
    printf("Informe o Id do vertice...\n");

    scanf("%d", &id);

    Exclui_Vertice(grafo, id);
}

void Opcao_Excluir_Aresta(){
    int id;
    Vertice *vertice;
    Aresta *aresta;
    printf("Informe o Id do primeiro vertice...\n");

    scanf("%d", &id);

    vertice = Busca_Vertice(grafo, id);

    if (vertice == NULL)
    {
        printf("Vertice nao encontrado\n");
        return;
    }

    printf("Informe o Id do segundo vertice...\n");
    scanf("%d", &id);

    aresta = Busca_Aresta(vertice, id);

    if (aresta == NULL)
    {
        printf("Aresta nao encontrado\n");
        return;
    }

    Exclui_Aresta(vertice, id);
}

void Opcao_Imprimir_Grafo(){
    printf("Dados do grafo...\n\n");

    if (grafo == NULL)
    {
        printf("Grafo nulo.\n");
        return;
    }

    printf("Numero de vertices: %d\n", grafo->Numero_Vertice);
    printf("Numero de arestas: %d\n", grafo->Numero_Aresta);

    Opcao_Imprimir_Vertices();

    Opcao_Imprimir_Arestas();

    Opcao_Imprimir_Hash();
}

void Opcao_Imprimir_Vertices(){
    printf("\nLista de vertices pela lista de adjacencia...\n");
    Imprime_Todos_Vertices(grafo);
}

void Opcao_Imprimir_Arestas(){
    printf("\nLista de arestas, vertice por vertice...\n");
    Imprime_Todas_Arestas(grafo);
}

void Opcao_Busca_Vertice(){
    clock_t Ticks[2];
    Ticks[0] = clock();
    //O código a ter seu tempo de execução medido ficaria neste ponto.

    int id;
    Vertice *vertice;

    printf("Informe o id a ser pesquisado...\n");

    scanf("%d", &id);
//grafo->Trabalha_Com_Hash = 0;
    for (int i = 0; i < 1000; i++)
        vertice = Busca_Vertice(grafo, id);

    if (vertice == NULL)
        printf("Vertice nao encontrado.\n");
    else
        printf("Vertice %d encontrado, com grau %d.\n", vertice->Id, vertice->Grau_Vertice);

    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

    printf("Tempo gasto: %g ms.", Tempo);

}

void Opcao_Busca_Aresta(){
    int id;
    Vertice *vertice;
    Aresta *aresta;
    printf("Informe o id do vertice em que deseja consultar a aresta...\n");
    scanf("%d", &id);

    vertice = Busca_Vertice(grafo, id);

    if (vertice == NULL)
    {
        printf("Vertice nao encontrado. Deseja consultar outro vertice?");
        int resposta = Retorna_Sim_Nao();

        if (resposta == 1)
        {
            Opcao_Busca_Aresta();
        }

        return;
    }
    else
    {
        printf("Informe o id do vertice em que a aresta esta ligada...\n");

        scanf("%d", &id);

        aresta = Busca_Aresta(vertice, id);

        if (aresta == NULL)
        {
            printf("Aresta nao encontrada.\n");
        }
        else
        {
            printf("Aresta encontrada, ligando os vertices %d e %d, com peso %d", vertice->Id, aresta->Id_Vertice, aresta->Peso);
        }
    }


}

void Opcao_Retorna_Grau_No(){
     int id, grau;
    Vertice *vertice;
    printf("Informe o Id do vertice...\n");

    scanf("%d", &id);

    vertice = Busca_Vertice(grafo, id);

    grau = Retorna_Grau_Vertice(vertice);

    if (grau == -1)
        printf("Vertice %d nao encontrado", id);
    else
        printf("Grau do vertice %d -> %d", id, grau);
}

void Opcao_Verifica_K_regularidade(){
     int k = 0;

    printf("Informar o valor de k...\n");
    scanf("%d", &k);

    int resultado = Verificar_K_Regularidade_Grafo(grafo, k);

    if (resultado == 0)
        printf("Grafo nao %d-regular\n", k);
    else
        printf("Grafo eh %d-regular\n", k);
}

void Opcao_Retorna_Ordem_Grafo(){
    if (grafo == NULL)
    {
        printf("Grafo nulo.\n");
    }
    else
    {
        printf("Ordem do grafo: %d\n", Retorna_Ordem_Grafo(grafo));
    }
}

void Opcao_Informa_Grafo_eh_Trivial(){
      int trivial = Verificar_Grafo_Trivial(grafo);

    if (trivial == 1)
        printf("Grafo informado eh trivial\n");
    else
        printf("Grafo nao eh trivial\n");
}

void Opcao_Informa_Grafo_eh_nulo(){
       int nulo = Verificar_Grafo_Nulo(grafo);

    if (nulo == 1)
        printf("Grafo informado eh nulo\n");
    else
        printf("Grafo nao eh nulo\n");
}

void Opcao_Vizinhaca_Aberta_No(){

    int id;
    Vertice *vertice;
    printf("Informe o Id do vertice...\n");

    scanf("%d", &id);

    vertice = Busca_Vertice(grafo, id);

    if (vertice == NULL)
        printf("Vertice nao encontrado!\n");
    else
        Imprimir_Vizinhanca_Aberta(vertice);
}

void Opcao_Vizinhaca_Fechada_No(){
      int id;
    Vertice *vertice;
    printf("Informe o Id do vertice...\n");

    scanf("%d", &id);

    vertice = Busca_Vertice(grafo, id);

    if (vertice == NULL)
        printf("Vertice nao encontrado!\n");
    else
        Imprimir_Vizinhanca_Fechada(vertice);
}

void Opcao_Eh_Multigrafo(){}

void Opcao_Eh_Grafo_Completo(){
        int completo = Verificar_Grafo_Completo(grafo);

    if (completo == 1)
        printf("Grafo eh completo");
    else
        printf("Grafo nao eh completo");
}

void Opcao_Eh_Bipartido(){}
void Opcao_Caminho_Minimo_Dijkstra(){}
void Opcao_Caminho_Minimo_Floyd(){}
void Opcao_Retorna_Grau_Grafo(){}
void Opcao_Retorna_Fecho_Transitivo_Direto(){}
void Opcao_Retorna_Fecho_Transitivo_Indireto(){}
void Opcao_Apresentar_Sequencia_Grau(){}
void Opcao_Apresentar_SubGrafo_Induzido_por_Vertices(){}
void Opcao_Apresentar_Complementar_do_Grafo(){}
void Opcao_Apresentar_Componentes_Fortemente_Conexa(){}
void Opcao_Verificar_Eh_Euleriano(){}
void Opcao_Apresentar_Nos_Articulacao(){}
void Opcao_Apresentar_Arestas_Ponte(){}
void Opcao_Apresentar_Raio_Centro_Periferia(){}
void Opcao_Apresentar_AGM_ou_Floresta_Custo_Minimo(){}
void Opcao_Apresentar_Arvore_de_Busca_Pronfundidade(){}
void Opcao_Apresentar_Arvore_de_Busca_Largura(){}


void Opcao_Libera_Grafo()
{
    printf("Liberando grafo da memoria...\n");

    Libera_Grafo(grafo);

    printf("Grafo liberado.\n");

    grafo = NULL;
}
void Opcao_SAIR()
{
    if (grafo != NULL)
        Libera_Grafo(grafo);
}

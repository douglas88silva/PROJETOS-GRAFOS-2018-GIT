#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

/**
 * @file    Grafo.h
 * @author
 * @version
 * @brief   Estrutura Grafo.
 *          Estrutura para armazenar alguns dados do grafo, lista de vértices e hash.
 *          Possui também variáveis de controle para determinar se iremos trabalhar com hash ou não.
 */
struct grafo
{
    int Numero_Vertice;               /**< Número de vértices do grafo. Será incrementada toda vez que for adicionado um novo vértice. */
    int Numero_Aresta;                /**< Número de arestas do grafo. Será incrementada toda vez que for adicionado uma aresta entre dois vértices. */

    int Trabalha_Com_Hash;            /**< Variável que irá controlar se utilizaremos hash ou não. Será criada com valor 0 e, caso comece a trabalhar com hash, irá mudar o valor para 1. */
    int Tamanho_Hash;                 /**< Tamanho do hash que será armazenado em memória. O tamanho do hash é definido como o próximo número primo após aproximadamente um terço do número de vértices com que iremos trabalhar.*/

    struct vertice *Primeiro_Vertice; /**< Ponteiro para o primero vértice da lista de adjacência do grafo.*/

    struct hashVertice **Hash_Vertice;    /**< Ponteiro para o hash que iremos trabalhar.*/
};
typedef struct grafo Grafo;

/**
 * @file    Grafo.h
 * @author
 * @version
 * @brief   Estrutura Vertice
 *          Estrutura utilizada para armazenar dados do vértice, ponteiro para aresta e para o próximo vértice na lista de adjacência.
 */
struct vertice
{
    int Id;                          /**< Id do vértice, usado para identificar cada vértice no grafo.*/
    int Grau_Vertice;                /**< Grau do vértice. Incrementado a medida com que se adiciona arestas no vértice.*/

    struct aresta *Primeira_Aresta;  /**< Ponteiro para a lista de adjacência de arestas.*/

    struct vertice *Proximo_Vertice; /**< Ponteiro para o próximo vértice da lista de adjacência.*/
};
typedef struct vertice Vertice;

/**
 * @file    Grafo.h
 * @author
 * @version
 * @brief   Estrutura Aresta
 *          Estrutura utilizada para armazenar dados da aresta e ponteiro para próxima aresta.
 */
struct aresta
{
    int Peso;                      /**< Peso da aresta.*/
    int Id_Vertice;                /**< Identificador do vértice que está sendo ligado pela aresta.*/

    struct aresta *Proxima_Aresta; /**< Ponteiro para a próxima aresta na lista de adjacência.*/
};
typedef struct aresta Aresta;

/**
 * @file    Grafo.h
 * @author
 * @version
 * @brief   Estrutura HashVertice
 *          Estrutura utilizada para armazenar ponteiro para os vértices, afim de melhorar a performance de busca dentro do grafo.
 */
struct hashVertice
{
    struct vertice *Vertice;         /**< Ponteiro para o vértice dentro do hash.*/
    struct HashVertice *Proximo_Hash_Vertice; /**< Ponteiro para o próximo vértice, dentro da lista.*/
};
typedef struct hashVertice HashVertice;


/**
 * @file    Grafo.h
 * @author
 * @version
 * @brief   Cria um novo grafo vazio.
 *          Cria um novo grafo em memória, aloca o grafo e inicializa suas variáveis. Por fim, retorna o grafo criado.
 * @return  Grafo vazio.
 */
Grafo *Cria_Novo_Grafo();


/**
 * @file      Grafo.h
 * @author
 * @version
 * @brief     Cria novo vértice.
 *            Cria um novo vértice em memória, aloca o vértice e inicializa suas variáveis. Por fim, retorna o vértice criado.
 * @param Id  Identificador do vértice.
 * @return    Novo vértice com Id passado por parâmetro.
 */
Vertice *Cria_Novo_Vertice(int Id);


/**
 * @file              Grafo.c
 * @author
 * @version
 * @brief             Cria nova aresta.
 *                    Cria nova aresta em memória, aloca a aresta e inicializa suas variáveis.
 * @param Peso        Peso da aresta.
 * @param Id_Vertice  Identificado do vértice ligado pela aresta.
 * @return            Nova aresta com peso e ligada ao vétice com Id passado por parâmetro.
 */
Aresta *Cria_Nova_Aresta(int Peso, int Id_Vertice);


/**
 * @file           Grafo.c
 * @author
 * @version
 * @brief          Cria novo hash.
 *                 Cria novo hash em memória, aloca o hash e inicializa suas variáveis.
 * @param vertice  Ponteiro para vértice que será inserido no hash.
 * @return         Novo hash apontando para o vértice passado por parâmetro.
 */
HashVertice *Cria_Novo_Hash(Vertice *vertice);


/**
 * @file            Grafo.c
 * @author
 * @version
 * @brief           Insere vértice no grafo.
 *                  Verifica se a primeira posição do grafo está vazia. Se estiver insere o vértice passado por parâmetro nela.
 *                  Se a posição não estiver fazia, faz o vértice apontar para o primeiro vértice da lista do grafo e, coloca a primeira posição do grafo como sendo o novo vértice.
 * @param *grafo    Grafo que irá receber o vértice.
 * @param *vertice  Vértice a ser inserido no grafo.
 */
void Insere_Vertice(Grafo *grafo, Vertice *vertice);


/**
 * @file               Grafo.h
 * @author
 * @version
 * @brief              Insere aresta na lista de adjacência do vértice passado por parâmetro.
 *                     Cria a aresta ligada ao vértice com Id do vértice ligado e peso da arestas, passados por parâmetro.
 * @param entrada      Vértice de origem da aresta.
 * @param Id_Vertice   Id do vértice que está sendo ligado pela aresta.
 * @param Peso_Aresta  Peso da aresta que será inserida.
 */
void Insere_Aresta(Vertice *entrada, int Id_Vertice, int Peso_Aresta);


/**
 * @file         Grafo.h
 * @author
 * @version
 * @brief        Função que irá definir se iremos utilizar a função Busca_Vertice_Com_Hash ou Busca_Vertice_Sem_Hash.
 *               Essa decisão é tomada com base na variável Trabalha_Com_Hash dentro do grafo.
 *               Caso essa variável seja igual a 1, a busca será feita com hash. Caso contrário, será feita pela lista de adjacência.
 * @param grafo  Grafo onde será pesquisado o vértice.
 * @param Id     Identificador do vértice pelo qual será feita a busca.
 * @return       NULL caso não encontre o vértice ou um ponteiro para o vértice, caso ele seja encontrado.
 */
Vertice *Busca_Vertice(Grafo *grafo, int Id);


/**
 * @file         Grafo.h
 * @author
 * @version
 * @brief        Busca vértice pela lista de adjacência do grafo.
 *               Começando pelo primeiro vértice do grafo, essa função compara o Id passado por parâmetro com o Id do vértice.
 *               Caso os Ids não sejam iguais, é feita uma nova comparação no próximo vértice da lista, até chegar encontrar o vértice ou chegar ao final da lista.
 * @param grafo  Grafo onde será pesquisado o vértice.
 * @param Id     Identificador do vértice pelo qual será feita a busca.
 * @return       NULL caso não encontre o vértice ou um ponteiro para o vértice, caso ele seja encontrado.
 */
Vertice *Busca_Vertice_Pela_Lista_Adjacencia(Grafo *grafo, int Id);


/**
 * @file         Grafo.h
 * @author
 * @version
 * @brief        Busca pelo hash do grafo.
 *               É feito o cálculo do index do hash que corresponde ao Id passado por parâmetro. Após isso, será feita a busca pelo hash, no index informado.
 *               Caso o Id passado por parâmetro não seja encontrado, verifica-se o próximo item dentro do index calculado.
 * @param grafo  Grafo onde será pesquisado o vértice.
 * @param Id     Identificador do vértice pelo qual será feita a busca.
 * @return       NULL caso não encontre o vértice ou um ponteiro para o vértice, caso ele seja encontrado.
 */
Vertice *Busca_Vertice_Pelo_Hash(Grafo *grafo, int Id);


/**
 * @file                Grafo.h
 * @author
 * @version
 * @brief               Busca aresta.
 *                      A busca é feita na lista de adjacência do vértice passado por parâmetro, buscando uma aresta que esteja ligada a outro vértice, com o id igual ao Id_Vertice.
 * @param vertice       Grafo onde será pesquisado o vértice.
 * @param Id_Vertice    Identificador do vértice pelo qual será feita a busca.
 * @return              NULL caso não encontre a aresta ou um ponteiro para a aresta, caso seja encontrada.
 */
Aresta *Busca_Aresta(Vertice *vertice, int Id_Vertice);

/**
 * @file        Grafo.h
 * @author
 * @version
 * @brief       Imprime todos os vértices do grafo, passando por toda a lista de adjacência.
 *              O formato da impressão é apenas o Id do vértice, um por linha.
 * @param grafo Grafo que terá seus vértices impressos na tela.
 */
void Imprime_Todos_Vertices(Grafo *grafo);


/**
 * @file         Grafo.h
 * @author
 * @version
 * @brief        Imprime todos as arestas, vértice por vértice.
 *               O formato de impressão é o Id do vértice seguido pelos Ids de cada vértice com o qual ele tem aresta.
 * @param grafo  Grafo que terá seus vértices impressos.
 */
void Imprime_Todas_Arestas(Grafo *grafo);


/**
 * @file         Grafo.h
 * @author
 * @version
 * @brief        Retorna a ordem do grafo, a qual é dada pelo número de vértices do grafo.
 * @param grafo  Grafo onde será feita a consulta pela sua ordem.
 * @return       Inteiro com o valor da ordem do grafo.
 */
int Retorna_Ordem_Grafo(Grafo *grafo);


/**
 * @file        Grafo.h
 * @author
 * @version
 * @brief       Função que insere a aresta entre dois vértices.
 *              Para isso, é feita a busca pelos vértices no grafo, através dos identificadores Id1 e Id2.
 *              Caso eles ainda não tenham sido inseridos no grafo, é feita a inserção deles e, por último, a aresta que irá ligar esses dois vértices.
 * @param grafo Grafo onde serão inseridos os vértices e a aresta.
 * @param Id1   Identificador do primeiro vértice.
 * @param Id2   Identificador do segundo vértice.
 * @param Peso  Peso da aresta que liga os dois vértices.
 */
void Popula_Grafo(Grafo *grafo, int Id1, int Id2, int Peso);


/**
 * @file            Grafo.h
 * @author
 * @version
 * @brief           Aloca espaço para o hash dentro do grafo, altera a variável do grafo Trabalha_Com_Hash para 1 e, guarda o tamanho do hash.
 * @param grafo     Grafo que irá trabalhar com hash.
 * @param Total_Nos Inteiro que será utilizado para calcular o tamanho do hash.
 */
void Aloca_Array_Hash(Grafo *grafo, int Total_Nos);


/**
 * @file            Grafo.h
 * @author
 * @version
 * @brief           Função para inserir o vértice no hash do grafo.
 *                  É feito o cálculo do index onde o ponteiro do vértice será inserido. Por fim, insere-se o vértice nessa posição.
 *                  Caso não tenha nenhum ponteiro armazenado nessa posição, insere-o sem nenhum tratamento.
 *                  Caso contrário, insere o ponteiro na primeira posição da lista.
 * @param grafo     Grafo onde está inserido o vértice.
 * @param vertice   Ponteiro para vértice que será guardado no hash.
 */
void Insere_Vertice_Hash(Grafo *grafo, Vertice *vertice);


/**
 * @file            Grafo.h
 * @author
 * @version
 * @brief           Função para imprimir todos os vértices adicionados no hash.
 *                  O formato da impressão é a posição do index seguido por todos os Ids dos vértices que estão inseridos dentro dele.
 * @param  grafo    Grafo que terá seus vértice impressos.
 */
void Imprime_Lista_Hash(Grafo *grafo);


/**
 * @file        Grafo.h
 * @author
 * @version
 * @brief       Função para liberar o grafo de memória. Antes de liberar o grafo, são chamadas as funções para liberar cada estrutura dentro do grafo.
 * @see         Libera_Lista_Arestas
 * @see         Libera_Lista_Verice
 * @see         Libera_Hash_Grafo
 * @see         Libera_Lista_Hash
 * @param grafo Grafo que será liberado da memória
 */
void Libera_Grafo(Grafo *grafo);


/**
 * @file            Grafo.h
 * @author
 * @version
 * @brief           Função recursiva para liberar as arestas na lista de adjacência passada por parâmetro.
 * @param aresta    Lista de aresta que será liberada.
 */
void Libera_Lista_Arestas(Aresta *aresta);


/**
 * @file            Grafo.h
 * @author
 * @version
 * @brief           Função recursiva para liberar os vértices na lista de adjacência passada por parâmetro.
 *
 * @param vertice   Lista de vértices que será liberada.
 */
void Libera_Lista_Verice(Vertice *vertice);


/**
 * @file            Grafo.h
 * @author
 * @version
 * @brief           Função para liberar o array de hash do grafo.
 * @param grafo     Array de hash que será liberada.
 */
void Libera_Hash_Grafo(Grafo *grafo);


/**
 * @file                Grafo.h
 * @author
 * @version
 * @brief               Função recursiva para liberar a lista de adjacência de hash, passada por parâmetro.
 * @param hashVertice   Lista de aresta que será liberada.
 */
void Libera_Lista_Hash(HashVertice *hashVertice);


/**
 * @file            Grafo.c
 * @author
 * @version
 * @brief           Exclui aresta do vértice passado por parâmetro, ligado ao vértice com o Id passado por parâmetro.
 * @param *vertice  Ponteiro para o vértice de saída.
 * @param *Id       Id do vértice de entrada.
 */
void Exclui_Aresta(Vertice *vertice, int Id);


/**
 * @file            Grafo.c
 * @author
 * @version
 * @brief           Exclui arestas do vértice por parâmetro.
 * @param *grafo    Ponteiro para o grafo.
 * @param *vertice  Vértice a ser retiradas as arestas.
 */
void Excluir_Todas_Aresta_Vertice(Grafo *grafo, Vertice *vertice);


/**
 * @file            Grafo.c
 * @author
 * @version
 * @brief           Exclui vértice do hash no grafo passado por parâmetro.
 * @param *grafo    Ponteiro para o grafo.
 * @param *Id       Id do vértice a ser excluído.
 */
void Exclui_Vertice_Hash(Grafo *grafo, int Id);


/**
 * @file            Grafo.c
 * @author
 * @version
 * @brief           Exclui vértice do grafo passado por parâmetro.
 * @param *grafo    Ponteiro para o grafo.
 * @param *Id       Id do vértice a ser excluído.
 */
void Exclui_Vertice(Grafo *grafo, int Id);


/**
 * @file            Grafo.c
 * @author
 * @version
 * @brief           Retorna o grau do vértice passado por parâmetro.
 * @param *vertice  Ponteiro para o vértice.
 * @return          Inteiro com o valor do grau do vértice
 */
int Retorna_Grau_Vertice(Vertice *vertice);


/**
 * @file            Grafo.c
 * @author
 * @version
 * @brief           Verifica se um grafo é k-regular, sendo k valor passado por parâmetro.
 * @param *grafo    Grafo que será verificado
 * @param *k        Valor inteiro que será utilizado para comparar os graus de cada vértice do grafo.
 * @return          Retorna 1 se o grafo for k-regular e 0, caso contrário
 */
int Verificar_K_Regularidade_Grafo(Grafo *grafo, int k);


/**
 * @file            Grafo.c
 * @author
 * @version
 * @brief           Verifica se um grafo é trivial, ou seja, se possui apenas um vértice.
 * @param *grafo    Grafo que será verificado
 * @return          Retorna 1 se o grafo for trivial e 0, caso contrário
 */
int Verificar_Grafo_Trivial(Grafo *grafo);


 /**
 * @file            Grafo.c
 * @author
 * @version
 * @brief           Verifica se um grafo é nulo, ou seja, se não possui vértice.
 * @param *grafo    Grafo que será verificado
 * @return          Retorna 1 se o grafo for nulo e 0, caso contrário
 */
int Verificar_Grafo_Nulo(Grafo *grafo);


 /**
 * @file            Grafo.c
 * @author
 * @version
 * @brief           Imprime a vizinhança aberta do vértice passado por parâmetro.
 * @param *vertice  Ponteiro para o vértice que terá sua vizinhança impresso.
 */
void Imprimir_Vizinhanca_Aberta(Vertice *vertice);


 /**
 * @file            Grafo.c
 * @author
 * @version
 * @brief           Imprime a vizinhança fechada do vértice passado por parâmetro.
 * @param *vertice  Ponteiro para o vértice que terá sua vizinhança impresso.
 */
void Imprimir_Vizinhanca_Fechada(Vertice *vertice);


/**
 * @file            Grafo.c
 * @author
 * @version
 * @brief           Verifica se um grafo é completo. Para isso, usa-se a função 'Verificar_K_Regularidade_Grafo', com k igual ao número de vértices - 1.
                    Para os casos em que o grafo for trivial ou nulo, o grafo é completo.
 * @param *grafo    Grafo que será verificado.
 * @return          Retorna 1 se o grafo for completo e 0, caso contrário
 */
int Verificar_Grafo_Completo(Grafo *grafo);




//************** IMPLEMENTANDO***********//

int Eh_Bipartido();
void Caminho_Minimo_Dijkstra();
void Caminho_Minimo_Floyd();
void Retorna_Grau_Grafo();
void Retorna_Fecho_Transitivo_Direto();
void Retorna_Fecho_Transitivo_Indireto();
void Apresentar_Sequencia_Grau();
void Apresentar_SubGrafo_Induzido_por_Vertices();
void Apresentar_Complementar_do_Grafo();
void Apresentar_Componentes_Fortemente_Conexa();
void Verificar_Eh_Euleriano();
void Apresentar_Nos_Articulacao();
void Apresentar_Arestas_Ponte();
void Apresentar_Raio_Centro_Periferia();
void Apresentar_AGM_ou_Floresta_Custo_Minimo();
void Apresentar_Arvore_de_Busca_Pronfundidade();
void Apresentar_Arvore_de_Busca_Largura();




#endif // GRAFO_H_INCLUDED

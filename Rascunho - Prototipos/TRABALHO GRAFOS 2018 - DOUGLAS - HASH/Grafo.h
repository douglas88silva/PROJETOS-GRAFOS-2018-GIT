#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

/**
 * @file    Grafo.h
 * @author
 * @version
 * @brief   Estrutura Grafo.
 *          Estrutura para armazenar alguns dados do grafo, lista de v�rtices e hash.
 *          Possui tamb�m vari�veis de controle para determinar se iremos trabalhar com hash ou n�o.
 */
struct grafo
{
    int Numero_Vertice;               /**< N�mero de v�rtices do grafo. Ser� incrementada toda vez que for adicionado um novo v�rtice. */
    int Numero_Aresta;                /**< N�mero de arestas do grafo. Ser� incrementada toda vez que for adicionado uma aresta entre dois v�rtices. */

    int Trabalha_Com_Hash;            /**< Vari�vel que ir� controlar se utilizaremos hash ou n�o. Ser� criada com valor 0 e, caso comece a trabalhar com hash, ir� mudar o valor para 1. */
    int Tamanho_Hash;                 /**< Tamanho do hash que ser� armazenado em mem�ria. O tamanho do hash � definido como o pr�ximo n�mero primo ap�s aproximadamente um ter�o do n�mero de v�rtices com que iremos trabalhar.*/

    struct vertice *Primeiro_Vertice; /**< Ponteiro para o primero v�rtice da lista de adjac�ncia do grafo.*/

    struct hashVertice **Hash_Vertice;    /**< Ponteiro para o hash que iremos trabalhar.*/
};
typedef struct grafo Grafo;

/**
 * @file    Grafo.h
 * @author
 * @version
 * @brief   Estrutura Vertice
 *          Estrutura utilizada para armazenar dados do v�rtice, ponteiro para aresta e para o pr�ximo v�rtice na lista de adjac�ncia.
 */
struct vertice
{
    int Id;                          /**< Id do v�rtice, usado para identificar cada v�rtice no grafo.*/
    int Grau_Vertice;                /**< Grau do v�rtice. Incrementado a medida com que se adiciona arestas no v�rtice.*/

    struct aresta *Primeira_Aresta;  /**< Ponteiro para a lista de adjac�ncia de arestas.*/

    struct vertice *Proximo_Vertice; /**< Ponteiro para o pr�ximo v�rtice da lista de adjac�ncia.*/
};
typedef struct vertice Vertice;

/**
 * @file    Grafo.h
 * @author
 * @version
 * @brief   Estrutura Aresta
 *          Estrutura utilizada para armazenar dados da aresta e ponteiro para pr�xima aresta.
 */
struct aresta
{
    int Peso;                      /**< Peso da aresta.*/
    int Id_Vertice;                /**< Identificador do v�rtice que est� sendo ligado pela aresta.*/

    struct aresta *Proxima_Aresta; /**< Ponteiro para a pr�xima aresta na lista de adjac�ncia.*/
};
typedef struct aresta Aresta;

/**
 * @file    Grafo.h
 * @author
 * @version
 * @brief   Estrutura HashVertice
 *          Estrutura utilizada para armazenar ponteiro para os v�rtices, afim de melhorar a performance de busca dentro do grafo.
 */
struct hashVertice
{
    struct vertice *Vertice;         /**< Ponteiro para o v�rtice dentro do hash.*/
    struct HashVertice *Proximo_Hash_Vertice; /**< Ponteiro para o pr�ximo v�rtice, dentro da lista.*/
};
typedef struct hashVertice HashVertice;


/**
 * @file    Grafo.h
 * @author
 * @version
 * @brief   Cria um novo grafo vazio.
 *          Cria um novo grafo em mem�ria, aloca o grafo e inicializa suas vari�veis. Por fim, retorna o grafo criado.
 * @return  Grafo vazio.
 */
Grafo *Cria_Novo_Grafo();


/**
 * @file      Grafo.h
 * @author
 * @version
 * @brief     Cria novo v�rtice.
 *            Cria um novo v�rtice em mem�ria, aloca o v�rtice e inicializa suas vari�veis. Por fim, retorna o v�rtice criado.
 * @param Id  Identificador do v�rtice.
 * @return    Novo v�rtice com Id passado por par�metro.
 */
Vertice *Cria_Novo_Vertice(int Id);


/**
 * @file              Grafo.c
 * @author
 * @version
 * @brief             Cria nova aresta.
 *                    Cria nova aresta em mem�ria, aloca a aresta e inicializa suas vari�veis.
 * @param Peso        Peso da aresta.
 * @param Id_Vertice  Identificado do v�rtice ligado pela aresta.
 * @return            Nova aresta com peso e ligada ao v�tice com Id passado por par�metro.
 */
Aresta *Cria_Nova_Aresta(int Peso, int Id_Vertice);


/**
 * @file           Grafo.c
 * @author
 * @version
 * @brief          Cria novo hash.
 *                 Cria novo hash em mem�ria, aloca o hash e inicializa suas vari�veis.
 * @param vertice  Ponteiro para v�rtice que ser� inserido no hash.
 * @return         Novo hash apontando para o v�rtice passado por par�metro.
 */
HashVertice *Cria_Novo_Hash(Vertice *vertice);


/**
 * @file            Grafo.c
 * @author
 * @version
 * @brief           Insere v�rtice no grafo.
 *                  Verifica se a primeira posi��o do grafo est� vazia. Se estiver insere o v�rtice passado por par�metro nela.
 *                  Se a posi��o n�o estiver fazia, faz o v�rtice apontar para o primeiro v�rtice da lista do grafo e, coloca a primeira posi��o do grafo como sendo o novo v�rtice.
 * @param *grafo    Grafo que ir� receber o v�rtice.
 * @param *vertice  V�rtice a ser inserido no grafo.
 */
void Insere_Vertice(Grafo *grafo, Vertice *vertice);


/**
 * @file               Grafo.h
 * @author
 * @version
 * @brief              Insere aresta na lista de adjac�ncia do v�rtice passado por par�metro.
 *                     Cria a aresta ligada ao v�rtice com Id do v�rtice ligado e peso da arestas, passados por par�metro.
 * @param entrada      V�rtice de origem da aresta.
 * @param Id_Vertice   Id do v�rtice que est� sendo ligado pela aresta.
 * @param Peso_Aresta  Peso da aresta que ser� inserida.
 */
void Insere_Aresta(Vertice *entrada, int Id_Vertice, int Peso_Aresta);


/**
 * @file         Grafo.h
 * @author
 * @version
 * @brief        Fun��o que ir� definir se iremos utilizar a fun��o Busca_Vertice_Com_Hash ou Busca_Vertice_Sem_Hash.
 *               Essa decis�o � tomada com base na vari�vel Trabalha_Com_Hash dentro do grafo.
 *               Caso essa vari�vel seja igual a 1, a busca ser� feita com hash. Caso contr�rio, ser� feita pela lista de adjac�ncia.
 * @param grafo  Grafo onde ser� pesquisado o v�rtice.
 * @param Id     Identificador do v�rtice pelo qual ser� feita a busca.
 * @return       NULL caso n�o encontre o v�rtice ou um ponteiro para o v�rtice, caso ele seja encontrado.
 */
Vertice *Busca_Vertice(Grafo *grafo, int Id);


/**
 * @file         Grafo.h
 * @author
 * @version
 * @brief        Busca v�rtice pela lista de adjac�ncia do grafo.
 *               Come�ando pelo primeiro v�rtice do grafo, essa fun��o compara o Id passado por par�metro com o Id do v�rtice.
 *               Caso os Ids n�o sejam iguais, � feita uma nova compara��o no pr�ximo v�rtice da lista, at� chegar encontrar o v�rtice ou chegar ao final da lista.
 * @param grafo  Grafo onde ser� pesquisado o v�rtice.
 * @param Id     Identificador do v�rtice pelo qual ser� feita a busca.
 * @return       NULL caso n�o encontre o v�rtice ou um ponteiro para o v�rtice, caso ele seja encontrado.
 */
Vertice *Busca_Vertice_Pela_Lista_Adjacencia(Grafo *grafo, int Id);


/**
 * @file         Grafo.h
 * @author
 * @version
 * @brief        Busca pelo hash do grafo.
 *               � feito o c�lculo do index do hash que corresponde ao Id passado por par�metro. Ap�s isso, ser� feita a busca pelo hash, no index informado.
 *               Caso o Id passado por par�metro n�o seja encontrado, verifica-se o pr�ximo item dentro do index calculado.
 * @param grafo  Grafo onde ser� pesquisado o v�rtice.
 * @param Id     Identificador do v�rtice pelo qual ser� feita a busca.
 * @return       NULL caso n�o encontre o v�rtice ou um ponteiro para o v�rtice, caso ele seja encontrado.
 */
Vertice *Busca_Vertice_Pelo_Hash(Grafo *grafo, int Id);


/**
 * @file                Grafo.h
 * @author
 * @version
 * @brief               Busca aresta.
 *                      A busca � feita na lista de adjac�ncia do v�rtice passado por par�metro, buscando uma aresta que esteja ligada a outro v�rtice, com o id igual ao Id_Vertice.
 * @param vertice       Grafo onde ser� pesquisado o v�rtice.
 * @param Id_Vertice    Identificador do v�rtice pelo qual ser� feita a busca.
 * @return              NULL caso n�o encontre a aresta ou um ponteiro para a aresta, caso seja encontrada.
 */
Aresta *Busca_Aresta(Vertice *vertice, int Id_Vertice);

/**
 * @file        Grafo.h
 * @author
 * @version
 * @brief       Imprime todos os v�rtices do grafo, passando por toda a lista de adjac�ncia.
 *              O formato da impress�o � apenas o Id do v�rtice, um por linha.
 * @param grafo Grafo que ter� seus v�rtices impressos na tela.
 */
void Imprime_Todos_Vertices(Grafo *grafo);


/**
 * @file         Grafo.h
 * @author
 * @version
 * @brief        Imprime todos as arestas, v�rtice por v�rtice.
 *               O formato de impress�o � o Id do v�rtice seguido pelos Ids de cada v�rtice com o qual ele tem aresta.
 * @param grafo  Grafo que ter� seus v�rtices impressos.
 */
void Imprime_Todas_Arestas(Grafo *grafo);


/**
 * @file         Grafo.h
 * @author
 * @version
 * @brief        Retorna a ordem do grafo, a qual � dada pelo n�mero de v�rtices do grafo.
 * @param grafo  Grafo onde ser� feita a consulta pela sua ordem.
 * @return       Inteiro com o valor da ordem do grafo.
 */
int Retorna_Ordem_Grafo(Grafo *grafo);


/**
 * @file        Grafo.h
 * @author
 * @version
 * @brief       Fun��o que insere a aresta entre dois v�rtices.
 *              Para isso, � feita a busca pelos v�rtices no grafo, atrav�s dos identificadores Id1 e Id2.
 *              Caso eles ainda n�o tenham sido inseridos no grafo, � feita a inser��o deles e, por �ltimo, a aresta que ir� ligar esses dois v�rtices.
 * @param grafo Grafo onde ser�o inseridos os v�rtices e a aresta.
 * @param Id1   Identificador do primeiro v�rtice.
 * @param Id2   Identificador do segundo v�rtice.
 * @param Peso  Peso da aresta que liga os dois v�rtices.
 */
void Popula_Grafo(Grafo *grafo, int Id1, int Id2, int Peso);


/**
 * @file            Grafo.h
 * @author
 * @version
 * @brief           Aloca espa�o para o hash dentro do grafo, altera a vari�vel do grafo Trabalha_Com_Hash para 1 e, guarda o tamanho do hash.
 * @param grafo     Grafo que ir� trabalhar com hash.
 * @param Total_Nos Inteiro que ser� utilizado para calcular o tamanho do hash.
 */
void Aloca_Array_Hash(Grafo *grafo, int Total_Nos);


/**
 * @file            Grafo.h
 * @author
 * @version
 * @brief           Fun��o para inserir o v�rtice no hash do grafo.
 *                  � feito o c�lculo do index onde o ponteiro do v�rtice ser� inserido. Por fim, insere-se o v�rtice nessa posi��o.
 *                  Caso n�o tenha nenhum ponteiro armazenado nessa posi��o, insere-o sem nenhum tratamento.
 *                  Caso contr�rio, insere o ponteiro na primeira posi��o da lista.
 * @param grafo     Grafo onde est� inserido o v�rtice.
 * @param vertice   Ponteiro para v�rtice que ser� guardado no hash.
 */
void Insere_Vertice_Hash(Grafo *grafo, Vertice *vertice);


/**
 * @file            Grafo.h
 * @author
 * @version
 * @brief           Fun��o para imprimir todos os v�rtices adicionados no hash.
 *                  O formato da impress�o � a posi��o do index seguido por todos os Ids dos v�rtices que est�o inseridos dentro dele.
 * @param  grafo    Grafo que ter� seus v�rtice impressos.
 */
void Imprime_Lista_Hash(Grafo *grafo);


/**
 * @file        Grafo.h
 * @author
 * @version
 * @brief       Fun��o para liberar o grafo de mem�ria. Antes de liberar o grafo, s�o chamadas as fun��es para liberar cada estrutura dentro do grafo.
 * @see         Libera_Lista_Arestas
 * @see         Libera_Lista_Verice
 * @see         Libera_Hash_Grafo
 * @see         Libera_Lista_Hash
 * @param grafo Grafo que ser� liberado da mem�ria
 */
void Libera_Grafo(Grafo *grafo);


/**
 * @file            Grafo.h
 * @author
 * @version
 * @brief           Fun��o recursiva para liberar as arestas na lista de adjac�ncia passada por par�metro.
 * @param aresta    Lista de aresta que ser� liberada.
 */
void Libera_Lista_Arestas(Aresta *aresta);


/**
 * @file            Grafo.h
 * @author
 * @version
 * @brief           Fun��o recursiva para liberar os v�rtices na lista de adjac�ncia passada por par�metro.
 *
 * @param vertice   Lista de v�rtices que ser� liberada.
 */
void Libera_Lista_Verice(Vertice *vertice);


/**
 * @file            Grafo.h
 * @author
 * @version
 * @brief           Fun��o para liberar o array de hash do grafo.
 * @param grafo     Array de hash que ser� liberada.
 */
void Libera_Hash_Grafo(Grafo *grafo);


/**
 * @file                Grafo.h
 * @author
 * @version
 * @brief               Fun��o recursiva para liberar a lista de adjac�ncia de hash, passada por par�metro.
 * @param hashVertice   Lista de aresta que ser� liberada.
 */
void Libera_Lista_Hash(HashVertice *hashVertice);


/**
 * @file            Grafo.c
 * @author
 * @version
 * @brief           Exclui aresta do v�rtice passado por par�metro, ligado ao v�rtice com o Id passado por par�metro.
 * @param *vertice  Ponteiro para o v�rtice de sa�da.
 * @param *Id       Id do v�rtice de entrada.
 */
void Exclui_Aresta(Vertice *vertice, int Id);


/**
 * @file            Grafo.c
 * @author
 * @version
 * @brief           Exclui arestas do v�rtice por par�metro.
 * @param *grafo    Ponteiro para o grafo.
 * @param *vertice  V�rtice a ser retiradas as arestas.
 */
void Excluir_Todas_Aresta_Vertice(Grafo *grafo, Vertice *vertice);


/**
 * @file            Grafo.c
 * @author
 * @version
 * @brief           Exclui v�rtice do hash no grafo passado por par�metro.
 * @param *grafo    Ponteiro para o grafo.
 * @param *Id       Id do v�rtice a ser exclu�do.
 */
void Exclui_Vertice_Hash(Grafo *grafo, int Id);


/**
 * @file            Grafo.c
 * @author
 * @version
 * @brief           Exclui v�rtice do grafo passado por par�metro.
 * @param *grafo    Ponteiro para o grafo.
 * @param *Id       Id do v�rtice a ser exclu�do.
 */
void Exclui_Vertice(Grafo *grafo, int Id);


/**
 * @file            Grafo.c
 * @author
 * @version
 * @brief           Retorna o grau do v�rtice passado por par�metro.
 * @param *vertice  Ponteiro para o v�rtice.
 * @return          Inteiro com o valor do grau do v�rtice
 */
int Retorna_Grau_Vertice(Vertice *vertice);


/**
 * @file            Grafo.c
 * @author
 * @version
 * @brief           Verifica se um grafo � k-regular, sendo k valor passado por par�metro.
 * @param *grafo    Grafo que ser� verificado
 * @param *k        Valor inteiro que ser� utilizado para comparar os graus de cada v�rtice do grafo.
 * @return          Retorna 1 se o grafo for k-regular e 0, caso contr�rio
 */
int Verificar_K_Regularidade_Grafo(Grafo *grafo, int k);


/**
 * @file            Grafo.c
 * @author
 * @version
 * @brief           Verifica se um grafo � trivial, ou seja, se possui apenas um v�rtice.
 * @param *grafo    Grafo que ser� verificado
 * @return          Retorna 1 se o grafo for trivial e 0, caso contr�rio
 */
int Verificar_Grafo_Trivial(Grafo *grafo);


 /**
 * @file            Grafo.c
 * @author
 * @version
 * @brief           Verifica se um grafo � nulo, ou seja, se n�o possui v�rtice.
 * @param *grafo    Grafo que ser� verificado
 * @return          Retorna 1 se o grafo for nulo e 0, caso contr�rio
 */
int Verificar_Grafo_Nulo(Grafo *grafo);


 /**
 * @file            Grafo.c
 * @author
 * @version
 * @brief           Imprime a vizinhan�a aberta do v�rtice passado por par�metro.
 * @param *vertice  Ponteiro para o v�rtice que ter� sua vizinhan�a impresso.
 */
void Imprimir_Vizinhanca_Aberta(Vertice *vertice);


 /**
 * @file            Grafo.c
 * @author
 * @version
 * @brief           Imprime a vizinhan�a fechada do v�rtice passado por par�metro.
 * @param *vertice  Ponteiro para o v�rtice que ter� sua vizinhan�a impresso.
 */
void Imprimir_Vizinhanca_Fechada(Vertice *vertice);


/**
 * @file            Grafo.c
 * @author
 * @version
 * @brief           Verifica se um grafo � completo. Para isso, usa-se a fun��o 'Verificar_K_Regularidade_Grafo', com k igual ao n�mero de v�rtices - 1.
                    Para os casos em que o grafo for trivial ou nulo, o grafo � completo.
 * @param *grafo    Grafo que ser� verificado.
 * @return          Retorna 1 se o grafo for completo e 0, caso contr�rio
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

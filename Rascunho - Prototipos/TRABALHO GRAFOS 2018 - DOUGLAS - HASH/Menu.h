#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void Inicializa_Menu();
void Limpa_Tela();
void Opcoes_Menu();
void Voltar_Ao_Menu();
int  Retorna_Sim_Nao();

/************* Opções do menu *************/

void Opcao_Carrega_Arquivo();
void Opcao_Salvar_Arquivo();
void Opcao_Criar_Grafo();
void Opcao_Inserir_Vertice();
void Opcao_Inserir_Aresta();
void Opcao_Excluir_Vertice();
void Opcao_Excluir_Aresta();
void Opcao_Imprimir_Grafo();
void Opcao_Imprimir_Vertices();
void Opcao_Imprimir_Arestas();
void Opcao_Imprimir_Hash();
void Opcao_Busca_Vertice();
void Opcao_Busca_Aresta();
void Opcao_Busca_Sem_Hash();
void Opcao_Retorna_Grau_No();
void Opcao_Verifica_K_regularidade();
void Opcao_Retorna_Ordem_Grafo();
void Opcao_Informa_Grafo_eh_Trivial();
void Opcao_Informa_Grafo_eh_nulo();
void Opcao_Vizinhaca_Aberta_No();
void Opcao_Vizinhaca_Fechada_No();

void Opcao_Eh_Multigrafo();

void Opcao_Eh_Grafo_Completo();

void Opcao_Eh_Bipartido();
void Opcao_Caminho_Minimo_Dijkstra();
void Opcao_Caminho_Minimo_Floyd();
void Opcao_Retorna_Grau_Grafo();
void Opcao_Retorna_Fecho_Transitivo_Direto();
void Opcao_Retorna_Fecho_Transitivo_Indireto();
void Opcao_Apresentar_Sequencia_Grau();
void Opcao_Apresentar_SubGrafo_Induzido_por_Vertices();
void Opcao_Apresentar_Complementar_do_Grafo();
void Opcao_Apresentar_Componentes_Fortemente_Conexa();
void Opcao_Verificar_Eh_Euleriano();
void Opcao_Apresentar_Nos_Articulacao();
void Opcao_Apresentar_Arestas_Ponte();
void Opcao_Apresentar_Raio_Centro_Periferia();
void Opcao_Apresentar_AGM_ou_Floresta_Custo_Minimo();
void Opcao_Apresentar_Arvore_de_Busca_Pronfundidade();
void Opcao_Apresentar_Arvore_de_Busca_Largura();
void Opcao_Libera_Grafo();
void Opcao_SAIR();

#endif // MENU_H_INCLUDED

#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED
#include <stdio.h>

///     Fun��o: FILE *Abre_Arquivo(char *nome_arquivo)
///     M�todo: Abre_Arquivo
/// Par�metros:
///             1) char *nome_arquivo
///    Retorno: FILE
///      Autor: Douglas
///     Resumo: Abre um arquivo para leitura, que tenha o nome igual ao par�metro 'nome_arquivo'.
FILE *Abre_Arquivo(char *nome_arquivo);



///     Fun��o: FILE *Cria_Arquivo(char *nome_arquivo)
///     M�todo: Cria_Arquivo
/// Par�metros:
///             1) char *nome_arquivo
///    Retorno: FILE
///      Autor: Douglas
///     Resumo: Abre ou cria um aquivo para escrita, com o nome igual ao par�metro 'nome_arquivo'.
FILE *Cria_Arquivo(char *nome_arquivo);



///     Fun��o: void Imprime_Arquivo(FILE *arquivo)
///     M�todo: Imprime_Arquivo
/// Par�metros:
///             1) FILE *arquivo
///    Retorno: void
///      Autor: Douglas
///     Resumo: Imprime na tela cada linha do arquivo, com uma limita��o de at� 99 caracteres por linha.
void Imprime_Arquivo(FILE *arquivo);



///     Fun��o: void Escreve_Linha(FILE *arquivo, char *linha)
///     M�todo: Escreve_Linha
/// Par�metros:
///             1) FILE *arquivo,
///             2) char *linha
///    Retorno: void
///      Autor: Douglas
///     Resumo: Escreve uma linha no arquivo passado por par�metro, caso o arquivo seja v�lido.
void Escreve_Linha(FILE *arquivo, char *linha);



///     Fun��o: void Fecha_Arquivo(FILE *arquivo).
///     M�todo: Fecha_Arquivo.
/// Par�metros:
///             1) FILE *arquivo.
///    Retorno: void
///      Autor: Douglas
///     Resumo: Fun��o fecha o arquivo passado por par�metro, caso seja poss�vel.
void Fecha_Arquivo(FILE *arquivo);



#endif // ARQUIVO_H_INCLUDED

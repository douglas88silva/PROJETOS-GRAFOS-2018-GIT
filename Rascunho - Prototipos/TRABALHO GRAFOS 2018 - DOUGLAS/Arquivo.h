#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED
#include <stdio.h>

///     Função: FILE *Abre_Arquivo(char *nome_arquivo)
///     Método: Abre_Arquivo
/// Parâmetros:
///             1) char *nome_arquivo
///    Retorno: FILE
///      Autor: Douglas
///     Resumo: Abre um arquivo para leitura, que tenha o nome igual ao parâmetro 'nome_arquivo'.
FILE *Abre_Arquivo(char *nome_arquivo);



///     Função: FILE *Cria_Arquivo(char *nome_arquivo)
///     Método: Cria_Arquivo
/// Parâmetros:
///             1) char *nome_arquivo
///    Retorno: FILE
///      Autor: Douglas
///     Resumo: Abre ou cria um aquivo para escrita, com o nome igual ao parâmetro 'nome_arquivo'.
FILE *Cria_Arquivo(char *nome_arquivo);



///     Função: void Imprime_Arquivo(FILE *arquivo)
///     Método: Imprime_Arquivo
/// Parâmetros:
///             1) FILE *arquivo
///    Retorno: void
///      Autor: Douglas
///     Resumo: Imprime na tela cada linha do arquivo, com uma limitação de até 99 caracteres por linha.
void Imprime_Arquivo(FILE *arquivo);



///     Função: void Escreve_Linha(FILE *arquivo, char *linha)
///     Método: Escreve_Linha
/// Parâmetros:
///             1) FILE *arquivo,
///             2) char *linha
///    Retorno: void
///      Autor: Douglas
///     Resumo: Escreve uma linha no arquivo passado por parâmetro, caso o arquivo seja válido.
void Escreve_Linha(FILE *arquivo, char *linha);



///     Função: void Fecha_Arquivo(FILE *arquivo).
///     Método: Fecha_Arquivo.
/// Parâmetros:
///             1) FILE *arquivo.
///    Retorno: void
///      Autor: Douglas
///     Resumo: Função fecha o arquivo passado por parâmetro, caso seja possível.
void Fecha_Arquivo(FILE *arquivo);



#endif // ARQUIVO_H_INCLUDED

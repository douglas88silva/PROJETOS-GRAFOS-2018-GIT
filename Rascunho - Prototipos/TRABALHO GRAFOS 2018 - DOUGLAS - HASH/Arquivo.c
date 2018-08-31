#include <stdio.h>

FILE *Abre_Arquivo(char *nome_arquivo)
{
    FILE *arquivo = fopen(nome_arquivo, "rt");

    if (arquivo == NULL)
        printf("\nErro ao abrir arquivo!\n");

    return arquivo;
}

FILE *Cria_Arquivo(char *nome_arquivo)
{
    FILE *arquivo = fopen(nome_arquivo, "wt");

    if (arquivo == NULL)
        printf("Erro ao criar arquivo!\n");

    return arquivo;
}

void Imprime_Arquivo(FILE *arquivo)
{
    if (arquivo == NULL)
    {
        printf("Nao eh possivel imprimir esse arquivo!\n");
        return;
    }

    char linha[100];
    char *result;

    while (!feof(arquivo))
    {
        result = fgets(linha, 100, arquivo);
        if (result)
            printf("%s", linha);

    }

}

void Escreve_Linha(FILE *arquivo, char *linha)
{
    if (arquivo == NULL)
    {
        printf("Nao eh possivel escrever nesse arquivo!\n");
        return ;
    }

    int result = fprintf(arquivo, "%s\n", linha);

    if (result == EOF)
        printf("Erro na Gravacao\n");
}


void Fecha_Arquivo(FILE *arquivo)
{
    if (arquivo == NULL)
    {
        printf("Nao eh possivel fechar esse arquivo!\n");
        return;
    }
    fclose(arquivo);
}

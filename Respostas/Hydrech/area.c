
#include "area.h"
#include <stdio.h>
#include <string.h>

/**
 * Função que lê uma área comum de acordo com o formato de entrada descrito na
 * especificação e retorna a Area lida.
 */
Area lerArea()
{
    Area a;
    scanf("%[^\n]\n", a.nome);
    scanf("%[^\n]\n", a.id);
    scanf("%d\n", &a.capacidade);
    return a;
}

/**
 * Função que imprime todas as informações de uma Area conforme o formato
 * descrito na especificação. Dica: veja o arquivo de saída nos casos de teste.
 *
 */
void imprimeArea(Area a)
{
    printf("Nome: %s\n", a.nome);
    printf("Id: %s\n", a.id);
    printf("Capacidade: %d convidado(s)\n", a.capacidade);
}

/*
 * Função que compara se duas áreas são iguais através do
 * id delas.
 * Retorna 1 se forem iguais e 0 caso contrário
 */
int comparaArea(Area a1, Area a2)
{
    return strcmp(a1.id, a2.id) == 0;
}

/*
 * Função que verifica se o id passado é igual ao id da área passada
 * Retorna 1 se for igual e 0 caso contrário
 */
int verificaIdArea(Area a, char *id)
{
    return strcmp(a.id, id) == 0;
}

/**
 * Função que retorna a capacidade de uma área comum.
 */
int getCapacidadeArea(Area a)
{
    return a.capacidade;
}
#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_NO 20  // Número máximo de nós na árvore

// Variável global para controlar o número total de nós
extern int total_nos;

// Estrutura da árvore: matriz onde cada linha representa um nó
// Cada nó possui 4 colunas: [filho_esquerda, valor, pai, irmao_direita]

// Funções da árvore
void inicializar(int arvore[][4]); // Cria o nó raiz da árvore
void addNo(int arvore[][4]);       // Adiciona um novo nó como filho ou irmão
void removeNo(int arvore[][4]);    // Remove um nó e seus filhos da árvore
void existe(int arvore[][4]);      // Busca um valor na árvore
void imprimir(int arvore[][4]);    // Imprime a árvore em pré-ordem

#endif
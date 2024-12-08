#include "arvore.h"

// Inicialização da variável global
int total_nos = 0;

int main() {
    int arvore[MAX_NO][4];
    int op;
    
    // Inicializa a árvore com o nó raiz
    inicializar(arvore);
    
    do {
        printf("\nSelecione uma opcao:\n");
        printf("1. Inserir\n2. Deletar\n3. Consultar\n");
        printf("4. Imprimir\n0. Encerrar\n>>> ");
        scanf("%d", &op);

        switch (op) {
            case 0:
                printf("Encerrando...\n");
                break;
            case 1:
                addNo(arvore);
                break;
            case 2:
                removeNo(arvore);
                break;
            case 3:
                existe(arvore);
                break;
            case 4:
                imprimir(arvore);
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (op != 0);

    return 0;
}

void inicializar(int arvore[][4]) {
    int raiz;
    printf("Digite um valor para a raiz: ");
    scanf("%d", &raiz);
    
    // Inicializa o nó raiz na posição 0
    arvore[0][0] = -1; // Sem filho à esquerda
    arvore[0][1] = raiz; // Valor do nó
    arvore[0][2] = -1; // Sem pai (é raiz)
    arvore[0][3] = -1; // Sem irmão à direita
    total_nos = 1;
}

void addNo(int arvore[][4]) {
    if (total_nos >= MAX_NO) {
        printf("Arvore cheia!\n");
        return;
    }

    int valor, pai;
    printf("Digite o valor do novo no: ");
    scanf("%d", &valor);
    
    do {
        printf("Digite o indice do pai desse novo no (0 a %d): ", total_nos - 1);
        scanf("%d", &pai);    
    } while (pai >= total_nos || pai < 0);
    
    // Inicializa o novo nó
    arvore[total_nos][0] = -1; // Sem filho à esquerda
    arvore[total_nos][1] = valor; // Valor do nó
    arvore[total_nos][2] = pai; // Índice do pai
    arvore[total_nos][3] = -1; // Sem irmão à direita
    
    // Se o pai não tem filho, este será seu primeiro filho
    if (arvore[pai][0] == -1) {
        arvore[pai][0] = total_nos;
    }
    // Senão, percorre a lista de irmãos até encontrar o último
    else {
        int irmao = arvore[pai][0];
        while (arvore[irmao][3] != -1) {
            irmao = arvore[irmao][3];
        }
        arvore[irmao][3] = total_nos;
    }
    
    total_nos++;
}

void removeNo(int arvore[][4]) {
    if (total_nos <= 1) {
        printf("Apenas o no raiz existe!\n");
        return;
    }

    int indice;
    printf("Digite o indice do no a ser removido (1 a %d): ", total_nos - 1);
    scanf("%d", &indice);
    
    if (indice <= 0 || indice >= total_nos) {
        printf("Indice invalido!\n");
        return;
    }
    
    // Remove o nó da lista de filhos/irmãos
    int pai = arvore[indice][2];
    
    // Se é o primeiro filho
    if (arvore[pai][0] == indice) {
        arvore[pai][0] = arvore[indice][3];
    }
    // Senão, procura na lista de irmãos
    else {
        int irmao = arvore[pai][0];
        while (arvore[irmao][3] != indice) {
            irmao = arvore[irmao][3];
        }
        arvore[irmao][3] = arvore[indice][3];
    }
    
    // Move o último nó para a posição removida
    total_nos--;
    if (indice < total_nos) {
        arvore[indice][0] = arvore[total_nos][0];
        arvore[indice][1] = arvore[total_nos][1];
        arvore[indice][2] = arvore[total_nos][2];
        arvore[indice][3] = arvore[total_nos][3];
        
        // Atualiza referências ao nó movido
        int pai_ultimo = arvore[total_nos][2];
        if (arvore[pai_ultimo][0] == total_nos) {
            arvore[pai_ultimo][0] = indice;
        }
        else {
            int irmao = arvore[pai_ultimo][0];
            while (arvore[irmao][3] != total_nos) {
                irmao = arvore[irmao][3];
            }
            arvore[irmao][3] = indice;
        }
    }
}

void existe(int arvore[][4]) {
    int valor;
    printf("Digite o valor a ser procurado: ");
    scanf("%d", &valor);
    
    for (int i = 0; i < total_nos; i++) {
        if (arvore[i][1] == valor) {
            printf("Valor %d encontrado no indice %d\n", valor, i);
            return;
        }
    }
    printf("Valor %d nao encontrado na arvore\n", valor);
}

// Função auxiliar para imprimir a árvore recursivamente
void imprimirRecursivo(int arvore[][4], int no, int nivel) {
    // Imprime espaços para representar o nível
    for (int i = 0; i < nivel; i++) {
        printf("  ");
    }
    printf("└─ %d (i = %d)\n", arvore[no][1], no);
    
    // Imprime todos os filhos
    int filho = arvore[no][0];
    while (filho != -1) {
        imprimirRecursivo(arvore, filho, nivel + 1);
        filho = arvore[filho][3];
    }
}

void imprimir(int arvore[][4]) {
    printf("Arvore:\n");
    imprimirRecursivo(arvore, 0, 0);
}

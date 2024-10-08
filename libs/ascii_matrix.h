#include <string.h>
#include <stdio.h>

#if defined _WIN32
    #include <windows.h>
    # define WIN_USER
#else
    #include <stdlib.h>
    #include <unistd.h>
    #define UNIX_USER
#endif

#define HEIGHT 5 // Altura dos caracteres
#define WIDTH 6 // Largura dos caracteres

int SPACE[5][6] = {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};

int EXCLAMATION[5][6] = {{0,0,0,0,0,0},
                        {0,0,0,0,0,0},
                        {0,0,0,0,0,0},
                        {0,0,0,0,0,0},
                        {0,0,0,0,0,0},};

int DOUBLE_QUOTES[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int HASHTAG[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int DOLLAR[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int PERCENTAGE[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int AND[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int SINGLE_QUOTES[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int OPEN_PARENTHESIS[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int CLOSE_PARENTHESIS[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int ASTERISK[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int PLUS[5][6] = {{0,0,0,0,0,0},
                   {0,0,1,0,0,0},
                   {0,1,1,1,0,0},
                   {0,0,1,0,0,0},
                   {0,0,0,0,0,0},};

int COMMA[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int MINUS[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int FINAL_POINT[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int BAR[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int ZERO[5][6] = {{0,1,1,1,0,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{0,1,1,1,0,0}};
int ONE[5][6] = {{0,0,0,1,0,0},{0,0,1,1,0,0},{0,1,0,1,0,0},{0,0,0,1,0,0},{0,0,0,1,0,0}};
int TWO[5][6] = {{0,1,1,1,0,0},{1,0,0,0,1,0},{0,0,0,1,0,0},{0,1,1,0,0,0},{1,1,1,1,1,0}};
int THREE[5][6] = {{0,1,1,1,0,0},{1,0,0,0,1,0},{0,0,0,1,0,0},{1,0,0,0,1,0},{0,1,1,1,0,0}};
int FOUR[5][6] = {{0,0,1,1,0,0},{0,1,0,1,0,0},{1,1,1,1,1,0},{0,0,0,1,0,0},{0,0,0,1,0,0}};
int FIVE[5][6] = {{1,1,1,1,1,0},{1,0,0,0,0,0},{1,1,1,1,0,0},{0,0,0,0,1,0},{1,1,1,1,0,0}};
int SIX[5][6] = {{0,0,1,1,0,0},{0,1,0,0,0,0},{1,1,1,1,0,0},{1,0,0,0,1,0},{0,1,1,1,0,0}};
int SEVEN[5][6] = {{1,1,1,1,1,0},{0,0,0,0,1,0},{0,0,0,1,0,0},{0,0,1,0,0,0},{0,1,0,0,0,0}};
int EIGHT[5][6] = {{0,1,1,1,0,0},{1,0,0,0,1,0},{0,1,1,1,0,0},{1,0,0,0,1,0},{0,1,1,1,0,0}};
int NINE[5][6] = {{0,1,1,1,0,0},{1,0,0,0,1,0},{0,1,1,1,1,0},{0,0,0,1,0,0},{0,1,1,0,0,0}};

int COLON_POINTS[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int SEMICOLON[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int LESS_THAN[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int EQUAL[5][6] = {{0,0,0,0,0,0},
                   {0,1,1,1,0,0},
                   {0,0,0,0,0,0},
                   {0,1,1,1,0,0},
                   {0,0,0,0,0,0},};

int MORE_THAN[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int QUESTION[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int AT[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int A[5][6] = {{0,1,1,1,0,0},{1,0,0,0,1,0},{1,1,1,1,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0}};
int B[5][6] = {{1,1,1,1,0,0},{1,0,0,0,1,0},{1,1,1,1,0,0},{1,0,0,0,1,0},{1,1,1,1,0,0}};
int C[5][6] = {{0,1,1,1,1,0},{1,0,0,0,0,0},{1,0,0,0,0,0},{1,0,0,0,0,0},{0,1,1,1,1,0}};
int D[5][6] = {{1,1,1,1,0,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,1,1,1,0,0}};
int E[5][6] = {{1,1,1,1,1,0},{1,0,0,0,0,0},{1,1,1,1,0,0},{1,0,0,0,0,0},{1,1,1,1,1,0}};
int F[5][6] = {{1,1,1,1,1,0},{1,0,0,0,0,0},{1,1,1,1,0,0},{1,0,0,0,0,0},{1,0,0,0,0,0}};
int G[5][6] = {{0,1,1,1,1,0},{1,0,0,0,0,0},{1,0,0,1,1,0},{1,0,0,0,1,0},{0,1,1,1,1,0}};
int H[5][6] = {{1,0,0,0,1,0},{1,0,0,0,1,0},{1,1,1,1,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0}};
int I[5][6] = {{0,1,1,0,0,0},{0,1,1,0,0,0},{0,1,1,0,0,0},{0,1,1,0,0,0},{0,1,1,0,0,0}};
int J[5][6] = {{0,0,0,0,1,0},{0,0,0,0,1,0},{0,0,0,0,1,0},{1,0,0,0,1,0},{0,1,1,1,0,0}};
int K[5][6] = {{1,0,0,0,1,0},{1,0,0,1,0,0},{1,1,1,0,0,0},{1,0,0,1,0,0},{1,0,0,0,1,0}};
int L[5][6] = {{1,0,0,0,0,0},{1,0,0,0,0,0},{1,0,0,0,0,0},{1,0,0,0,0,0},{1,1,1,1,1,0}};
int M[5][6] = {{1,0,0,0,1,0},{1,1,0,1,1,0},{1,0,1,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0}};
int N[5][6] = {{1,0,0,0,1,0},{1,1,0,0,1,0},{1,0,1,0,1,0},{1,0,0,1,1,0},{1,0,0,0,1,0}};
int O[5][6] = {{0,1,1,1,0,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{0,1,1,1,0,0}};
int P[5][6] = {{1,1,1,1,0,0},{1,0,0,0,1,0},{1,1,1,1,0,0},{1,0,0,0,0,0},{1,0,0,0,0,0}};
int Q[5][6] = {{0,1,1,1,0,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,1,1,0},{0,1,1,1,1,0}};
int R[5][6] = {{1,1,1,1,0,0},{1,0,0,0,1,0},{1,1,1,1,0,0},{1,0,0,1,0,0},{1,0,0,0,1,0}};
int S[5][6] = {{0,1,1,1,1,0},{1,0,0,0,0,0},{0,1,1,1,0,0},{0,0,0,0,1,0},{1,1,1,1,0,0}};
int T[5][6] = {{1,1,1,1,1,0},{0,0,1,0,0,0},{0,0,1,0,0,0},{0,0,1,0,0,0},{0,0,1,0,0,0}};
int U[5][6] = {{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{0,1,1,1,0,0}};
int V[5][6] = {{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{0,1,0,1,0,0},{0,0,1,0,0,0}};
int W[5][6] = {{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,1,0,1,0},{1,1,0,1,1,0},{1,0,0,0,1,0}};
int X[5][6] = {{1,0,0,0,1,0},{0,1,0,1,0,0},{0,0,1,0,0,0},{0,1,0,1,0,0},{1,0,0,0,1,0}};
int Y[5][6] = {{1,0,0,0,1,0},{0,1,0,1,0,0},{0,0,1,0,0,0},{0,0,1,0,0,0},{0,0,1,0,0,0}};
int Z[5][6] = {{1,1,1,1,1,0},{0,0,0,1,0,0},{0,0,1,0,0,0},{0,1,0,0,0,0},{1,1,1,1,1,0}};

int OPEN_BRACKETS[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int BACKSLOPE[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int CLOSE_BRACKETS[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int CIRCUMFLEX[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int UNDERLINE[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int CRASIS[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int OPEN_KEYS[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int VERTICAL_BAR[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int CLOSE_KEYS[5][6] = {{0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},
                   {0,0,0,0,0,0},};

int (*ASCII[126])[WIDTH] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, SPACE, EXCLAMATION, DOUBLE_QUOTES, HASHTAG, DOLLAR, PERCENTAGE, AND, SINGLE_QUOTES, OPEN_PARENTHESIS, CLOSE_PARENTHESIS, 
ASTERISK, PLUS, COMMA, MINUS, FINAL_POINT, BAR, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, 
COLON_POINTS, SEMICOLON, LESS_THAN, EQUAL, MORE_THAN, QUESTION, AT, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, 
P, Q, R, S, T, U, V, W, X, Y, Z, OPEN_BRACKETS, BACKSLOPE, CLOSE_BRACKETS, CIRCUMFLEX, UNDERLINE, CRASIS, 
A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, OPEN_KEYS, VERTICAL_BAR, CLOSE_KEYS};


char base = 219; // Este será o caractere usado no contorno dos textos exibidos
int width = 50; // Largura da caixa de exibição

void show(int length, char string[length]); // Apenas para manter a semântica (redireciona para 'decode' que porsua vez chama 'write')
void decode(int length, char string[length]); // Decodifica uma String para o código ASCII
void write(int length, int all_matrix[length]); // Exibe uma sequência de matrizes, na horizontal (Formando uma nova matriz)

void clear();
void delay(int time);
void line(char mode);
void header(char mode, char title[30]);
void finish();
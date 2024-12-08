#include <string.h>

#define LENGTH 15

int integer[LENGTH];
int top_i = -1;
int new_int;
float real[LENGTH];
int top_f = -1;
float new_float;
char character[LENGTH] ;
int top_c = -1;
char new_char;
char strings[LENGTH][LENGTH];
int top_s = -1;
char new_string[LENGTH];

typedef struct nodle{
    int content;
    struct nodle *left, *right; 
} Nodle;


typedef struct {
    Nodle *root;
} Tree;

int lengthStack(char stack);
int stack(char stack);
int unstack(char stack);
void printStack();

void insertNodle(Tree *tree, int content);
void insertLeft(Nodle *nodle, int content);
void insertRight(Nodle *nodle, int content);


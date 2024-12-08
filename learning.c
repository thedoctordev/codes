#include <stdio.h>
#include "libs/data_structures.c"

int main() {
   int option, content;
   Tree arvore;
   arvore.root = NULL;


   do
   {
      system("cls");
      printf("Selecione uma opção:\n0. Encerrar\n1. Inserir\n2. Remover\n3. Imprimir\n");
      scanf("%d", &option);

      switch (option)
      {
      case 1:
         printf("Digite um valor para o novo nó");
         scanf("%d", &content);
         insertNodle(&arvore, content); 
         break;

      case 2:
         break;

      case 3:
         system("cls");
         printTree(arvore.root);
         system("pause"); 
      }
   } while (option != 0);

   return 0;
}

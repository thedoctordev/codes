#include "ascii_matrix.h"

void show(int length, char string[length])
{
    decode(length, string);
}

void decode(int length, char string[length])
{
    int ascii[length];
    for (int i = 0; i < strlen(string); i++)
    {
        ascii[i] = (int)string[i];
    }
    write(length, ascii);
}

void write(int length, int all_matrix[length])
{
    int word[HEIGHT][WIDTH*length];
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < length; j++)
        {
            for (int k = 0; k < WIDTH; k++)
            {
                word[i][WIDTH*j+k] = ASCII[all_matrix[j]][i][k];
            }
        }
    }
    printf("\n");
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH*length; j++)
        {
            if (word[i][j] == 1)
            {
                printf("%c", base);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void clear()
{
    #ifdef WIN_USER
        system("cls");
    #else
        system("clear");
    #endif
}

void delay(int time)
{
    #ifdef WIN_USER
        Sleep(time * 1000);
    #else
        sleep(time);
    #endif
}

void line(char mode)
{
    if(mode == 't') printf("%c", 201);
    else if(mode == 'm') printf("%c", 204);
    else if(mode == 'b') printf("%c", 200);
    for (int i = 0; i <= width - 2; i++)
    {
        printf("%c", 205);
    }
    if(mode == 't') printf("%c", 187);
    else if(mode == 'm') printf("%c", 185);
    else if(mode == 'b') printf("%c", 188);
    printf("\n");
}

void header(char mode, char title[30])
{
    clear();

    if (mode >= 65 && mode <= 90)
    {
        int length = strlen(title);
        line('t');
        decode(length, title);
        printf("\n");
        line('m');
    }
    else if (mode >= 97 && mode <= 122)
    {
        line('t');
        printf("%c %-*s %c\n", 186, width-3, title, 186);
        line('m');
    }
    
    
}

void finish()
{
    line('b');
    printf("\nClique ENTER para encerrar o programa...");
    getchar();getchar(); // Gambiarra :)
    clear();
    exit(0);
}

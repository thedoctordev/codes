#include "data_structures.h"


int lengthStack(char stack)
{
    if (stack == 'i')
    {
        if (top_i != -1)
        {
            return top_i+1;
        }
    }
    
    if (stack == 'f')
    {
        if (top_f != -1)
        {
            return top_f+1;
        }
    }
    
    if (stack == 'c')
    {
        if (top_c != -1)
        {
            return top_c+1;
        }
    }
    
    if (stack == 's')
    {
        if (top_s != -1)
        {
            return top_s+1;
        }
    }
    
    return 0;
}

int stack(char stack)
{
    if (stack == 'i')
    {
        if (top_i == LENGTH-1)
        {
            return -1;
        }
        else
        {
            top_i++;
            integer[top_i] = new_int;
            return top_i;
        }
    }
    
    if (stack == 'f')
    {
        if (top_f == LENGTH-1)
        {
            return -1;
        }
        else
        {
            top_f++;
            real[top_f] = new_float;
            return top_f;
        }
    }
    
    if (stack == 'c')
    {
        if (top_c == LENGTH-1)
        {
            return -1;
        }
        else
        {
            top_c++;
            character[top_c] = new_char;
            return top_c;
        }
    }
    
    if (stack == 's')
    {
        if (top_s == LENGTH-1)
        {
            return -1;
        }
        else
        {
            top_s++;
            strcpy(strings[top_s], new_string); // Ver depois
            return top_s;
        }
    }
}

int unstack(char stack)
{
    if (stack == 'i')
    {
        if (top_i == LENGTH-1)
        {
            return -1;
        }
        else
        {
            new_int = integer[top_i];
            top_i--;
            return 0;
        }
    }
    
    if (stack == 'f')
    {
        if (top_f == LENGTH-1)
        {
            return -1;
        }
        else
        {
            new_float = real[top_f];
            top_f--;
            return 0;
        }
    }
    
    if (stack == 'c')
    {
        if (top_c == LENGTH-1)
        {
            return -1;
        }
        else
        {
            new_char = character[top_c];
            top_c--;
            return 0;
        }
    }
    
    if (stack == 's')
    {
        if (top_s == LENGTH-1)
        {
            return -1;
        }
        else
        {
            strcpy(strings[top_s], new_string); // Ver depois
            top_s--;
            return 0;
        }
    }
}

void printStack()
{
    printf("\n");
    for(int i = 0; i < LENGTH + 63; i++) printf("-");
    printf("\n| %-10s (%02d) ", "Integer", lengthStack('i'));
    printf("| %-10s (%02d) ", "Real", lengthStack('f'));
    printf("| %-10s (%02d) ", "Charecter", lengthStack('c'));
    printf("| %-*s (%02d) |\n", LENGTH, "Strings", lengthStack('s'));
    for(int i = 0; i < LENGTH + 63; i++) printf("-");
    
    for (int i = LENGTH - 1; i >= 0; i--)
    {
        (i > top_i) ? printf("\n| %15c ", 176) : printf("\n| %15d ", integer[i]);
        (i > top_f) ? printf("| %15c ", 176) : printf("| %15lf ", real[i]);
        (i > top_c) ? printf("| %15c ", 176) : printf("| %15c ", character[i]);
        (i > top_s) ? printf("| %*c |", LENGTH + 5, 176) : printf("| %*s |", LENGTH + 5, strings[i]);
    }
    printf("\n");
    for(int i = 0; i < LENGTH + 63; i++) printf("-");
    printf("\n");
}

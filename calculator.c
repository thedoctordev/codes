#include "libs/ascii_matrix.c"
#include "libs/data_structures.c"

#define MAX_LENGTH 30 // Define o tamanho máximo da expressão aceita na entrada
#define DELAY 1 // Delay no processo de exibição e execução das operações

int isNumber(char character); // Verifica se o caractere equivale a um Número Inteiro
int toInteger(char character); // Converte um caractere em Número Inteiro
int precedence(char operator); // Verifica a ordem de precedência de um operador
int power(int base, int expoent);
int calculate();

int operation = 0; // Flag que controla as operações

int main(int argc, char const *argv[])
{
    char expression[MAX_LENGTH];
    if (argc == 1)
    {
        header('a', "Calculadora de expressoes (Utilizando pilha)");
        printf("%c %-*s %c\n%c  %c %-*s %c\n%c  %c %-*s %c\n%c  %c %-*s %c\n%c  %c %-*s %c\n%c  %c %-*s %c\n", 186, width-3, "Use apenas numeros e os seguintes sinais:", 186, 186, 195, width-6, "+ (adicao)", 186, 186, 195, width-6, "- (subtracao)", 186, 186, 195, width-6, "x ou * (multiplicacao)", 186, 186, 195, width-6, "/ (divisao)", 186, 186, 192, width-6, "^ (exponenciacao)", 186);
        line('m');
        printf("%c Digite a expressao a ser calculada:\n%c >>> ", 186, 200);
        scanf("%[^\n]s", expression);
    }
    else strcpy(expression, argv[1]);
    
    
    // Remove os expaços, se hover.
    for (int i = 0; i < strlen(expression); i++)
    {
        if(expression[i] == 32) // 32 é o caractere 'Espaço' na tabela ASCII
        {
            for (int j = i; j < strlen(expression); j++)
            {
                expression[j] = expression[j+1];
            }
            i--;
        }
    }

    // Empilha os operandos e operadores, em pilhas distintas
    for (int i = 0; i < strlen(expression); i++)
    {
        // Se for um operando
        if (isNumber(expression[i]))
        {
            int number = toInteger(expression[i]);
            int j = i + 1;
            while (isNumber(expression[j]))
            {
                number = number * 10 + toInteger(expression[j]);
                i++;
                j++;
            }
            new_int = number;
            stack('i');
            if(operation == 1)
            {
                new_int = calculate();
                stack('i');
                operation = 0;
            }
        }
        // Se for um operador
        else
        {
            if(top_c != -1)
            {
                unstack('c');
                if(precedence(expression[i]) < precedence(new_char))
                {
                    operation = 1;
                    stack('c');
                }
                else if(precedence(expression[i]) > precedence(new_char))
                {
                    stack('c');
                    new_int = calculate();
                    stack('i');
                }
                else stack('c');
            }

            new_char = expression[i];
            stack('c');
        }
        
        clear();
        printf("\n%s\n", expression);
        //show(strlen(expression), expression);
        printStack();
        delay(DELAY);
    }

    // Desempilha e calcula
    while (top_i > 0)
    {
        new_int = calculate();
        stack('i');

        clear();
        printf("\n%s\n", expression);
        //show(strlen(expression), expression);
        printStack();
        delay(DELAY);
    }
    
    delay(3);
    clear();
    unstack('i');
    line('t');
    printf("%c %-*s = %10d %c\n", 186, width-16, expression, new_int, 186);
    //show(strlen(expression), expression);
    finish();

    return 0;
}

int isNumber(char character)
{
    if (character >= 48 && character <= 57) return 1;
    else return 0;
}

int toInteger(char character)
{
    int num = (int)character - 48;
    return num;
}

int precedence(char operator)
{
    if(operator == '^') return 1;
    else if(operator == 'x' || operator =='*' || operator =='/') return 2;
    else if(operator == '+' || operator =='-') return 3;
    else return -1;
}

int power(int base, int expoent)
{
    int result = 1;
    for (int i = 0; i < expoent; i++)
    {
        result = result * base;
    }
    return result;
}

int calculate()
{
    int result = 0;
    unstack('i');
    int operand_2 = new_int;
    unstack('c');
    char operator = new_char;
    unstack('i');
    int operand_1 = new_int;

    if(operator == '^') result = power(operand_1, operand_2);
    else if(operator == 'x' || operator =='*') result = operand_1 * operand_2;
    else if(operator == '/') result = operand_1 / operand_2;
    else if(operator == '+') result = operand_1 + operand_2;
    else if(operator == '-') result = operand_1 - operand_2;

    operation = 0;
    return result;
}

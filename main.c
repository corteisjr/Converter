#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constante simples
const int base_binaria = 2;

// Funções
void Decimal(int numero);
void Help(void);

int main(int argc , char *argv[])
{

    if(argc == 1 || argc < 3 || argc > 3)
    {
        Help();
        return EXIT_FAILURE;
    }
    else if(strncmp("-d" , argv[1] , 2) == 0 && argc == 3)
    {
        Decimal(atoi(argv[2]));
    }
    
    return EXIT_SUCCESS;
}


// Converte de decimal para binario
void Decimal(int numero)
{
    // Variaveis
    int conta , aux;
    int binario[1024];

    if(numero == 0 || numero == 1)
    {
        printf("%i\n",numero);
        return;
    }

    // Converte para binario
    for(conta = 0;numero > 0;++conta)
    {
        aux = (numero / base_binaria);
        binario[conta] = numero % 2;
        numero = aux;
    }

    // Imprime o resultado
    printf("> Saida: ");
    for(;conta >= 0;--conta)
    {
        printf("%i", binario[conta]);
    }
    printf("\n");

}

// Ajuda
void Help(void)
{
    puts("> Use: Converter [OPÇÃO] [NUMERO]");
    puts("> Opções: -d [DECIMAL] -o [OCTAL] -hx [HEXADECIMAL]");
}

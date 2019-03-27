/*
 * David Arcis Moreno
 *
 * Ejercicio: 1  -  Quincena: 9
 *
 * Programa que pide dos enteros y devuelve su operacion XOR
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

short int esEntero(char* numero);
long int calculaXOR(long int num1, long int num2);


int main(int argc, char** argv)
{

    char numA[128];
    char numB[128];
    long int a;
    long int b;
    long int c;

    printf("CALCULANDO XOR\n");
    printf("===============================\n");

    do
    {
        printf("Dame el primer número entero: ");
        scanf("%127s", numA);
        while(getchar() != '\n');

    } while (!esEntero(numA));

    a = strtol(numA, NULL, 10);

    do
    {
        printf("Dame el segundo número entero: ");
        scanf("%127s", numB);
        while(getchar() != '\n');

    } while (!esEntero(numB));

    b = strtol(numB, NULL, 10);

    c = calculaXOR(a, b);

    printf("\n%li XOR %li = %li\n", a, b, c);

    printf("\nPulse Intro para terminar...");
    getchar();

    return(0);
}

short int esEntero(char* numero)
{
    int i;
    int punto = 0;
    short int esDigito = 0;

    if (numero[0] == '-')
        i = 1;
    else
        i = 0;

    for (i; i < strlen(numero); i++)
    {
        if (isdigit(numero[i]))
            esDigito = 1;
        else
        {
            printf("Eso no es un número entero válido.\n");
            return 0;
        }
    }

    if (esDigito)
        return 1;

}

long int calculaXOR(long int num1, long int num2)
{
    return num1 ^ num2;
}

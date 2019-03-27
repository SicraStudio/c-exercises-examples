/*
 * File:   main.c
 * Author: sicra
 *
 * Created on 21 de enero de 2015, 21:08
 */

#include <stdio.h>
#include <stdlib.h>

long int aBinario(long int num);

/*
 *
 */
int main(int argc, char** argv) {

    long int numero;

    printf("Número decimal a convertir: ");
    scanf("%li", &numero);

    printf("El %li en binario es: %li", numero, aBinario(numero));

    printf("Pulse Intro para terminar...");
    getchar();

    return (0);
}

// función recursiva
long int aBinario(long int num)
{
    long int resultado;

    if (num < 2)
        resultado = num;
    else
        resultado = num % 2 + (10 * aBinario(num / 2));

    return resultado;
}


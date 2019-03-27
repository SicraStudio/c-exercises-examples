/*  Ejercicio 5 - David Arcis Moreno  */
/*  Programa que sume los N numeros introducidos por teclado. Acabar y mostrar suma al introducir un numero negativo  */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, acum =  0;

    printf("Escriba los numeros a sumar (num. negativo para terminar):\n");

    do
    {
        scanf("%d", &num);

        if (num >= 0)
            acum += num;

    } while (num >= 0);

    printf("La suma de los numeros es %d\n", acum);
    printf("Terminado...");

    system("PAUSE");
}

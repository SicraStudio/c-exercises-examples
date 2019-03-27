/*   Ejercicio 1 Q1 - David Arcis Moreno   */
/*   Programa que multiplica dos números enteros y muestra el resultado por pantalla  */

#include <stdio.h>
#include <stdlib.h>

int producto(int a, int b)
{
    return a * b;
}

int main()
{
    int a, b;

    printf("Multiplicador!!!!\n");
    printf("-----------------\n");
    printf("1er Numero entero: ");
    scanf("%d", &a);
    printf("2do Nuumero entero: ");
    scanf("%d", &b);

    printf("El producto %d X %d es %d", a, b, producto(a, b));

    system("PAUSE");
}



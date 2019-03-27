/* Ejercicio 4 - David Arcis Moreno */
/* Realizar una convertidora de euros a pesetas y viceversa. Informar si se toma una opcion incorrecta */

#include <stdio.h>
#include <stdlib.h>
#define TIPO 166.386

float aPesetas(float cant)
{
    return cant * TIPO;
}

float aEuros(float cant)
{
    return cant / TIPO;
}

int main()
{
    float cant;
    int opcion;

    printf("Convertidor Euros / Pesetas\n");
    printf("---------------------------\n");
    printf("Introduza la cantidad: ");
    scanf("%f", &cant);
    printf("\nA qué quiere convertirlo? (elija una opcion):\n");
    printf("\t1 - Pesetas\n");
    printf("\t2 - Euros\n");

    do {
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("%.2f euros son %.2f pesetas.", cant, aPesetas(cant));
            break;
        case 2:
            printf("%.2f pesetas son %.2f euros.", cant, aEuros(cant));
            break;
        default:
            printf("Opcion elegida incorrecta. Pulse 1 o 2...\n");
        }
    } while (opcion != 1 && opcion !=2);

    system("PAUSE");

}

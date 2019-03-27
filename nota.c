/*  Ejercicio 3 - David Arcis Moreno  */
/*  Pide una nota y en funcion de esta da una calificacion  */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nota;

    printf("Nota del alumno: ");

    do {
        scanf("%d", &nota);

        switch(nota)
        {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            printf("SUSPENSO");
            break;
        case 5:
            printf("APROBADO");
            break;
        case 6:
            printf("BIEN");
            break;
        case 7:
        case 8:
            printf("NOTABLE");
            break;
        case 9:
        case 10:
            printf("SOBRESALIENTE");
            break;
        default:
            printf("Nota no valida...\n");
        }
    } while(nota < 0 || nota > 10);

    system("PAUSE");
}

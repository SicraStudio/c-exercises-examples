/*  Ejercicio 2 - Q1 - David Arcis Moreno  */
/*  Programa que calcula el perimetro y el area de una circunferencia dandole el radio  */

#include <stdio.h>
#include <stdlib.h>
#define PI 3.1416

float perimetro(float r)
{
    return 2 * PI * r;
}

float area(float r)
{
    return PI * r * r;
}

int main()
{
    float radio;

    printf("Introduzca el radio: ");
    scanf("%f", &radio);
    printf("El perimetro es %f y su area es %f.", perimetro(radio), area(radio));

    system("PAUSE");
}

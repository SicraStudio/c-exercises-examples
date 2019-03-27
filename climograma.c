#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    // Por simplificar, suponemos meses de 30 días
    double tempDia[30];
    double precDia[30];
} Mes;

struct climograma {
    char poblacion[20];
    Mes anyo[12];
};

void muestraClimograma(struct climograma cli)
{
    int i, j;
    double sumTemp = 0, sumPrec = 0, promedioTemp, promedioPrec;
    printf("Climograma de %s:\n", cli.poblacion);
    for (i = 1; i <= 12; i++ )
    {
        printf("Mes %d: ", i);
        for (j = 0; j < 30; j++)
        {
            sumTemp += cli.anyo[i].tempDia[j];
            sumPrec += cli.anyo[i].precDia[j];
        }
        promedioTemp = sumTemp / 30;
        sumTemp = 0;
        promedioPrec = sumPrec / 30;
        sumPrec = 0;

        printf("Temperatura media: %f C - Precipitaciones medias: %f mm\n", promedioTemp, promedioPrec);
    }
}

int main()
{
    struct climograma climo;

    strcpy(climo.poblacion, "Benasal");

    int i, j;

    for (i = 0; i < 12; i++)
    {
        printf("%d\n", i);
        for (j = 0; j < 30; j++)
        {
            climo.anyo[i].tempDia[j] = drand48();
            climo.anyo[i].precDia[j] = drand48();

            printf("%f",climo.anyo[i].tempDia[j]);
        }
        printf("\n\n");
    }

    muestraClimograma(climo);

    system("PAUSE");
}

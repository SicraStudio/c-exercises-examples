#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Prototipos */

char *cifrar(char *texto);
char *descifrar(char *texto);

/*
 *
 */
int main(int argc, char** argv) {

    char texto[100];
    char cadeOpcion[5];
    char cadeRespuesta[5];
    int continuar = 0;

    do {

        do {
            printf("Elija una opción (1 ó 2):\n");
            printf("=========================\n");
            printf("1 - Cifrar Texto\n");
            printf("2 - Descifrar Texto\n");
            printf("\nOpción: ");
            scanf("%4s", cadeOpcion);
            /*Limpiamos el buffer -> fflush(stdin) no me funciona*/
            while(getchar() != '\n');

            /*Nos aseguramos de que se haya escrito una de las opciones*/
            if (cadeOpcion[0] != '1' && cadeOpcion[0] != '2')
                printf("\n¡¡¡Elija una opción correcta...!!!\n\n");

        } while (cadeOpcion[0] != '1' && cadeOpcion[0] != '2');

        switch (cadeOpcion[0])
        {
            case '1':
                printf("\nEscriba el texto a cifrar:\n");
                scanf("%99[^\n]",texto);

                printf("\nTexto cifrado:\n");
                printf("%s", cifrar(texto));

                break;
            case '2':
                printf("\nEscriba el texto a descifrar:\n");
                scanf("%99[^\n]",texto);

                printf("\nTexto descifrado:\n");
                printf("%s", descifrar(texto));

                break;
        }

        do {
            printf("\n¿Desea continuar? (s/n): ");
            scanf("%4s", cadeRespuesta);
            while(getchar() != '\n');

            if ((cadeRespuesta[0] != 's' && cadeRespuesta[0] != 'n') && (cadeRespuesta[0] != 'S' && cadeRespuesta[0] != 'N'))
                printf("\nEscriba Sí (s) o No (n)\n");

        } while ((cadeRespuesta[0] != 's' && cadeRespuesta[0] != 'n') && (cadeRespuesta[0] != 'S' && cadeRespuesta[0] != 'N'));

        if (cadeRespuesta[0] == 's' || cadeRespuesta[0] == 'S')
            continuar = 1;
        else
            continuar = 0;

    } while (continuar);

    /*En lugar de usar la pausa del sistema esperamos a que se pulse intro para terminar*/
    printf("\nPulse Intro para terminar...");
    getchar();

    return(0);
}

char *cifrar(char *texto)
{
    int i;
    int j;

    for (i = 0; i < strlen(texto); i++)
    {
        /*Si el caraceter está dentro del rango de las letras, lo incrementamos 3 veces*/
        for (j = 0; j < 3; j++)
        {
            if ((texto[i] >= 97 && texto[i] < 122) || (texto[i] >= 65 && texto[i] < 90))
            {
                texto[i]++;
            }
            /*Controlamos los caracteres finales del rango*/
            else if (texto[i] == 122)
            {
                texto[i] = 97;
            }
            else if (texto[i] == 90)
            {
                texto[i] = 65;
            }
            else if (texto[i] == 32)
            {
                texto[i] = 32;
            }
        }
    }
    return texto;
}

char *descifrar(char *texto)
{
    int i;
    int j;

    for (i = 0; i < strlen(texto); i++)
    {
        for (j = 0; j < 3; j++)
        {
            if((texto[i] > 97 && texto[i] <= 122) || (texto[i]> 65 && texto[i] <= 90)){
                texto[i]--;
            }
            else if(texto[i] == 97)
            {
                texto[i] = 122;
            }
            else if(texto[i] == 65)
            {
                texto[i] = 90;
            }
            else if (texto[i] == 32)
            {
                texto[i] = 32;
            }
        }
    }
    return texto;
}

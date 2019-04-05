/*
 * David Arcis Moreno
 *
 * Ejercicio:  -  Quincena:
 *
 * <Enunciado/>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Manejo de strings
#include <ctype.h>

/*Variables globales*/
int resto;

/* Prototipos de funciones */
int sonLetras(char *palabra);
int dniCorrecto(char *Dni);
int calculaLetra(char *doc);
int compruebaPass(char *pass);
void encriptaPass(char *passProvisional, char* passDefinitivo);
void desencriptaPass(char *passEncriptado);


// definimos el struct
typedef struct persona {
    char nombre[15];
    char apellidos[30];
    char dni[10];
    char password[17];
};

int main(int argc, char** argv)
{
    struct persona mPersona;

    printf("Alta de una nueva persona:\n");
    printf("=================================\n");
    // Pedimos los datos de la persona comprobando que lo que se introduce es correcto
    do
    {
        printf("Nombre: ");
        scanf("%14s",mPersona.nombre);
        // limpiando el buffer
        while(getchar() != '\n');
    } while (!sonLetras(mPersona.nombre));

    do
    {
        printf("Apellidos: ");
        scanf("%29s",mPersona.apellidos);
        while(getchar() != '\n');
    } while (!sonLetras(mPersona.apellidos));

    // El DNI... comprobaremos con una funcion que sea del formato adecuado
    do
    {
        printf("DNI (8 números y una letra): ");
        scanf("%9s",mPersona.dni);
        while(getchar() != '\n');
        int c;
        // ahora comprobaremos la letra, si el formato del dni es valido
        if (dniCorrecto(mPersona.dni))
        {
            if (calculaLetra(mPersona.dni))
                printf("Número y Letra Correctos!\n");
        }
    } while (!dniCorrecto(mPersona.dni) || !calculaLetra(mPersona.dni));

    printf("resto = %d\n",resto);

    /*Tema password*/
    char passProv[17]; // Password provisional para guardar en el campo pass el encriptado
    do
    {
        printf("Password: ");
        scanf("%16s",passProv);
        while(getchar() != '\n');
    } while (!compruebaPass(passProv));

    // Encriptamos el password
    encriptaPass(passProv, mPersona.password);

    // Imprimimos los datos:
    printf("Datos de la persona:\n");
    printf("===============================================\n");
    printf("Nombre y Apellidos: %s %s\n", mPersona.nombre, mPersona.apellidos);
    printf("DNI: %s\n", mPersona.dni);
    printf("Contraseña encriptada: %s\n", mPersona.password);

    desencriptaPass(mPersona.password);

    printf("Contraseña desencriptada: %s\n", mPersona.password);



    printf("\nPulse Intro para terminar...");
    getchar();

    return(0);
}

/*Funcion que comprueba que lo que se ha introducido no lleva ningún número*/
int sonLetras(char *palabra)
{
    int esLetra = 1;
    int i;

    for (i = 0; i < strlen(palabra); i++)
    {
        if (!isalpha(palabra[i]))
        {
            esLetra = 0;
            printf("Error: No puede haber números o símbolos.\n");
            break; // si encuentra un solo numero paramos el bucle
        }
    }

    return esLetra;
}

/*Funcion que comprueba que el dato que se ha introducido para el dni está estructurado correctamente*/
int dniCorrecto(char *Dni)
{
    int correcto = 1;
    int i;

    for (i = 0; i < 8; i++)
    {
        if (!isdigit(Dni[i]))
        {
            correcto = 0;
            printf("Error: DNI incorrecto: %s\n",Dni);
            break;
        }
    }
    if (!isalpha(Dni[8]))
    {
        correcto = 0;
        printf("Error: La letra del DNI ha de ser un caracter no numerico.\n");
    }
    return correcto;
}

/*¿Cómo se calcula la letra del dni?

Se tiene que obtener el resto de dividir el número de dni entre 23. Con el resto obtenido se consulta.*/
int calculaLetra(char *doc)
{
    char numero[9];
    char letraObtenida, letraDoc; // la letra que se obtendra y la que viene con el documento
    int i, correcto;
    double numDni;

    char tablaValores[23] = {'t','r','w','a','g','m','y','f','p','d','x','b','n','j','z','s','q','v','h','l','c','k','e'};
    letraDoc = tolower(doc[8]); // pasamos a minúsculoa la letra por si acaso

    for (i = 0; i < 9; i++)
    {
        numero[i] = doc[i];
    }
    numero[i] = '\0';

    numDni = strtod(numero, NULL);

    resto = (int)numDni % 23;

    letraObtenida = tablaValores[resto];


    if (letraObtenida == letraDoc)
        correcto = 1;
    else
    {
        correcto = 0;
        printf("Letra del dni erronea. La correcta: %c\n",letraObtenida);
    }

    return correcto;
}

int compruebaPass(char *pass)
{
    int i, correcto = 1;

    for (i = 0; i < strlen(pass); i++)
    {
        if(!isalpha(pass[i]) && !isdigit(pass[i]))
        {
            correcto = 0;
            printf("Escriba solo numeros y letras...\n");
            break;
        }
    }
    if (correcto)
        printf("Password almacenado correctamente...\n");
    return correcto;
}

/*Metodo para encripatar el password*/
void encriptaPass(char *passProvisional, char* passDefinitivo)
{
    int i;

    for (i = 0; i < strlen(passProvisional); i++)
    {
        if (i % 2 == 0)
        {
            passDefinitivo[i] = passProvisional[i] - (resto + i);
        }
        else
        {
            passDefinitivo[i] = passProvisional[i] + (resto + i);
        }
    }

}

void desencriptaPass(char *passEncriptado)
{
    int i;

    for (i = 0; i < strlen(passEncriptado); i++)
    {
        if (i % 2 == 0)
        {
            passEncriptado[i] = passEncriptado[i] + (resto + i);
        }
        else
        {
            passEncriptado[i] = passEncriptado[i] - (resto + i);
        }
    }

}















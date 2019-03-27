/* 
 * File:   ejercicio2q5.c
 * Author: sicra
 *
 * Created on 21 de noviembre de 2014, 22:55
 * 
 * Modificar el programa anterior para que su salida por pantalla sea siempre 
 * la siguiente: 
 *      Principal: voy a crear un hilo.
 *      Hilo: mi identificador es 1234.
 *      Principal: el hilo 1234 ha terminado.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *funcThread(void*);        // Prototipo de la función

pthread_t hilo, hiloPrincipal;  // Variables globales
pthread_attr_t attr;

/*
 * 
 */
int main(int argc, char** argv) {
    // Variable para almacenar lo que devuelve el hilo creado al salir
    pthread_t *valorDevuelto = NULL;
    
    hiloPrincipal = pthread_self();
    
    pthread_attr_init(&attr);
    
    printf("Principal: Voy a crear un hilo.\n");
    
    pthread_create(&hilo, &attr, funcThread, NULL);
    // Esperamos a que acabe el hilo creado
    pthread_join(hilo, (void **)&valorDevuelto);
    // Imprimimos que el hilo ha finalizado junto a su tid
    printf("El hilo %d ha terminado.\n", valorDevuelto);
    pthread_exit(NULL);

    return (EXIT_SUCCESS);
}

void *funcThread(void *arg) {
    pthread_t tid = 1234;
    printf("Hilo: Mi identificador es %d\n", tid);
    // al salir devuelve su tid
    pthread_exit((void*)tid);
}


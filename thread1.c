/* 
 * File:   main.c
 * Author: sicra
 *
 * Created on 21 de noviembre de 2014, 21:39
 * 
 * Realizar un programa en C cuyo hilo principal cree un hilo y espere a que 
 * termine. El hilo debe mostrar en pantalla el mensaje "Soy el hilo 1234" 
 * (donde 1234 debe ser el identificador del hilo) y terminar.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *funcThread(void*);        // Prototipo de la función

pthread_t hilo, hiloPrincipal;  // Varibles globales
pthread_attr_t attr;

/*
 * 
 */
int main(int argc, char** argv) {
    
    hiloPrincipal = pthread_self();
    
    pthread_attr_init(&attr);
    
    pthread_create(&hilo, &attr, funcThread, NULL);
    pthread_exit(NULL);

    return (EXIT_SUCCESS);
}

void *funcThread(void *arg) {
    pthread_t tid = 1234;
    printf("Soy el thread %d\n", tid);
    pthread_exit(NULL);
}
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

FILE *file;


void manejador(int sig) {
    time_t t;
    struct tm *tm_info;

   
    time(&t);
    tm_info = localtime(&t);

  
    file = fopen("salidas.txt", "a");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

   
    fprintf(file, "Intento de parar el programa en: %02d/%02d/%04d %02d:%02d:%02d\n", 
            tm_info->tm_mday, 
            tm_info->tm_mon + 1, 
            tm_info->tm_year + 1900, 
            tm_info->tm_hour, 
            tm_info->tm_min, 
            tm_info->tm_sec);

    fclose(file); 
}
int main() {
    
    signal(SIGINT, manejador);

    
    while (1) {
        printf("Programa en ejecución. Presiona Ctrl+C para intentar detenerlo...\n");
        sleep(5); 
    }

    return 0; 
}

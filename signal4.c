
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int count = 0; 
int max_count; 
int interval;  


void manejador_alarma(int sig) {
    time_t t;
    struct tm *tm_info;

    
    time(&t);
    tm_info = localtime(&t);

    
    printf("Señal de alarma recibida a las %02d:%02d:%02d\n", 
           tm_info->tm_hour, 
           tm_info->tm_min, 
           tm_info->tm_sec);

   
    count++;
    if (count >= max_count) {
        printf("Alarma desactivada\n");
        exit(0); 
    }
}

int main() {
    
    printf("¿Cuántas veces sonará la alarma?: ");
    scanf("%d", &max_count);
    printf("¿Cada cuántos segundos se repetirá la alarma?: ");
    scanf("%d", &interval);

   
    signal(SIGALRM, manejador_alarma);

    
    printf("Alarma activada\n");

    
    for (int i = 0; i < max_count; i++) {
        alarm(interval); 
        pause();         
    }

    return 0; 
}

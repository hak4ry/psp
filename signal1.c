#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>

pid_t pid;


void manejador(int sig) {
    time_t end_time;
    struct tm *tm_info;

    
    time(&end_time);
    tm_info = localtime(&end_time);

   
    printf("Fin del proceso %d: %02d/%02d/%04d %02d:%02d:%02d\n", 
           pid, 
           tm_info->tm_mday, 
           tm_info->tm_mon + 1, 
           tm_info->tm_year + 1900, 
           tm_info->tm_hour, 
           tm_info->tm_min, 
           tm_info->tm_sec);
    
    exit(0);  
}

int main() {
    
    pid = getpid();

   
    signal(SIGINT, manejador);

    
    time_t start_time;
    time(&start_time);
    struct tm *tm_info = localtime(&start_time);

    
    printf("Inicio del proceso %d: %02d/%02d/%04d %02d:%02d:%02d\n", 
           pid, 
           tm_info->tm_mday, 
           tm_info->tm_mon + 1, 
           tm_info->tm_year + 1900, 
           tm_info->tm_hour, 
           tm_info->tm_min, 
           tm_info->tm_sec);

 
    while (1) {
        sleep(1); 
    }

    return 0;  
}

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int segundos = 0; 

void manejador(int sig) {
    segundos += 5; 
    printf("Han transcurrido %d segundos\n", segundos);
}
int main() {
    signal(SIGALRM, manejador);
    alarm(5);
    while (1) {
        pause();
        alarm(5); 
    }

    return 0; 
}

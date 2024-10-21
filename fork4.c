#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void manejar_acumulado(int *acumulado, pid_t pid) {
    if (pid % 2 == 0) {  
        *acumulado += 10;
    } else {  
        *acumulado -= 100;
    }
    printf("Proceso (pid: %d), acumulado: %d\n", pid, *acumulado);
}

void proceso_p5(int acumulado) {
    manejar_acumulado(&acumulado, getpid());
    exit(0);
}


void proceso_p4(int acumulado) {
    manejar_acumulado(&acumulado, getpid());
    exit(0);
}


void proceso_p3(int acumulado) {
    manejar_acumulado(&acumulado, getpid());

   
    pid_t p4 = fork();
    if (p4 < 0) {
        perror("Error al crear p4");
        exit(1);
    }

    if (p4 == 0) {
        proceso_p4(acumulado); 
    } else {
        wait(NULL);  
    }

    exit(0);
}


void proceso_p2(int acumulado) {
    manejar_acumulado(&acumulado, getpid());

    
    pid_t p5 = fork();
    if (p5 < 0) {
        perror("Error al crear p5");
        exit(1);
    }

    if (p5 == 0) {
        proceso_p5(acumulado);  
    } else {
        wait(NULL);  
    }

    exit(0);
}

int main() {
    int acumulado = getpid(); 
    printf("Proceso p1 (pid: %d), acumulado inicial: %d\n", getpid(), acumulado);

 
    pid_t p2 = fork();
    if (p2 < 0) {
        perror("Error al crear p2");
        exit(1);
    }

    if (p2 == 0) {
        proceso_p2(acumulado);  
    } else {
        wait(NULL);  

        pid_t p3 = fork();
        if (p3 < 0) {
            perror("Error al crear p3");
            exit(1);
        }

        if (p3 == 0) {
            proceso_p3(acumulado);  
        } else {
            wait(NULL); 
        }
    }

    return 0;
}

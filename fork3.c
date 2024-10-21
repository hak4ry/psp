#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void mostrar_proceso(pid_t pid_padre, pid_t pid_abuelo) {
    printf("Proceso (pid: %d), padre (pid: %d)", getpid(), pid_padre);
    if (pid_abuelo != -1) {
        printf(", abuelo (pid: %d)\n", pid_abuelo);
    } else {
        printf("\n");
    }
}

void proceso_p5(pid_t pid_padre, pid_t pid_abuelo) {
    mostrar_proceso(pid_padre, pid_abuelo);
    exit(0);
}

void proceso_p6(pid_t pid_padre, pid_t pid_abuelo) {
    mostrar_proceso(pid_padre, pid_abuelo);
    exit(0);
}

void proceso_p3(pid_t pid_padre, pid_t pid_abuelo) {
    mostrar_proceso(pid_padre, pid_abuelo);

 
    pid_t p5 = fork();
    if (p5 < 0) {
        perror("Error al crear p5");
        exit(1);
    }

    if (p5 == 0) {
        proceso_p5(getpid(), pid_padre); 
    } else {
        wait(NULL);  
    }

    exit(0);
}

void proceso_p4(pid_t pid_padre, pid_t pid_abuelo) {
    mostrar_proceso(pid_padre, pid_abuelo);

   
    pid_t p6 = fork();
    if (p6 < 0) {
        perror("Error al crear p6");
        exit(1);
    }

    if (p6 == 0) {
        proceso_p6(getpid(), pid_padre);  
    } else {
        wait(NULL); 
    }

    exit(0);
}

void proceso_p2(pid_t pid_padre) {
    mostrar_proceso(pid_padre, -1);  

    
    pid_t p3 = fork();
    if (p3 < 0) {
        perror("Error al crear p3");
        exit(1);
    }

    if (p3 == 0) {
        proceso_p3(getpid(), pid_padre); 
    } else {
        wait(NULL); 
    }

   
    pid_t p4 = fork();
    if (p4 < 0) {
        perror("Error al crear p4");
        exit(1);
    }

    if (p4 == 0) {
        proceso_p4(getpid(), pid_padre); 
    } else {
        wait(NULL);  
    }

    exit(0);
}

int main() {
    printf("Proceso p1 (pid: %d)\n", getpid());

   
    pid_t p2 = fork();
    if (p2 < 0) {
        perror("Error al crear p2");
        exit(1);
    }

    if (p2 == 0) {
        proceso_p2(getpid());  
    } else {
        wait(NULL);  
    }

    return 0;
}

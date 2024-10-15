#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid; 

    pid = fork();

    if (pid < 0) { 
        perror("Error al crear el proceso hijo");
        return 1;
    }

    if (pid == 0) { 
        printf("Soy el hijo. Mi nombre es [Nombre del Alumno]\n");
        
        exit(0); 
    } else { 
        int status;
        waitpid(pid, &status, 0); 
        printf("Soy el padre. Mi PID es %d, y el PID de mi hijo es %d\n", getpid(), pid);
    }

    return 0;
}

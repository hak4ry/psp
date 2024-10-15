#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid2, pid3; 


    pid2 = fork();

    if (pid2 < 0) { 
        perror("Error al crear el proceso P2");
        return 1;
    }

    if (pid2 == 0) { 
        pid3 = fork(); 
        if (pid3 < 0) { 
            perror("Error al crear el proceso P3");
            return 1;
        }

        if (pid3 == 0) { 
         
            printf("Soy el proceso P3. Mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());
            exit(0); 
        } else { 
            printf("Soy el proceso P2. Mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());
            waitpid(pid3, NULL, 0); 
            exit(0); 
    } else { 
        printf("Soy el proceso P1. Mi PID es %d y el PID de mi hijo es %d\n", getpid(), pid2);
        waitpid(pid2, NULL, 0); 
    }
    }
    return 0;
}

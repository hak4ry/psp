#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    int suma_hijo = 0;
    int suma_padre = 0;
    
    // Crear proceso hijo
    pid = fork();
    
    if (pid < 0) {
        printf("Error al crear el proceso hijo.\n");
        return 1;
    } else if (pid == 0) {
        // Este es el proceso hijo
        while (suma_hijo < 100) {
            suma_hijo += rand() % 5 + 1;  // Aumentar con valores entre 1 y 5
            printf("Proceso Hijo: suma = %d\n", suma_hijo);
        
        }
       
    } else {
        while (suma_padre < 100) {
            suma_padre += rand() % 5 + 1; 
            printf("Proceso Padre: suma = %d\n", suma_padre);
        }
        
        
        wait(NULL);
    }

    return 0;
}

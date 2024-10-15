#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
int main() {
    printf("CCC \n");
    
    if (fork() == 0) {
        // Proceso hijo
        printf("BBB \n");
        exit(0);  
    } else {
        
        wait(NULL); 
        printf("AAA \n");
    }

    return 0;
}

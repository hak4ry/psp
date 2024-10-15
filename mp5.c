#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;
    printf("AAA \n");
    
    pid1 = fork();
    
    if (pid1 == 0) {
        
        printf("BBB \n");
        exit(0);  
    } else {
        
        wait(NULL);  

        pid2 = fork();
        
        if (pid2 == 0) {
            
            printf("CCC \n");
            exit(0);  
        } else {
           
            wait(NULL); 
            printf("CCC \n");  
        }
    }
    return 0;
}

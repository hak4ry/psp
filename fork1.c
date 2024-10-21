#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void proceso_p4() {
    if (getpid() % 2 == 0) {
        printf("Proceso p4 (pid: %d), padre: %d\n", getpid(), getppid());
    } else {
        printf("Proceso p4 (pid: %d)\n", getpid());
    }
    exit(0); 
}


void proceso_p3() {
    pid_t p4;

    if (getpid() % 2 == 0) {
        printf("Proceso p3 (pid: %d), padre: %d\n", getpid(), getppid());
    } else {
        printf("Proceso p3 (pid: %d)\n", getpid());
    }

  
    p4 = fork();
    if (p4 < 0) {
        perror("Error al crear p4");
        exit(1);
    }

    if (p4 == 0) {
      
        proceso_p4();
    } else {
      
        wait(NULL);
    }

    exit(0);  
}


void proceso_p2() {
    if (getpid() % 2 == 0) {
        printf("Proceso p2 (pid: %d), padre: %d\n", getpid(), getppid());
    } else {
        printf("Proceso p2 (pid: %d)\n", getpid());
    }
    exit(0); 
}

void main() {
    pid_t p2, p3;

    printf("Proceso p1 (pid: %d)\n", getpid());

    
    p2 = fork();
    if (p2 < 0) {
        perror("Error al crear p2");
        exit(1);
    }

    if (p2 == 0) {
        
        proceso_p2();
    } else {
    
        wait(NULL);

     

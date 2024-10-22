#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define PIPE02 "/tmp/pipe02"

int main() {
    int num, factorial_result;
    int fd1, fd2;
    mkfifo(PIPE02, 0666);
    srand(getpid());
    num = rand() % 10; 
    printf("fifo11: Número generado: %d\n", num);
    fd1 = open(PIPE02, O_WRONLY);
    write(fd1, &num, sizeof(int));
    close(fd1);

    fd2 = open(PIPE02, O_RDONLY);
    read(fd2, &factorial_result, sizeof(int));
    close(fd2);

    printf("fifo11: Factorial de %d es: %d\n", num, factorial_result);
   
    unlink(PIPE02);

    return 0;
}

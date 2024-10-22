#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FIFO1 "/tmp/fifo1"
#define FIFO2 "/tmp/fifo2"

int main() {
    int num, factorial_result;
    int fd1, fd2;
  
    mkfifo(FIFO1, 0666);
    mkfifo(FIFO2, 0666);
    srand(getpid());
    num = rand() % 50; 
    printf("fifo11: Número generado: %d\n", num);
    fd1 = open(FIFO1, O_WRONLY);
    write(fd1, &num, sizeof(int));
    close(fd1);
    fd2 = open(FIFO2, O_RDONLY);
    read(fd2, &factorial_result, sizeof(int));
    close(fd2);

    printf("fifo11: Factorial de %d es: %d\n", num, factorial_result);

    unlink(FIFO1);
    unlink(FIFO2);

    return 0;
}

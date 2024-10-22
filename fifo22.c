#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define PIPE02 "/tmp/pipe02"


int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}
int main() {
    int num, result;
    int fd1, fd2;

    fd1 = open(PIPE02, O_RDONLY);
    read(fd1, &num, sizeof(int));
    close(fd1);
   
    result = factorial(num);
    printf("fifo12: Factorial calculado de %d es %d\n", num, result);

    fd2 = open(PIPE02, O_WRONLY);
    write(fd2, &result, sizeof(int));
    close(fd2);

    return 0;
}

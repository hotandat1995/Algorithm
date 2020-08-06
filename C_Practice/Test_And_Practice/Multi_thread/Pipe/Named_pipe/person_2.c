#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

static char * myfifo = "/tmp/myfifo";

int main(int argc, int **argv)
{
    int fd;
    mkfifo(myfifo, 0666);
    char str1[] = "Hi person 1";
    char str2[80];
    sleep(1);

    while (1)
    {
        fd = open(myfifo, O_WRONLY);
        write(fd, str1, strlen(str1)+1);
        close(fd);
        sleep(2);

        fd = open(myfifo, O_RDONLY);
        read(fd, str2, 80);
        close(fd);
        sleep(2);

        printf("P2 received: %s\n", str2);
    }

    return 0;
}
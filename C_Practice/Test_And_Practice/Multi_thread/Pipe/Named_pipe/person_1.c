#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// FIFO file path
static char * myfifo = "/tmp/myfifo";

int main()
{
    int fd;
    // Creating the named file(FIFO)
    // mkfifo(<pathname>,<permission>)
    mkfifo(myfifo, 0666);

    char str1[] = "Hi person 2";
    char str2[80];
    while (1)
    {
        // First open in read only and read
        fd = open(myfifo, O_RDONLY);
        read(fd, str2, 80);
        close(fd);

        printf("P1 received: %s\n", str2);
        sleep(2);

        fd = open(myfifo, O_WRONLY);
        write(fd, str1, strlen(str1)+1);
        close(fd);
        sleep(2);

        // Deleting the named pipe
        //unlink();
    }
    return 0;
}
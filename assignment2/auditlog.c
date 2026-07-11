#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (strcmp(argv[1], "--add") == 0){
        int fd = open("audit.log", O_WRONLY | O_CREAT | O_APPEND, 0644);
        write(fd, argv[2], strlen(argv[2]));
        write(fd, "\n", 1);
        close(fd);
    }

    else if (strcmp(argv[1], "--view") == 0){
        int fd = open("audit.log", O_RDONLY);
        char ch;
        int line = 1;

        printf("%d: ", line);

        while (read(fd, &ch, 1) > 0){
            putchar(ch);
            if (ch == '\n'){
                if (read(fd, &ch, 1) > 0){
                    line++;
                    printf("%d: ", line);
                    putchar(ch);
                }
            }
        }
        close(fd);
    }
    return 0;
}

#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd[2];
    pipe(fd);
    int pid = fork();
    if (pid == 0)
    {
        close(0);
        dup(fd[0]);
        close(fd[1]);
        execlp("wc", "wc", "-l", NULL);
    }
    else
    {
        close(1);
        dup(fd[1]);
        close(fd[0]);
        execlp("ls", "ls", NULL);
    }
    return 0;
}
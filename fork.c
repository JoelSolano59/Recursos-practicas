#include <stdio.h>
#include <unistd.h>

int main()
{
    while (1)
    {
        int pid = fork();
        if (pid == 0)
        {
            printf("Child process\n");
        }
        else
        {
            printf("Father: this | Child: %d\n", pid);
        }
    }
}
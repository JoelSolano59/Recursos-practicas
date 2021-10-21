#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

int main()
{
    char c;
    char upperC;
    int n;

    do
    {
        n = read(STDIN_FILENO, &c, 1);
        upperC = toupper(c);
        write(STDOUT_FILENO, &upperC, 1);
    } while (n != 0);

    return 0;
}
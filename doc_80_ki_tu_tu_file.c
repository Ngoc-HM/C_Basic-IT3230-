#include <stdio.h>
#include <stdlib.h>
enum {Max = 80};
int main()
{
    int num;
    FILE *ptr;
    char filename[]="haiku.txt";
    char buff[Max+1];
    if ((ptr= fopen(filename, "r")) == NULL)
    {
        printf("doc that bai.\n");
        reval = FALL ; exit(1);
    }
    num = fread(buff, sizeof(char), Max, fin);
    buff[num * sizeof(char)] = '\0';
    printf("%s", buff);
    return 0;
    
}
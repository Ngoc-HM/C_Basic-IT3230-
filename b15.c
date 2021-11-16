#include <stdio.h>
#include <string.h>
int main()
{
    char a[100];
    int max, tg, c[26]={0};
    gets(a);
    max = strlen(a);
    for (int i = 0; i < max; i++)
    {
        if(a[i] >= 'a' && a[i] <= 'z') c[a[i]-'a']+=1;
    }
     for (int i = 0; i < 26; i++)
     {
         if(c[i]>0) printf("ki tu %c xuat hien %d lan \n ", 'a'+i, c[i]);

     }

  return 0;   

}
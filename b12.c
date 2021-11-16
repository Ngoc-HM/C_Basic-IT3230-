#include <stdio.h>
int main()
{
    int n,a[100],b[100],c[100], le=0, chan=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) 
    {
    scanf("%d",&a[i]);
    if (a[i]%2 != 0) {b[le]=a[i] ; le+=1;}
    else {c[chan]=a[i]; chan+=1;}    
    }
    printf("Mang ban nhap : ");
    for(int i=0;i<n;i++) printf("%d, ",a[i]);
    printf("\nMang gom %d so le la : ", le); for(int i=0;i<le;i++) printf("%d, ",b[i]);
    printf("\nMang gom %d so chan la : ", chan); for(int i=0;i<chan;i++) printf("%d, ",c[i]);
    return 0;

}
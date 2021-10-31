#include <stdio.h>
int main()
{
    int a[10],n;
    printf("Nhap so phan tu cua mang = "); scanf("%d",&n);
    for(int i=0 ; i<n ; i++) scanf("%d", &a[i]);
    printf("\n");
    printf(" Mang dao nguoc la : ");
    for (int i = n-1 ; i>=0  ; i--)
    {
        printf("%d, ",a[i]);
    }

    return 0;
}

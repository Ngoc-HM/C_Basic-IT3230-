#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,n, *p;
    printf("Nhap so nguyen : ") ; scanf("%d",&n);
    p = (int *)malloc(n*sizeof(int));
    if(p == NULL)
    {
        printf("Cap phat that bai. \n");
        return 1;
    }
    else printf("Cap phat thanh cong \n");
    // giải phóng bộ nhớ đã được cấp phát 
    free(p);
    return 0;
}

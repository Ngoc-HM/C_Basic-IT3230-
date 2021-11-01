#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *ptr;
    int *p;
    int i=0,n,giatri, tong=0;
    int reval = SUCCESS;
    printf("Nhap so luong so can xuat file out.txt : "); scanf("%d",&n);
    p=(int *)malloc(n*sizeof(int)) ;
    while (i<n)
    {
        scanf("%d", &giatri);
        p[i++]=giatri;
        tong+=giatri;
    }
    if ((ptr=fopen("out.txt","w")) == NULL )
    {
        printf("Cap phat that bai.\n");
        reval = FAIL;
    }
    for ( i = n-1 ; i >= 0; i--)
    {
        fprintf(ptr,"%d ",p[i]);
    }
    fprintf(ptr,"%d",tong);
    fclose(ptr);
    free(p);
    return reval;
     
}
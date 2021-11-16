#include <stdio.h>
#define MAX 100
int sapxep(int a[MAX], int n)
{
  for(int i=0; i<n ; i++)
   for(int j=i ; j<n ; j++)
    if (a[i]>a[j])
    {
      int tg = a[i];
      a[i] = a[j];
      a[j] = tg;
    }
    for (int i = 0; i < n; i++)
    {
      printf("%d, ",a[i]); 
    }
    
}
int main()
{
    int n,m,a[100],b[100],c[100]={0},tg=0, max=0;
    scanf("%d %d",&n,&m);
    printf("bat dau nhap mang a[n] : ");
      for(int i=0;i<n;i++) 
      { scanf("%d",&a[i]); if(max<a[i]) max=a[i];} 
    printf(" bat dau nhap mang b[m] : ");
      for(int i=0;i<m;i++) 
      { scanf("%d",&b[i]);  if(max<b[i]) max=b[i]; } 
    
    printf("\n so phan tu chung la : ");
    for(int i=0;i<n;i++)
     for(int j=0;j<n;j++)
       if(a[i]==b[j]) 
      {
         int dem=a[i];
		     c[dem]=a[i];
	    }

      for(int i=0; i<max ; i++) 
      {
        if(c[i]>0) { printf("%d, ",c[i]); tg+=1; }
      }
      if (tg==0) printf("khong co phan tu chung nao"); 
      else printf("co %d phan tu chung ", tg);
      printf("\n mang a sau xap xep : ");
      sapxep(a, n);
      printf("\n mang b sau sap xep : ");
      sapxep(b,m);
      printf("\n");
      tg=m+n;
      for (int i = 0; i < tg ; i++)
      {
        if(i<n) c[i]=a[i];
        else c[i]=b[i-n];
      }
        sapxep(c,(m+n));
      return 0;
}

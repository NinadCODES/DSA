#include<stdio.h>
void cntsrt(int a[],int n,int pass)
{
  int count[10]={0},i,final[n];
  for(i=0;i<n;i++)
  {
    ++count[(a[i]/pass)%10];
  }
  for(i=1;i<9;i++)
  {
    count[i]=count[i]+count[i-1];
  }
  for(i=n-1;i>=0;i--)
  {
    final[--count[(a[i]/pass)%10]]=a[i];
  }
  for(i=0;i<n;i++)
  {
    a[i]=final[i];
  }
  
}
void radix_srt(int a[],int n,int max)
{
  int pass;
  for(pass=1;(max/pass)>0;pass=(pass)*10)
  cntsrt(a,n,pass);
}

void main()
{
  int i,n,max=0;
  printf("Enter no. of elements: ");
  scanf("%d",&n);
  int a[n];
  printf("\nEnter the elements:\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++)
  {
    if(max<a[i])
    max=a[i];
  }
  
  radix_srt(a,n,max);
  printf("|Sorted array USING RADIX SORT :");
  for(i=0;i<n;i++)
  {
    printf("%4d",a[i]);
  }
}














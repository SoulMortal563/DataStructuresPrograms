#include<stdio.h>
int main()
{
	
   int i, j, temp,n, arr[5]={1.2,5.9,3.2,7.9,10.9};
  
   for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
   for(i=1;i<n;i++)
   {
      temp=arr[i];
      j=i-1;
      while((temp<arr[j])&&(j>=0))
      {
         arr[j+1]=arr[j];
         j=j-1;
      }
      arr[j+1]=temp;
   }

   printf("Order of Sorted elements: ");
   for(i=0;i<n;i++)
      printf(" %d",arr[i]);

   return 0;
}

#include <stdio.h>
void mergeSort(int arr[],int lb, int mid, int ub);
void partition(int arr[],int lb,int ub);
int main()
{
   int arr[50];
   int i, n;
	printf("Enter total number of elements:");
	scanf("%d", &n);
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
    {
         scanf("%d", &arr[i]);
    }
    partition(arr, 0, n-1);
    printf("After merge sort:\n");
    for(i = 0;i < n; i++)
    {
         printf("%d   ",arr[i]);
	}
   return 0;
}
void partition(int arr[],int lb,int ub)
{
    int mid;
    if(lb < ub)
    {
        mid = (lb + ub) / 2;
        partition(arr, lb, mid);
        partition(arr, mid + 1, ub);
        mergeSort(arr, lb, mid, ub);
    }
}
void mergeSort(int arr[],int lb,int mid,int ub)
{
    int i, j, k, b[50];
    k = 0;
    i = lb;
    j = mid + 1;
    while ((i<= mid) && (j <= ub))
    {
        if (arr[i] <= arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i> mid)
    {
        while(j<=ub)
        {
            b[k] = arr[j];
            j++;
        }
    }
    else
    {
        {
             b[k] = arr[i];
             i++;
        }
        k++;
    }
	for (i = lb; i <=ub; i++)
    {
        arr[i] = b[k];
    }
}

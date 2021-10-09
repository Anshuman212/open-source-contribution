
#include <stdio.h>
#include <math.h>
void merge(int a[],int left,int mid,int right);
void mergesort(int a[],int left,int right);
void print_array(int a[],int n);

void mergesort(int a[],int left,int right)
{
    //Merge sort works on divide and conquer technique. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves. The merge() function is used for merging two halves. The merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.
    if(left<right)
    {
        int mid=((left+right-1)/2);
        mergesort(a, left,mid);
        mergesort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  
void print_array(int a[],int n)
{ printf("the sorted array is:\n");
    for(int i=0;i<n;i++)
{
    printf("%d,",a[i]);
}
printf("\n");
}


int main()
{
   int n;
   printf("Enter the size of the array\n");
   scanf("%d",&n);
   int a[n];
    printf("Enter the array elements\n");
   for(int i=0;i<n;i++)
   {
       scanf("%d,",&a[i]);
   }
   
   mergesort(a,0,n-1);
   print_array(a,n);

    return 0;
}




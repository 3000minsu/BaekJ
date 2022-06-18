#include <stdio.h>
int main()
{
    int arr1[50];
    int arr2[50];
    int n, temp;
    scanf("%d", &n);
    for(int i=0;i<n; i++)
        scanf("%d", &arr1[i]);
    for(int i=0; i<n; i++)
        scanf("%d", &arr2[i]);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            if(arr1[j]>arr1[j+1])
            {
                temp=arr1[j];
                arr1[j]=arr1[j+1];
                arr1[j+1]=temp;
            }  
            if(arr2[j]<arr2[j+1])
            {
                temp=arr2[j];
                arr2[j]=arr2[j+1];
                arr2[j+1]=temp;
            }  
        }
    } 
    temp=0;
    for(int i=0; i<n; i++)
        temp+=arr1[i]*arr2[i];
    printf("%d", temp);
    return 0;
}
#include<stdio.h>
int main()
{
    int arr[20],n,key,i,lb,ub,mid,flag=0;
    printf("\nHow many elements you want to enter:");
    scanf("%d",&n);
    printf("\nEnter the elements in ascending order:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the elements which you want to search:");
    scanf("%d",&key);
    lb=0,ub=n-1;
    mid=(lb+ub)/2;
    while(lb<=ub)
    { 
      if(arr[mid]==key)
      {
        flag=1;
        printf("\nThe %d element is found at %d position in the Index",key,mid);
        break;
      }
      else
      {
        if(arr[mid]<key)
        {
            lb=mid+1;
        }
        else
        {
           ub=mid-1;
        }
      }
      mid=(lb+ub)/2;
    }
    if(flag==0)
    {
        printf("\nThe %d element is not found",key);
    }
    return 0;
}
#include<stdio.h>
int main()
{
    int arr[20],i,key,n,f=0;
    printf("\n How many elements you want to enter:");
    scanf("%d",&n);
    printf("\n Enter the elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n Enter the elements which you want to search:");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(key==arr[i])
        {
            f=1;
            break;
        }  
    }
    if(f==1)
        {
            printf("The element is found at the %dth position in the Index.",i);
        }
        else
        {
            printf("\n The element is not found");
        }
        
     return 0;   
}
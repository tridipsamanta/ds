#include<stdio.h>
#include<stdlib.h>
void bubble(int a[], int n)
{
    int i, j, temp;
    for(i=0; i<n;i++)
    {
      for(j=0; j<n-i-1;j++)
       {
         if(a[j]>a[j+1])
          {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
          }
        }
    }
}
void selection(int a[], int n)
{
   int i, j, temp;
   for(i=0;i<n-1;i++)
   {
    for(j=i+1;j<n;j++)
     {
      if(a[i]<a[j])
       {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
       }
     }
    }
}

void main()
{
    int a[20],n,i, opt;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    for(;;)
    {
        printf("\n ***** Sorting *****\n");
        printf("\n 1. Selection Sort (Descending Order) \n 2. Bubble Sort(Ascending Order) \n 3. Exit ");
        printf("\n Enter your option:");
        scanf("%d",&opt);
        switch(opt)
            {
            case 1:
                    printf("\nEnter array elements:\n");
                    for(i=0;i<n;i++)
                    {
                    scanf("%d",&a[i]);
                    }
                    selection(a, n);
                    printf("\nElements in Descending order:\n");
                    for(i=0;i<n;i++)
                    {
                     printf("%d \t", a[i]);
                    } 
                    break;
            case 2: 
                    printf("\nEnter array elements:\n");
                    for(i=0;i<n;i++)
                    {
                     scanf("%d",&a[i]);
                    }
                    bubble(a, n);
                    printf("\nElements in ascending order:\n");
                    for(i=0;i<n;i++)
                    {
                     printf("%d \t", a[i]);
                    } 
                    break;
            case 3: 
                    default: exit(0);
            }
    }
}

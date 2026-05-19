#include<stdio.h>
#include<stdlib.h>
void display();
void insert();
void delete_begin();
void delete_end();
void delete_pos();
struct node
{
 int info;
 struct node *next;
};
struct node *start=NULL;

int main()
{
        int choice;
        while(1){
        printf("\n MENU\n");
        printf(" 1.Insert\n");
        printf(" 2.Display\n");
        printf(" 3.Delete from beginning\n");
        printf(" 4.Delete from the end\n");
        printf(" 5.Delete from specified position\n");
        printf(" 6.Exit\n");
        printf("------------------------------------- \n");
        printf("Enter your choice:\t");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1: insert();
                break;
        case 2: display();
                break;
        case 3: delete_begin();
                break;
        case 4: delete_end();
                break;
        case 5: delete_pos();
                break;
        case 6: exit(0);
                break;
        default: printf("\n Wrong Choice! Please Enter a valid choice:\n");
                 break;
        }
       }
    return 0;    
} 

void insert()
{
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
if(temp==NULL)
{
  printf("\nOut of Memory Space:\n");
  return;
}
printf("\nEnter the data value for the node:\t");
scanf("%d",&temp->info);
temp->next =NULL;
if(start==NULL)
{
    start=temp;
}
else
{
    temp->next=start;
    start=temp;
}
}
void display()
{
struct node *ptr;
if(start==NULL)
{
  printf("\nList is empty:\n");
  return;
}
else
{
    ptr=start;
    printf("\nThe List elements are:\n");
    while(ptr!=NULL)
    {
        printf("%d--->\t",ptr->info );
        ptr=ptr->next;
    }
}
}
void delete_begin()
{
    struct node *ptr;
    if(ptr==NULL)
    {
       printf("\nList is Empty:\n");
       return;
    }
    else
    {
        ptr=start;
        start=start->next ;
        printf("\nThe deleted element is :%d\t",ptr->info);
        free(ptr);
    }
}

void delete_end()
{
    struct node *temp,*ptr;
    if(start==NULL)
    {
    printf("\nList is Empty:");
    exit(0);
    }
    else if(start->next ==NULL)
    {
      ptr=start;
      start=NULL;
      printf("\nThe deleted element is:%d\t",ptr->info);
      free(ptr);
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
        temp=ptr;
        ptr=ptr->next;
        }
        temp->next=NULL;
        printf("\nThe deleted element is:%d\t",ptr->info);
        free(ptr);
    }
}
void delete_pos()
{
    int i,pos;
    struct node *temp,*ptr;
    if(start==NULL)
    {
        printf("\nThe List is Empty:\n");
        exit(0);
    }
    else
    {
        printf("\nEnter the position of the node to be deleted:\t");
        scanf("%d",&pos);
        if(pos==0)
        {
            ptr=start;
            start=start->next ;
            printf("\nThe deleted element is:%d\t",ptr->info);
            free(ptr);

        }
        else
        {
            ptr=start;
            for(i=0;i<pos;i++)
            {
             temp=ptr; 
             ptr=ptr->next;
             if(ptr==NULL)
                {
                printf("\nPosition not Found:\n");
                return;
                }
            }
            temp->next=ptr->next ;
            printf("\nThe deleted element is:%d\t",ptr->info );
            free(ptr);
        }
    }
}
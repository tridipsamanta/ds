#include<stdio.h>
#include<string.h>
char infix[50],postfix[50],stack[25];
int top=-1;
void convert_fun();
int precedence(char);
void push(char);
char pop();

void main()
{
 printf("\nEnter the infix expression:\n");
 scanf("%s",infix);
 convert_fun();
 printf("\n\t THE INFIX EXPRESSION :%s",infix);
 printf("\n\t THE POSTFIX EXPRESSION:%s",postfix);
}

void convert_fun()
{
 int i=0,j=0;
 char c,tmp;
 push('#');
 while(i<strlen(infix))
 {
  c=infix[i++];
  switch(c)
  {
   case '(' :
    {
     push(c);
     break;
    } 
   case ')' :
   {
    tmp=pop();
    while(tmp!='(')
     {
       postfix[j++]=tmp;
       tmp=pop();
     }
     break;
    } 
   case'+':
   case'-':
   case'*':
   case'/':
   case'^':
      while(precedence(stack[top])>=precedence(c))
       {
        tmp=pop();
        postfix[j++]=tmp;
       }
      push(c);
      break;
   default: 
    {
     postfix[j++]=c;
     break;
    } 
   } 
  }
 while(top>0)
 {
  tmp=pop();
  postfix[j++]=tmp;
 }
}

void push(char c)
{
  stack[++top]=c;
}

char pop()
{
  return(stack[top--]);
}

int precedence(char c)
{
  switch(c)
  {
   case'^':return (3);
   case'*':
   case'/': return(2);
   case '+':
   case'-':return(1);
   case'(':
   case')':return(0);
   case'#':return(-1);
  }
}
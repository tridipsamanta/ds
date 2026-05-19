#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int top,s[100];
int cal(char sym,int op1,int op2)
{
   switch(sym)
   {
    case'+' : return(op1+op2);
    case'-' : return(op1-op2);
    case'*' : return(op1*op2);
    case'/' : return(op1/op2);
    case'^' : return(pow(op1,op2));
   }
return 0;
}
void main()
{
  int i,op1,op2;
  char pf[100],sym;
  top=-1;
  printf("enter the postfix expression:");
  gets(pf);
  for(i=0;i<strlen(pf);i++)
  {
   sym=pf[i];
   if(isdigit(sym))
   {
    s[++top]=sym-'0';
   }
   else
   {
     op2=s[top--];
     op1=s[top--];
     s[++top]=cal(sym,op1,op2);
   }
  }

printf("\n value of %s is %d",pf,s[top--]);
getch();
}
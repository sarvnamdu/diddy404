/** Evaluation of postfix expression**/

#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#define maxsize 10
struct stackarray
{
int top;
int operand[maxsize];
}
stack;
void push(int oprd)
{
stack.top++;
stack.operand[stack.top]=oprd;
}
int pop()
{
int tmp;
tmp=stack.operand[stack.top];
stack.top--;
return(tmp);
}
void main()
{
int len,i,op1,op2,result;
char exp[20];
stack.top=-1;
clrscr();
printf("\nenter postfix expresion :");
scanf("%s",&exp);
len=strlen(exp);
for(i=0;i<len;i++)
if(isdigit(exp[i]))
push(exp[i]-'0');
else
{
op1=pop();
op2=pop();
switch(exp[i])
{
case'+':
result=op1+op2;
break;
case '-':
result=op1-op2;
break;
case '*':
result=op1*op2;
break;
case '/':
result=op1/op2;
break;
}
push(result);
}
printf("\nthe result of given expresion is%d",result);
getch();
}
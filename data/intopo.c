/**Conversion of Infix expression to Postfix form**/

#include<stdio.h>
#include<conio.h>
#include<alloc.h>
 char inf[40],post[40];
 int top=0,st[20];
 void postfix();
 void push(int);
 char pop();
 void main(void)
 {
	 clrscr();
	 printf("\n\tEnter the infix expression :: \n\n\t\t");
	 scanf("%s",inf);
	 postfix();
	 getch();
 }
 void postfix()
 {
	int i,j=0;
	for(i=0;inf[i]!='\0';i++)
	{
	switch(inf[i])
	{
		case '+' : while(st[top] >= 1)
		  post[j++] = pop();
		  push(1);
		  break;
		case '-' : while(st[top] >= 1)
		  post[j++] = pop();
		  push(2);
		  break;
		case '*' : while(st[top] >= 3)
		  post[j++] = pop();
		  push(3);
		  break;
		case '/' : while(st[top] >= 3)
		  post[j++] = pop();
		  push(4);
		  break;
		case '^' : while(st[top] >= 4)
		  post[j++] = pop();
		  push(5);
		  break;
		case '(' : push(0);
		  break;
		case ')' : while(st[top] != 0)
		  post[j++] = pop();
		  top--;
		  break;
		default  : post[j++] = inf[i];
	}
	}
	while(top>0)
	post[j++] = pop();
	printf("\n\tPostfix expresion is =>\n\n\t\t %s",post);
 }
  void push(int ele)
 {
	top++;
	st[top] = ele;
 }
  char pop()
 {
	int el;
	char e;
	el = st[top];
	top--;
	switch(el)
	{
		case 1 : e = '+';
		break;
		case 2 : e = '-';
		break;
		case 3 : e = '*';
		break;
		case 4 : e = '/';
		break;
		case 5 : e = '^';
		break;
	}
	return(e);
 }
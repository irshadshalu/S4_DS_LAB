#include<stdio.h>
#include<stdlib.h>
char stack[100];
int top=-1,maxsize=100;
void push(char n)
{
	if(top == maxsize )
			printf(" StackOverflow \n");
	else
	{	
		top++;
		stack[top]=n;
	}
}
char pop()
{
	if(top==-1)
	{
		return 0;
	}
	else
	{
		top--;
		return stack[top+1];
	}
}
int prec(char a)
{
	if(a=='+' || a=='-')
		return 1;
	if(a=='*' || a=='/')
		return 2;
	return 0;
}
int main()
{
	char infix[100],postfix[100]="",temp;
	int i,j,g=0,valid=1;
	printf(" Enter Infix Expression : ");
	scanf("%s",infix);
	for(i=0;infix[i]&&valid;i++)
	{
		char c=infix[i];
		if(c=='(')
			push('(');
		else if(isalnum(c))
			postfix[g++]=c;
		else if(c==')')
		{
			while((temp=pop())!='(' && temp!=0)
				postfix[g++]=temp;
			if(temp==0)
				valid=0;
		}
		else if(prec(c))
		{
			while((temp=pop())!=0 && prec(temp)>=prec(c))
				postfix[g++]=temp;
			if(temp!=0)
				push(temp);
			push(c);
		}
		else
			valid=0;
		
	}
	while((temp=pop())!=0)
		postfix[g++]=temp;
	if(valid)
		printf(" Postfix Expression : %s\n",postfix);
	else
		printf(" Invalid Expression ");
}
				
	


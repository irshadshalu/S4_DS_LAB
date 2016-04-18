#include<stdio.h>
#include<stdlib.h>
double stack[100];
int top=-1,maxsize=100;
void push(double n)
{
	if(top == maxsize )
			printf(" StackOverflow \n");
	else
	{	
		top++;
		stack[top]=n;
	}
}
double pop()
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
int main()
{
	char postfix[100];
	double temp1,temp2;
	int i,valid=1;
	printf(" Enter Postfix Expression : ");
	scanf("%s",postfix);
	for(i=0;postfix[i]!='\0' && valid;i++)
	{
		char c=postfix[i];
		if(isdigit(c))
			push(c-'0');
		else 
		{
			temp1=pop();
			temp2=pop();
			if(top<-1)
				valid=0;
			switch(c)
			{
				case '+':
					push(temp2+temp1);
					break;

				case '-':
					push(temp2-temp1);
					break;

				case '*':
					push(temp2*temp1);
					break;

				case '/':
					if(temp2==0)
					{
						valid=0;
						break;
					}
					push(temp2/temp1);
					break;
				default:
					valid=0;
					break;
			}

		}
	}
	if(top!=0)
		valid=0;
	if(valid)
		printf(" Result : %.2f\n",pop());
	else
		printf(" Invalid Expression ");
}
				
	


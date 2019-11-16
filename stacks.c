#include<stdio.h>
int n=500;
//scanf("%d",&n);
int arr[n+1];
int head=0;
int push(int val)
{
	if(head!=n)
	{
		arr[head]=val;
		head=head+1;
	}
	else
	{
		printf("stack is full\n");
	}
}
int pop()
{
	head=head-1;
}
int display()
{
	for(int i=0;i<head;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main ()
{
	push(3);
	push(4);
	push(5);
	push(6);
	display();
	//pop();
	//display();
	//pop();

	display();
}

#include<stdio.h>
int n;
int arr[1000];
int f=0;
int r=0;
int enque(int val)
{
	arr[r]=val;
	if(r==n-1)
	{
		r=0;
	}
	else
	{
		r++;
	}
}
int deque()
{
	int k=arr[f];
	if(f==n-1)
		f=0;
	else
		f=f+1;
	return k;
}
int size()
{
	if(r>f)
	{
		printf("%d\n", r-f);
	}

	else
	{
		printf("%d\n",n-f+r);
	}
}
int display()
{
	if(r>f)
	{
		for(int i=f;i<r;i++)
		{
			printf("%d ",arr[i]);
		}
		//printf("\n");
	}
	else
	{
		for(int i=f;i<n;i++)
		{
			printf("%d ",arr[i]);
		}
		for(int i=0;i<r;i++)
		{
			printf("%d ",arr[i]);
		}
	}
	printf("\n");
}


int main ()
{
	n=5;
	enque(5);
	enque(3);
		enque(7);
		deque();
		deque();
		enque(8);
		enque(9);
		enque(10);
		display();
	size();
}

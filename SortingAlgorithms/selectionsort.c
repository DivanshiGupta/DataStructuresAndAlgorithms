#include<stdio.h>
int selsort(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		int k=arr[i];
		int mi=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[mi])
			{
				mi=j;
			}
		}
		if(mi!=i)
		{
			int temp=arr[i];
			arr[i]=arr[mi];
			arr[mi]=temp;
		}
	}
}
int main ()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);

	}
	selsort(arr,n);
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}

	

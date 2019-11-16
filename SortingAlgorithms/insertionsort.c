#include<stdio.h>
void insort(int arr[],int n)
{
	for(int i=1;i<n;i++)
	{
		int k=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>k)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=k;
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
	insort(arr,n);
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}

}


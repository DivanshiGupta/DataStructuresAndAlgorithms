#include<stdio.h>
#include<stdlib.h>
struct nodes{
	int value;
	struct nodes *left;
	struct nodes *right;
};
struct nodes *head=NULL;
struct nodes *head1=NULL;
struct nodes *head2=NULL;
struct nodes *head3=NULL;
struct nodes *head4=NULL;
struct nodes *head5=NULL;
void del(int val)
{
	head1=head;
	while(head1->value != val)
	{
		if(val>head1->value)
		{
			head2=head1;
			head1=head1->right;
		}
		else
		{
			head2=head1;
			head1=head1->left;
		}
	}
	if(head1->left == NULL && head1->right== NULL)
	{
		
		if(head1==head)
		{
			head==NULL;
		}
		{
		if(head1->value > head2->value)
		{
			head2->right=NULL;
		}
		else
		{
			head2->left =NULL;
		}
	}
	}
	else if( (head1->left == NULL && head1->right != NULL) || (head1->right==NULL && head1->left !=NULL)) 
	{
		if(head1==head)
		{
			if(head1->left!=NULL)
			{
				head=head1->left;
			}
			else
			{
				head=head1->right;
			}
		}
		else
		{if(head1->left != NULL)
		{
			if(head1->value > head2->value)
			{
				head2->right = head1->left;
			}
			else
			{
				head2->left =head1->left;
			}
		}
		else if (head1->right !=NULL)
		{
			if(head1->value > head2->value)
			{
				head2->right = head1->right;
			}
			else
			{
				head2->left=head1->right;
			}
		}
	}
	}
	else
	{
		head3=head1;
		head4=head2;
		while(head3->left != NULL)
		{
			head4=head3;
			head3=head3->left;
		}
		int k=head3->value;
		int t= head3->value;
		head3->value=head1->value;
		head1->value=t;
		if(head3->right== NULL && head3->left == NULL)
		{
			if(k>head4->value)
			{
				head4->right=NULL;
			}
			else
			{
				head4->left=NULL;
			}
		}
		else
		{
			if(k>head4->value)
			{
				head4->right=head3->right;
			}
			else
			{
				head4->left=head3->right;
			}
		}
	}

}

void add(int val)
{
	struct nodes *node;
	node=(struct nodes *)malloc(sizeof(struct nodes));
	if(head==NULL)
	{
		head=node;
		node->value=val;
		node->left=NULL;
		node->right=NULL;
	}
	else
	{
		node->value=val;
		node->left=NULL;
		node->right=NULL;
		head1=head;
		while(head1 != NULL)
		{
			if(val > head1->value)
			{
				head2=head1;
				head1=head1->right;
			}
			else
			{
				head2=head1;
				head1=head1->left;
			}
		}
		if(val > head2->value)
		{

			head2->right=node;
		}
		else
		{
			head2->left=node;
		}
		//node->value=val;
		//node->right=NULL;
		//node->left=NULL;
	}
}
int print(struct nodes *node)
{
	head1=node;
	if(head1==NULL)
		return 0;
	else
	{
		print(node->left);
		printf("%d ",node->value);
		print(node->right);
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
		add(arr[i]);
	}
	int m;
	scanf("%d",&m);
	int arr1[m];
	for(int i=0;i<m;i++)
	{
		scanf("%d",&arr[i]);
		del(arr[i]);
		print(head);
		printf("\n");
	}
	//print(head);

}


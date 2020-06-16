#include <stdio.h>
#include <stdlib.h>
typedef struct nodes
{
	int value;
	struct nodes *nextnode;
};
struct nodes *head = NULL;
int add(int val)
{
	struct nodes *node = (struct nodes *)malloc(sizeof(struct nodes));
	if (head == NULL)
	{
		node->value = val;
		head = node;
		node->nextnode = NULL;
	}
	else
	{
		node->value = val;
		node->nextnode = head;
		head = node;
	}
}
int delete (int val)
{
	struct nodes *node;
	node = head;
	if (head == NULL)
	{
		return 0;
	}
	if (node->value == val)
	{
		head = node->nextnode;
	}
	while (node->nextnode != NULL)
	{
		if ((node->nextnode)->value == val)
		{
			node->nextnode = (node->nextnode)->nextnode;
		}
		node = node->nextnode;
	}
	return 0;
}

int display()
{
	struct nodes *node;
	node = head;
	while (node->nextnode != NULL)
	{
		printf("%d ", node->value);
		node = node->nextnode;
	}
	printf("%d\n", node->value);
}

int insertatlast(int val)
{
	struct nodes *node;
	struct nodes *new = (struct nodes *)malloc(sizeof(struct nodes));
	node = head;
	while (node->nextnode != NULL)
	{
		node = node->nextnode;
	}
	new = node;
	new->value = val;
	new->nextnode = NULL;
}
int reverse()
{
	struct nodes *node;
	struct nodes *temp;
	struct nodes *temp1;
	node = head;
	temp = node->nextnode;
	node->nextnode = NULL;
	while (temp->nextnode != NULL)
	{
		temp1 = temp->nextnode;
		temp->nextnode = node;
		node = temp;
		temp = temp1;
	}
	temp->nextnode = node;
	head = temp;
}

int main()
{
	add(10);
	add(30);
	add(40);
	add(50);
	add(60);
	display();
	delete (40);
	reverse();
	display();
}

#include <stdio.h>
#include <stdlib.h>

struct ListHeadNode
{
	int value;
	struct ListHeadNode* right;
	struct ListHeadNode* down;
};

struct ListHeadNode* createNode(int n)
{
	struct ListHeadNode* vertex = (struct ListHeadNode*) malloc(sizeof(struct ListHeadNode));
	if (vertex)
	{
		vertex->value = n;
		vertex->right = NULL;
		vertex->down = NULL;
	}
	return vertex;
}

void insertNode(struct ListHeadNode** array, int n)
{
	if (*array == NULL)
	{
		*array = createNode(n);
	}
	else
	{
		insertNode(&(*array)->right, n);
	}
}

void insertChild(struct ListHeadNode** array, int m)
{
	if ((*array)->down == NULL)
	{
		(*array)->down = createNode(m);
	}
	else
	{
		insertChild(&(*array)->down, m);
	}
}

void insertSingleEdge(struct ListHeadNode** array, int n, int m)
{
	if (*array == NULL)
	{
		return;
	}
	else if ((*array)->value == n)
	{
		insertChild(array, m);
	}
	else
	{
		insertSingleEdge(&(*array)->right, n, m);
	}
}

void insertEdge(struct ListHeadNode** array, int n, int m)
{
	insertSingleEdge(array, n, m);
	insertSingleEdge(array, m, n);
}

void printList(struct ListHeadNode* array)
{
	while (array != NULL)
	{
		printf("Wierzcholek %d: ", array->value);
		struct ListHeadNode* bottom = array->down;
		while (bottom != NULL)
		{
			printf("%d ", bottom->value);
			bottom = bottom->down;
		}
		printf("\n");
		array = array->right;
	}
}

int main(void)
{
	struct ListHeadNode* array = NULL;

	insertNode(&array, 1);
	insertNode(&array, 2);
	insertNode(&array, 3);
	insertNode(&array, 4);
	
	insertEdge(&array, 1, 2);
	insertEdge(&array, 3, 4);
	insertEdge(&array, 1, 3);

	printList(array);

	return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    struct NODE *link;
    int value;
} Node;

int
carry(Node **rootp)
{
    Node *current;
    Node *new;
    int car = 0;
    current = *rootp;
    if (current->value>9)
    {
	current->value %= 10;
	car++;
	rootp = &current->link;
    }
    if (car>0)
	while ((current = *rootp) != NULL && car > 0)
	{
	    current->value += car;
	    car = current->value / 10;
	    current->value %= 10;
	    rootp = &current->link;
	}
    if (car > 0 )
    {
	new = (Node *)malloc(sizeof(Node));
	if (new == NULL)
	    return 0;
	new->value = car;
	*rootp = new;
	new->link = NULL;
    }
    return 1;
}
int
main()
{
    FILE *fd = NULL;
    fd = fopen("pe13.in", "rw+");
    int n = 5000;
    char c;
    Node *root;
    Node a;
    a.value = 0;
    a.link = NULL;
    root = &a;
    int i;
    while ((c=fgetc(fd))!=EOF)
    {
	root->value += c - 48;
	if (!carry(&root))
	    printf("false");
    }
    while (root != NULL)
    {
	printf("%d", root->value);
	root = root->link;
    }
}

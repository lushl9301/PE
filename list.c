#include <stdio.h>
#include <stdlib.h>

typedef struct NOED{
    struct NOED *link;
    int value;
} Node;

Node a;

int
sll_insert(register Node **linkp, int new_value)
{
    register Node *current;
    register Node *new;

    while ((current = *linkp) != NULL && current->value < new_value)
	linkp = &current->link;
    new =(Node *)malloc(sizeof(Node));
    if (new == NULL)
	return 0;
    new->value = new_value;

    new->link = current;
    *linkp = new;
    return 1;
}
    
int
main()
{
    int n, i, x;
    scanf("%d", &n);
    Node *root;
    Node a;
    root = &a;
    for (i=0; i<n; i++)
    {
	scanf("%d", &x);
	sll_insert(&root, x);
    }
}

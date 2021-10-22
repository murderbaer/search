typedef struct node {
	short boardState[9];
	struct node * children;
	struct node * solutionPath;
} node;

void append(node * list, node * node);
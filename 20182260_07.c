#include <stdio.h>
#include <stdlib.h>

typedef struct AvlNode
{
	int data;
	struct AvlNode* leftchild;
	struct AvlNode* rightchild;
	int height;
}AvlNode;

AvlNode* Insert(AvlNode*, int);
AvlNode* Delete(AvlNode*, int);

int Height(AvlNode*);
int HeightDifferent(AvlNode*);

AvlNode* rightrotation(AvlNode*);
AvlNode* leftrotation(AvlNode*);
AvlNode* RRrotation(AvlNode*);
AvlNode* LLrotation(AvlNode*);
AvlNode* RLrotation(AvlNode*);
AvlNode* LRrotation(AvlNode*);

void Preorder(AvlNode* node);

int main()
{
	AvlNode* root = NULL;
	int number, deleteData, insertData;

	//number of datas when AVL tree creation
	printf("How many will you enter? \n");
	scanf("%d", &number);

	//insert datas
	printf("Insert node to AVL tree : \n");
	for (int i = 0; i < number; i++)
	{
		scanf("%d", &insertData);
		root = Insert(root, insertData);
	}

	printf("\n\n\n");

	printf("Preorder traversal of the constructed AVL tree is \n");
	Preorder(root);
	printf("\nPreorder traversal after deletion of ");
	scanf("%d", &deleteData);
	root = Delete(root, deleteData);
	Preorder(root);
	printf("\n");

//Insert data from AVL tree
AvlNode* Insert(AvlNode* node, int insertdata)
{
	//AVL tree is empty
	if (node == NULL)
	{
		node = (AvlNode*)malloc(sizeof(AvlNode));
		node->data = insertdata;
		node->leftchild = NULL;
		node->rightchild = NULL;
	}

	//insertdata is less than data in the AVL tree
	else if (insertdata < node->data)
	{
		node->leftchild = Insert(node->leftchild, insertdata);
		if (HeightDifferent(node) == 2)
			if (insertdata < node->leftchild->data)
				node = LLrotation(node);
			else
				node = LRrotation(node);
	}

	//insertdata is larger than data in the AVL tree
	else if (insertdata > node->data)
	{
		node->rightchild = Insert(node->rightchild, insertdata);
		if (HeightDifferent(node) == -2)
			if (insertdata > node->rightchild->data)
				node = RRrotation(node);
			else
				node = RLrotation(node);
	}

	//Duplicate Value Exists
	else
		printf("Duplicate Data");
	node->height = Height(node);
	return(node);
}

//Delete data from the AVL tree
AvlNode* Delete(AvlNode* node, int deletedata)
{
	AvlNode* p;

	//AVL tree is empty
	if (node == NULL)
	{
		return NULL;
	}

	//deletedata is less than data in the AVL tree
	else if (deletedata < node->data)
	{
		node->leftchild = Delete(node->leftchild, deletedata);
		if (HeightDifferent(node) == -2)
			if (HeightDifferent(node->rightchild) <= 0)
				node = RRrotation(node);
			else
				node = RLrotation(node);
	}

	//deletedata is larger than data in the AVL tree
	else if (deletedata > node->data)
	{
		node->rightchild = Delete(node->rightchild, deletedata);
		if (HeightDifferent(node) == 2)
			if (HeightDifferent(node->leftchild) >= 0)
				node = LLrotation(node);
			else
				node = LRrotation(node);
	}

	//deletedata is the same as data
	else
	{
		if (node->rightchild != NULL)
		{
			p = node->rightchild;

			while (p->leftchild != NULL)
				p = p->leftchild;

			node->data = p->data;
			node->rightchild = Delete(node->rightchild, p->data);

			if (HeightDifferent(node) == 2)
				if (HeightDifferent(node->leftchild) >= 0)
					node = LLrotation(node);
				else
					node = LRrotation(node);
		}
		else
			return(node->leftchild);
	}
	node->height = Height(node);
	return(node);
}


//node height
int Height(AvlNode* node)
{
	int LeftHeight, RightHeight;

	if (node == NULL)
		return(0);

	if (node->leftchild == NULL)
		LeftHeight = 0;
	else
		LeftHeight = 1 + node->leftchild->height;

	if (node->rightchild == NULL)
		RightHeight = 0;
	else
		RightHeight = 1 + node->rightchild->height;

	if (LeftHeight > RightHeight)
		return(LeftHeight);
	else
		return(RightHeight);
}

// Height different
int HeightDifferent(AvlNode* node)
{
	int leftheight, rightheight;

	if (node == NULL)
		return(0);

	if (node->leftchild == NULL)
		leftheight = 0;
	else
		leftheight = 1 + node->leftchild->height;

	if (node->rightchild == NULL)
		rightheight = 0;
	else
		rightheight = 1 + node->rightchild->height;

	return(leftheight - rightheight);
}

//right rotation
AvlNode* rightrotation(AvlNode* node)
{
	AvlNode* y;
	y = node->leftchild;
	node->leftchild = y->rightchild;
	y->rightchild = node;
	node->height = Height(node);
	y->height = Height(y);
	return(y);
}

//left rotation
AvlNode* leftrotation(AvlNode* node)
{
	AvlNode* y;
	y = node->rightchild;
	node->rightchild = y->leftchild;
	y->leftchild = node;
	node->height = Height(node);
	y->height = Height(y);
	return(y);
}

AvlNode* RRrotation(AvlNode* node)
{
	node = leftrotation(node);
	return(node);
}

AvlNode* LLrotation(AvlNode* node)
{
	node = rightrotation(node);
	return(node);
}

AvlNode* RLrotation(AvlNode* node)
{
	node->rightchild = rightrotation(node->rightchild);
	node = leftrotation(node);
	return(node);
}

AvlNode* LRrotation(AvlNode* node)
{
	node->leftchild = leftrotation(node->leftchild);
	node = rightrotation(node);
	return(node);
}


//preorder traversal
void Preorder(AvlNode* node)
{
	if (node != NULL)
	{
		printf("%d ", node->data);
		Preorder(node->leftchild);
		Preorder(node->rightchild);
	}
}
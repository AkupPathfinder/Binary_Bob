#include <iostream>
#include "types.h"



void creation1(Node** node, int value1) // This program will create new leaves. If you use value, that already exists, it will ignore it.
{
    Node* newNode; // ukazatel pro novy vkladany Node
    Node* actNode; // ukazatel na aktualni Node

    newNode = (Node*)malloc(sizeof(Node)); // Creates new Node.
	newNode->value = value1;
    newNode->leftNode = NULL; // And gives parameter values.
    newNode->rightNode = NULL;

	actNode = *node;
	
	if (*node == NULL) // Checking if we don't have clear node without anything
	{
		*node = newNode; // Checking if we have first value as a value we have to delete
		return;
	}

	while (actNode) // 
	{
		if (actNode->value == newNode->value)
		{
		printf_s("The value already exists.\n");
		break;
		}

		else if ((actNode->value > newNode->value) && (actNode->leftNode == NULL)) // 
		{
			actNode->leftNode = newNode; // pridavame na konec
			break;
		}
		
		else if ((actNode->value < newNode->value) && (actNode->rightNode == NULL)) // 
		{
			actNode->rightNode = newNode; // 
			break;
		}
		
		else if (actNode->value > newNode->value) // so we choose lNode
		{
			actNode = actNode->leftNode;
		}

		else if (actNode->value < newNode->value)
		{
			actNode = actNode->rightNode;
		}
	}
}
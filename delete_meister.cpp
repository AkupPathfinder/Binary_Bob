#include <iostream>
#include "types.h"

void delete_meister(Node** node, int value1)
{
	
	Node* actNode = *node;

	if (!*node)
		return;
	else if (actNode->value == value1)
	{
		*node = NULL;
		return;
	}

	while (actNode && (actNode->leftNode || actNode->rightNode))
	{
		if (actNode->leftNode)
		{
			if (actNode->leftNode && (actNode->leftNode->value == value1))
			{
				free(actNode->leftNode); // delete son from the tree
				actNode->leftNode = NULL;
				return;
			}

			if (actNode->value > value1) // so we choose lNode
			{
				actNode = actNode->leftNode;
			}
		}
		if (actNode->rightNode)
		{
			if (actNode->rightNode && (actNode->rightNode->value == value1))
			{
				free(actNode->rightNode); // delete son from the tree
				actNode->rightNode = NULL; 
				return;
			}

			else if (actNode->value < value1)
			{
				actNode = actNode->rightNode;
			}
		}
	}
}
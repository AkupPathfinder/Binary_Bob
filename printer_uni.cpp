#include <iostream>
#include "types.h"

void printer(Node* node, int indent)
{
    printf_s("  ");
    if (node != NULL)
    {
        for (int i = 0; i < indent; ++i) // printing tree while cycle is valid 
        {
            printf_s("    ");
        }
        printf_s("|--  %d\n", node->value); //printing value of the node 
        if (node->leftNode != NULL)
            printer(node->leftNode, indent + 1);// printing value of the left child 
        if (node->rightNode != NULL)
            printer(node->rightNode, indent + 1);// printing value of the right child 
    } 
    return;
}
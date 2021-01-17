#include <iostream>
#include "types.h"

Node* noder(int value1) // This program has to create a node to add it into the tree.
{
    Node* x = (Node*)malloc(sizeof(Node));
    x->value = value1;
    x->leftNode = NULL;
    x->rightNode = NULL;
    return x;
}

Node* node_creation(Node* node, int value1) // This program will create new leaves. If you use value, that already exists, it will ignore it.
{
    if (node != NULL && node->value != NULL)
    {
        if (node->value < value1)
            node->rightNode = node_creation(node->rightNode, value1);
        else if (node->value > value1)
            node->leftNode = node_creation(node->leftNode, value1);
    }

    else
    {
        node = noder(value1);
        return node;
    }
    return node;
}

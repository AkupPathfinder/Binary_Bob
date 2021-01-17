#pragma once

#include <iostream>

typedef struct Node // A structure of our binary tree nodes
{
    int value;
    Node* leftNode;
    Node* rightNode;
} Node;
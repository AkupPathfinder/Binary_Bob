#include <iostream>
#include "types.h"
#include <stdio.h>

void printer_with_save(Node* node,FILE* output )//printing tree and saving it into file
{
    
    if (node != NULL)
    {
        
        fprintf(output,"%d \n",node->value);//
        if (node->leftNode != NULL) {
            printer_with_save(node->leftNode, output);// printing value of the left child
        }
        if (node->rightNode != NULL) {
            
            printer_with_save(node->rightNode, output);// printing value of the right child 
            
        }
        
    }
    return;
}
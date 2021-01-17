#include <iostream>
#include "delete_meister.h"
#include "printer_uni.h"
#include "printer_with_save.h"
#include "types.h"
#include "creation1.h"

Node* treepo = NULL; // global tree 

int input_tree() // inputing tree from file system 
{
    FILE* stfu; // pointer na FILE
    if ((stfu = fopen("input.txt", "rt")) == NULL)// kontrola existence souboru
    {
        printf("cannot open file.\\n"); 
        exit(1);
    };
    size_t counter = 0;
    int ch, pre = EOF;
    while ((ch = fgetc(stfu)) != EOF) //scanning string until the end of file 
    {
        pre = ch;

        if (ch == '\n')
            ++counter;
    }
    if (pre == EOF)
        puts("file is empty");
    else if (pre != '\n') {
        ++counter;

    }
    int* val; //creating pointer for array 
    val = (int*)malloc(counter * sizeof(int)); // allocating memory for dynamic array 
    stfu = fopen("input.txt", "rt");
   
    for (int i = 0;i < counter; i++) //adding tree
    {
        fscanf_s(stfu, "%d", &val[i]);
        creation1(&treepo, val[i]);
    }
    fclose(stfu);//closing file stream
    free(val);//here we will free memory 
    return 0;
}


int menu()// simple menu for managing program
{
    int command = 0;
    printf_s(" Welcome to the Binary_Bob! Write the digit: \n 1 - Add tree from file.\n 2 - Add the node. \n 3 - Delete the node.\n ");
    printf_s("4 - Print the tree as a file system.\n 5 - Print & save it in the file.\n 6 - Exit the program.\n");
    while (command < 1 or command > 6)
    {
        command = 10;
        scanf_s("%d", &command);
        if (command >= 1 and command <= 6)
            return command;
        printf_s("You have written wrong digit. Please, write another one from the list.\n");
    }
}

int op_choose()//scenario for each variant of the operation 
{
    int command = menu();
    switch (command)
    {
    case 1: //add tree from file
        {
            printf_s(" Tree was added from file\n\n");
            input_tree();
            break;
        }
    case 2: // add node from keyboard 
    {
        printf_s(" What value do you want to add?\n");
        int val;
        scanf_s("%d", &val);
        creation1(&treepo, val);
        break;
    }

    case 3: // delete chosen node 
    {
        printf_s(" What value do you want to delete?\n\n");
        int val;
        scanf_s("%d", &val);
        delete_meister(&treepo, val);
        break;
    }

    case 4: //printing tree on the screen
    {
        printf_s(" Printing the tree...\n\n");
        printer(treepo, 0);
        printf_s("\n Tree was printed.\n\n");
        break;
    }
    case 5://printing and saving tree into the output.txt
    {
        printf_s(" Saving the tree...\n\n");
        FILE* output;
        output = fopen("output.txt", "w");
        printer_with_save(treepo, output);
        fclose(output);
        printf_s(" Tree successfully saved in file out.txt\n\n");
        break;
    }
    case 6://end programm
    {
        printf_s("Exiting...");
        exit(0);
    }
    }
    return command;
}


int main()
{
    int prog_end = 0;
    while (prog_end == 0)
    {
        op_choose();
    }
}


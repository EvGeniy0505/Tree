#include <stdlib.h>
#include <assert.h>

#include "tree.h"


Node* C_tor(int first_tree_val)
{
    Node* nd = Create_node(first_tree_val);

    return nd;
}

void Insert(Node* nd, int new_val)
{
    if(!nd)   return;

    if(new_val < nd -> data)
    {
        Insert(nd -> left, new_val);

        if(nd -> left == NULL)
            nd -> left = (Node*)Create_node(new_val);
    }
    else
    {
        Insert(nd -> right, new_val);

        if(nd -> right == NULL)
            nd -> right = (Node*)Create_node(new_val);
    }
}

void Print(Node* nd)
{
    if(!nd)   return;

    putchar('(');

    if(nd -> left)
        Print(nd -> left);

    printf("%d", nd -> data);

    if(nd -> right)
        Print(nd -> right);

    printf(")");
}

Node* Create_node(int new_val)
{
    Node* nd = (Node*) calloc(1, sizeof(Node));

    nd -> data  = new_val;
    nd -> left  = NULL;
    nd -> right = NULL;

    return nd;
}

void Dot_dump(Node* nd, int num_graph)
{
    FILE* f_dot = fopen("output/tree.dot", "w");

    assert(f_dot);
    assert(nd);
    if(ferror(f_dot))
        fprintf(stderr, "FILE OPEN ERROR!!!\n");

    fprintf(f_dot, "digraph TREE%d {\n\trankdir=HR;\n\tbgcolor = \"green:yellow\";\n", num_graph);

    // fprintf(f_dot, "\tsubgraph cluster0 {\n\t\tnode [style=filled,color=white];\n"
    //                "\t\tstyle=filled;\n\t\tcolor=lightgrey;\n");




    fprintf(f_dot, "}");

    fclose(f_dot);

    Dot_file_compile(num_graph);
}

void Dot_file_compile(int num_pucture)
{
    char com1[40] = "dot -Tpng output/tree.dot > output/tree";
    char com2[5]  = ".png";

    char com[47] = "";

    char num_str[3] = "";

    snprintf(num_str, sizeof(num_str), "%d", num_pucture);

    sprintf(com, "%s%s%s", com1, num_str, com2);

    system(com);
}

void D_tor(Node* nd)
{
    if(nd -> left || nd -> right)
        if(nd -> right)
            D_tor(nd -> right);
        else
            D_tor(nd -> left);
    else
        nd = NULL;
        free(nd);
}
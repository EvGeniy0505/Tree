#include <stdio.h>


struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* C_tor(int first_tree_val);

Node* Create_node(int new_val);

void Insert(Node* nd, int new_val);

void Dot_file_compile(int num_pucture);

void Dot_dump(Node* nd, int num_graph);

void Print(Node* nd);

void D_tor(Node* nd);

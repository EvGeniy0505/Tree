#include "tree.h"


int main()
{
    Node* nd = Tree_ctor(50);

    for(int i = 0; i < 10; i++)
        Insert(nd, i * 11);

    Insert(nd, 35);

    Insert(nd, 30);

    Print(nd);

    putchar('\n');

    Dot_dump(nd, 1);

    Tree_dtor(nd);

    return 0;
}
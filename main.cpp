#include "tree.h"


int main()
{
    Node* nd = C_tor(50);

    for(int i = 0; i < 10; i++)
        Insert(nd, i * 11);

    Insert(nd, 35);

    Print(nd);
    putchar('\n');

    D_tor(nd);

    return 0;
}
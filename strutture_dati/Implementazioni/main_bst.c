#include "bst.h"
int main(int argc, char const *argv[])
{

    Nodo *root = NULL;
    root =  insert(root, 10, 11);
    insert(root, 12, 1);
    insert(root, 22, 10);

    printf("%d\n",root->value);

    return 0;
}
